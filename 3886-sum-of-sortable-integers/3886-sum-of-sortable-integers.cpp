class Solution {
public:
    vector<int> divisor_sum(int n) {
        vector<int>a;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                a.push_back(i);
                if (i * i != n)
                    a.push_back(n/i);
            }
        }
        return a;
    }
    bool check(vector<int>& nums, int l, int r,int &mini,int &maxi) {
        int drops = 0;
        for (int i = l; i <=r; i++) {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            if(i==r){
                if (nums[i] > nums[l])
                drops++;
            }
            else if (nums[i] > nums[i + 1])
                drops++;
            if (drops > 1)
                return false;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
       int n = nums.size();
       vector<int>divisor=divisor_sum(n);
       int res=0;
       for(auto d:divisor){
        if(d==1) continue;
        bool flag=true;
        int minii=INT_MIN;
          for(int i=0;i<=n-d;i+=d){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            if(!check(nums,i,i+d-1,mini,maxi)){
                 flag=false;
                 break;
            }else{
                if(mini<minii){
                flag=false;
                break;
              }else minii=maxi;
            }
          }
          if(flag) res+=d;
       }
        vector<int> temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        if (temp == nums) return res+1;
        return res;
    }
};