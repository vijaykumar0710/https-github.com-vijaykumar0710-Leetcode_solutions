class Solution {
public:
    struct Node {
        int total_prod;
        int pref_cnt[105]; 
        Node() {
            total_prod = 1;
            memset(pref_cnt, 0, sizeof(pref_cnt));
        }
    };
    int k_mod;
    vector<Node> tree;
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.total_prod = (left.total_prod * right.total_prod) % k_mod;
        for (int i = 0; i < k_mod; i++) {
            res.pref_cnt[i] += left.pref_cnt[i];
        }
        for (int i = 0; i < k_mod; i++) {
            if (right.pref_cnt[i] > 0) {
                int new_mod = (left.total_prod * i) % k_mod;
                res.pref_cnt[new_mod] += right.pref_cnt[i];
            }
        }
        return res;
    }
    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % k_mod;
            tree[node].total_prod = val;
            tree[node].pref_cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            val = val % k_mod;
            tree[node].total_prod = val;
            memset(tree[node].pref_cnt, 0, sizeof(tree[node].pref_cnt));
            tree[node].pref_cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    Node queryRange(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return queryRange(2 * node + 1, start, mid, l, r);
        } else if (l > mid) {
            return queryRange(2 * node + 2, mid + 1, end, l, r);
        } else {
            Node left_res = queryRange(2 * node + 1, start, mid, l, r);
            Node right_res = queryRange(2 * node + 2, mid + 1, end, l, r);
            return merge(left_res, right_res);
        }
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        k_mod = k;
        tree.assign(4 * n, Node()); 
        build(0, 0, n - 1, nums);
        vector<int> result;
        result.reserve(queries.size()); 
        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            update(0, 0, n - 1, index, value);
            Node res_node = queryRange(0, 0, n - 1, start, n - 1);
            result.push_back(res_node.pref_cnt[x]);
        }
        return result;
    }
};