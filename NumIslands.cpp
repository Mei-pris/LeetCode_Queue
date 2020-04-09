#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//BFS·½·¨
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        queue<pair<int, int> > q;
        vector<vector<int> > dirs{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
        if (grid.size() == 0) return 0;
        if(grid[0].size()== 0) return 0;

        for (unsigned int i = 0; i < grid.size(); ++i) {
            for (unsigned int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    grid[i][j]= '0';
                    q.push({ i, j });

                    while (!q.empty()) {
                        unsigned int ii = q.front().first, jj = q.front().second; q.pop();
                        for (unsigned int k = 0; k < dirs.size(); ++k) {
                            int x = ii + dirs[k][0], y = jj + dirs[k][1];
                            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') continue;
                            grid[x][y] = '0';
                            q.push({ x, y });
                        }
                    }


                }


            }
        }

        return num;


    }

};

int main()
{
    int num = 0;
    vector<vector<char> >a{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution mysolution;
    num=mysolution.numIslands(a);  
    cout << num << endl;
    return 0;
}