#include <iostream>
using namespace std;

struct example //struct declaration
{
    int data;
    example * next; //poiting to the next struct
};

int main(){
    example a,b; //struct declaration
    b.data = 10;
    a.next = &b; 
    cout << a.next -> data << endl; //accessing b's data value through struct a
    return 0;
}