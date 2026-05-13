#include <iostream>
#include <climits>

using namespace std;

class CountMinSketch {

    int depth, width;
    int **arr;

public:

    CountMinSketch(int d, int w) {

        depth = d;
        width = w;

        arr = new int*[depth];

        for (int i = 0; i < depth; i++) {
            arr[i] = new int[width]();
        }
    }

    ~CountMinSketch() {

        for (int i = 0; i < depth; i++) {
            delete[] arr[i];
        }

        delete[] arr;
    }

    int hash(int key, int row) {
        return (key + row * 31) % width;
    }

    void insert(int key) {

        for (int i = 0; i < depth; i++) {

            int index = hash(key, i);
            arr[i][index]++;
        }

        cout << "Inserted in Count Min Sketch.\n";
    }

    int getCount(int key) {

        int minimum = INT_MAX;

        for (int i = 0; i < depth; i++) {

            int index = hash(key, i);

            if (arr[i][index] < minimum)
                minimum = arr[i][index];
        }

        return minimum;
    }

    void print() {

        cout << "\nCount Min Sketch Table:\n";

        for (int i = 0; i < depth; i++) {

            for (int j = 0; j < width; j++) {
                cout << arr[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    CountMinSketch cms(3, 10);

    int choice, key;

    do {

        cout << "\n====== COUNT MIN SKETCH MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Get Frequency\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter key: ";
            cin >> key;
            cms.insert(key);
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;

            cout << "Estimated Count = "
                 << cms.getCount(key)
                 << endl;

            break;

        case 3:
            cms.print();
            break;

        case 4:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}