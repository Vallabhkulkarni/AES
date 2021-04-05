
typedef struct stack{
    int *a;        
    int size;       
    int top;        
}stack;


void init(stack *s, int len);
int isFull(stack s);
int isEmpty(stack s);
void push(stack *s, int d);
int pop(stack *s);
int peek(stack s);
