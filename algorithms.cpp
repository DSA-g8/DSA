#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Merge sort, souce: https://www.softwaretestinghelp.com/merge-sort/
void mergeWithTime(int *arr, int low, int high, int mid) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void mergeSortWithTime(int *arr, int low, int high) {
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergeSortWithTime(arr,low,mid);
        mergeSortWithTime(arr,mid+1,high);
        mergeWithTime(arr,low,high,mid);
    }
}

void mergeWithComparison(int *arr, int low, int high, int mid, int &comparisons_count) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (++comparisons_count && i <= mid && j <= high) {
        if (++comparisons_count && arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (++comparisons_count && i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (++comparisons_count && j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; ++comparisons_count && i < k; i++)  {
        arr[i] = c[i];
    }
}

void mergeSortWithComparison(int *arr, int low, int high, int &comparisons_count) {
    int mid;
    if (++comparisons_count && low < high) {
        mid=(low+high)/2;
        mergeSortWithComparison(arr,low,mid, comparisons_count);
        mergeSortWithComparison(arr,mid+1,high, comparisons_count);
        mergeWithComparison(arr,low,high,mid, comparisons_count);
    }
}
