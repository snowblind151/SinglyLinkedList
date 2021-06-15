#include <iostream>
using namespace std;

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class Data{
    private:
    int val;

    public:
    Data() : val(-1) {}
    Data(int val) : val(val) {}

    void setData(int val){
        this->val = val;
    }

    int getData(){
        return val;
    }

    friend ostream& operator<<(ostream& os, Data &obj){
        os << obj.getData();
        return os;
    }

    bool operator>(Data &obj){
        if (val > obj.getData()) return 1;

        return false;
    }

    bool operator<(Data &obj){
        if (val < obj.getData()) return 1;

        return false;
    }

    bool operator==(Data &obj){
        return (obj.val == val);
    }
};

class Node{
    private:
    Data data;
    Node* next;

    public:
    Node() : data(0), next(nullptr) {}
    Node(Data val, Node* pNext) : data(val), next(pNext) {}

    void setNext(Node *next){
        this->next = next;
    }

    Node* getNext(){
        return next;
    }

    void setData(Data val){
        data.setData(val.getData());
    }

    Data getData(){
        return data;
    }

    const void displayData(){
        cout << data.getData() << "\n";
    }
};

//

class SinglyLinkedList{
    private:
    Node *head;
    int nE;

    Node* getNode(int idx){
    if (!size() || idx < 0 || idx >= size()) return nullptr;

    Node *pNode = head;

    for(int i=0; i<idx; ++i)
        pNode = pNode->getNext();

    return pNode;
    }

    void swapNode(int i, int j){

    Node *prevA = getNode(i - 1), *curA = getNode(i);
    Node *prevB = getNode(j - 1), *curB = getNode(j);

    if (prevA) prevA->setNext(curB);
    else head = curB;

    if (prevB) prevB->setNext(curA);
    else head = curA;

    Node *temp = curA->getNext();
    curA->setNext(curB->getNext());
    curB->setNext(temp);

    }

    public:
    SinglyLinkedList() : head(nullptr), nE(0) {}

    ~SinglyLinkedList(){
        // Error: Can not delete objects after using func mergeWith_At
    }

    int size();


    bool push(Data);
    void push(Data*, int);

    bool pop();
    Data front();
    Data back();

    bool insertAt(Data, int);
    void insertAt(Data*, int*, int);
    bool removeAt(int);

    void display();

    void bubleSort();
    void swapAt(int, int);

    Data highest();
    Data lowest();

    bool push_back(Data);
    void push_back(Data*, int);
    bool pop_back();

    void clear();

    bool mergeWith_At(SinglyLinkedList&, int);

    void removeDuplicates();
};
//

#endif