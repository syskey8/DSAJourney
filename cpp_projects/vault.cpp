#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Entry {
    string site;
    string username;
    string password;
};

string xor_data(const string& data, const string& key) {
    if (key.empty()) return data;
    string out = data;
    for (size_t i = 0; i < data.size(); ++i) {
        out[i] = data[i] ^ key[i % key.size()];
    }
    return out;
}

string serialize(const vector<Entry>& vault) {
    ostringstream oss;
    for (const auto& e : vault) {
        oss << e.site << "\n";
        oss << e.username << "\n";
        oss << e.password << "\n";
        oss << "---" << "\n";
    }
    return oss.str();
}

vector<Entry> deserialize(const string& text) {
    vector<Entry> vault;
    istringstream iss(text);
    string line;

    while (true) {
        Entry e;
        if (!getline(iss, e.site)) break;
        if (!getline(iss, e.username)) break;
        if (!getline(iss, e.password)) break;
        if (!getline(iss, line)) break; // separator line
        // optional: if (line != "---") handle malformed data
        vault.push_back(e);
    }

    return vault;
}

bool save_vault(const string& filename,
                const vector<Entry>& vault,
                const string& master_password) {
    string plain = serialize(vault);
    string encrypted = xor_data(plain, master_password);

    ofstream out(filename, ios::binary | ios::trunc);
    if (!out) {
        cerr << "Error: could not open file for writing: " << filename << "\n";
        return false;
    }

    out.write(encrypted.data(),
              static_cast<std::streamsize>(encrypted.size()));
    if (!out) {
        cerr << "Error: failed while writing to file: " << filename << "\n";
        return false;
    }

    return true;
}

bool load_vault(const string& filename,
                vector<Entry>& vault,
                const string& master_password) {
    ifstream in(filename, ios::binary);
    if (!in) {
        // File does not exist yet – start with empty vault
        vault.clear();
        return true;
    }

    string encrypted((istreambuf_iterator<char>(in)),
                      istreambuf_iterator<char>());
    if (!in.good() && !in.eof()) {
        cerr << "Error: failed while reading file: " << filename << "\n";
        return false;
    }

    if (encrypted.empty()) {
        vault.clear();
        return true;
    }

    string plain = xor_data(encrypted, master_password);
    vault = deserialize(plain);
    return true;
}

void add_entry(vector<Entry>& vault) {
    Entry e;
    cout << "Site: ";
    getline(cin, e.site);
    cout << "Username: ";
    getline(cin, e.username);
    cout << "Password: ";
    getline(cin, e.password);

    vault.push_back(e);
    cout << "Entry added.\n";
}

void list_entries(const vector<Entry>& vault) {
    if (vault.empty()) {
        cout << "Vault is empty.\n";
        return;
    }

    for (size_t i = 0; i < vault.size(); ++i) {
        const auto& e = vault[i];
        cout << "[" << i << "]\n";
        cout << "  Site: " << e.site << "\n";
        cout << "  Username: " << e.username << "\n";
        cout << "  Password: " << e.password << "\n";
    }
}

void search_entries(const vector<Entry>& vault) {
    string query;
    cout << "Search site: ";
    getline(cin, query);

    bool found = false;
    for (const auto& e : vault) {
        if (e.site.find(query) != string::npos) {
            cout << "Site: " << e.site << "\n";
            cout << "Username: " << e.username << "\n";
            cout << "Password: " << e.password << "\n";
            cout << "---------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No matching entries.\n";
    }
}

void print_menu() {
    cout << "\nPassword Vault\n";
    cout << "1. Add entry\n";
    cout << "2. List entries\n";
    cout << "3. Search\n";
    cout << "4. Save and Exit\n";
    cout << "Choice: ";
}

int main() {
    vector<Entry> vault;
    const string filename = "vault.dat";

    string master_password;
    cout << "Enter master password: ";
    getline(cin, master_password);

    if (!load_vault(filename, vault, master_password)) {
        cerr << "Failed to load vault. Exiting.\n";
        return 1;
    }

    while (true) {
        print_menu();

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover '\n'

        if (choice == 1) {
            add_entry(vault);
        } else if (choice == 2) {
            list_entries(vault);
        } else if (choice == 3) {
            search_entries(vault);
        } else if (choice == 4) {
            if (!save_vault(filename, vault, master_password)) {
                cerr << "Failed to save vault.\n";
                return 1;
            }
            return 0;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
