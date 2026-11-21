class Solution {
public:
void dfs1(int u,int par,vector<int>&parent,unordered_map<int,vector<int>>&adj,string &s,vector<int>&seen){
if(seen[s[u]-'a']!=-1){
    parent[u]=seen[s[u]-'a'];
}
int y=seen[s[u]-'a'];
seen[s[u]-'a']=u;
for(auto v:adj[u]){
if(v==par) continue;
dfs1(v,u,parent,adj,s,seen);
}
seen[s[u]-'a']=y;
}
void dfs(int u,int par,vector<int>&subtree,unordered_map<int,vector<int>>&adj1){
for(auto &v:adj1[u]){
    if(v==par) continue;
    dfs(v,u,subtree,adj1);
    subtree[u]+=subtree[v];
}
}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        unordered_map<int,vector<int>>adj;
        vector<int>seen(26,-1);
        for(int i=1;i<parent.size();i++){
         adj[parent[i]].push_back(i);
        }
        dfs1(0,-1,parent,adj,s,seen);
        unordered_map<int,vector<int>>adj1;
        for(int i=1;i<parent.size();i++){
         adj1[parent[i]].push_back(i);
        }
        vector<int>subtree(parent.size(),1);
        dfs(0,-1,subtree,adj1);
        return subtree;
    }
};