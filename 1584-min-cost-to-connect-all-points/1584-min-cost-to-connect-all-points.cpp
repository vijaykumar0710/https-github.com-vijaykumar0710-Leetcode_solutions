class Solution {
public:
vector<int>parent,rank;
int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
}
void Union(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);
    if(parent_x==parent_y) return;
    if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
    else if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
    else{
        parent[parent_x]=parent_y;
        rank[parent_y]++;
    }
}
int kruskal_algo(vector<vector<int>>&vec){
int totalCost=0;
for(auto &temp:vec){
int u=temp[0];
int v=temp[1];
int cost=temp[2];
  int parent_u=find(u);
  int parent_v=find(v);
  if(parent_u!=parent_v){
    Union(u,v);
    totalCost+=cost;
  }
  }
  return totalCost;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
       vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
              vec.push_back({i,j,cost});
              vec.push_back({j,i,cost});
            }
        }
      sort(vec.begin(),vec.end(),[](auto &a,auto &b){
         return a[2]<b[2];
      });
        return kruskal_algo(vec);
    }
};