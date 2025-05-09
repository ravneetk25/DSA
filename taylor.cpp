#include<bits/stdc++.h>
using namespace std;
double e (int x, int n){
    static double a=1, b=1;
    double r;
    if(n==0) return 1;
    else{
        r=e(x, n-1);
        a=a*x;
        b=b*n;
        return r+ a/b;
    }
}
int main(){
    int r, x, n;
    cout<<"Enter power and terms: ";
    cin>>x>>n;
    cout<<"Result : "<<e(x,n);
    return 0;
}