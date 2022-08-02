#include<bits/stdc++.h> 
using namespace std;

int main(){ 
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=a;i<=b;i++){
        ans*=i;
    }
    cout<<(ans%10)/2;
    return 0;
}