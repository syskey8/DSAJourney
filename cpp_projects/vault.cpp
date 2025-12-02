#include <iostream>
#include <sstream>
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
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void search_entries(const vector<Entry>& vault) {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

int main () {
    vector<Entry> vault;
    vector<Entry> test;

  while(true) {
    int choice;
    string s1;
    cout << "Menu: " << endl;
    cout << "Select an option: " << endl;
    cout << "1. Add" << endl;
    cout << "2. List" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl;
    cout << "5. Serialize" << endl;
    cout << "6. deserialize" << endl;
    cin >> choice;
    cout << "Choice :" << choice << endl;

    switch(choice) {
      case 1: 
        add_entry(vault);
        break;
      case 2: 
        list_entries(vault);
        break;
      case 3: 
        search_entries(vault);
        break;
      case 4:
        return 0;
      case 5:
        s1 = serialize(vault);
        cout << s1 << endl;
        break;
      case 6:
        test = deserialize(s1);
        for (size_t i = 0; i < test.size(); ++i) {
        const auto& e = test[i];
        std::cout << "[" << i << "]\n";
        std::cout << "  Site: " << e.site << "\n";
        std::cout << "  Username: " << e.username << "\n";
        std::cout << "  Password: " << e.password << "\n";
    }
        break;
    }
  }
  return 0;
}

