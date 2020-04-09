#include <iostream>
#include <vector>

using namespace std;

class SeQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int length;
public:
    SeQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        length = k;
    }

    bool IsEmpty() {
        return head == tail;
    }

    bool IsFull() {
        return tail == length;
    }

    bool EnQueue(int x) {
        if (IsFull()) {
            cout << "队列已满" << endl;
            return false;
        }
        data[tail] = x;
        tail++;
        return true;
    }

    bool DeQueue() {
        if (IsEmpty()) {
            cout << "队列为空" << endl;
            return false;
        }
        head++;
        return true;
    }

    void GetHead() {
        if (IsEmpty()) {
            cout << "队列为空" << endl;
        }
        cout << "队头元素为：" << data[head] << endl;
    }

    void printfQueue() {
        int i = head;
        while (i < tail) {
            cout << data[i] << " ";
            i++;
        }
        cout << endl;
    }
};

int main()
{
    SeQueue mySeQueue(5);
    mySeQueue.EnQueue(5);
    mySeQueue.EnQueue(10);
    mySeQueue.EnQueue(30);
    mySeQueue.EnQueue(8);
    mySeQueue.EnQueue(6);
    mySeQueue.EnQueue(7);
    mySeQueue.printfQueue();
    mySeQueue.DeQueue();
    mySeQueue.printfQueue();
    mySeQueue.DeQueue();
    mySeQueue.printfQueue();
}
