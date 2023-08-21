#include <iostream>
using namespace std;

int main() {
    const int maxSize = 100; // Maximum size of the array
    int arr[maxSize]; // Declare an array
    int size = 0; // Current number of elements in the array

    // Insert elements into the array
    arr[size++] = 5;
    arr[size++] = 10;
    arr[size++] = 15;

    // Insert an element at a specific position (index 1)
    int elementToInsert = 20;
    int insertIndex = 1;

    // Shift elements to make space for the new element
    for (int i = size; i > insertIndex; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[insertIndex] = elementToInsert;
    size++; // Increment the size of the array

    // Print the array after insertion
    cout << "Array after insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Delete an element at a specific position (index 2)
    int deleteIndex = 2;

    // Shift elements to close the gap left by the deleted element
    for (int i = deleteIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Decrement the size of the array

    // Print the array after deletion
    cout << "Array after deletion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

