#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    m["headphones"] = 100;
    m["laptop"] = 100;
    m["laptop"] = 100;
    m["tablet"] = 100;
    m["tablet "] = 100;
    m["watch"] = 100;
    m["watch"] = 100;
    m["watch"] = 100;

    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    if (m.find("watch") != m.end())
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}