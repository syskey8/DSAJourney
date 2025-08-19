#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> m;
    m.emplace("tv", 100);
    m.emplace("watch", 120);
    m.emplace("laptop", 130);
    m.emplace("fridge", 140);
    m.emplace("fridge", 140);
    m.emplace("fridge", 140);

    cout << "normal print" << endl;
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    m.erase(m.find("fridge"));
    cout << "after erasing the found item" << endl;
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    m.erase("fridge");
    cout << "after erasing without find" << endl;
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}