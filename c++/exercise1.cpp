////////////////////////////////////////////////////////////////////////////////////////
//  ▄████▄   ▄▄▄       ▄████▄   ██░ ██ ▓█████  ███▄ ▄███▓▓█████
// ▒██▀ ▀█  ▒████▄    ▒██▀ ▀█  ▓██░ ██▒▓█   ▀ ▓██▒▀█▀ ██▒▓█   ▀
// ▒▓█    ▄ ▒██  ▀█▄  ▒▓█    ▄ ▒██▀▀██░▒███   ▓██    ▓██░▒███
// ▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒▓▓▄ ▄██▒░▓█ ░██ ▒▓█  ▄ ▒██    ▒██ ▒▓█  ▄
// ▒ ▓███▀ ░ ▓█   ▓██▒▒ ▓███▀ ░░▓█▒░██▓░▒████▒▒██▒   ░██▒░▒████▒
// ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ░▒ ▒  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░   ░  ░░░ ▒░ ░
//   ░  ▒     ▒   ▒▒ ░  ░  ▒    ▒ ░▒░ ░ ░ ░  ░░  ░      ░ ░ ░  ░
// ░          ░   ▒   ░         ░  ░░ ░   ░   ░      ░      ░
// ░ ░            ░  ░░ ░       ░  ░  ░   ░  ░       ░      ░  ░
// ░                  ░
//
// Create a cache class able to store 5 keys within.
// Values must be arranged from the most recently used key to least recently used key.
//
// Assume the data to cache is the following array:
//
// ["A", "B", "C", "D", "E", "F", "G", "H", "I"]
//
// Assume at a given point the internal cache state is (key-value representation):
//
// [1:"A", 4:"D", 6:"F", 2:"B", 9:"I"]
//
// In case the next call is via key "6" (cache hit) the cache should return "F" without
// accessing the data array. The cache state changes as follows:
//
// [6:"F", 1:"A", 4:"D", 2:"B", 9:"I"]
//
// In case the next call is "8" (cache miss) the cache should retrieve "H" from the data
// array, return it and change its state as follows:
//
// [8:"H", 6:"F", 1:"A", 4:"D", 2:"B"]
//
// Bonus: make the cache able to act on a underlying data array containing ANY data type
//
// Bonus 2: abstract the cache in order to accept C and std arrays and std vectors as
//          underlying data structures
//
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

typedef pair<int, string> pairIntString;

void print_vector(vector<pairIntString> &m)
{
    cout << "[ ";
    for (const auto &iter : m)
    {
        cout << iter.first << " : " << iter.second << ", ";
    }
    cout << "]" << endl;
}

void normalMapCache(vector<pairIntString> &m, string keys[], int idx)
{
    bool flag = false;
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        if ((*iter).first == idx)
        {
            auto x = *iter;
            m.erase(iter);
            m.insert(m.begin(), x);
            flag = true;
            cout << "== Cache Hit ==" << endl;
            break;
        }
    }
    if (!flag)
    {
        m.pop_back();
        m.insert(m.begin(), pairIntString(idx, keys[idx - 1]));
        cout << "== Cache Miss ==" << endl;
    }
}

int main()
{
    vector<pairIntString> m;
    srand((unsigned)time(nullptr));
    int idx;
    string keys[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    for (int i = 0; i < 5; i++)
    {
        idx = (rand() % 9);
        // This will generate caches with duplicate keys, and was made for testing purposes only
        m.emplace_back(idx + 1, keys[idx]);
    }
    cout << "Original Cache: ";
    print_vector(m);
    for (int i = 0; i < 10; i++)
    {
        idx = (rand() % 9) + 1;
        cout << "Calling Cache with Key: " << idx << endl;
        normalMapCache(m, keys, idx);
        cout << "Modified Cache: ";
        print_vector(m);
    }
}
