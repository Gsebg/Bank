#include <iostream>
#include "Node.cpp"  
#include "List.cpp"

class Stack : public List{
  Stack() : List(){};
  void append(int data){
    Node* aux = new Node(data);
    if(isEmpty()){
      head = last = aux;
    }else{
      aux->next = head;
      head = aux;
    }
    length++;
  };
};