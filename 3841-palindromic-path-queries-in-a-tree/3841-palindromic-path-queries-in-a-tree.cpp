class Solution {
    int t;
    vector<vector<int>>up;
    vector<int>in,out,b;
    void add(int i,int v){
    for(;i<b.size();i+=i&-i) b[i]^=v;    
    }
    void upd(int l,int r,int v){
        add(l,v);
        add(r+1,v);
    }

    int qry(int i){
        int r=0;
        for(;i>0;i-=i&-i) r^=b[i];
        return r;
    }

    void dfs(int u,int p,vector<vector<int>>&g){
        in[u]=++t;
        up[u][0]=p;
        for(int i=1;i<20;i++){
            up[u][i]=up[up[u][i-1]][i-1];
        }
        for(int v:g[u]){
            if(v!=p) dfs(v,u,g);
        }
        out[u]=t;
    }

    bool anc(int u,int v){
        return in[u]<=in[v]&&out[u]>=out[v];
    }

    int lca(int u,int v){
        if(anc(u,v)) return u;
        if(anc(v,u)) return v;
        for(int i=19;i>=0;i--)
            if(!anc(up[u][i],v)) u=up[u][i];
            return up[u][0];
    }
    public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>>g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        in.assign(n,0);
        out.assign(n,0);
        up.assign(n,vector<int>(20,0));
        b.assign(n+2,0);
        dfs(0,0,g);
        for(int i=0;i<n;i++){
            upd(in[i],out[i],1<<(s[i]-'a'));
        }
        vector<bool>res;
        for(auto &q:queries){
            stringstream ss(q);
            string op;
            ss>>op;
            if(op[0]=='u'){
                int u;char c;
                ss>>u>>c;
                int d=(1<<(s[u]-'a'))^(1<<(c-'a'));
                upd(in[u],out[u],d);
                s[u]=c;
            }else{
                int u,v;
                ss>>u>>v;
                int l=lca(u,v);
                int m=qry(in[u])^qry(in[v])^(1<<(s[l]-'a'));
                res.push_back((m&(m-1))==0);
            }
        }
        return res;
    }
};