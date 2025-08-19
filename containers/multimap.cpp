#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<string, int> m;
    m.emplace("watch", 100);
    m.emplace("watch", 100);
    m.emplace("watch", 100);
    m.emplace("watch", 100);

    cout << "normal print" << endl;
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    m.erase(m.find("watch"));
    cout << "after erasing the found item" << endl;
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    m.erase("watch");
    cout << "after erasing without find";
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}