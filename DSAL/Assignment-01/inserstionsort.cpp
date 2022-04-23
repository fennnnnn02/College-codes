#include <bits/stdc++.h>

using namespace std;

void ins_sort(){
    int a[5];

    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<5;i++){
        int j=i-1;
        int temp = a[i];
        while(a[j]>temp and j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}

int main(){

    

    return 0;
}