#include <bits/stdc++.h>
using namespace std;


const int MAX_SIZE = 100;

class PriorityQueue {
private:
    array<pair<string, int>, MAX_SIZE> arr;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;

            if (arr[parentIndex].second < arr[index].second) {
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
            int largestIndex = index;

            if (leftChildIndex < size && arr[leftChildIndex].second > arr[largestIndex].second) {
                largestIndex = leftChildIndex;
            }

            if (rightChildIndex < size && arr[rightChildIndex].second > arr[largestIndex].second) {
                largestIndex = rightChildIndex;
            }

            if (largestIndex != index) {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue() : size(0) {}

    string top() {
        if (size == 0) {
            throw logic_error("Priority queue is empty.");
        }

        return arr[0].first;
    }

    void insert(string x, int weight) {
        if (size == MAX_SIZE) {
            throw logic_error("Priority queue is full.");
        }

        arr[size] = make_pair(x, weight);
        heapifyUp(size);
        size++;
    }

    void remove() {
        if (size == 0) {
            throw logic_error("Priority queue is empty.");
        }

        swap(arr[0], arr[size - 1]);
        size--;
        heapifyDown(0);
    }
};

int main() {
    PriorityQueue pq;
    pq.insert("Apple", 3);
    pq.insert("Banana", 2);
    pq.insert("Orange", 5);
    pq.insert("Mango", 1);
    pq.insert("Grapes", 4);

    while (true) {
        try {
            cout << pq.top() << " ";
            pq.remove();
        } catch (const logic_error& e) {
            cout << endl << e.what() << endl;
            break;
        }
    }

    return 0;
}
