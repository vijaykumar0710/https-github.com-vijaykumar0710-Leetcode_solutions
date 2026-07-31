class Solution {
public:
    typedef int long long;
    const int M = 1e9 + 7;
    typedef vector<vector<int>> Matrix;
    Matrix multiply(Matrix& A, Matrix& B) {
        int k = A.size();
        Matrix C(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int x = 0; x < k; x++) {
                    int pro = (A[i][x] * B[x][j]) % M;
                    C[i][j] = (C[i][j] + pro) % M;
                }
            }
        }
        return C;
    }

    Matrix pow(Matrix& T, int p) {
        int k = T.size();
        Matrix res(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
            res[i][i] = 1;
        while (p) {
            if (p & 1)
                res = multiply(res, T);
            T = multiply(T, T);
            p >>= 1;
        }
        return res;
    }
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        int k = 2;
        Matrix T = {{1, 1}, {1, 0}};
        vector<int> S1 = {1, 0};
        Matrix T_pow = pow(T, n - 1);
        int res = 0;
        for (int i = 0; i < k; i++) {
            int term = T_pow[0][i] * S1[i];
            res = (res + term) % M;
        }
        return res;
    }
};