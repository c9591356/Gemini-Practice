int my_strlen(const char *str) {
    // 你的純淨白板發揮時間
    int count=0;
    while(*str!='\0'){
        count++;
        str++;
    }
    return count;
}