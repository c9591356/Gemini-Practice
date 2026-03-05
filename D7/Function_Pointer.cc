#include <stdio.h>

// 1. 定義兩個運算函式
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

// 2. 重點：請定義 compute 函式
// 它接受兩個 int，以及一個「指向函式的指標 (op)」
// 該指標指向的函式必須接受兩個 int 並回傳一個 int
int compute(int a, int b,int op(int,int) ) {
    return op(a, b);
}

int main() {
    // 3. 如何呼叫？
    // 我想要算 10 + 5
    int result = compute(10, 5,add);
    printf("Result: %d\n", result);
    return 0;
}