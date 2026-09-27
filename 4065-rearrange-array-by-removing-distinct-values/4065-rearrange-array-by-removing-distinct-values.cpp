class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101,0);
        for(auto num:nums) freq[num]++;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int num=1;num<101;num++){
                if(freq[num]>0){
                    ans.push_back(num);
                    freq[num]--;
                }
            }
        }
        return ans;
    }
};