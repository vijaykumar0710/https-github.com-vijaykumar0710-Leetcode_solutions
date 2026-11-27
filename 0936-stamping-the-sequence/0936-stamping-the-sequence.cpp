class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int k = stamp.size();
        string s;
        for (int i = 0; i < k; i++)
            s += '?';
        vector<int> res;
        while (true) {
            bool flag = false;
            for (int i = 0; i <= n - k; i++) {
                string st = target.substr(i, k);
                if (st != s) {
                    bool fl = true;
                    for (int j = 0; j < k; j++) {
                        if (st[j] == '?')
                            continue;
                        else if (st[j] != stamp[j])
                            fl = false;
                    }
                    if (fl) {
                        flag = true;
                        res.push_back(i);
                        for (int j = i; j < i + k; j++)
                            target[j] = '?';
                    }
                }
            }
            if (!flag)
                break;
        }
        for (int j = 0; j < n; j++) {
            if (target[j] != '?')
                return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};