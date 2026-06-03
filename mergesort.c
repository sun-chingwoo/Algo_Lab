#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000
hh
int arr[MAX], temp[MAX],n=5;

void merge(int low,int mid,int high){
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergesort(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        
        merge(low,mid,high);
    }
}

int main(){
    for (int i = 5; i >=0; i--){
        arr[5-i]=i;
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
