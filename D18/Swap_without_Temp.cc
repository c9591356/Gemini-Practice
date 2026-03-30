void swap(int *a, int *b) {
    // 只能使用 a 和 b 進行位元運算
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}