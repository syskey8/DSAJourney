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

string serialize(const vector<Entry>& vault) {
  ostringstream oss;
  for(const auto& e : vault) {
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

  while(true) {
    Entry e;
    if (!getline(iss, e.site)) break;
    if (!getline(iss, e.username)) break;
    if (!getline(iss, e.password)) break;
    if (!getline(iss, line)) break; //separtor line
                                    //
    vault.push_back(e);
  }

  return vault;
}

bool save_vault(const string& filename, const vector<Entry>& vault) {
    string plain = serialize(vault);
    ofstream out(filename, ios::trunc);
    if (!out) {
        cerr << "Error writing file\n";
        return false;
    }
    out << plain;
    return true;
}

bool load_vault(const string& filename, vector<Entry>& vault) {
    ifstream in(filename);
    if (!in) {
        vault.clear();
        return true;
    }
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    vault = deserialize(content);
    return true;
}

void search_entries(const vector<Entry>& vault) {
  string query;
  cout << "Search site: ";
  getline(cin, query);

  bool found = false;
  for(const auto& e : vault) {
    if(e.site.find(query) != string::npos) {
      cout << "Site : " << e.site << endl;
      cout << "Username: " << e.username << endl;
      cout << "Password: " << e.password << endl;
      cout << "---------------\n";
      found = true;
    }
  }
  if(!found) {
    cout << "No mathcing entries." << endl;
  }
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
  cout << "Entry added. \n";
}

void list_entries(vector<Entry>& vault){
  if(vault.empty()) {
    cout << "Valut is empty" << endl;
    return;
  }
  else {
    for(int i = 0; i < vault.size(); i++) {
      const auto& e = vault[i];
      cout << "[" << i << "]" << endl;
      cout << "Site: " << e.site << endl;
      cout << "Username: " << e.username << endl;
      cout << "Password: " << e.password << endl;
    }
  }
}

int main() {
    vector<Entry> vault;
    const string filename = "vault.dat";

    load_vault(filename, vault);

    while (true) {
        cout << "\nPassword Vault\n";
        cout << "1. Add\n";
        cout << "2. List\n";
        cout << "3. Search\n";
        cout << "4. Save and Exit\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // one-time ignore

        if (choice == 1) {
            add_entry(vault);
        } else if (choice == 2) {
            list_entries(vault);
        } else if (choice == 3) {
            search_entries(vault);
        } else if (choice == 4) {
            save_vault(filename, vault);
            return 0;
        }
    }
}
