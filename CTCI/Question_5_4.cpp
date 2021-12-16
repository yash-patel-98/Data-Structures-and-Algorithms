#include <iostream>
#include<bits/stdc++.h>

int getNextSmallest(int n);
int getNextLargest(int n);

using namespace std;

int main(void){
    int num;
    cin >> num;
    int nextSmallest = getNextSmallest(num);
    cout << "Next smallest = " << nextSmallest << endl;
    int nextLargest = getNextLargest(num);
    cout << "Next largest = " << nextLargest << endl;
}

int getNextSmallest(int n){
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while((c & 1)){
        c1 ++;
        c >>= 1;
    }
    if (c == 0)
        return -1;
    while( !(c & 1) && (c!=0)){
        c0 ++;
        c >>= 1;
    }
    int p = c0 + c1;
    n &= (~0 << (p+1)); // clear bits from 0 to p
    int mask =  (1 << (c1 + 1)) - 1;
    return n | mask << (c0 - 1);
}

int getNextLargest(int n){
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while(!(c & 1) && (c != 0)){
        c0 ++;
        c >>= 1;
    }
    while(c&1){
        c1 ++;
        c >>= 1;
    }
    int p = c0 + c1;
    if (p == 31 || p == 0)
        return -1;
    n |= (1 << p); // Flip the bit at index p. Which evidently is the rightmost non trailing zero
    n &= ~((1 << p) - 1); // clear bits to the right of p
    n |= (1 << (c1 -1)) - 1;
    return n;
}