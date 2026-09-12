typedef long long ll;
ll t[50001][5];
vector<int> path[50001][5];
class Solution {
public:
    vector<vector<int>> intervals;
    vector<pair<vector<int>, int>> arr;
    vector<int> nxt; 
    int binary_search_next(int i, int val) {
        int l = i, r = intervals.size() - 1, idx = intervals.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] > val) {
                idx = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return idx;
    }
    ll f(int i, int n, int cnt) {
        if (i >= n || cnt == 4)
            return 0;
        if (t[i][cnt] != -1)
            return t[i][cnt];
        int next_idx = nxt[i];
        // take
        ll take = (ll)intervals[i][2] + f(next_idx, n, cnt + 1);
        vector<int> take_path = {arr[i].second};
        take_path.insert(take_path.end(), path[next_idx][cnt + 1].begin(),
                         path[next_idx][cnt + 1].end());
        // skip
        ll skip = f(i + 1, n, cnt);
        vector<int> skip_path = path[i + 1][cnt];

        sort(take_path.begin(), take_path.end());
        sort(skip_path.begin(), skip_path.end());

        if (take > skip) {
            t[i][cnt] = take;
            path[i][cnt] = take_path;
        } else if (skip > take) {
            t[i][cnt] = skip;
            path[i][cnt] = skip_path;
        } else {
            if (take_path < skip_path) {
                t[i][cnt] = take;
                path[i][cnt] = take_path;
            } else {
                t[i][cnt] = take;
                path[i][cnt] = skip_path;
            }
        }
        return t[i][cnt];
    }

    vector<int> maximumWeight(vector<vector<int>>& in) {
        int n = in.size();
        arr.clear();
        for (int i = 0; i < n; i++)
            arr.push_back({in[i], i});
        sort(arr.begin(), arr.end());

        intervals.resize(n);
        for (int i = 0; i < n; i++)
            intervals[i] = arr[i].first;

        nxt.resize(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = binary_search_next(i + 1, intervals[i][1]);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                path[i][j].clear();
            }
        }
        memset(t, -1, sizeof(t));
        f(0, n, 0);
        return path[0][0];
    }
};