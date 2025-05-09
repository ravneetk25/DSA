#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    int a=0, b=1, s;
    if(n<=0) return 0 ;
    cout<<a<<" ";
    if(n>1){
        cout<<b<<" ";
    }
    for(int i=2; i<n; i++){
        
        s=a+b;
        cout<<s<<" ";
        a=b;
        b=s;
        
        
    }
    cout<<endl;  
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
     fib(n);
     return 0;
}