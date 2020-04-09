#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int>tasknum;
		int maxsize = 0, cnt = 0;
		for (auto task : tasks) {
			++tasknum[task];
			maxsize = max(maxsize, tasknum[task]);
		}
		cnt = (maxsize - 1) * (n + 1);
		for (auto p : tasknum) {
			if (p.second== maxsize) ++cnt;
		}
		return max(cnt, (int)tasks.size());
	}

};

int main() {
	Solution mysolution;
	int ans = 0,n=2;
	vector<char>task{'A','B','B','A','A','C','A','B','B','D','E','F'};
	ans = mysolution.leastInterval(task, n);
	cout << ans << endl;
}