//4.  Max, Min Heap Kodu
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) { 
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void heapifyDown(int i) {
        int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void insert(int val) { heap.push_back(val); heapifyUp(heap.size() - 1); }
    void extractMin() {
        if (heap.empty()) return;
        heap[0] = heap.back(); heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
    void print() { for (int x : heap) cout << x << " "; cout << endl; }
};

class MaxHeap {
private:
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void heapifyDown(int i) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    void insert(int val) { heap.push_back(val); heapifyUp(heap.size() - 1); }
    void extractMax() {
        if (heap.empty()) return;
        heap[0] = heap.back(); heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
    void print() { for (int x : heap) cout << x << " "; cout << endl; }
};

int main() {
    vector<int> data = {15, 10, 30, 5, 20};

    cout << "--- MIN HEAP TEST ---" << endl;
    MinHeap minH;
    for (int x : data) minH.insert(x);
    cout << "Min Heap Yapisi: "; minH.print();
    minH.extractMin();
    cout << "Min Silindikten Sonra: "; minH.print();

    cout << "\n--- MAX HEAP TEST ---" << endl;
    MaxHeap maxH;
    for (int x : data) maxH.insert(x);
    cout << "Max Heap Yapisi: "; maxH.print();
    maxH.extractMax();
    cout << "Max Silindikten Sonra: "; maxH.print();

    return 0;
}