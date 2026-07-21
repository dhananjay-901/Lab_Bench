#include <stdio.h>
int main(){
    char *str = "hello world";
    str[0] = 'h'; //undefined behavior
    printf("%s\n", str);
    return 0;
}