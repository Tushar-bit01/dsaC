#include<stdio.h>
int binarysearch(int arr[],int size, int element){
    int mid;
    int low=0,high=size-1;
    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]>element){
            high=mid-1;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,3,5,7,9,45,67,89};
    int size=sizeof(arr)/sizeof(int);
    int ans=binarysearch(arr,size,9);
    if(ans==-1){
        printf("element is not found there");
    }
    else{
    printf("index is %d",ans);
    }

    return 0;
}