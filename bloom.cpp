#include <iostream>
using namespace std;

class BloomFilter {
    int size;
    int *arr;

public:

    BloomFilter(int s) {
        size = s;
        arr = new int[size]();
    }

    ~BloomFilter() {
        delete[] arr;
    }

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return (key / size) % size;
    }

    int hash3(int key) {
        return ((7 * key) + 3) % size;
    }

    void insert(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);
        int h3 = hash3(key);

        arr[h1] = 1;
        arr[h2] = 1;
        arr[h3] = 1;

        cout << "Data inserted in Bloom Filter.\n";
    }

    void search(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);
        int h3 = hash3(key);

        if (arr[h1] == 1 &&
            arr[h2] == 1 &&
            arr[h3] == 1) {

            cout << key << " may be present.\n";
            cout << "(False positive possible)\n";
        }
        else {
            cout << key << " is NOT present.\n";
        }
    }

    void print() {

        cout << "\nBloom Filter Bit Array:\n";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    BloomFilter bf(10);

    int choice, key;

    do {

        cout << "\n====== BLOOM FILTER MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter key: ";
            cin >> key;
            bf.insert(key);
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;
            bf.search(key);
            break;

        case 3:
            bf.print();
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