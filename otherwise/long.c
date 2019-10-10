#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int count = 0;
    char c;
    while( (scanf("%c",&c)) != EOF){
        str[count] = c;
        ++count;
        if(c == '\n') break;
    }
    str[count] = '\0';
    for(int j = 0 ; j < count ; ++j){
        printf("%c", str[j]);
    }
}
