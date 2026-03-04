#include <iostream>
using namespace std;

// 火星词典
// 现有一种使用英语字母的火星语言
// 这门语言的字母顺序对你来说是未知的。
// 给你一个来自这种外星语言字典的字符串列表 words
// words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
// 如果这种说法是错误的，并且给出的 words 不能对应任何字母的顺序，则返回 ""
// 否则，返回一个按新语言规则的 字典递增顺序 排序的独特字符串
// 如果有多个解决方案，则返回其中任意一个
// words中的单词一定都是小写英文字母组成的
// 测试链接 : https://leetcode.cn/problems/alien-dictionary/
// 测试链接(不需要会员) : https://leetcode.cn/problems/Jf1JuT/

// abc
// abe
// xfd
// ijk
// ikk

// 先搞出这么多节点， 再进行连接

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        // 入度表
        // 字母用ascll码表示
        int kinds = 0; // 所有出现过的字符数量
        vector<int> indegree(26, -1);
        // 将出现的字母进行标记
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                indegree[words[i][j] - 'a'] = 0; // 最开始默认是0
            }
        }

        // 构建邻接表
        vector<vector<int>> graph(26);
        for (int i = 0; i < words.size() - 1; i++)
        {
            string &cur = words[i];
            string &nxt = words[i + 1];                                    // 只需要两两比较
            int len = (cur.size() > nxt.size() ? nxt.size() : cur.size()); // 比较长度
            // abc
            // abcd
            int j = 0;
            for (; j < len; j++)
            {
                if (cur[j] != nxt[j])
                {
                    graph[cur[j] - 'a'].push_back(nxt[j] - 'a');
                    indegree[nxt[j] - 'a']++;
                    break;
                }
            }
            // 特殊情况处理：当前缀相同但前一个单词更长（非法，如 "abc", "ab"）
            if (j == len && cur.size() > nxt.size())
                return "";
        }

        // Topo
        int queue[26];
        int l = 0, r = 0;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] == 0)
                queue[r++] = i;
            if (indegree[i] != -1)
                kinds++;
        }

        int cnt = 0;
        while (l < r)
        {
            int cur = queue[l++];
            cnt++;
            for (int i = 0; i < graph[cur].size(); i++)
            {
                indegree[graph[cur][i]]--;
                if (indegree[graph[cur][i]] == 0)
                {
                    queue[r++] = graph[cur][i];
                }
            }
        }

        string ans = "";
        if (cnt == kinds)
        {
            for (int i = 0; i < kinds; i++)
                ans.push_back(queue[i] + 'a');
        }
        return ans;
    }
};