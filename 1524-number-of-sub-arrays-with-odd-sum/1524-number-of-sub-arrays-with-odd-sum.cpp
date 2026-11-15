class Solution {
public:
const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int even=0,odd=0;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
           sum+=arr[i];
           if(sum%2){
            res=(res+1+even)%M;
            odd++;
           }else{
            res=(res+odd)%M;
            even++;
           }
        }
        return res;
    }
};