#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool read(int * array, unsigned int size) {
    string line;
    getline(cin, line);
    istringstream stream(line);
    for (unsigned int i = 0; i < size; ++i) {
        if (!(stream >> array[i])) {
            cout<<"An error has occured while reading input data."<<endl;
            return false;
        }
    }
    return true;
}
void merge(int * array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int * left = new int[n1];
    int * right = new int[n2];
    for (i = 0; i < n1; ++i) {
        left[i] = array[l + i];
    }
    for (j = 0; j < n2; ++j) {
        right[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while ((i < n1) && (j < n2)) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int * array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
int main() {
    int size;
    string number;
    getline(cin, number);
    istringstream num(number);
    if (!(num >> size) || (size < 2)) {
        cout << "An error has occured while reading input data" << endl;
        return -1;
    }
    int * array = new int[size];
    if (read(array, size)) {
        mergesort(array, 0, size - 1);
        for (unsigned int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
    }
    delete[] array;
    return 0;
}
