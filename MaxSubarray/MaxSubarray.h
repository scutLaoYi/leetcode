class Solution {
    public:
        int maxSubArray(int A[], int n) {
            if (!n) return 0;
            int maxSum, curSum;
            maxSum = curSum = A[0];
            for(int i = 1; i != n; ++i) {
                if (curSum > 0) {
                    curSum += A[i];
                } else {
                    curSum = A[i];
                }
                if (curSum > maxSum) {
                    maxSum = curSum;
                }
            }
            return maxSum;
        }
};
