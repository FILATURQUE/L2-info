#include <stdlib.h>
#include <stdio.h>
#define prl printf("\n")

void affTab(char *s){
        
    printf("%s",s);
    
}

int stringlen(char* s){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

char* cpystr(char* dst, char* src){
    
    if (stringlen(dst) == stringlen(src))
    {   
        printf("IN");
        for (size_t i = 0; i < stringlen(src); i++)
        {
            *(dst + i) = *(src + i);
        }
        
        return dst;
    }
    printf("OUT");prl;
    return NULL;
    
}

int main(){
    // printf("%d\n",stringlen("Patrick"));
    char* mot = "aababab";
    char* cpy_mot;
    cpy_mot = malloc(8 * sizeof(char));
    cpy_mot = cpystr(cpy_mot,mot);
    affTab(cpy_mot);

    return EXIT_SUCCESS;
}