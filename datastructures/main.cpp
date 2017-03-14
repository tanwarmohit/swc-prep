#include "SingleLinkedList.h"
#include <time.h>

int main(){
    srand(time(NULL));
    SingleLinkedList list;
    int numberOfTries = rand() % 100;
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