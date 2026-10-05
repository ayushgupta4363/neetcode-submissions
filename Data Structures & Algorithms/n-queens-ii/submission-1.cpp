class Solution {
public:
      vector<string> board;
    vector<bool> col, posDiag, negDiag;
    void backtrack(int r, int n, int& res) {
        if (r == n) {
            res++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || posDiag[r + c] || negDiag[r - c + n]) {
                continue;
            }
            col[c] = true;
            posDiag[r + c] = true;
            negDiag[r - c + n] = true;

            backtrack(r + 1, n, res);

            col[c] = false;
            posDiag[r + c] = false;
            negDiag[r - c + n] = false;
        }
    }
    int totalNQueens(int n) {
       
        col.resize(n, false);
        posDiag.resize(2 * n, false);
        negDiag.resize(2 * n, false);
        int res = 0;
        backtrack(0, n, res);
        return res;
    }
};