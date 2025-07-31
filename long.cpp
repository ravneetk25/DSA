class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int l = 0;
        unordered_map<char, int> count;
        int maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            // If more than k replacements needed, shrink the window
            if ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
