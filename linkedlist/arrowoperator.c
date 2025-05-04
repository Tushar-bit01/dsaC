#include<stdio.h>
#include<stdlib.h>
//arrow operator= arrow operator allows me too acces member variable of struct when having pointer to that struct
struct node{
    int x;
    int y;
};
int main(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->x=5;
    ptr->y=9;
    printf("%d,%d",ptr->x,ptr->y);
    free(ptr);
    return 0;
}