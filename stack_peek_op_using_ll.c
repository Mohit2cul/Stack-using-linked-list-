# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node * top = NULL;

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr -> next;
    }
}    

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        return 1;
    }
    else{
        return 0; 
    }
}

struct Node * push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }
}

int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node * n = tp;
        top = tp -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

int peek(int pos){
    struct Node * ptr = top;
    for(int i=0;(i<pos-1 && ptr != NULL);i++){
        ptr = ptr -> next;
    }
    if(ptr != NULL){
        return ptr -> data;
    }
    else{
        return -1;
    }
}

int main() {
    top = push(top, 5);
    top = push(top, 9);
    top = push(top, 15);
    printf("Stack elements are:-\n");
    linkedListTraversal(top);
    for(int i = 1; i<=3 ; i++){
        printf("Value at position %d is %d\n", i, peek(i));
    }
    return 0;
}