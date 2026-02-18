#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    int str_count = 0;
    cin >> str_count;
    string origin, target, t;
    cin >> origin >> target;
    queue<string> que;
    unordered_set<string> str_set;
    unordered_map<string, int> visit_map;

    que.push(origin);
    visit_map.insert(pair<string, int>(origin, 1));

    while (str_count--)
    {
        cin >> t;
        str_set.insert(t);
    }

    // bfs
    while (!que.empty())
    {
        string word = que.front();
        que.pop();
        int path = visit_map[word];

        for (int i = 0; i < str_count; i++)
        {
            string new_word = word;

            for(int j = 0; j < 26; j++)
            {
                new_word[i] = 'a' + j;
                
                if(new_word == target)
                {
                    cout<< path + 1;
                    return 0;
                }

                if(str_set.find(new_word) != str_set.end() && visit_map.find(new_word) == visit_map.end())
                {
                    visit_map.insert(pair<string, int>(new_word, path + 1));
                    que.push(new_word);
                }
            }
        }
    }
    cout<<0;
    return 0;
}