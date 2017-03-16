#include "DoublyLinkedList.h"
#include <time.h>

DoublyLinkedList::DoublyLinkedList(){
    head = tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
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

Nodeptr DoublyLinkedList::CreateNode(int data){
    Nodeptr newNode = (Nodeptr) malloc(sizeof(lnode));
    newNode->data = data;
    newNode->next = newNode->previous = NULL;
    return newNode;
}

void DoublyLinkedList::FreeNode(Nodeptr node){
    if(node != NULL){
        node->next = node->previous = NULL;
    }
    free(node);
}

void DoublyLinkedList::InsertFirst(int data){
    Nodeptr newNode = CreateNode(data);
    newNode->next = head;
    newNode->previous = NULL;

    if(head != NULL)
        head->previous = newNode;
    
    head = newNode;

    if(tail == NULL)
        tail = head;
}

void DoublyLinkedList::InsertLast(int data){
    Nodeptr newNode = CreateNode(data);
    newNode->previous = tail;
    newNode->next = NULL;

    if(tail != NULL)
        tail->next = newNode;
    
    tail = newNode;

    if(head == NULL)
        head = tail;
}

void DoublyLinkedList::DeleteFirst(){
    if(head != NULL){
        Nodeptr current = head;
        head = current->next;

        if(tail == current)
            tail = head;

        if(head != NULL)
            head->previous = NULL;
        
        FreeNode(current);
    }
}

void DoublyLinkedList::DeleteLast(){
    if(tail != NULL){
        Nodeptr current = tail;
        tail = current->previous;

        if(head == current)
            head = tail;
        
        if(tail != NULL)
            tail->next = NULL;

        FreeNode(current);
    }
}

int DoublyLinkedList::First(){
    if(head != NULL)
        return head->data;
    
    return -1;
}

int DoublyLinkedList::Last(){
    if(tail != NULL)
        return tail->data;
    
    return -1;
}

bool DoublyLinkedList::IsEmpty(){
    return head == NULL && head == tail;
}

int DoublyLinkedList::Size(){
    Nodeptr current = head;
    int N = 0;
    while(current != NULL){
        N++;
        current = current->next;
    }
    return N;
}

void DoublyLinkedList::PrintList(){
    cout << "Head: " << head << " Tail: " << tail << " ";
    Nodeptr current = head;
    int N = 0;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
        N++;
    }
    cout << "[ Size: " << N << " ]\n"; 
}


int main(){
    srand(time(NULL));
    DoublyLinkedList list;
    int numberOfTries = 300 + rand() % 500;
    cout << "Number of tries: " << numberOfTries << "\n";
    int prob;
    while(numberOfTries--){
        prob = rand() % 100;
        cout << "[---- ";
        if(prob < 25){
            cout << "INSERT FIRST";
            list.InsertFirst(rand() % 200);
        }else if(prob < 50){
            cout << "INSERT  LAST";
            list.InsertLast(rand() % 200);
        }else if(prob < 75){
            cout << "DELETE FIRST";
            list.DeleteFirst();
        }else{
            cout << "DELETE  LAST";
            list.DeleteLast();
        }
        cout << " ----] ";
        list.PrintList();
    }  
    return 0;
}