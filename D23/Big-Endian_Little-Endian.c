void check_endian() {
    int x = 1;
    // 把 int 的位址，強制轉型成 char 的指標，只看第一個 Byte
    char *ptr = (char *)&x; 
    
    if (*ptr == 1) {
        printf("Little-Endian\n");
    } else {
        printf("Big-Endian\n");
    }
}