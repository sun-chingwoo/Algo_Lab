#include <stdio.h>

#define LEFT -1
#define RIGHT 1
int n;
int arr[100];
int dir[100];

void printper(){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int getmobile(){
    int mobile=0;
    int mi=-1;
    for(int i=0;i<n;i++){
        if(dir[i]==LEFT && i!=0 && arr[i]>arr[i-1]){
            if(arr[i]>mobile){
                mobile=arr[i];
                mi=i;
            }
        }
        
        if(dir[i]==RIGHT && i!=n-1 && arr[i]>arr[i+1]){
            if(arr[i]>mobile){
                mobile=arr[i];
                mi=i;
            }
        }
    }
    return mi;
}

void jt(){
    for(int i=0;i<n;i++){
        arr[i]=i+1;
        dir[i]=LEFT;
    }
    printper();
    while(1){
        int mobileindex=getmobile();
        int swap;
        if(mobileindex==-1) break;
        if(dir[mobileindex]==LEFT) swap=mobileindex-1;
        else swap=mobileindex+1;
        
        int temp=arr[mobileindex];
        arr[mobileindex]=arr[swap];
        arr[swap]=temp;
        
        temp = dir[mobileindex];
        dir[mobileindex] = dir[swap];
        dir[swap] = temp;
        
        for(int i=0;i<n;i++){
            if(arr[i]>arr[swap]){
                dir[i]=-dir[i];
            }
        }
        printper();
    }
}

int main(){
    printf("enter the numbr of ele");
    scanf("%d",&n);
    jt();
    return 0;
}
