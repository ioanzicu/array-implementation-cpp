// ArrayADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
    void Swap(int* x, int* y);

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];

    }
    ~Array() {
        delete []A;
    }
    void Display();
    void Append(int value);
    void Insert(int index, int value);
    int Delete(int index);
    int LinearSearch(int key);
    int RecBinarySearch(int begin, int end, int key);
    int ItrBinarySearch(int key);
    int Get(int index);
    void Set(int index, int value);
    int Min();
    int Max();
    int Sum();
    double Avg();
    void Reverse();
    void AReverse();
    void Shift();
    void Unshift();
    void RRotate();
    void LRotate();
    void InsertSort(int value);
    bool isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
};

// O (n)
void Array::Display() {
    int i;

    if (length > 0) {
        cout << "\nElements are: \n";
        for (i = 0; i < length; ++i)
            cout << A[i] << " ";
    }
    else {
        cout << "\nArray is empty \n";
    }
    cout << endl;
}

// O (1)
void Array::Append(int value) {
    if (length < size) {
        A[length] = value;
        length++;
    }
}

// O (n) - Max | O (1) - Min
void Array::Insert(int index, int value) {
    int i;
    if (index >= 0 && index <= length) {
        for (i = length; i > index; i--) 
            A[i] = A[i - 1];
        
        A[index] = value;
        length++;
    }
}

// O (n) - Max | O (1) - Min
int Array::Delete(int index) {
    int i, value = 0;
    if (index >= 0 && index < length) {
        value = A[index];

        for (i = index; i < length - 1; i++) 
            A[i] = A[i + 1];
        
        length--;
    }

    return value;
}

void Array::Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// O (n) - Max | O (1) - Min | O (n) - Avg
int Array::LinearSearch(int key) {
    int i;
    for (i = 0; i < length; ++i)
        if (A[i] == key) {
            /* 
            // Transposition Method
            Swap(&A[i], &A[i - 1]);
            return i;
            */

            // Transposition Method
            Swap(&A[i], &A[0]);
            return 0;
        }

    return -1;
}

// Recursive Binary Search - O (log(n)) - Tail Recursion
int Array::RecBinarySearch(int begin, int end, int key) {
    int middle;
  
    if (begin <= end) {
        middle = (begin + end) / 2;
        if (key == A[middle])
            return middle;
        else if (key < A[middle])
            return RecBinarySearch(begin, middle - 1, key);
        else if (key > A[middle])
            return RecBinarySearch(middle + 1, end, key);
    }

    return -1;
}

int Array::ItrBinarySearch(int key) {
    int begin, middle, end;
    begin = 0;
    end = length - 1;

    while (begin <= end) {
        middle = (begin + end) / 2;
        if (key == A[middle])
            return middle;
        else if (key < A[middle])
            end = middle - 1;
        else if (key > A[middle])
            begin = middle + 1;
    }

    return -1;
}

// O (1)
int Array::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];

    return -1;
}

// O (1)
void Array::Set(int index, int value) {
    if (index >= 0 && index < length)
        A[index] = value;
}

// O (n)
int Array::Min() {
    int min = A[0];
    int i;
    for (i = 1; i < length; ++i)
        if (min > A[i])
            min = A[i];

    return min;
}

// O (n)
int Array::Max() {
    int i, max = A[0];
    
    for (i = 1; i < length; ++i)
        if (max < A[i])
            max = A[i];

    return max;
}

// O (n)
int Array::Sum() {
    int i, sum = 0;

    for (i = 0; i < length; ++i)
        sum += A[i];

    return sum;
}

// O (n)
double Array::Avg() {
    return (double)Sum() / length;
}

// O (n)
void Array::Reverse() {
    int i;
    int middle = length / 2;
    int last = length - 1;

    for (i = 0; i <= middle; ++i)
        Swap(&A[i], &A[last - i]);
}

// O (n) - use additional array
void Array::AReverse() {
    int i, j = 0;
    int* B = new int[length];

    for (i = length - 1; i >= 0; --i, ++j)
        B[j] = A[i];

    for (i = 0; i < length; ++i)
        A[i] = B[i];
}

// O (n) - Left Shift (remove first element)
void Array::Shift() {
    int i;
    
    if (length > 0) {
        for (i = 0; i < length; ++i)
            A[i] = A[i + 1];

        length--;
    }
}

// O (1) - Right Shift (remove last element)
void Array::Unshift() {
    int i;

    if (length > 0) {
        A[length - 1] = 0;

        length--;
    }
}

// O (n) - Rotate to Right
void Array::RRotate() {
    int i, first;

    if (length > 0) {
        first = A[0];

        for (i = 0; i < length; ++i)
            A[i] = A[i + 1];

        A[length - 1] = first;
    }
}

// O (n) - Rotate to Left 
void Array::LRotate() {
    int i, last;

    if (length > 0) {
        last = A[length - 1];

        for (i = length - 1; i >= 0; --i)
            A[i] = A[i - 1];
        
        A[0] = last;
    }
}

// O (n)
void Array::InsertSort(int value) {
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > value) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = value;
    length++;
}

// O (n) - Max | O (1) - Min 
bool Array::isSorted() {
    int i;
    for (i = 0; i < length - 1; ++i)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

// O (n) - Separate Negative from the Positive Values
void Array::Rearrange() {
    int i = 0;
    int j = length - 1;

    while (i < j) {
        while (A[i] < 0) { i++; }
        while (A[j] >= 0) { j--; }
        if (i < j) 
            Swap(&A[i], &A[j]);
    }
}

// O (m + n) - Teta
Array* Array::Merge(struct Array arr2) {
    int i = 0;
    int j = 0;
    int k = 0;
    Array* arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; ++i)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; ++j)
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;
    
    return arr3;
}

// O (m + n) - Teta
Array* Array::Union(Array arr2) {
    int i = 0;
    int j = 0;
    int k = 0;  
    Array* arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; ++i)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; ++j)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;

    return arr3;
}

// O (m + n) - Teta
Array* Array::Intersection(Array arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if(A[i] == arr2.A[j]) {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;

    return arr3;
}

// O (m + n) - Teta
Array* Array::Difference(Array arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* arr3 = new Array(length + arr2.length);
    
    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
           j++;
        else {
            i++;
            j++;
        }
    }

    for (; i < length; ++i)
        arr3->A[k++] = A[i];

    arr3->length = k;
    
    return arr3;
}

int main()
{
    Array* arr1;
    int ch, value, index, size;

    cout << "Enter Size of Array: ";
    cin >> size;
    arr1 = new Array(size);

    do {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Reverse\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: \n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            cout << "Enter the index: ";
            cin >> index;
            arr1->Insert(index, value);
            break;
        case 2:
            cout << "Enter the index: ";
            cin >> index;
            value = arr1->Delete(index);
            cout << "Element " << value << " was deleted." << endl;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> value;
            index = arr1->LinearSearch(value);
            cout << "Element's index: " << index << endl;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum() << endl;
            break;
        case 5:
            arr1->Display();
            break;
        case 6:
            cout << "The Array was Reversed" << endl;
            arr1->Reverse();
            break;
        default:
            cout << "Bye!!! " << ch << endl;
            break;
        }
    } while (ch > 0 && ch < 7);
}
