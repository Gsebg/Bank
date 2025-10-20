#include <iostream>
#include "Node.cpp"  

class List{
  protected:
    Node* head;
    Node* last;
    int length;

  public:
    List(){
      head = NULL;
      last = NULL;
      length = 0;
    };

    ~List(){
      clear();
    };

    void clear(){
      while(!isEmpty()){
        Node* aux = head;
        head = head->next;
        delete aux;
      };
      head = last = NULL;
      length = 0;
    };

    virtual void append(int data) = 0;

    bool isEmpty(){
      return head==NULL;
    };

    int len(){
      return length;
    };

    bool get(){
      if(!isEmpty()){
        int x = head->data;
        Node * aux = head;
        head = head->next;
        delete aux;
        if(isEmpty()){
          last = NULL;
        };
        length--;
        return x;
      };
      throw -1;
    };

    void print(std::ostream& os){
      os << length;
      Node* a=head;
      while(a!=NULL){
        os << ' ' << a->data;
        a = a->next;
      };
    };

    void read(std::istream& is){
      clear();
      int x;
      int n;
      //if(is == std::cin){
      //  std::cout << "Ingrese el número de elemntps de la lista:";
      //}
      is >> n;
      for(int i=0; i<n; i++){
        //if(is == std::cin){
        //  std::cout << "Ingrese el dato " << i "-esimo de la lista:";
        //}
        is >> x;
        if(isEmpty()){
          head = new Node(x);
          last = head;
        }else{
          last->next  = new Node(x);
          last = last->next;
        };
        length++;
      };
    };

    void bubblesort(){
      if(head!=NULL){
        for(Node* i=head; i->next != NULL; i=i->next){
          for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->data > j->data){
              int t = i->data;
              i->data = j->data;
              j->data = t;
            };
          };
        };
      };
    };

    Node* msort(Node* h){
      if(h->next!=NULL){
        Node* l = h;
        Node* r = h->next;
        Node* lastl = l;
        Node* lastr = r;
        bool f = true;
        Node* aux = r->next;
        while(aux!=NULL){
          if(f){
            lastl->next = aux;
            lastl = aux;
          }else{
            lastr->next = aux;
            lastr = aux;
          };
          aux = aux->next;
          f = !f;
        };
        lastl->next = NULL;
        lastr->next = NULL;
        l = msort(l);
        r = msort(r);

      };
      return h;
    };

    void mergesort(){
      if(head!=NULL){
        head = msort(head);
        last = head;
        while(last->next != NULL){ last = last->next; };
      };
    };
};

std::ostream& operator<< (std::ostream& os, List& l){
  l.print(os);
  return os;
};

std::istream& operator>> (std::istream& is, List& l){
  l.read(is);
  return is;
};