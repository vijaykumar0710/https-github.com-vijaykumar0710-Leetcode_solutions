const int MOD = 1e9 + 7;
struct Node {
    long long sum_d;   
    long long sum_d2;  
    long long lazy;    
};
vector<Node> tree;
int N;
void push(int node, int start, int end) {
    if (tree[node].lazy == 0) return;
    long long val = tree[node].lazy;
    long long len = end - start + 1;
    tree[node].sum_d = (tree[node].sum_d + len * val) % MOD;
    long long old_sum_d = (tree[node].sum_d - len * val + MOD) % MOD;
    tree[node].sum_d2 = (tree[node].sum_d2 + 2 * val % MOD * old_sum_d % MOD + len % MOD * val % MOD * val % MOD) % MOD;
    if (start != end) {
        tree[node*2].lazy = (tree[node*2].lazy + val) % MOD;
        tree[node*2+1].lazy = (tree[node*2+1].lazy + val) % MOD;
    }
    tree[node].lazy = 0;
}
void update_range(int node, int start, int end, int l, int r, long long val) {
    push(node, start, end);
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        tree[node].lazy = (tree[node].lazy + val) % MOD;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update_range(node*2, start, mid, l, r, val);
    update_range(node*2+1, mid+1, end, l, r, val);
    tree[node].sum_d = (tree[node*2].sum_d + tree[node*2+1].sum_d) % MOD;
    tree[node].sum_d2 = (tree[node*2].sum_d2 + tree[node*2+1].sum_d2) % MOD;
}
long long query_d2(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (start > end || start > r || end < l) return 0;
    if (l <= start && end <= r) return tree[node].sum_d2;
    int mid = (start + end) / 2;
    long long left = query_d2(node*2, start, mid, l, r);
    long long right = query_d2(node*2+1, mid+1, end, l, r);
    return (left + right) % MOD;
}
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        N = nums.size();
        tree.assign(4*N, {0,0,0});
        long long total_sum = 0;
        unordered_map<int,int> last_seen;
        for (int j = 0; j < N; j++) {
            int p = -1;
            if (last_seen.count(nums[j])) p = last_seen[nums[j]];
            update_range(1, 0, N-1, p+1, j, 1);
            long long cur_sum_d2 = query_d2(1, 0, N-1, 0, j);
            total_sum = (total_sum + cur_sum_d2) % MOD;

            last_seen[nums[j]] = j;
        }
        return (int)total_sum;
    }
};