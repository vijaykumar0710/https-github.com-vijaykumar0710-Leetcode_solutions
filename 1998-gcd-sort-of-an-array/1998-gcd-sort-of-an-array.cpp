class Solution {
public:
vector<int>parent,rank;
int find(int u){
    if(parent[u]==u) return u;
    return parent[u]=find(parent[u]);
}
void Union(int u,int v){
    int par_u=find(u);
    int par_v=find(v);
    if(par_u==par_v) return;
    if(rank[par_u]>rank[par_v]){
        parent[par_v]=par_u;
    }else if(rank[par_u]<rank[par_v]){
        parent[par_u]=par_v;
    }else{
        parent[par_u]=par_v;
        rank[par_v]++;
    }
}
vector<int>spf;
void precompute(int n){
spf.resize(n+1);
for(int i=1;i<=n;i++) spf[i]=i;
for(int i=2;i*i<=n;i++){
    if(spf[i]==i){
        for(int j=i*i;j<=n;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
 }
}
void fact(int x){
    int val=x;
    while(x!=1){
        Union(val,spf[x]);
        x/=spf[x];
    }
}
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        parent.resize(maxi+1);
        for(int i=0;i<=maxi;i++) parent[i]=i;
        rank.assign(maxi+1,1);
        precompute(maxi+1);
        for(int i=0;i<n;i++) fact(nums[i]);
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=sorted[i]){
                if(find(nums[i])!=find(sorted[i])) return false;
            }
        }
        return true;
    }
};