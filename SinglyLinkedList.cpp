#include <iostream>
using namespace std;

#include "SinglyLinkedList.h"

void SinglyLinkedList::insertAt(Data *arr, int *pos, int N){
    for(int i=0; i<N; ++i){
        insertAt(arr[i], pos[i]);
    }
}

void SinglyLinkedList::push(Data *arr, int N){
    for(int i=0; i<N; ++i){
        push(arr[i]);
    }
}

void SinglyLinkedList::push_back(Data *arr, int N){
    for(int i=0; i<N; ++i){
        push_back(arr[i]);
    }
}

void SinglyLinkedList::removeDuplicates(){
    for(int i=0; i < size() - 1; ++i){
        Node *pNode = getNode(i);
        Node* pPrev = pNode;
        Node *pNext = pNode->getNext();
        
        while(pNext){
            if (pNode->getData().getData() == pNext->getData().getData()){
                Node *delNode = pNext;
                pPrev->setNext(pNext->getNext());
                pNext = pNext->getNext();
                delete delNode;
            } else {
                pPrev = pNext;
                pNext = pNext->getNext();
            }
        }
    }
}

bool SinglyLinkedList::mergeWith_At(SinglyLinkedList &list, int idx){
    if (!idx){
        Node *pNode = list.head;

        while(pNode->getNext())
            pNode = pNode->getNext();

        pNode->setNext(head);

        head = list.head;

        return 1;
    } else if (idx <= size()){
        Node *pNode = head;

        for(int i=0; i<idx - 1; ++i){
            pNode = pNode->getNext();
        }

        Node *temp = pNode->getNext();
        pNode->setNext(list.head);

        while(pNode->getNext()){
            pNode = pNode->getNext();
        }

        pNode->setNext(temp);
        return 1;
    }

    return 0;
}

void SinglyLinkedList::clear(){
    Node *pNode, *curNode = head;

    while(curNode){
        pNode = curNode->getNext();
        delete curNode;
        curNode = pNode;
    }

    head = nullptr;
    nE = 0;
}

bool SinglyLinkedList::pop_back(){
    if (!size()) return 0;

    if (size()){
        Node *delNode = head;
        head = head->getNext();
        delete delNode;

        return 1;
    }

    Node *pNode = head;

    while(pNode->getNext()){
        pNode = pNode->getNext();
    }

    Node *delNode = pNode->getNext();
    pNode->setNext(nullptr);
    delete delNode;

    return 1;
}

bool SinglyLinkedList::push_back(Data obj){
    Node *newNode = new Node(obj, head);
    head = newNode;

    return 1;
}

Data SinglyLinkedList::highest(){
    Data ret;

    Node *pNode = head;

    while(pNode){
        if (pNode->getData() > ret){
            ret = pNode->getData();
        }

        pNode = pNode->getNext();
    }

    return ret;
}

Data SinglyLinkedList::lowest(){
    Data ret = head->getData();
    Node *pNode = head->getNext();

    while(pNode){
        if (pNode->getData() < ret){
            ret = pNode->getData();
        }

        pNode = pNode->getNext();
    }

    return ret;
}

void SinglyLinkedList::swapAt(int i, int j){
    swapNode(i, j);
}

void SinglyLinkedList::bubleSort(){
    bool swapped;

    for(int i=0; i<size() - 1; ++i){
        swapped = false;

        for(int j=0; j<size() - i - 1; ++j){
            if(getNode(j)->getData().getData() > getNode(j + 1)->getData().getData()){
                swapNode(j, j + 1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void SinglyLinkedList::display(){
    if (!size()){
        cout << "[EMPTY]\n";
        return;
    }

    Node *pNode = head;
    Data data;
    cout << "[";
    while(pNode){
        data = pNode->getData();
        cout << data;
        cout << " -> ";

        pNode = pNode->getNext();
    }

    if (!pNode) cout << "NULL";

    cout << "]\n";
}

bool SinglyLinkedList::removeAt(int idx){
    if (idx >= 0 && idx < size() && head){
        if (!idx){
            pop();
            return 1;
        }

        Node *pNode = head;

        for(int i=0; i < idx - 1; ++i){
            pNode = pNode->getNext();
        }

        Node *delNode = pNode->getNext();

        pNode->setNext(pNode->getNext()->getNext());

        delete delNode;
    }

    return 0;
}

bool SinglyLinkedList::insertAt(Data val, int idx){
    if (idx >= 0 && idx <= size()){
        if (!idx) return push_back(val);

        if (idx == size()) return push(val);

        Node *pNode = head;

        for(int i=0; i<idx - 1; ++i)
            pNode = pNode->getNext();

        Node *newNode = new Node(val, pNode->getNext());
        pNode->setNext(newNode);

        return 1;
    }

    return 0;
}

int SinglyLinkedList::size(){
        int count = 0;

        Node *pNode = head;

        while(pNode){
            count++;
            pNode = pNode->getNext();
        }

        return count;
    }

bool SinglyLinkedList::push(Data val){
    if (!head){
        Node *newNode = new Node(val, head);
        head = newNode;

        return 1;
    }

    Node *pNode = head;

    while(pNode->getNext()){
        pNode = pNode->getNext();
    }

    Node *newNode = new Node(val, nullptr);
    pNode->setNext(newNode);

    return true;
}

bool SinglyLinkedList::pop(){
    if (!size()) return 0;

    Node *delNode = head;
    head = head->getNext();
    
    delete delNode;
    return 1;
}

Data SinglyLinkedList::front(){
    if (!size()) return Data();

    Data data = head->getData();
    return data;
}

Data SinglyLinkedList::back(){
    if (!size()) return Data();

    Node *pNode = head;

    while(pNode->getNext()){
        pNode = pNode->getNext();
    }

    Data data = pNode->getData();
    return data;
}

