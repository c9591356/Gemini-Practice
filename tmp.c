void my_strcpy(char *dest, const char *src){
    while (*src!='\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;
    
}