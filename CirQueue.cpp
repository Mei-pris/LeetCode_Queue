#include <iostream>
#include <vector>

using namespace std;
class MyCircularQueue {
private:
    vector<int>data;
    int head;
    int tail;
    int length;
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        length = k;
    }
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % length;
        data[tail] = value;
        return true;
    }


    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % length;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }

    bool isEmpty() {
        return head == -1;

    }


    bool isFull() {
        return head == (tail + 1) % length;

    }
};


int main()
{
    MyCircularQueue circularQueue(3);
    cout << circularQueue.enQueue(1) << endl;
    cout << circularQueue.enQueue(2) << endl;
    cout << circularQueue.enQueue(3) << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.isFull() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    return 0;
}
