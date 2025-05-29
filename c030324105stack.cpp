#include <iostream>
using namespace std;

typedef int ItemType;

typedef struct{
    ItemType Item[10];
    int Count;

}Stack;

void InitializeStack(Stack* S);
int Full(Stack* S);
int Empty(Stack* S);
void Pop(Stack* S, ItemType *x);
void Push(ItemType x, Stack *S);

int main(){
    Stack Stack1;
    Stack* S = &Stack1;


    InitializeStack(S);
    


    return 0;
}

void InitializeStack(Stack* S){
    S->Count = 0;
}

int Full(Stack* S){
    return (S->Count == 10);
}

int Empty(Stack *S){
    return (S->Count == 0);
}

void Pop(Stack* S, ItemType *x){
    if (Empty(S)){
        cout << "Stack masih kosong!" << endl;
    }else{
        --(S->Count);
        *x = S->Item[S->Count];
    }
}

void Push(ItemType x, Stack *S){
    if (Full(S)){
        cout << "Stack Penuh! Data tidak dapat masuk!" << endl;
    }else{
        S->Item[S->Count] = x;
        ++(S->Count);
    }
}