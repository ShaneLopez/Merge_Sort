#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i;
    int j;
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int arr[], int l, int r)
{
    if(r > l)
    {
        int m = (l + (r - 1)) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    mergesort(arr, 0, 7);
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
