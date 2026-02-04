#include <stdio.h>

// MTK 筆試常考的 Macro 寫法
#define SET_BIT(n, i)    ((n) |=  (1U << (i)))
#define CLEAR_BIT(n, i)  ((n) &= ~(1U << (i)))
#define TOGGLE_BIT(n, i) ((n) ^=  (1U << (i)))

int main() {
    unsigned int n = 10; // 0000 1010
    int i ;
    scanf("%d",&n);
    scanf("%d",&i);
    SET_BIT(n, i);    // 變為 14 (0000 1110)
    printf("After set: %u\n", n);

    CLEAR_BIT(n, i);  // 變回 10 (0000 1010)
    printf("After clear: %u\n", n);

    TOGGLE_BIT(n, i); // 變為 14
    printf("After toggle: %u\n", n);

    getchar();
}