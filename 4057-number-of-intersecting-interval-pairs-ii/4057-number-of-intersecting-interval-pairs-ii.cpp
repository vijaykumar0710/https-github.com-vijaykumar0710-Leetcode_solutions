class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        long long res=0;
        for(int i=0;i<n-1;i++){
            int j=-1;
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(intervals[i][1]>=intervals[mid][0]){
                    j=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            if(j!=-1) res=(res+j-i);
        }
        return res;
    }
};