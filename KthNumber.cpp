#include <iostream>
#include <vector>

using namespace std;
class Solution {
public :
	int getKthMagicNumber(int k) {
		vector<int>num(k);
		int pos3 = 0, pos5 = 0, pos7 = 0;
		num[0]=1;
		for (unsigned int i = 1; i < k; ++i) {
			num[i] =mymin(num[pos3] * 3, num[pos5] * 5, num[pos7] * 7);
			if (num[i] == num[pos3] * 3)
				++pos3;
			if (num[i] == num[pos5] * 5) 
				++pos5;
			if (num[i] == num[pos7] * 7) 
				++pos7;
		}
		return num[k - 1];	
	}

	int mymin(int x, int y, int z) {
		int ans = x < y ? x : y;
		ans = ans < z ? ans : z;
		return ans;
	}
};
int main() {
	Solution mysolution;
	cout << mysolution.getKthMagicNumber(14) << endl;;
}