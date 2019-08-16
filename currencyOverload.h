#ifndef Currency_
#define Currency_

class currency
{
    private:
        long amount;
    public:
        currency(
            signType theSign = p,
            unsigned long theDollars = 0,
            unsigned int theCents = 0
        );
        ~currency(){};
        void setValue(signType, unsigned long, unsigned int);
        void setValue(double);
        signType getSign() const{
            if (amount < 0) return m;
            else return p;
        }
        unsigned long getDollars() const{
            if (amount < 0) return (-amount) / 100;
            else return amount / 100;
        }
        unsigned int getCents() const{
            if (amount < 0) return -amount - getDollars() * 100;
            else return amount - getDollars() * 100;
        }
        currency operator+(const currency&) const;
        currency& operator+=(const currency& x){
            amount += x.amount;
            return *this;
        }
        friend ostream& operator<<(ostream&, const currency&);
};

currency::currency(signType thisSign, unsigned long theDollars, unsigned int theCents){
    setValue(thisSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents){
    if (theCents > 99){
        throw illegalParameter("Cents should be < 100");
    }
    amount = theDollars * 100 + theCents;
    if (theSign < 0) amount = -amount;
}

void currency::setValue(double theAmount){
    amount = theAmount;
}

currency currency::operator+(const currency& x) const{
    currency result;
    result.amount = amount + x.amount;
    return result;
}

ostream& operator<< (ostream& out, const currency& x){
    long theAmount = x.amount;
    if (theAmount < 0){
        out <<"-";
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out <<"$"<<dollars<<".";
    int cents = theAmount - dollars * 100;
    if (cents < 10) out <<"0";
    out <<cents;
    return out;
}

#endif