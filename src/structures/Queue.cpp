#include <iostream>
#include "Node.cpp"  
#include "List.cpp"

class Queue : public List{
  Queue() : List(){};
  void append(int data){
    if(isEmpty()){
      head = new Node(data);
      last = head;
    }else{
      Node* aux = new Node(data);
      last->next = aux;
      last = aux;
    };
    length++;
  };
};