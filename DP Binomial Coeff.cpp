#include <iostream>
using namespace std;
int binomialCoeffDP(int n,int k){
    int c[n+1][k+1];
    int i,j;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0 || j==i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
    return c[n][k];
}
int binomialCoeff(int n,int k){
    if(k==n || k==0){
        return 1;
    }
    return binomialCoeff(n-1,k-1)+ binomialCoeff(n-1,k);
}
int main() {
    int n;
    int k;
    cin>>n>>k;
    cout<<"Binomial Coeff Recursively: "<<binomialCoeff(n,k)<<endl;
    cout<<"Binomial Coeff DP: "<<binomialCoeffDP(n,k);
}
