#include <iostream>
#include <queue>
#include <unordered_set>
#include <xstring>
#include <string>  


using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock(deadends.begin(), deadends.end());
        if (deadlock.count("0000")) return -1;
        queue<string>q{ {"0000"} };
        unordered_set<string>visited{ {"0000"} };
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int k = q.size(); k > 0; --k) {
                auto t = q.front(); q.pop();
                for (unsigned int i = 0; i < t.size(); ++i) {
                    char c = t[i];
                    string str1 = t.substr(0, i) + to_string(c == '9' ? 0 : c - '0' + 1) + t.substr(i + 1);
                    string str2 = t.substr(0, i) + to_string(c == '0' ? 9 : c - '0' - 1) + t.substr(i + 1);
                    if ((str1 == target) || (str2 == target)) return step;
                    if ((!deadlock.count(str1)) && (!visited.count(str1))) q.push(str1);
                    if ((!deadlock.count(str2)) && (!visited.count(str2))) q.push(str2);
                    visited.insert(str1);
                    visited.insert(str2);
                }

            }
        }
        return -1;
       
    }
};

int main() {
    Solution mysolution;
    int ans = 0;
    vector<string> deadstring{ {"0201"},{"0101"},{"0102"},{"1212"},{"2002"} };
    string tar = "0202";
    ans = mysolution.openLock(deadstring, tar);
    cout << ans << endl;
    return -1;
}
