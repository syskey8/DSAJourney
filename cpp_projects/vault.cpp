#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Entry {
    string site; 
    string username; 
    string password;
  };

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

  while(true) {
    int choice;
    cout << "Menu: " << endl;
    cout << "Select an option: " << endl;
    cout << "1. Add" << endl;
    cout << "2. List" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    switch(choice) {
      case 1: 
        add_entry(vault);
        break;
      case 2: 
        list_entries(vault);
        break;
      case 3: return 0;
    }
  }

  return 0;
}

