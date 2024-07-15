#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int r)
{
    int i = l - 1; //-1
    int j = l;     // 0
    int pivot = arr[r];
    for (j; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8, 7};
    quickSort(arr, 0, 6);
    for (int i = 0; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}