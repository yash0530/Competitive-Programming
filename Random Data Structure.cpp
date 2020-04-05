#include <bits/stdc++.h>
using namespace std;

class RandDataStructure {
    private:
        int *arr;
        unordered_map<int, int> H;
        int size;
        int cap;

    public:
        RandDataStructure() {
            srand(time(NULL));
            arr = new int[10];
            size = 0;
            cap = 10;
        }

        void insert(int val) {
            if (size == cap) {
                int *temp = new int[cap * 2];
                for (int i = 0; i < cap; i++) {
                    temp[i] = arr[i];
                }
                cap *= 2;
                arr = temp;
            }
            arr[size++] = val;
            H[val] = size - 1;
        }

        bool del(int val) {
            if (H.find(val) != H.end()) {
                int loc = H[val];
                if (loc == size - 1) {
                    H.erase(arr[loc]);
                    size--;
                    return true;
                }
                swap(arr[loc], arr[size - 1]);
                H.erase(val);
                H[arr[loc]] = loc;
                size--;
                return true;
            }
            return false;
        }

        int getRandom() {
            if (size > 0) {
                int loc = rand() % size;
                return arr[loc];
            }
            return -1;
        }

        void printDS() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " "; 
            } cout << endl;
        }
};

int main() {
    // Testing
    RandDataStructure rds;
    for (int i = 0; i < 20; i++) {
        rds.insert(i);
    }
    rds.del(5);
    rds.del(17);
    rds.del(9);
    cout << rds.del(16) << endl;
    cout << rds.del(16) << endl;
    rds.printDS();
    cout << rds.getRandom() << endl;
}