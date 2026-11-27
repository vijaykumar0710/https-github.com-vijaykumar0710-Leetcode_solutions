class Solution {
public:
int t[1001][1501];
unordered_map<int,int>mp;
int mini_price=INT_MAX;
int fn(int i,vector<vector<int>>& items, int budget,int n){
    if(i>=n) return budget/mini_price;
    if(t[i][budget]!=-1) return t[i][budget];
    int op1=fn(i+1,items,budget,n);
    int op2=0;
    if(budget-items[i][1]>=0)op2=mp[i]+fn(i+1,items,budget-items[i][1],n);
    return t[i][budget]=max(op1,op2);
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        for(int i=0;i<n;i++){
            mini_price=min(mini_price,items[i][1]);
            for(int j=0;j<n;j++){
                if((items[j][0]%items[i][0])==0) mp[i]++;
            }
        }
        memset(t,-1,sizeof(t));
        return fn(0,items,budget,n);
    }
};