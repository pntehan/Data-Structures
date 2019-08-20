#ifndef ArrayList_
#define ArrayList_

#include "linearList.h"

// -----------------------------------------------非类方法-------------------------------------------------------
template<class T>
void changeLength1D(T*& a, int oldLength, int newLength){
    if (newLength < 0){
        throw illegalParameter("New length must be >= 0");
    }
    T* temp = new T [newLength];
    int number = min(oldLength, newLength);
    copy(a, a+number, temp);
    delete [] a;
    a = temp;
}

template<class T>
class arrayList : public linearList<T>
{
    public:
        // 构造函数，复制构造函数和析构函数
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() { delete []element; }
        // 实现ADT方法
        bool empty() const { return listSize==0; }
        int size() const { return listSize; }
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(ostream& out) const;
        // 其他方法
        int capacity() const { return arrayLength; }
        class iterator
        {
            protected:
                T* position;
            public:
                typedef bidirectional_iterator_tag iterator_category;
                typedef T value_type;
                typedef ptrdiff_t difference_type;
                typedef T* pointer;
                typedef T& reference;
                // 构造函数
                iterator(T* thePosition = 0) { position = thePosition; }
                // 解引用操作符
                T& operator*() const { return *position; }
                T* operator->() const { return &*position; }
                // 迭代器的值增加
                iterator& operator++() { ++position; return *this; }
                iterator operator++(int) {
                    iterator old = *this;
                    ++position;
                    return old;
                }
                // 迭代器的值减少
                iterator& operator--() { --position; return *this; }
                iterator operator--(int) {
                    iterator old = *this;
                    --position;
                    return old;
                }
                // 测试是否相等
                bool operator!=(const iterator right) const{
                    return position != right.position;
                }
                bool operator==(const iterator right) const{
                    return position == right.position;
                }
        };
        iterator begin() { return iterator(element); }
        iterator end() { return iterator(element+listSize); }
    protected:
        void checkIndex(int theIndex) const; // 检查索引是否有效
        T* element;
        int arrayLength;
        int listSize;
};

template<class T>
arrayList<T>::arrayList(int initialCapacity){
    // 构造函数
    if (initialCapacity < 1){
        try{
            ostringstream s;
            s <<"Initial capacity ="<<initialCapacity<<"Must be > 0";
            throw illegalParameter(s.str());
        }
        catch (illegalParameter& e){
            e.outputMessage();
chain::chain(/* args */)
{
}

chain::~chain()
{
}
        }
    }
    arrayLength = initialCapacity;
    element = new T [arrayLength];
    listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList){
    // 复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T [arrayLength];
    copy(theList.element, theList.element+listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const{
    // 判定索引是否在有效值内
    if (theIndex < 0 || theIndex >= listSize){
        try{
            ostringstream s;
            s <<"index = "<<theIndex<<"size = "<<listSize;
            throw illegalIndex(s.str());
        }
        catch (illegalIndex& e){
            e.outputMessage();
        }
    }
}

template<class T>
T& arrayList<T>::get(int theIndex) const{
    // 先检测索引项是否存在，存在即返回值，不存在抛出异常
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const{
    // 返回元素theElement第一次出现的索引值，不存在即返回-1
    int theIndex = (int) (find(element, element + listSize, theElement) - element);
    if (theIndex == listSize){
        return -1;
    }
    else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex){
    // 删除其索引为theIndex的元素
    checkIndex(theIndex);
    // 有效索引，移动其索引大于theIndex的元素
    copy(element+theIndex+1, element+listSize, element+theIndex);
    element[--listSize].~T(); // 调用析构函数
    if (listSize < arrayLength/4){
        int newLength = max(listSize, arrayLength/2);
        T* temp = new T [newLength];
        copy(element, element+newLength, temp);
        delete [] element;
        element = temp;
        arrayLength = newLength;
    }
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement){
    // 在索引theIndex上插入元素theElement
    checkIndex(theIndex);
    if (listSize == arrayLength){
        // 数组空间已满，数组长度倍增
        changeLength1D(element, arrayLength, 2*arrayLength);
        arrayLength *= 2;
    }
    copy_backward(element+theIndex, element+listSize, element+listSize+1);
    element[theIndex] = theElement;
    listSize++;
}

template<class T>
void arrayList<T>::output(ostream& cout) const{
    copy(element, element+listSize, ostream_iterator<T>(cout, " "));
}

template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x){
    x.output(out);
    return out;
}

#endif










