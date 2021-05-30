#include<stdio.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

int main()
{
    int t,i,n,b,j,z,l=1;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        j=0;
        scanf("%d%d",&n,&b);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        mergeSort(a,0,n-1);
        i=0;
        while(b>0){
            b=b-a[i];
            if(b>=0)
                j++;
            i++;
            if(i==n)
                break;
        }
        printf("Case #%d: %d\n",l,j);
        l++;
    }
    return 0;
}
            