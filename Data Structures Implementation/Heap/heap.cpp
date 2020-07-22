#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>& heap, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[largest] < heap[left])
        largest = left;
    if (right < n && heap[largest] < heap[right])
        largest = right;
    
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify(heap,n, largest);
    }
}

void createHeap(vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0;i--){
        heapify(arr,n,i);
    }
    
}

void printHeap(vector<int>& arr){
    for(int i = 0; i < arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void){

    vector<int> initArray = {20, 5 , 3 , 50, 84 ,22, 12, 1, 8};
    // vector<int> initArray = { 12, 11, 13, 5, 6, 7 };
    printHeap(initArray);
    createHeap(initArray);
    printHeap(initArray);
}