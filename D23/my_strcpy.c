char* my_strcpy(char *dest, const char *src) {
    // 你的純淨白板發揮時間
    while(*src!='\0'){
        *dest = *src;
        src++;
        dest++;
    }
    dest++; 
    *dest = '\0';
}