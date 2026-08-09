class Solution {
public:
unordered_set<int>st;
vector<int>parent,rank;
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void Union(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);
    if(parent_x==parent_y) return;
    if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
    else if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
    else{
        parent[parent_y]=parent_x;
        rank[parent_x]++;
    }
}
int kruskal_algo_1(vector<vector<int>>&edges,int n){
    int m=edges.size();
    int sum=0,edge_count=0;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        int idx=edges[i][3];
        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u!=parent_v){
            Union(u,v);
            sum+=wt;
            edge_count++;
            st.insert(idx);
        }
    }
    return (edge_count==n-1)?sum:INT_MAX;
}
int kruskal_algo_2(vector<vector<int>>&edges,int remove_edge,int n){
    int m=edges.size();
    int sum=0,edge_count=0;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        int idx=edges[i][3];
        if(idx==remove_edge) continue;
        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u!=parent_v){
            Union(u,v);
            sum+=wt;
            edge_count++;
        }
    }
    return (edge_count==n-1)?sum:INT_MAX;
}
int kruskal_algo_3(vector<vector<int>>&edges,int n,int force_edge_index){
    int m=edges.size();
    int sum=0,edge_count=0;
        int u = edges[force_edge_index][0];
        int v = edges[force_edge_index][1];
        int wt = edges[force_edge_index][2];
        if(find(u)!=find(v)){
            Union(u,v);
            sum+=wt;
            edge_count++;
        }
    for(int i=0;i<m;i++){
        if(i==force_edge_index) continue;
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        int idx=edges[i][3];
        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u!=parent_v){
            Union(u,v);
            sum+=wt;
            edge_count++;
        }
    }
    return (edge_count==n-1)?sum:INT_MAX;
}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
       edges[i].push_back(i);  // Add original index
      }
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
             return a[2]<b[2];
        });
        // minimum spannig sum initial
        rank.assign(n,0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        int mini_span=kruskal_algo_1(edges,n);

        vector<vector<int>>res;
        vector<int>temp1;
        vector<int>temp2;
        unordered_set<int>critical_set; //for pseudo-critical check

          // MST for critical edges
        for(int i=0;i<edges.size();i++){
           rank.assign(n,0);
          for(int j=0;j<n;j++) parent[j]=j;
           int span=kruskal_algo_2(edges,edges[i][3],n);
           if(mini_span<span){
            temp1.push_back(edges[i][3]);
            critical_set.insert(edges[i][3]);
           }
        }

        //MST for pseudo-critical edges
    for (int i = 0; i < edges.size(); i++) {
    if(critical_set.count(edges[i][3])) continue;
    rank.assign(n,0);
    for(int j=0;j<n;j++) parent[j]=j;
    int span = kruskal_algo_3(edges,n,i);
    if (span == mini_span) {
        temp2.push_back(edges[i][3]);
    }
}
        res.push_back(temp1);
        res.push_back(temp2);
        return res;
    }
};