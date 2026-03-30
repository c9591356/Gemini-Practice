#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

void push(int val) {
    // 實作 push 邏輯
    
    if(top>=MAX_SIZE-1)
        return;
    else
        stack[++top] = val;
}

int pop() {
    // 實作 pop 邏輯，空的時候回傳 -1
    if(top==-1)
        return -1;
    else{
        return stack[top--];
    }
}