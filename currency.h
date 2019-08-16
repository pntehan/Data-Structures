#ifndef Currency_
#define Currency_

class currency{
    private:
        signType sign;
        unsigned long dollars;
        unsigned int cents;
    public:
        currency(
            signType thisSign = p,
            unsigned long theDollars = 0,
            unsigned int theCents = 0
        );
        ~currency(){}
        void setValue(signType, unsigned long, unsigned int);
        void setValue(double);
        signType getSign() const {return sign;}
        unsigned long getDollars() const {return dollars;}
        unsigned int getCents() const {return cents;}
        currency add(const currency&) const;
        currency& increment(const currency&);
        void output() const;
};

currency::currency(signType thisSign, unsigned long theDollars, unsigned int theCents){
    setValue(thisSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents){
    if (theCents > 99){
        throw illegalParameter("Cents should be < 100");
    }
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount){
    if (theAmount < 0){
        sign = m;
        theAmount = -theAmount;
    }else{
        sign = p;
    }
    dollars = (unsigned long) theAmount;
    cents = (unsigned int) ((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency& x) const{
    long a1, a2, a3;
    currency result;
    a1 = dollars * 100 + cents;
    if (sign == m) a1 = -a1;
    a2 = x.dollars * 100 + x.cents;
    if (x.sign == m) a2 = -a2;
    a3 = a1 + a2;
    if (a3 < 0){
        result.sign = m;
        a3 = -a3;
    }
    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;
    return result;
}

currency& currency::increment(const currency& x){
    *this = add(x);
    return *this;
}

void currency::output() const{
    if (sign == m) cout <<"-";
    cout <<"$"<<dollars<<".";
    if (cents < 10) cout <<"0";
    cout <<cents<<endl;
}

#endif