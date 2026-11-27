class Solution {
   
    bool pal[2001][2001];

public:
    

    int minCut(string s) {
        int n = s.size();
        memset(pal, false, sizeof(pal));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        pal[i][j] = true;
                    } else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        vector<int> cut(n);
        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                cut[i] = 0;
                continue;
            }
            int mn = INT_MAX;

            for (int k = 0; k < i; k++) {
                if (pal[k + 1][i]) {
                    mn = min(mn, cut[k] + 1);
                }
            }
            cut[i] = mn;
        }
        return cut[n - 1];
    }

    

}
;