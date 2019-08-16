// C++对于排序算法的简单实现
#include<iostream>
using namespace std;
#include "illegalParameter.h"

template<class T>
void make1dArray(T * &x, int n){
    x = new T [n];
    for (int i=0; i<n; i++){
        cout <<"Please input number of "<<i<<": ";
        scanf("%d", &x[i]);
    }
}

template<class T>
void show1dArray(T * &x, int n){
    cout <<"The array is ";
    for (int i=0; i<n; i++){
        cout <<x[i]<<" ";
    }
    cout <<endl;
}

template<class T>
void findPath(T * &x, int start, int n){
    // 查找到最后一个元素的最短路径
    if (start == n-1) cout <<"start"<<endl;
    else if (x[start] >= n-1-start){
        cout <<x[start]<<"<<";
        findPath(x, 0, start+1);
    }
    else if (x[start] < n-1-start) findPath(x, start+1, n);
}

template<class T>
int indexOfMax(T a[], int n){
    // 查找数组最大值位置返回
    if (n < 0){
        throw illegalParameter("n must be  > 0");
    }
    int index = 0;
    for (int i=1; i<n; i++){
        if (a[index] < a[i]){
            index = i;
        }
    }
    return index;
}

template<class T>
void selectionSort(T a[], int n){
    // 选择排序算法
    for (int size=n; size > 1; size--){
        int j = indexOfMax(a, size);
        swap(a[j], a[size-1]);
    }
}

template<class T>
void bubble(T a[], int n){
    // 一次冒泡过程
    for (int i=0; i<n-1; i++){
        if (a[i] > a[i+1]){
            swap(a[i], a[i+1]);
        }
    }
}

template<class T>
void bubbleSort(T a[], int n){
    // 对数组进行毛冒泡排序
    for (int i=n; i>1; i--){
        bubble(a, i);
    }
}

template<class T>
void insert(T a[], int n, const T& x){
    // 将x插入数组a中
    int i;
    for(i=n-1; i>=0 && x<a[i]; i--){
        a[i+1] = a[i];
    }
    a[i+1] = x;
}

template<class T>
void insertionSort(T a[], int n){
    // 插入排序
    for (int i=1; i<n; i++){
        T t = a[i];
        insert(a, i, t);
    }
}

int main(){
    int *a, n;
    cout <<"Please input size of 1d array: ";
    scanf("%d", &n);
    make1dArray(a, n);
    show1dArray(a, n);
    findPath(a, 0, n);
    // selectionSort(a, n);
    // bubbleSort(a, n);
    insertionSort(a, n);
    show1dArray(a, n);
}