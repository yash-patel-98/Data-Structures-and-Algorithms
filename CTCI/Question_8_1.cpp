#include <bits/stdc++.h>

using namespace std;

int count = 0;

int solve(int n,vector<int>& arr){
    if(n < 0)
        return 0;
    if(arr[n] != -1)
        return arr[n];
    arr[n] = solve(n-1,arr) + solve(n-2,arr) + solve(n-3,arr);
    return arr[n];
}

int main(void){
    int n;
    cin >> n;
    vector<int> arr(n+1,-1);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    solve(n,arr);
    cout << arr[n] << endl;
}