class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_set<int>st1,st2,st3;
        for(int i=2;i<=5;i++) st1.insert(i);
        for(int i=4;i<=7;i++) st2.insert(i);
        for(int i=6;i<=9;i++) st3.insert(i);
        map<int,vector<int>>mp;
        int res=0,max_row=0;
        for(auto rs:reservedSeats) mp[rs[0]].push_back(rs[1]),max_row=max(max_row,rs[0]);
        int row=1;
        for(auto [r,vec]:mp){
            if(r-row>0) res+=2*(r-row);
            row=r+1;
            bool f1=true;
            bool f2=true;
            bool f3=true;
            for(auto x:vec){
                if(st1.count(x)) f1=false;
                if(st2.count(x)) f2=false;
                if(st3.count(x)) f3=false;
            }
            if(f1 && f3) res+=2;
            else if(f1) res++;
            else if(f2) res++;
            else if(f3) res++;
        }
       if(max_row<n) res+=(2*(n-max_row));
       return res;
    }
};