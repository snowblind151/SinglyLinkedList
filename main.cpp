#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;

int main(){
    Data point(3);
    SinglyLinkedList list1, list2;
    const int N = 3;
    Data arr[N] = {1, 2, 3};
    int pos[N] = {0, 1, 1};
    list1.insertAt(arr, pos, 3);

    list1.display();
    list1.clear();
    list1.display();

    list1.bubleSort();
    list1.display();

    return 0;
}