class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] == 0) zeros++;

            while (zeros > k) {
                if (arr[left] == 0) zeros--;
                left++;  // shrink the window
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
