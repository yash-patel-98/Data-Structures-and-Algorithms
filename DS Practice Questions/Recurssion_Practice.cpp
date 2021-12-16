#include<bits/stdc++.h>

using namespace std;


int fib(int n){
    cout << "fib function - " << n << endl;
    if(n < 0)
        return 0;
    if(n <= 1)
        return n;
    if(n == 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main(void){
    cout << fib(10) << endl;
}