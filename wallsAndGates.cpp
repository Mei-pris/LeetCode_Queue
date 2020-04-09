#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2147483647
class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        queue<pair<int, int> > q;
        vector<vector<int> > dirs{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
        for (unsigned int i = 0; i < rooms.size(); ++i) {
            for (unsigned int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) q.push({ i, j });
            }
        }
        while (!q.empty()) {
           unsigned int i = q.front().first, j = q.front().second; q.pop();
            for (unsigned int k = 0; k < dirs.size(); ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({ x, y });
            }
        }
    }
};
int main()
{

    vector<vector<int> >a{ {-1,-1,0,INF},{INF,-1,INF,-1},{INF,-1,INF,-1},{0,-1,INF,INF} };
    Solution mysolution;
    mysolution.wallsAndGates(a);
    for (unsigned int i = 0; i < a.size(); ++i) {
        for (unsigned int j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
