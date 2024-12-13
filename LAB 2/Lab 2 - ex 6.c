#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char concatena(char *s1, char *s2, char *s3){
    for (int i = 0; i < 5; i++){
        s3[i] = s1[i];
    }
    for (int i = 0, j = 5; i < 5; i++, j++){
        s3[j] = s2[i];
    }
    return 'a';
}

int main (){
    char *s3;
    char s1[] = {'a', 'b', 'c', 'd', 'e'};
    char s2[] = {'f', 'g', 'h', 'i', 'j'};
    
    s3 = (char *) malloc(10*sizeof(char));

    char *p1, *p2, *p3;

    p1 = s1;
    p2 = s2;
    p3 = s3;

    concatena (p1, p2, p3);

    printf ("%s", s3);

    return 0;
}