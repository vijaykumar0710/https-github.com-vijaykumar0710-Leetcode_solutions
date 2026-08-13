class Solution {
public:
    struct Node {
        int max_len;
        int pref_len;
        int suff_len;
        int size;
        char pref_char;
        char suff_char;
    };
    vector<Node> tree;
    string str;
    Node merge(Node& left, Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;
        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.suff_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }
        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.pref_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }
        return res;
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, str[start], str[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, ch, ch};
            str[idx] = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    vector<int> longestRepeating(string s, string queryCharacters,vector<int>& queryIndices) {
        int n = s.length();
        int k = queryCharacters.length();
        str = s;
        tree.resize(4 * n);
        build(1, 0, n - 1);
        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].max_len);
        }
        return ans;
    }
};