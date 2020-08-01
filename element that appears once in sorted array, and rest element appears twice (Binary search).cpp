#include <iostream>
using namespace std;
// approach1 using o(n) time complexity
int ans(int arr[],int n){
    if(n==0){
        return -1;
    }
    if(n==1){
        return arr[0];
    }
    int i=0;
    while(i < n-1){
        if(arr[i]!=arr[i+1]){
            return arr[i];
        }
        i = i+2;
    }
    return arr[i];
}
// approach 2 using log n time complexity(Binary Search)
int ans2(int arr[],int n){
    int low=0;
    int mid;
    int high = n-1;
    if(high == 0){
        return arr[0];
    }
    else if(arr[0]!= arr[1]){
        return arr[0];
    }
    else if(arr[high-1]!= arr[high]){
        return arr[high];
    }
    while(low<high){
        mid = low+ (high-low)/2;
        if(arr[mid]!= arr[mid+1]&& arr[mid]!= arr[mid-1]){
            return arr[mid];
        }
        if(((mid%2==0)&& arr[mid]== arr[mid+1]) || ((mid%2==1) && arr[mid-1]== arr[mid])){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<ans(arr,n)<<endl;
    cout<<ans2(arr,n);
}
