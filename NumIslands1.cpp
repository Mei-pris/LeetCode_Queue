#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    infect(grid, i, j);
                }
            }
        }
        return num;
    }

    void infect(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        infect(grid, i - 1, j);
        infect(grid, i, j + 1);
        infect(grid, i + 1, j);
        infect(grid, i, j - 1);
    }

};

int main()
{
    int num = 0;
    vector<vector<char> >a{ {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
    Solution mysolution;
    num = mysolution.numIslands(a);
    cout << num << endl;
    return 0;
}