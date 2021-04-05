#include "stack.h"
#include <stdlib.h>
//stack functions
void init(stack *s, int len){
   s->a = (int *)malloc(sizeof(int)*len);
   s->size = len;
   s->top = -1;
   return;
}

int isFull(stack s){
    if(s.top == s.size-1){
        return 1;
    }
    else
        return 0;
}


int isEmpty(stack s){
    if(s.top == -1){
        return 1;
    }
    else
        return 0;
}


void push(stack *s, int d){
    if(!isFull(*s)){
        s->top++;
        s->a[s->top]=d;
        return;
    }
    else
        return;
}


int peek(stack s){
   int e = '0';
   if(!isEmpty(s))
        e = s.a[s.top];
   return e;
}

int pop(stack *s){
    int e = '0';
    if(!isEmpty(*s)){
        e = s->a[s->top];
        s->top--;
    }
    return e;
}
