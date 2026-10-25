class Solution {
public:
void fn(vector<int>&nums,int sz,int k,int &res){
  int n=nums.size();
  unordered_map<int,int>mp;
  int i=0;
  for(int j=0;j<n;j++){
    mp[nums[j]]++;
    if((j-i+1)==sz){
        bool fl=true;
        int f=1;
        unordered_set<int>st;
        for(int it=i;it<i+sz;it++){
            if(st.count(nums[it])) continue;
            st.insert(nums[it]);
            if(mp[nums[it]]!=f){
                fl=false; 
                break;
            }
            f++;
            if(f>k) break;
        }
        if(fl) res++;
        mp[nums[i]]--;
        if(mp[nums[i]]==0) mp.erase(nums[i]);
        i++;
    }
  }
}
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int k=1;(k*(k+1))<=2*n;k++){
           int sz=(k*(k+1))/2;
           fn(nums,sz,k,res);
        }
        return res;
    }
};