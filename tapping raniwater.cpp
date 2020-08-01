#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int la[n];
    int countl =0;
    la[0] = arr[0];
    for(int i=1;i<=n;i++){
        la[i] = max(arr[i-1],arr[i]);
        if(countl>la[i]){
            la[i] = countl;
        }
        countl = la[i];
    }
    reverse(arr, arr + n);
    int ra[n];
    int countr =0;
    ra[0] = arr[0];
    for(int i=1;i<=n;i++){
        ra[i] = max(arr[i-1],arr[i]);
        if(countr>ra[i]){
            ra[i] = countr;
        }
        countr = ra[i];
    }
    reverse(arr, arr + n);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans + (min(la[i],ra[i])-arr[i]);
    }
    cout<<ans;
}
