#include<sstream>
#include<string>
#include<iostream>
using namespace std;
#include "illegalIndex.h"
#include "illegalParameter.h"
#include "arrayList.h"

int main(){
    int n, temp;
    arrayList<int> y(100);
    cout <<"Please input size of arrayList: ";
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        y.insert(i, i);
    }
    arrayList<int>::iterator x = y.begin();
    for (arrayList<int>::iterator z=x; z!=y.end(); z++){
        cout <<"Please input value: ";
        scanf("%d", z);
    }
    cout <<"The array is "<<y<<endl;
    cout <<endl;
}