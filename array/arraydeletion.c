#include<stdio.h>
int deletion(int arr[],int* size,int index){
    if(*size<=0){
        return -1;
    }
    for(int i=index;i<*size-1;i++){
        arr[i]=arr[i+1];
    }
    (*size)--;
    return 1;
}
int main(){
    int arr[9]={1,3,2,4,6,2};
    int size=6;
    int index=2;
    int result=deletion(arr,&size,index);
    if(result==1){
        printf("deleted your element in that index");
        for(int i=0;i<size;i++){
            printf("%d\n",arr[i]);
        }
    }
    else if(result==-1){
        printf("undeflow case");
    }
    return 0;
}