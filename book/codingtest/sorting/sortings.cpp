#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

void print_arr(int arr[SIZE]) {
    for(int i = 0; i<SIZE; i++) {
        cout<< arr[i] << ' ';
    }
    cout<<endl;
}
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// selection sort
int *selection_sort(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        int min_index = i;
        for(int j = i; j<SIZE; j++) {
            if(arr[min_index] > arr[j])
                min_index = j;
        }
        int temp  = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    return arr;
}

// insertion sort
int *insertion_sort(int arr[SIZE]) {
    for(int i = 1; i<SIZE; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            } else break;
        }
    }
    return arr;
}

// quick sort
void quicksort(int* arr, int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int left = start+1;
    int right = end;
    while(left <= right) {
        while(left<=end && arr[left] <=arr[pivot]) left++;
        while(right> start && arr[right] >= arr[pivot]) right--;
        if(left>right) swap(arr[pivot],arr[right]);
        else swap(arr[left], arr[right]);
    }
    quicksort(arr,start,right-1);
    quicksort(arr,right+1,end);
}

int main() {
    int arr[SIZE] = {7,5,9,0,3,1,6,2,4,8};
    print_arr(arr);
    int *result = selection_sort(arr);
    print_arr(result);
    cout<<endl;

    int arr2[SIZE] = {7,5,9,0,3,1,6,2,4,8};
    print_arr(arr2);
    int *result2 = insertion_sort(arr2);
    print_arr(result2);
    cout<<endl;

    int arr3[SIZE] = {7,5,9,0,3,1,6,2,4,8};
    print_arr(arr3);
    quicksort(arr3,0,SIZE-1);
    print_arr(arr3);
    cout<<endl;
    return 0;
}