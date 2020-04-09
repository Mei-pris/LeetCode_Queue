#include <iostream>
#include <queue>
#include<iomanip>

using namespace std;
class MovingAverage {
private:
    queue <int> q;
    int maxsize;
    double sum;
public:
    MovingAverage(int k) {
        maxsize = k;
        sum = 0;
    }

    double next(int val) {
        if (q.size() >= maxsize)
        {
            sum = sum - q.front();
            q.pop();
        }
        sum = sum + val;
        q.push(val);
        return sum / q.size();
    }



};
int main()
{
    double b = 0;
    MovingAverage m(4);
    b = m.next(1);
    cout << fixed << setprecision(4) << b << endl;
    b = m.next(10);
    cout << fixed << setprecision(4) << b << endl;
    b = m.next(3);
    cout << fixed << setprecision(4) << b << endl;
    b = m.next(5);
    cout << fixed << setprecision(4) << b << endl;
    b = m.next(8);
    cout << fixed << setprecision(4) << b << endl;

    return 0;
}
