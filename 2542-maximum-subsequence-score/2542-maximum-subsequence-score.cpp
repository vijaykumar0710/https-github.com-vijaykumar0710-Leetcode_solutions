class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long res=0;
        for(int i=0;i<n;i++){
          int num1=vec[i].second;
          int num2=vec[i].first;
          sum+=num1;
          pq.push(num1);
          if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
          }
          if(pq.size()==k){
              res=max(res,1LL*sum*num2);
          }
        }
        return res;
    }
};