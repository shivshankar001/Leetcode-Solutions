class Solution {
public:
    int n;
    int k;
    int arr[31];
    int dp[31][31];
    int prefixSum[31];

    void pre() {
        prefixSum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
    }

    int rec1(int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int minCost = 1e9;
        for (int mid = 0; mid + i < j; mid += k - 1) {
            int mergeCost = rec1(i, i + mid);
            minCost = min(minCost, mergeCost + rec1(i + mid + 1, j));
        }
        int mergeRangeCost = 0;
        if ((i - j) % (k - 1) == 0) {
            mergeRangeCost = prefixSum[j + 1] - prefixSum[i];
        }
        return dp[i][j] = mergeRangeCost + minCost;
    }

    int mergeStones(vector<int>& stones, int K) {
        n=stones.size();
        k=K;
        if ((n-1) % (k-1) != 0) return -1;
        for (int i = 0; i < n; ++i) {
            arr[i]=stones[i];
        }
        pre();
        memset(dp, -1, sizeof(dp));
        return rec1(0,n-1);
    }
};