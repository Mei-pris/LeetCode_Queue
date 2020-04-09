#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
	vector<int>killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		vector<int>ans;
		queue<int>q{ {kill} };
		unordered_map<int, vector<int>>m;
		for (unsigned int i = 0; i < ppid.size();++i ) {
			m[ppid[i]].push_back(pid[i]);
		}
		while (!q.empty()) {
			int t = q.front(); q.pop();
			ans.push_back(t);
			for (int mm : m[t]) {
				q.push(mm);
			}
		}
		return ans;
	}
};

int main() {
	Solution mysolution;
	vector<int>pd{1,3,10,5};
	vector<int>ppd{3,0,5,3};
	vector<int>result;
	int kil = 3;
	result = mysolution.killProcess(pd, ppd, kil);
	for (unsigned int j = 0; j < result.size(); ++j) {
		cout << result[j] << ' ';
	}


}