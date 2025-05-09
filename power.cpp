#include<bits/stdc++.h>
using namespace std;
int power(int n, int m){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power(m*m, n/2);
    }
    else{
        return m*power(m*m, (n-1)/2);
    }
}
int main(){
    int m, n;
    cout<<"Enter the value and power :";
    cin>>m>>n;
    int a= pow(m,n);
    cout<<"The result is :"<<a;
    return 0;

}
