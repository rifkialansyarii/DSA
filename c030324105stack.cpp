#include <iostream>
using namespace std;

typedef int ItemType;

typedef struct{
    ItemType Item[10];
    int Count;

}Stack;

void InitializeStack(Stack* S);

int main(){
    Stack Stack1;
    Stack* S = &Stack1;


    return 0;
}

void InitializeStack(Stack* S){
    S->Count = 0;
}