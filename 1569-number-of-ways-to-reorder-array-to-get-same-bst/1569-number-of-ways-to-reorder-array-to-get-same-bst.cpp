int M=1e9+7;
class Solution {
public:
vector<long long>f;
void fact(){
f.resize(1002);
f[0]=1;
f[1]=1;
for(int i=2;i<=1000;i++) f[i]=(f[i-1]%M*i%M)%M;
}
long long mod_power(long long a,long long b){
long long res=1;
a%=M;
while(b){
    if(b%2) res=(res*a)%M;
    a=(a*a)%M;
    b/=2;
}
return res;
}
int nCr(int n,int r){
if(r<0 || r>n) return 0;
long long a=f[n];
long long b=(f[r]*f[n-r])%M;
return a*mod_power(b,M-2)%M;
}
long long solve(vector<int>&nums){
    int n=nums.size();
    if(n<3) return 1;
    vector<int>left,right;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[0]) right.push_back(nums[i]);
        else left.push_back(nums[i]);
    }
    long long x=solve(left)%M;
    long long y=solve(right)%M;
    long long z=nCr(n-1,right.size())%M;
    return (((x*y)%M)*z)%M;
}
    int numOfWays(vector<int>& nums) {
        fact();
        long long res=solve(nums)-1;
        return res;
    }
};