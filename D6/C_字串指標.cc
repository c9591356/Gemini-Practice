void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++)); // 連變數宣告都省了
}