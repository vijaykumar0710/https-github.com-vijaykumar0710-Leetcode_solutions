class Solution {
public:
long long t[100001][2];
int next(int i,int l,int r,vector<vector<int>>& meetings){
    int n=meetings.size();
   int idx=n;
   while(l<=r){
    int mid=l+(r-l)/2;
    if(meetings[mid][0]>=meetings[i][1]){
        idx=mid;
        r=mid-1;
    }else l=mid+1;
   }
   return idx;
}
long long fn(int i,int flag,int n,vector<vector<int>>& meetings){
    if(i>=n) return 0LL;
    if(t[i][flag]!=-1) return t[i][flag];
    long long skip=fn(i+1,flag,n,meetings);
    int nxt=next(i,i+1,n-1,meetings);
    long long take=0;
    if(nxt==n) take=meetings[i][2];
    if(nxt<n){
        take=fn(nxt,1,n,meetings);
        take-=(meetings[i][1]);
        take+=meetings[i][2];
    }
    if(flag) take+=meetings[i][0];
    return t[i][flag]=max(skip,take);
}
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        memset(t,-1,sizeof(t));
        return fn(0,0,n,meetings);
    }
};