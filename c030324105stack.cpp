#include <iostream>
#define MAXSTACK 10
using namespace std;

typedef int ItemType;


typedef struct{
    ItemType Item[MAXSTACK];
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
    Push(13, S);
    Push(70, S);

    


    return 0;
}

void InitializeStack(Stack* S){
    S->Count = 0;
}

int Full(Stack* S){
    return (S->Count == MAXSTACK);
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