#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int num = 0;
        queue<int>q;
        unordered_set<int>visited;
        q.push(n);
        while (!q.empty()) {
            ++num;
            for (int k = q.size(); k > 0; --k) {
                int val = q.front(); q.pop();
                for (int i = 1; val - i * i >= 0; ++i) {
                    int temp = 0;
                    temp = val - i * i;
                    if (temp == 0)  return num;
                    if (!visited.count(temp)) q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return  -1;
       
    }
};

int main() {
    Solution mysolution;
    int ans = 0;
    int  a = 12;
    ans = mysolution.numSquares(12);
    cout << ans << endl;
    return 0;

}