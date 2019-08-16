#include<iostream>
namespace std
{
    enum signType{
        p, m
    };
};
using namespace std;
#include "illegalParameter.h"
#include "currencyOverload.h"
#include "currency.h"

int main(){
    currency g, h(p, 3, 50), i, j;
    g.setValue(m, 2, 25);
    i.setValue(-6.45);
    j = h + g;
    cout <<h<<"+"<<g<<"="<<j<<endl;
    j = i + g + h;
    cout <<i<<"+"<<g<<"+"<<h<<"="<<j<<endl;
    cout <<"Increment"<<i<<"by"<<g<<"and then add"<<h<<endl;
    j = (i += g) + h;
    cout <<"Result is"<<j<<endl;
    cout <<"Incremented object is"<<i<<endl;
    cout <<"Attempting to initialize with cents = 152"<<endl;
    try{
        i.setValue(p, 3, 152);
    }catch (illegalParameter e){
        cout <<"Caught thrown exception"<<endl;
        e.outputMessage();
    }
    return 0;
}