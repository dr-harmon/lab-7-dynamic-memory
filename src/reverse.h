#pragma once

// Performs an in-order reversal of the contents of the array.
template <typename T>
void reverse(T *array, int arraySize)
{
    int i = 0;
    int j = arraySize - 1;
    while (i < j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}
