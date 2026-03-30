void swap(int *a, int *b) {
    // 你的純淨白板發揮時間
    *a ^= *b;
    *b = *a^*b;
    *a ^= *b;
}