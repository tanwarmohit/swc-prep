#include <iostream>

using namespace std;

typedef struct Node *Nodeptr;

typedef struct Node {
    int data;
    Nodeptr next;
    Nodeptr previous;
} lnode;

class DoublyLinkedList{
    private:
        Nodeptr head;
        Nodeptr tail;
        Nodeptr CreateNode(int);
        void FreeNode(Nodeptr);
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void InsertFirst(int);
        void DeleteFirst();
        void InsertLast(int);
        void DeleteLast();
        int First();
        int Last();
        bool IsEmpty();
        int Size();
        void PrintList();
};