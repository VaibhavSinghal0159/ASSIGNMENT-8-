#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int a[50];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void push(int value) {
        int i = size;
        a[size] = value;
        size++;

    
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (a[parent] < a[i]) {
                int t = a[parent];
                a[parent] = a[i];
                a[i] = t;
                i = parent;
            }
            else break;
        }
    }

    int top() {
        if (size == 0)
            return -1;
        return a[0];
    }

    void pop() {
        if (size == 0)
            return;

        a[0] = a[size - 1];
        size--;

        int i = 0;

  
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < size && a[left] > a[largest])
                largest = left;

            if (right < size && a[right] > a[largest])
                largest = right;

            if (largest == i)
                break;

            int t = a[i];
            a[i] = a[largest];
            a[largest] = t;

            i = largest;
        }
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(20);
    pq.push(5);
    pq.push(15);
    pq.push(40);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
