#include<bits/stdc++.h>
using namespace std;
// double e (int x, int n){
//     static double s;
//     if(n==0) return s;
//     s=1+x*s/n;
//     return e(x, n-1);
//     // else{
//     //     r=e(x, n-1);
//     //     a=a*x;
//     //     b=b*n;
//     //     return r+ a/b;
//     // }

double e (int x, int n){
     double s=1;
   int i;
   double num=1, den=1;
   for(i=1; i<=n; i++){
    num *=x;
    den *=i;
    s+=num/den;
   }
   return s;
}
int main(){
    int r, x, n;
    cout<<"Enter power and terms: ";
    cin>>x>>n;
    cout<<"Result : "<<e(x,n);
    return 0;
}