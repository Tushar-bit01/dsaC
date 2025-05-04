#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr=(int*)malloc(5*(sizeof(int)));
    for(int i=0;i<=4;i++){
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<=4;i++){
        printf("%d",ptr[i]);
    }
    free(ptr);
    return 0;
}