class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res=0;
        for(auto x:arr1){
            int t=0;
            for(auto y:arr2){
                if(abs(x-y)<=d) t=1;;
            }
            if(!t) res++; 
        }
        return res;
    }
};