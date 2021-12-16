#include "hashMap.h"

int main(){
    HashMap obj = HashMap();
    obj.insert(1200,5);
    cout << obj.get(1200) << endl;
    obj.insert(1200,10);
    cout << obj.get(1200) << endl;

}