#include "queue.h"
#include <iostream>

class queue{
public: int size,tail = 0; 
public: char array[];
void enqueue(char x){
    array[tail] = x;
    size++;
    tail++;
}

void dequeue(){
    char aux;
    for (int j =0;j < size;j++){
    aux=array[j];
    array[j]=array[j+1];

    }

}

void print(){
    for(int i=0;i < size;i++) std::cout << array[i] << " ";
}
};