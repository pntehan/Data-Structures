#include<bits/stdc++.h>

class illegalParameter
{
    private:
        string message;
    public:
        illegalParameter():
            message("Illegal parameter value"){}
        illegalParameter(string theMessage){
            message = theMessage;
        }
        void outputMessage(){
            cout << message <<endl;
        }
};
