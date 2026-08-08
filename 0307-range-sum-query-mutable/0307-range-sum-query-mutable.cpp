class NumArray {
public:
    vector<int> vec;
    vector<int> BIT;
    int n;
    void updatefn(int i, int val) {
        for (; i <= n; i += (i & -i))
            BIT[i] += val;
    }
    int queryfn(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & -i))
            sum += BIT[i];
        return sum;
    }

    NumArray(vector<int>& nums) {
        vec = nums;
        n = nums.size();
        BIT.assign(n + 1,0);
        for(int i=0;i<n;i++) updatefn(i+1,nums[i]);
    }

    void update(int index, int val) {
        updatefn(index+1,val-vec[index]);
        vec[index]=val;
    }

    int sumRange(int left, int right) {
        return queryfn(right+1)-queryfn(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */