#include <iostream>
#include <queue>
#include <unordered_set>


using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock(deadends.begin(),deadends.end());
        if (deadlock.count("0000")) return -1;
        int step = 0;
        queue<string>q{ {"0000"} };
        unordered_set<string> visited{ {"0000"} };
        while (!q.empty()) {
            ++step;
            for ( int k = q.size(); k > 0; --k) {
                auto t = q.front(); q.pop();
                for (unsigned int i = 0; i < t.size(); ++i) {
                    for ( int j = -1; j <= 1; ++j) {
                        if (j == 0) continue;
                        string str=t;
                        str[i] = ((t[i] - '0' + 10 + j)) % 10 + '0';
                        if (str == target) return step;
                        if ((!deadlock.count(str)) && (!visited.count(str))) q.push(str);
                        visited.insert(str);
                    }
                }

            }
        }
        return -1;
    }
};

int main() {
      Solution mysolution;
      int ans = 0;
     vector<string> deadstring{ {"0201"},{"0101"},{"0102"},{"1212"},{"2002"}};
      string tar = "0202";
      ans = mysolution.openLock(deadstring, tar);
      cout << ans << endl;
      return -1;
}