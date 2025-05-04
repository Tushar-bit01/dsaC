#include<stdio.h>
int insertion(int arr[],int* size,int capacity,int index){
    if(*size>=capacity){
        printf("overflow case case");
        return -1;
    }
    for(int i=*size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=9;
    (*size)++;
    return 1;
}
int main(){
    int arr[9]={1,4,2,5,3,6};
    int size=6;
    int capacity=9;
    int index=3;
    int result=insertion(arr,&size,capacity,index);
    if(result==1){
        printf("value inserted\n");
        for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
    }
    else{
        printf("overflow case\n");
    }
    return 0;
}