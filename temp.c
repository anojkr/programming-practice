#include<stdio.h>
#include<stdlib.h>


int main(){
    int SIZE;
    scanf("%d", &SIZE);
    char *c[SIZE];
    
    for(int i=0; i<SIZE; i++){
        scanf("%s", c[i]);
        //printf("%s \n", c[i]);
    }
    
    for(int i=0; i<SIZE; i++){
        printf("%s \n", c[i]);
    }

}