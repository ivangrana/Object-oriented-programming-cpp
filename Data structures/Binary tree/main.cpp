#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node * lchild;
    node * rchild;
};

void insert(node a,node b,int num){
    
}


int main(){
    node a,b;
    a.value = 5;
    b.value = 2;
    a.lchild = &b;
    cout << a.lchild->value << endl;
    return 0;
}