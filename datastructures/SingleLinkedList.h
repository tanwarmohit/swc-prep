#include <iostream>

using namespace std;

typedef struct Node *Nodeptr;

typedef struct Node {
    int data;
    Nodeptr next;
} lnode ;


class SingleLinkedList{
    private:
        Nodeptr head;
        Nodeptr tail;
        Nodeptr CreateNewNode(int);
        void FreeNode(Nodeptr node);
    
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        int First();
        int Last();
        int Size();
        bool IsEmpty();
        void PrintList();
};