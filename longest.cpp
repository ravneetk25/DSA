class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i]<= nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, left[i]);
            int length = 0;

            if (i == 0) {
                length = right[i + 1]; 
            }
            else if(i == n - 1){
                length = left[i - 1];
            }
            else {
                if (nums[i - 1] <= nums[i + 1])
                    length = left[i - 1] + right[i + 1];
                else{
                    length = max(left[i - 1], right[i + 1]);
                }
            }

            maxLen = max(maxLen, length + 1); 
        }

        return maxLen;
    }
}