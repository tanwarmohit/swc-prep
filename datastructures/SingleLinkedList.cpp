#include "SingleLinkedList.h"


int SingleLinkedList::First(){
    if(head != NULL)
        return head->data;
    return -1;
}

int SingleLinkedList::Last(){
    if(tail != NULL)
        return tail->data;
    return -1;
}

bool SingleLinkedList::IsEmpty(){
    return head == NULL && head == tail; 
}

int SingleLinkedList::Size(){
    if(IsEmpty())
        return 0;

    int N = 0;
    Nodeptr current = head;
    while(current != NULL){
        N++;
        current = current->next;
    }

    return N;
}

void SingleLinkedList::FreeNode(Nodeptr node){
    if(node != NULL){
        //Point NextPtr to NULL
        node->next = NULL;
    }
     //Free Node
    free(node);
}

Nodeptr SingleLinkedList::CreateNewNode(int data){
    Nodeptr newNode = (Nodeptr) malloc(sizeof(lnode));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

SingleLinkedList::SingleLinkedList(){
    head = tail = NULL;
}

SingleLinkedList::~SingleLinkedList(){
    if(head != NULL){
        Nodeptr current = head;
        Nodeptr temp;
        head = tail = NULL;
        while(current != NULL){
            temp = current;
            current = current->next;
            FreeNode(temp);
        }
    }
}

void SingleLinkedList::InsertFirst(int data){
    Nodeptr newNode = CreateNewNode(data);
    newNode->next = head;
    head = newNode;

    //If list was empty
    if(tail == NULL){
        tail = head;
    }
}

void SingleLinkedList::InsertLast(int data){
    Nodeptr newNode = CreateNewNode(data);
    //If List is Not Empty
    if(tail != NULL){
        tail->next = newNode;
    }
    tail = newNode;

    //If list was empty
    if(head == NULL){
        head = tail;
    }
}

void SingleLinkedList::DeleteFirst(){
    if(head != NULL){
        Nodeptr deleteNode = head;
        if(head == tail){ //If there is only 1 Element
            head = tail = NULL;
        } else {
            head = head->next;
        }
        FreeNode(deleteNode);
    }
}

void SingleLinkedList::DeleteLast(){
    if(tail != NULL){
        Nodeptr deleteNode = tail;
        if(head == tail){ //If there is only 1 Element
            head = tail = NULL;
        } else { //If there is greater than 1 element
            Nodeptr previous, current;
            previous = head;
            current = previous->next;
            //cout << "PREVIOUS: " << previous << " DATA: " << previous->data << " CURRENT: " << current << " DATA: " << current->data << "\n";
            while(current != tail){
                previous = current;
                current = current->next;
                //cout << "PREVIOUS: " << previous << " DATA: " << previous->data << " CURRENT: " << current << " DATA: " << current->data << "\n";
            }
            tail = previous;
            tail->next = NULL;
        }
        FreeNode(deleteNode);
    }
}

void SingleLinkedList::PrintList(){
    int N = 0;
    if(head != NULL){
        Nodeptr current = head;
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
            N++;
        }
    }
    cout << "[Size:" << N << "] [HEAD-POINTER: " << head << " ] [TAIL-POINTER: " << tail << " ]\n";
}

