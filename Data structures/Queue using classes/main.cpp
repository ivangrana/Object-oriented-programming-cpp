#include "queue.cpp"
#include <iostream>
#include <string>
using namespace std;


int main(){
queue a;
a.enqueue('U');
a.enqueue('F');
a.enqueue('P');
a.enqueue('A');
a.dequeue();
// a.dequeue();
a.print();
return 0;
}