class Solution {
public:
int RD[2][2]={{0,1},{1,0}};
int LU[2][2]={{0,-1},{-1,0}};
long long EC(int r,int c) {return (long long)(r+1)*(c+1);}
void costfn(long long curr_cost,long long penalty_cost,int n_r,int n_c,int next_p,int m,int n,vector<vector<vector<long long>>>&dist,priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>&pq){
long long new_cost=curr_cost+penalty_cost;
if(new_cost<dist[n_r][n_c][next_p]){
    dist[n_r][n_c][next_p]=new_cost;
    pq.push({new_cost,n_r,n_c,next_p});
  }
}

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>>dist(m,vector<vector<long long>>(n,vector<long long>(2,LLONG_MAX)));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        dist[0][0][1]=EC(0,0);
        pq.push({dist[0][0][1],0,0,1});
        while(!pq.empty()){
            vector<long long>curr=pq.top();
            pq.pop();
            long long curr_cost=curr[0];
            int r=curr[1],c=curr[2],p=curr[3];
            if(r==m-1 && c==c-1) return curr_cost;
            int next_p=1-p;
            long long curr_penalty=penalty[r][c];
            // Wait
            costfn(curr_cost,curr_penalty,r,c,next_p,m,n,dist,pq); 
            // Right/Down
            for(auto &d:RD){
                int n_r=d[0]+r,n_c=d[1]+c;
                if(n_r>=0 && n_r<m && n_c>=0 && n_c<n){
                    long long cost=EC(n_r,n_c)+(p==1?0:curr_penalty);
                    costfn(curr_cost,cost,n_r,n_c,next_p,m,n,dist,pq); 
                }
            }
            //Left/Up
            for(auto &d:LU){
                int n_r=d[0]+r,n_c=d[1]+c;
                if(n_r>=0 && n_r<m && n_c>=0 && n_c<n){
                    long long cost=EC(n_r,n_c)+(p==0?0:curr_penalty);
                    costfn(curr_cost,cost,n_r,n_c,next_p,m,n,dist,pq); 
                }
            }
        }
        return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }
};