class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<long long> busyUntil(n, 0);
        vector<int> ans(m);
        long long time = 0;
        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);
            int index = -1;
            while (index == -1) {
                for (int i = 0; i < n; i++) {
                    if (busyUntil[i] <= time) {
                        if (index == -1 ||
                            servers[i] < servers[index] ||
                            (servers[i] == servers[index] && i < index)) {
                            index = i;
                        }
                    }
                }
                if (index == -1) {
                    time = *min_element(busyUntil.begin(), busyUntil.end());
                }
            }
            ans[j] = index;
            busyUntil[index] = time + tasks[j];
        }
        return ans;
    }
};