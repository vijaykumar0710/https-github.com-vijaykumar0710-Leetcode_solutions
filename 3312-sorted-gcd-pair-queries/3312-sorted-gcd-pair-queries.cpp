class Solution {
public:
const static int MAXN=1e5+1;
int freq[MAXN]={0};
long long g[MAXN];
vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
      int n=nums.size();
      int max_val=0;
      for(int i=0;i<n;i++){
        freq[nums[i]]++;
        max_val=max(max_val,nums[i]);
      }  
      for(int i=max_val;i>=1;i--){
        long long c=0;
        for(int j=i;j<=max_val;j+=i) c+=freq[j];
        g[i]=(1LL*c*(c-1))/2;
        for(int j=i+i;j<=max_val;j+=i) g[i]-=g[j];
      }
      vector<pair<long long,long long>>idx;
      bool flag=false;
      for(int i=1;i<=max_val;i++){
        if(g[i]>0){
            if(!flag){
            idx.push_back({0,i});
            flag=true;
            }else idx.push_back({(long long)idx.back().first+g[idx.back().second],i});
         }
      }
      vector<int>res;
      for(int i=0;i<queries.size();i++){
        long long it=upper_bound(idx.begin(),idx.end(),make_pair(queries[i],INT_MAX))-idx.begin();
        res.push_back(idx[it-1].second);
      }
      return res;
    }
};