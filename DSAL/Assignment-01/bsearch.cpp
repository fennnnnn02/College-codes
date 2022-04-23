#include <bits/stdc++.h>

using namespace std;

// int inputarray(){
//     int n1;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n1;
//     int a[n1];
//     for(int i=0;i<n1;i++){
//         cin>>a[i];
//     }
    
// }



int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int del;
    cin>>del;
    for(int i=del-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}