class Solution {
public:
int n;
int t[50001];
int f(int i,vector<int>&sv){
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
    int score=INT_MIN;
        score=max(score,sv[i]-f(i+1,sv));
        if(i+1<n)score=max(score,sv[i]+sv[i+1]-f(i+2,sv));
        if(i+2<n)score=max(score,sv[i]+sv[i+1]+sv[i+2]-f(i+3,sv));
    return t[i]=score;
}
    string stoneGameIII(vector<int>& stoneValue) {
         n=stoneValue.size();
         memset(t,-1,sizeof(t));
         int score=f(0,stoneValue);
         if(score>0) return "Alice";
         if(score<0) return "Bob";
         return "Tie";
    }
};