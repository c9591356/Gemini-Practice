#include <stdio.h>
void swap_pointers(int **ptra,int **ptrb){
    int *tmp = *ptra;//ptra存ptrA這個指標的位置，Dereference一次取出ptrA(&a)給指標tmp，如果再Dereference一次取出&a裡面的值(10)
    *ptra = *ptrb;//Dereference一次取出ptrB(&b)給*ptra(Dereference一次存位置)
    *ptrb = tmp;
}
int main() {
    int a = 10;
    int b = 20;
    
    int *ptrA = &a; // ptrA 指向 a
    int *ptrB = &b; // ptrB 指向 b
    
    // 我想要呼叫一個函數，把這「兩個指標的指向」交換！
    // 也就是執行完後，ptrA 要改指向 b，ptrB 要改指向 a。
    // 注意：不可以更改 a 和 b 本身的值喔！
    
    // swap_pointers( ??? );
    swap_pointers(&ptrA,&ptrB);//他指向了ptrA跟ptrB的位址
    // 預期輸出要變成：ptrA points to 20, ptrB points to 10
    printf("ptrA points to %d, ptrB points to %d\n", *ptrA, *ptrB); 
    
    return 0;
}