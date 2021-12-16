#include<bits/stdc++.h>

using namespace std;

/*
    Recursive Binary Search
*/

int binarySearchRecursion(int arr[], int low, int high, int value){
    if(low >= high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == value)
        return mid;
    else if(arr[mid] > value)
        binarySearchRecursion(arr,low, mid-1,value);
    else
        binarySearchRecursion(arr,mid+1,high,value);
}

/*
    Iterative Binary Search
*/
int binarySearchIterative(int arr[], int value){
    int low,high,mid;
    low = 0;
    high = sizeof(arr)/sizeof(int) - 1;
    while(low < high){
        mid = (low+high)/2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] > value)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}


int main(){
    int arr[] = {1,2,3,4,5,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    cout << binarySearchRecursion(arr, 0, n - 1, 6) << std::endl;
    cout << binarySearchIterative(arr, 6) << endl;

}