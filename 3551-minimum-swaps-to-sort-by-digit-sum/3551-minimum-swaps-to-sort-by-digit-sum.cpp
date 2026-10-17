class Solution {
public:
int digit_sum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>t;
        for(int i=0;i<n;i++){
            t.push_back({digit_sum(nums[i]),nums[i],i});
        }
        sort(t.begin(),t.end());
        int min_swap=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]||t[i][2]==i) continue;
            int cycle_size=0;
            int j=i;
            while(!visited[j]){
                cycle_size++;
                visited[j]=true;
                j=t[j][2];
            }
            if(cycle_size>1) min_swap+=(cycle_size-1);
        }
        return min_swap;
    }
};