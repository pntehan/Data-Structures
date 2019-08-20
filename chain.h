#ifndef Chain_
#define Chain_

#include "linearList.h"
#include "chainNode.h"

template<class T>
class chain : public linearList<T>{
    public:
        // 构造函数，复制构造函数和析构函数
        chain (int initialCapacity = 10);
        chain (const chain<T>&);
        ~chain();
        // ADT方法
        bool empty() const { return listSize == 0; }
        int size() const { return listSize; }
        T& get (int theIndex) const;
        int indexOf (const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(ostream& out) const;
        // 自定义迭代器
        class iterator{
            public:
                // 向前迭代器所需要的typedef语句在此忽略
                // 构造函数
                iterator(chainNode<T>* theNode = NULL) { node = theNode; }
                // 解引用操作符
                T& operator*() const { return node->element; }
                T* operator->() const { return &node->element; }
                // 迭代器加法操作
                iterator& operator++() { //前加
                     node = node->next;
                     return *this;
                }
                iterator operator++(int){ //后加
                    iterator old = *this;
                    node = node->next;
                    return old;
                }
                // 相等检验
                bool operator!=(const iterator right) const { return node != right.node; }
                bool operator==(const iterator right) const { return node == right.node; }
            protected:
                chainNode<T>* node;
        };
        iterator begin() { return iterator(firstNode); }
        iterator end() { return iterator(NULL); }
    protected:
        void checkIndex(int theIndex) const;
        chainNode<T> * firstNode;
        int listSize;
};

template<class T>
chain<T>::chain(int initialCapacity){
    // 构造函数
    if (initialCapacity < 1){
        try{
            ostringstream s;
            s <<"Initial capacity = "<<initialCapacity<<" Must be > 0";
            throw illegalParameter(s.str());
        }
        catch (illegalParameter e){
            e.outputMessage();
        }
    }
    firstNode = NULL;
    listSize = initialCapacity;
}

template<class T>
chain<T>::chain(const chain<T>& theList){
    // 复制构造函数
    listSize = theList.listSize;
    if (listSize == 0){
        // 链表theList为空
        firstNode = NULL;
        return;
    }
    // 链表theList非空
    chainNode<T>* sourceNode = theList.firstNode; // 复制链表theList的节点
    firstNode = new chainNode<T>(sourceNode->element); // 复制链表theList的首元素
    sourceNode = sourceNode->next; // 将指针后移
    chainNode<T> * targetNode = firstNode; // 当前链表theList的最后一个节点
    while (sourceNode != NULL){
        // 复制剩余元素
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; //链表结束
}

template<class T>
chain<T>::~chain(){
    // 链表析构函数，删除链表所有节点
    while (firstNode != NULL){
        // 删除首节点
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const{
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
T& chain<T>::get(int theIndex) const{
    // 返回索引为theIndex的元素
    // 若元素不存在抛出异常
    checkIndex(theIndex);
    // 移向所需要的节点
    chainNode<T>* currentNode = firstNode;
    for (int i=0; i<theIndex; i++){
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const{
    // 返回元素theElement首次出现时的索引
    // 若该元素不存在，则返回-1
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement){
        // 移向下一个节点
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::erase(int theIndex){
    // 删除下标为theIndex的元素
    // 若元素不存在则抛出异常
    checkIndex(theIndex);
    // 索引有效需要找到删除的元素
    chainNode<T>* deleteNode;
    if (theIndex == 0){
        // 删除首节点
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else{
        // 用指针p指向要删除节点的前驱节点
        chainNode<T>* p = firstNode;
        for (int i=0; i<theIndex-1; i++){
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement){
    // 在索引为theIndex的位置上插入元素theElement
    // 判断索引是否有效
    checkIndex(theIndex);
    if (theIndex == 0)
        // 在表头插入
        firstNode = new chainNode<T>(theElement, firstNode);
    else{
        // 寻找新元素的前驱
        chainNode<T>* p = firstNode;
        for (int i=0; i<theIndex-1; i++)
            p = p->next;
        // 在p之后插入新元素
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const{
    // 把链表放入输出流
    for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
        out <<currentNode->element<<" ";
}

// 重载
template<class T>
ostream& operator<<(ostream& out, const chain<T>& x){
    x.output(out);
    return out;
}

#endif
















