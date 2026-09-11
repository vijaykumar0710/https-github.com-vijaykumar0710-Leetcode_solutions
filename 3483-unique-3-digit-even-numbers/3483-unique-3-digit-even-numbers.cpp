class Solution {
public:
    void solve(int num, int count, vector<int>& digits, vector<bool>& visited,
               unordered_set<int>& uniqueNums) {
        if (count == 3) {
            if (num % 2 == 0) {
                uniqueNums.insert(num);
            }
            return;
        }
        for (int i = 0; i < digits.size(); i++) {
            if (!visited[i]) {
                if (count == 0 && digits[i] == 0)
                    continue;
                visited[i] = true;
                solve(num * 10 + digits[i], count + 1, digits, visited, uniqueNums);
                visited[i] = false;
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNums;
        vector<bool> visited(digits.size(), false);
        solve(0, 0, digits, visited, uniqueNums);
        return uniqueNums.size();
    }
};