#include <bits/stdc++.h>
#include<vector>

using namespace std;

const int MAX_SIZE = 200;

struct HashTableEntry{
    int key;
    int value;
    HashTableEntry* nextNode;
};

class HashMap{
    private:
        int size;
        HashTableEntry** hashMapArr;
    public:
        HashMap();
        ~HashMap();
        void insert(int key, int value);
        bool exist(int key);
        int get(int key);
        int remove(int key);
        int hashFunction(int key);
        int getSize();
};