#include<bits/stdc++.h>
using namespace std;
int toh(int n, int a, int b, int c){
    if(n>0){
        toh(n-1,a, c, b );
        cout<<"(" <<a<<","<<c<<")"<<endl;
        toh(n-1, b, a, c);
    }
}
int main(){
    int n;
    int a=1;
    int b=2; 
    int c=3;
    cin>>n;
    toh(n, a, b, c);
    return 0;

}

