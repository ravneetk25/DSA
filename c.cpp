#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    else{ 
        return fact(n-1)*n;
    }
}
int C(int n, int r){
    int t1, t2, t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    cout<<   t1/(t2*t3);
}
int nc(int n, int r){
    if(n==r || r==0  ) return 1;
    
        return   nc(n-1, r-1)+nc(n-1, r);
}
int main(){
    int a, b;
    cout<<"Enter number n and r : ";
    cin>>a>>b;
    cout<<nc(a,b);
    return 0;
    
}