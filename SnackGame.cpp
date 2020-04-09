#include <iostream>
#include <queue>
#include <unordered_map>
#include<vector>

using namespace std;
class SnackGame {
private:
    int w, h, x, y, fdnum,flag;
    queue<int>q;
    unordered_map<int, bool>snackbody;
    vector<vector<int> >fd;
public:
    SnackGame(int width, int height, vector<vector<int> >& food) :
        w(width), h(height), x(0), y(0), fdnum(0), flag(0),fd(food) {
        q.push(0);
        snackbody[0] = true;
    }

    int move(string direction) {
        if (direction == "U") x--;
        if (direction == "R") y++;
        if (direction == "D") x++;
        if (direction == "L") y--;
        int max = w > h ? w : h;
        if(flag == 0) {
            int val = q.front();
            q.pop();
            snackbody.erase(val);
        }
        if (x<0 || y<0 || x>=h || y>=w || snackbody[x * max + y]) return -1;
        q.push(x * max + y);
        snackbody[x * max + y] = true;
        flag = 0;
        if(fdnum<fd.size())
        { 
            if ((x == fd[fdnum][0]) && (y == fd[fdnum][1])) {
                flag = 1;
                ++fdnum;
            }     
        }
        return q.size() + flag - 1;
    }
};

int main() {
    vector<vector<int> > fod{ {1,2},{0,1} };
    SnackGame snackgame(3,2,fod);
    int ans;
    ans = snackgame.move("R");
    cout << ans << endl;
    ans = snackgame.move("D");
    cout << ans << endl;
    ans = snackgame.move("R");
    cout << ans << endl;
    ans = snackgame.move("U");
    cout << ans << endl;
    ans = snackgame.move("L");
    cout << ans << endl;
    ans = snackgame.move("U");
    cout << ans << endl;
}