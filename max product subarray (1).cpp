#include <iostream>
using namespace std;
int maxProductDP(int* arr, int n) {  
    int minVal = arr[0]; 
    int maxVal = arr[0]; 
    int maxProduct = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] < 0) 
            swap(maxVal, minVal); 
        maxVal = max(arr[i], maxVal * arr[i]); 
        minVal = min(arr[i], minVal * arr[i]); 
        maxProduct = max(maxProduct, maxVal); 
    } 
    return maxProduct; 
} 
int maxProductRe(int nums[],int n){ 
    int maxEh = 1;
    int minEh = 1;
    int maxSf = 1;
    bool flag = 0;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            maxEh = maxEh * nums[i];
            minEh = min(minEh * nums[i],1);
            flag = 1;
        }
        else if(nums[i]== 0){
            minEh = 1;
            maxEh = 1;
        }
        else{
            int temp = maxEh;
            maxEh = max(maxEh * nums[i],1);
            minEh = temp * nums[i];
        }
        if(maxSf<maxEh){
            maxSf = maxEh;
        }
    }
    if(flag == 0 && maxSf ==1){
        return 0;
    }
    return maxSf;
}
int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxProductRe(nums,n)<<endl;
    cout<<maxProductDP(nums,n);

}
