#include<iostream>
using namespace std;
#include "illegalParameter.h"
#include "illegalIndex.h"
#include "chain.h"

int main(){
    chain<char>x(100);
    for (int i=0; i<10; i++){
        x.insert(i, i+1);
    }
    chain<char>::iterator y = x.begin();
    for (chain<char>::iterator p=y; p!=x.end(); p++){
        cout <<"Please input value: ";
        scanf(" %c", p);
    }
    cout <<x<<endl;
    x.erase(1);
    cout <<x<<endl;
}