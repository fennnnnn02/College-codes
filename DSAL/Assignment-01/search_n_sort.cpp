#include <bits/stdc++.h>

using namespace std;

int linear_search(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key) return i;
    }
    return -1;
}

int binary_search(int a[],int n,int key){
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==key) return mid;
        else if (a[mid]<key) {
            low = mid +1;
        }
        else high = mid - 1;
    }
    return -1;
}

void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
}

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            }
    }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
}

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int current = a[i];
        int j = i-1;
        while(a[j]>current and j>=0) a[j+1] = a[j],j--;
        a[j+1] = current;
    }
}

void shell_sort(int a[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int j=gap;j<n;j++){
            int temp = a[j];
            int i=0;
            for(i=j;i>=gap and a[i-gap]>temp;i-=gap){
                a[i] = a[i-gap];
            }
            a[i] = temp;
        }
    }
}

void quick_sort(int a[],int low,int high){
    
    int pivot = a[low];
    int i = low+1;
    int j = high;
    if(low<=high){while(i<j){
        while(a[i]<pivot and i<=high) i++;
        while(a[j]>pivot and j>=low) j--;
        if(i<j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(a[low]>a[j]) swap(a[low],a[j]);
    quick_sort(a,low,j-1);
    quick_sort(a,j+1,high);
    
}
}
                     
int main(){

    int n=4;
    // cout<<"Enter no of elements"<<endl;
    // cin>>n;
    int a[n]={8,9,5,10};
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }



    quick_sort(a,0,4);
    for(int i=0;i<4;i++){
        cout<<a[i]<<endl;
    }
    
    return 0;
}