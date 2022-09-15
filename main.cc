#include <iostream>
using namespace std;

void print(int arr[], int n);
void problemOne();
int binarySearch(const int list[], int key, int arraySize);
void problemTwo();
void selectionSort(int arr[], int n);
void problemThree();
void reverseSelectionSort(int arr[], int n);


int main() 
{
    cout << "CS 130, HW2" << endl; 
    cout << endl;

    problemOne();
    problemTwo();
    problemThree();

    return 0;
}

void print(int arr[], int n)
{
    for (int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void problemOne()
{
    //Problem 1.A
    int list1[13] = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};
    int key = 10;

    cout << "Problem 1A:" << endl;
    cout << "Searching for key: " << (key) << " in list of numbers: ";
    print(list1, 13);
    cout << "Using binary search..." << endl;

    int keyIndex1 = binarySearch(list1, key, 13);

    if (keyIndex1 > 0) 
        cout << key << " was found at index " << keyIndex1 << ", also known as position " << (keyIndex1+1) << endl;
    else
        cout << "Key: " << key << " was not found in the list" << endl;
   
    cout << endl;


    //Problem 1.b
    int list2[13] = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};
    key = 12;
    cout << "Problem 1B:" << endl;
    cout << "Searching for key: " << (key) << " in list of numbers: ";
    print(list2, 13);
    cout << "Using binary search..." << endl;
    int keyIndex2 = binarySearch(list2, key, 13);
    if (keyIndex2 < 0) 
        cout << "Key: " << key << " was not found in the list" << endl;
    else
        cout << key << " was found at index " << keyIndex2 << ", also known as position " << (keyIndex1+1) << endl;

    cout << endl;
}

int binarySearch(const int list[], int key, int arraySize)
{
    // low and high are the index range we are sorting through
    // key is what we are searching for
    int low = 0;
    int high = arraySize -1; // because index starts at 0

    while (high >= low) // this loop will end if nothing is found
    {
        int mid = (low + high) / 2; // finding halfway point
        if (key < list[mid]) 
            high = mid-1;
        else if (key == list[mid])
            return mid;
        else
            low = mid + 1;
        // the midpoint moves according to if the key is greater or smaller than the midpoint
        // if the key is found mid is returned
    }

    return - low - 1;
}

void problemTwo()
{
    // Problem 2
    cout << "Problem 2:" << endl;
    int arr[11] = {3, 4, 5, 3, 3, 5, 2, 2, 1, 9, 2};
    int n = 11;
    cout << "Unsorted array: ";
    print(arr, n);
    cout << "Using selection sort..." << endl;
    selectionSort(arr, n);
    cout << "Sorted array: " ;
    print(arr, n);
    cout << endl;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_in;
    for (i = 0; i < n; i++)
    {
        min_in = i;
        for (j=i+1; j<n; j++)
            if (arr[j] < arr[min_in])
                min_in = j;
        swap(arr[i], arr[min_in]);
    }
}

void problemThree()
{
    cout << "Problem 3:" << endl;
    int arr[7] = {2, 9, 5, 4, 8, 1, 6};
    int n = 7;
    cout << "Unsorted array: ";
    print(arr, n);
    cout << "Using reverse selection sort..." << endl;
    reverseSelectionSort(arr, n);
    cout << "Sorted reverse array: " ;
    print(arr, n);
}

void reverseSelectionSort(int arr[], int n)
{
        int i, j, min_in;
    for (i = 0; i < n; i++)
    {
        min_in = i;
        for (j=i+1; j<n; j++)
            if (arr[j] > arr[min_in])
                min_in = j;
        swap(arr[i], arr[min_in]);
    }
}
