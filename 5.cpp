#include <iostream>
using namespace std;

class Heap {
    int arr[100];
    int n;

public:
    
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // H D
    void heapify(int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(size, largest);
        }
    }

    // Build Max Heap
    void buildHeap() {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }
    }


    void heapSort() {
        buildHeap();

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);   
            heapify(i, 0);          
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    h.input();

    cout << "\nOriginal Array: ";
    h.display();

    h.heapSort();

    cout << "Sorted Array (Heap Sort): ";
    h.display();

    return 0;
}
