#include "hashMap.h"


HashMap:: HashMap(){
    hashMapArr = new HashTableEntry* [MAX_SIZE];
    this->size = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        hashMapArr[i] = NULL;
    }
}

int HashMap::hashFunction(int key){
    return (key*1191) % 200;
}

void HashMap::insert(int key, int value){
    this->size++;
    int h = hashFunction(key);
    if(hashMapArr[h] == NULL){
        HashTableEntry* node = new HashTableEntry;
        node->value = value;
        node->key = key;
        node->nextNode = NULL;
        hashMapArr[h] = node;
    }
    else{
        HashTableEntry* node = new HashTableEntry;
        node->value = value;
        node->key = key;
        node->nextNode = NULL;
        HashTableEntry* currentPresentNode = hashMapArr[h];
        if(currentPresentNode->nextNode == NULL){
            currentPresentNode->nextNode = node;
        }else{
            HashTableEntry* temp = currentPresentNode;
            while(temp -> nextNode != NULL){
                temp = temp->nextNode;
            }
            temp->nextNode = currentPresentNode;
        }
    }
}

bool HashMap::exist(int key){
    int h = hashFunction(key);
    if(hashMapArr[h] != NULL){
        HashTableEntry* entry = hashMapArr[h];
        if(entry->nextNode != NULL){
            cout << "Multiple Values Present for the Key : " << h << endl;            
        }
        return true;
    }
    return false;
}

int HashMap::get(int key){
    int h = hashFunction(key);
    if(hashMapArr[h] == NULL)
        return -1;
    else{
        HashTableEntry* entry = hashMapArr[h];
        int value = entry->value;
        if(entry->nextNode != NULL){
            cout << "Multiple Values Present" << endl;
            while(entry->nextNode != NULL){
                cout << entry->value << "->";
                entry = entry->nextNode;
            }
            cout << entry->value;
            cout << endl;
        }
        return value;
    }
}

int HashMap::remove(int key){
    this->size--;
    int h = hashFunction(key);
    if(hashMapArr[h] == NULL)
        return -1;
    else{
        HashTableEntry* entry = hashMapArr[h];
        delete entry;
        return 1;
    }
}
int HashMap::getSize(){
    return size;
}

HashMap::~HashMap(){
    hashMapArr = NULL;
    cout << "Destructor called" << endl;
}
