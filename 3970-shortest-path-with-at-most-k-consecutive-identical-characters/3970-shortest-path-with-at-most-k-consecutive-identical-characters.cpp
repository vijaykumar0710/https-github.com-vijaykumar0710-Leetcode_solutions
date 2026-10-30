class Solution {
public:
    int f(int n,vector<vector<pair<int,int>>>&adj,string &labels,int k){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>res(n,vector<int>(k+2,INT_MAX));
        res[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            int d=vec[0],conse=vec[2],node=vec[1];
            if(d!=res[node][conse]) continue;
            for(auto &arr:adj[node]){
                int dist=arr.second,adjNode=arr.first,nc=conse;
                if(labels[node]==labels[adjNode]){
                    if(nc+1>k) continue;
                    nc++;
                }else nc=1;
                if(dist+d<res[adjNode][nc]){
                     res[adjNode][nc]=d+dist;
                    pq.push({d+dist,adjNode,nc});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            ans=min(ans,res[n-1][i]);
        }
        return ans==INT_MAX?-1:ans;
    }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return 0;
     vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        return f(n,adj,labels,k);
    }
};