#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class Heap {
private:
    array<int, MAX_SIZE> arr;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;

            if (arr[parentIndex] > arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallestIndex = index;

            if (leftChildIndex < size && arr[leftChildIndex] < arr[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }

            if (rightChildIndex < size && arr[rightChildIndex] < arr[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            if (smallestIndex != index) {
                swap(arr[index], arr[smallestIndex]);
                index = smallestIndex;
            } else {
                break;
            }
        }
    }

public:
    Heap() : size(0) {}

    int top() {
        if (size == 0) {
            throw logic_error("Heap is empty.");
        }

        return arr[0];
    }

    void insert(int x) {
        if (size == MAX_SIZE) {
            throw logic_error("Heap is full.");
        }

        arr[size] = x;
        heapifyUp(size);
        size++;
    }

    void remove() {
        if (size == 0) {
            throw logic_error("Heap is empty.");
        }

        swap(arr[0], arr[size - 1]);
        size--;
        heapifyDown(0);
    }
};

int main() {
    Heap minHeap;
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(4);

    while (true) {
        try {
            cout << minHeap.top() << " ";
            minHeap.remove();
        } catch (const logic_error& e) {
            cout << endl << e.what() << endl;
            break;
        }
    }

    return 0;
}
