class Solution {
public:
int N;
vector<int>BIT;
void update(int i,int val){
for(;i<=N;i+=i&-i) BIT[i]=max(BIT[i],val);
}
int query(int i){
    int lis=0;
    for(;i>0;i-=i&-i) lis=max(lis,BIT[i]);
    return lis;
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        // Weight ko ascending order, height ko descending order
        sort(envelopes.begin(),envelopes.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
      N=100001;
      BIT.assign(N+1,0);
      int res=0;
      // LIS on height
      for(int i=0;i<n;i++){
        int x=envelopes[i][1];
        int len=1+query(x-1);
        res=max(res,len);
        update(x,len);
      }
      return res;
    }
};