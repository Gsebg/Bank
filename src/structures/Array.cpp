#include <iostream>

class Array{
  protected:
    int * buffer;
    int size;
    int length;

public:
    Array( int m, int l=0 ){
      length = l;
      size = m;
      buffer = new int[size];
    };

    ~Array(){
      delete[] buffer;
    };

  void sort(){
    if(length==2){
      if(buffer[0] > buffer[1]){
        int t = buffer[0];
        buffer[0] = buffer[1];
        buffer[1] = t;
      };
    }else{
      if(length>2){
        int m = length/2;
        Array L(m,m);
        Array R(length-m, length-m);
        for(int i=0; i<L.length; i++){
          L[i] = buffer[i];
        };
        for(int i=0; i<R.length; i++){
          R[i] = buffer[i+m];
        };
        L.sort();
        R.sort();
        int iL = 0;
        int iR = 0;
        int k = 0;
        while(iL < L.length && iR < R.length){
          if(L.buffer[iL] < R.buffer[iR]){
            buffer[k] = L.buffer[iL];
            iL++;
          }else{
            buffer[k] = R.buffer[iR];
            iR++;
          };
          k++;
        };
        if(iL==L.length){
          while(iR<R.length){
            buffer[k] = R.buffer[iR];
            iR++;
            k++;
          };
        }else{
          while(iL<L.length){
            buffer[k] = L.buffer[iL];
            iL++;
            k++;
          };
        };
      };
    };
  };

  int& operator[](int index){
    if(0<=index && index < length){
      return buffer[index];
    }else{
      throw -1;
    };
  };

  void grow(){
    if(length==size){
      int m = (int)(size*1.618);
      int * newbuffer = new int[m];
      for( int i=0; i<size; i++){
        newbuffer[i] = buffer[i];
      };
      delete[] buffer;
      buffer = newbuffer;
      size = m;
    };
  };

  bool insert(int index, int data){
    if(0<=index && index<=length){
      grow();
      for(int i=length; i>index; i--){
        buffer[i] = buffer[i-1];
      };
      buffer[index] = data;
      length++;
      return true;
    };
    return false;
  };

  void append(int data){
    insert(length, data);
  };

  void shrink(){
    if(size > 20 && length <= (int)(size/(1.618*1.618))){
      int m = size/1.618;
      int * newbuffer = new int[m];
      for(int i=0; i<m; i++){
        newbuffer[i] = buffer[i];
      };
      delete[] buffer;
      buffer = newbuffer;
      size = m;
    };
  };

  bool remove(int index){
    if(0<=index && index<length){
      length--;
      for(int i=index; i<length; i++){
        buffer[i] = buffer[i+1];
      };
      shrink();
      return true;
    }
    return false;
  };

  bool del(){
    return remove(length-1);
  };

  int len(){
    return length;
  };
};