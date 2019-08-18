#include<bits/stdc++.h>

class illegalIndex
{
    private:
        string message;
    public:
        illegalIndex():
            message("Illegal Index value"){}
        illegalIndex(string theMessage){
            message = theMessage;
        }
        void outputMessage(){
            cout << message <<endl;
        }
};
