#include<stdio.h>
int main(){
    int arr[3][3],nz=0,z=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("enter matrix elements");
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==0){
                z++;
            }
            else{
                nz++;
            }
        }
    }
    if(nz>z){
        printf("Not a sparse matrix");
    }
    else{
        int spar[nz][3],k=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                spar[k][0]=i;
                spar[k][1]=j;
                spar[k][2]=arr[i][j];
                k++;
            }
        }
    }
    printf("triplet representation of sparse matrix\n");
    for(int i=0;i<nz;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",spar[i][j]);
        }
        printf("\n");
    }
    }
    return 0;
}