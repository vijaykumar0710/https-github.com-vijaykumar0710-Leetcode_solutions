class Solution {
public:
int max_num(int n){
    priority_queue<int>pq;
    while(n){
        pq.push(n%10);
        n/=10;
    }
    int num=0;
    while(!pq.empty()){
        num=num*10+pq.top();
        pq.pop();
    }
    return num;
}
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int num=max_num(nums[i]);
            pq.push(num-nums[i]);
        }
        while(!pq.empty() && k>0){
            sum+=pq.top();
            pq.pop();
            k--;
        }
        return sum;
    }
};