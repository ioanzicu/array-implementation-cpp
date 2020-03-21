// ArrayADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

// O (n)
void Display(struct Array arr) {
    int i;

    if (arr.length > 0) {
        cout << "\nElements are: \n";
        for (i = 0; i < arr.length; ++i)
            cout << arr.A[i] << " ";
    }
    else {
        cout << "\nArray is empty \n";
    }
    cout << endl;
}

// O (1)
void Append(struct Array *arr, int value) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = value;
        arr->length++;
    }
}

// O (n) - Max | O (1) - Min
void Insert(struct Array *arr, int index, int value) {
    int i;
    if (index >= 0 && index <= arr->length) {
        for (i = arr->length; i > index; i--) 
            arr->A[i] = arr->A[i - 1];
        
        arr->A[index] = value;
        arr->length++;
    }
}

// O (n) - Max | O (1) - Min
int Delete(struct Array *arr, int index) {
    int i, value = 0;
    if (index >= 0 && index < arr->length) {
        value = arr->A[index];

        for (i = index; i < arr->length - 1; i++) 
            arr->A[i] = arr->A[i + 1];
        
        arr->length--;
    }

    return value;
}

void Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// O (n) - Max | O (1) - Min | O (n) - Avg
int LinearSearch(struct Array* arr, int key) {
    int i;
    for (i = 0; i < arr->length; ++i)
        if (arr->A[i] == key) {
            /* 
            // Transposition Method
            Swap(&arr->A[i], &arr->A[i - 1]);
            return i;
            */

            // Transposition Method
            Swap(&arr->A[i], &arr->A[0]);
            return 0;
        }

    return -1;
}

// Recursive Binary Search - O (log(n)) - Tail Recursion
int RecBinarySearch(struct Array arr, int begin, int end, int key) {
    int middle;
  
    if (begin <= end) {
        middle = (begin + end) / 2;
        if (key == arr.A[middle])
            return middle;
        else if (key < arr.A[middle])
            return RecBinarySearch(arr, begin, middle - 1, key);
        else if (key > arr.A[middle])
            return RecBinarySearch(arr, middle + 1, end, key);
    }

    return -1;
}

int ItrBinarySearch(struct Array arr, int key)  {
    int begin, middle, end;
    begin = 0;
    end = arr.length - 1;

    while (begin <= end) {
        middle = (begin + end) / 2;
        if (key == arr.A[middle])
            return middle;
        else if (key < arr.A[middle])
            end = middle - 1;
        else if (key > arr.A[middle])
            begin = middle + 1;
    }

    return -1;
}

// O (1)
int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

// O (1)
void Set(struct Array* arr, int index, int value) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = value;
}

// O (n)
int Min(struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; ++i)
        if (min > arr.A[i])
            min = arr.A[i];

    return min;
}

// O (n)
int Max(struct Array arr) {
    int i, max = arr.A[0];
    
    for (i = 1; i < arr.length; ++i)
        if (max < arr.A[i])
            max = arr.A[i];

    return max;
}

// O (n)
int Sum(struct Array arr) {
    int i, sum = 0;

    for (i = 0; i < arr.length; ++i)
        sum += arr.A[i];

    return sum;
}

// O (n)
double Avg(struct Array arr) {
    return (double)Sum(arr) / arr.length;
}

// O (n)
void Reverse(struct Array* arr) {
    int i;
    int middle = arr->length / 2;
    int last = arr->length - 1;

    for (i = 0; i <= middle; ++i)
        Swap(&arr->A[i], &arr->A[last - i]);
}

// O (n) - use additional array
void AReverse(struct Array* arr) {
    int i, j = 0;
    int* B = new int[arr->length];

    for (i = arr->length - 1; i >= 0; --i, ++j)
        B[j] = arr->A[i];

    for (i = 0; i < arr->length; ++i)
        arr->A[i] = B[i];
}

// O (n) - Left Shift (remove first element)
void Shift(struct Array* arr) {
    int i;
    
    if (arr->length > 0) {
        for (i = 0; i < arr->length; ++i)
            arr->A[i] = arr->A[i + 1];

        arr->length--;
    }
}

// O (1) - Right Shift (remove last element)
void Unshift(struct Array* arr) {
    int i;

    if (arr->length > 0) {
        arr->A[arr->length - 1] = 0;

        arr->length--;
    }
}

// O (n) - Rotate to Right
void RRotate(struct Array* arr) {
    int i, first;

    if (arr->length > 0) {
        first = arr->A[0];

        for (i = 0; i < arr->length; ++i)
            arr->A[i] = arr->A[i + 1];

        arr->A[arr->length - 1] = first;
    }
}

// O (n) - Rotate to Left 
void LRotate(struct Array* arr) {
    int i, last;

    if (arr->length > 0) {
        last = arr->A[arr->length - 1];

        for (i = arr->length - 1; i >= 0; --i)
            arr->A[i] = arr->A[i - 1];
        
        arr->A[0] = last;
    }
}

// O (n)
void InsertSort(struct Array* arr, int value) {
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > value) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

// O (n) - Max | O (1) - Min 
bool isSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; ++i)
        if (arr.A[i] > arr.A[i + 1])
            return false;
    return true;
}

// O (n) - Separate Negative from the Positive Values
void Rearrange(struct Array* arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) { i++; }
        while (arr->A[j] >= 0) { j--; }
        if (i < j) 
            Swap(&arr->A[i], &arr->A[j]);
    }
}

// O (m + n) - Teta
struct Array* Merge(struct Array* arr1, struct Array* arr2) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; ++i)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; ++j)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    
    return arr3;
}

// O (m + n) - Teta
struct Array* Union(struct Array* arr1, struct Array* arr2) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; ++i)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; ++j)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// O (m + n) - Teta
struct Array* Intersection(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// O (m + n) - Teta
struct Array* Difference(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
           j++;
        else {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; ++i)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1;
    int ch, value, index;

    cout << "Enter Size of Array: ";
    cin >> arr1.size;
    arr1.A = (int*)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

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
            cout << "Enter the index to be inserted: ";
            cin >> index;
            Insert(&arr1, index, value);
            break;
        case 2:
            cout << "Enter the index: ";
            cin >> index;
            value = Delete(&arr1, index);
            cout << "Element " << value << " was deleted." << endl;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> value;
            index = LinearSearch(&arr1, value);
            cout << "Element's index: " << index << endl;
            break;
        case 4:
            cout << "Sum is " << Sum(arr1) << endl;
            break;
        case 5:
            Display(arr1);
            break;
        case 6:
            cout << "The Array was Reversed" << endl;
            Reverse(&arr1);
            break;
        default:
            cout << "Bye!!!" << ch << endl;
            break;
        }
    } while (ch > 1 && ch < 7);





    // struct Array arr = { {2, 3, 4, 5, 6, 9}, 20, 6 };

    //Append(&arr, 10);
    //Insert(&arr, 2, 10);
    //cout << "\nDeleted value " << Delete(&arr, 0);
    //cout << "\nLinear Search: " << LinearSearch(&arr, 5) << endl;
    //cout << "\nBinary Search: " << RecBinarySearch(arr, 0, arr.length, 6) << endl;
    //cout << "\nBinary Search: " << ItrBinarySearch(arr, 6) << endl;

    //Display(arr);
    //cout << Get(arr, 3) << endl;
    //Set(&arr, 3, 39);
    
    //Display(arr);
    
    //cout << "Min " << Min(arr) << endl;
    //cout << "Max " << Max(arr) << endl;
    //cout << "Sum " << Sum(arr) << endl;
    //cout << "Average " << Avg(arr) << endl;

    //Shift(&arr);
    //Unshift(&arr);
    
    //Reverse(&arr);
    //AReverse(&arr);
    
    //RRotate(&arr);
    //LRotate(&arr);
    
    //InsertSort(&arr, 1);
    //cout << isSorted(arr) << endl;
    //Rearrange(&arr);
 
    /* Merge | Union | Set | Intersection */

    /*struct Array arr1 = { {2, 6, 10, 15, 25}, 10, 5 };
    struct Array arr2 = { {3, 6, 7, 15, 20}, 10, 5 };
    struct Array* arr3;*/

    //arr3 = Merge(&arr1, &arr2);
    //arr3 = Union(&arr1, &arr2);
    //arr3 = Intersection(&arr1, &arr2);
    //arr3 = Difference(&arr1, &arr2);

    //Display(*arr3);




}
