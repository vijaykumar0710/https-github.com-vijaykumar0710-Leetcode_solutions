class Solution {
public:
    void balancing(multiset<int>& mst1, multiset<int>& mst2) {
        if (mst1.size()>0 && mst2.size()>0) {
            if ((int)*mst1.rbegin() > (int)*mst2.begin()) {
                int x = *mst1.rbegin();
                int y = *mst2.begin();
                mst1.erase(mst1.find(x));
                mst2.erase(mst2.find(y));
                mst1.insert(y);
                mst2.insert(x);
            }
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        multiset<int> mst1, mst2;
        int i = 0;
        for (int j = 0; j < n; j++) {
            (int)mst1.size() <= (int)mst2.size() ? mst1.insert(nums[j]) : mst2.insert(nums[j]);
            balancing(mst1, mst2);
            if (j - i + 1 == k) {
                if (k % 2){
                    res.push_back(*mst1.rbegin());
                     if (mst1.find(nums[i]) != mst1.end())
                        mst1.erase(mst1.find(nums[i]));
                    else if (mst2.find(nums[i]) != mst2.end())
                        mst2.erase(mst2.find(nums[i]));
                }
                else {
                    double ans = ((int)*mst1.rbegin() + (!mst2.empty() ? (int)*mst2.begin() : 0.0)) /2.0;
                    res.push_back(ans);
                    if (mst1.find(nums[i]) != mst1.end())
                        mst1.erase(mst1.find(nums[i]));
                    else if (mst2.find(nums[i]) != mst2.end())
                        mst2.erase(mst2.find(nums[i]));
                }
                i++;
            }
        }
        return res;
    }
};