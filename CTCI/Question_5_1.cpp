#include <iostream>
#include <bitset>

using namespace std;

void updateBits(int n, int m, int i, int j){
    bitset<32> N(n);
    bitset<32>M(m);
    cout << N << endl;
    cout << M << endl;

    int x = ~0;
    x = x << (j+1);

    int y = ~0;
    y = y << (i);
    y = ~y;

    int mask = x | y;
    // cout << bitset<32>(mask) << endl;
    int newNum = (n & mask) | (m << i);
    bitset<32> temp(newNum);
    cout << temp << endl;    
}

int main(void){
    updateBits(1027,19,2,6);
}