#include<iostream>
#include<iterator>
using namespace std;

int factorial(int n){
    if (n <= 1) return 1;
    else return n * factorial(n-1);
}

template<class T>
T sum(T a[], int n){
    T theSum = 0;
    for (int i=0; i<n; i++){
        theSum += a[i];
    }
    return theSum;
}

template<class T>
T rSum(T a[], int n){
    if (n > 0){
        return rSum(a, n-1) + a[n-1];
    }
    return 0;
}

template<class T>
void permutations(T list[], int k, int m){
    if (k == m){
        copy(list, list+m+1, ostream_iterator<T>(cout, ""));
        cout << endl;
    }
    else{
        for (int i=k; i<=m; i++){
            swap(list[k], list[i]);
            permutations(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}

int main(){
    int a[10], start, end;
    for (int i=0; i<10; i++){
        a[i] = factorial(i+1);
        cout <<"a["<<i<<"]: "<<a[i]<<endl;
    }
    cout <<"sum is "<<rSum(a, 10)<<endl;
    char list[10] = {"abcdefghi"};
    cout <<"list is "<<list<<endl;
    cout <<"Please input number of start and end: ";
    scanf("%d %d", &start, &end);
    permutations(list, start, end);
    return 0;
}