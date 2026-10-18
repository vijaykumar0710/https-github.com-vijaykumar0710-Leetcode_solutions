class Solution {
public:
bool isValid(char a,char b){
    return (a=='R'&&b=='B' || a=='B'&&b=='W' || a=='W'&&b=='R');
}
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int>deg(n,0),indeg(n,0);
        for(auto e:edges){
           int u=e[0],v=e[1];
           if(colors[u]==colors[v]) return -1;
           deg[u]++,deg[v]++; 
           if(isValid(colors[u],colors[v])) indeg[v]++;
           else indeg[u]++;
        }
       int root=-1;
       for(int i=0;i<n;i++){
        if(indeg[i]>1) return -1;
        if(indeg[i]==0){
            root=i;
            if(deg[i]>2) return -1;
        }
       }
       return root;
    }
};