#include<stdio.h>
void updation(int arr[],int size,int value,int ind){
    if(ind>size-1||ind<0){
        printf("wrong input");
    }
    arr[ind]=value;
}
void traverse(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}
int main(){
    int arr[5]={1,3,2,4,5};
    int capacity=5;
    int size=5;
    int ind=3;
    updation(arr,size,101,ind);
    traverse(arr,size);
    return 0;
}