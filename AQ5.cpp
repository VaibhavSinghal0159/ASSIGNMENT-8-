#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

   
    for (int i = n - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    heapSort(a, n);

    cout << "Increasing: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Decreasing: ";
    for (int i = n-1; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

