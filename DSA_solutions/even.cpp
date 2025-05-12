class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            int n = digits.size();
            set<int> arr;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (i != j && j != k && k != i) {
                            int a = digits[i];
                            int b = digits[j];
                            int c = digits[k];
    
                            if (a == 0 || c % 2 != 0) {
                                continue;
                            }
                            int result = a * 100 + b * 10 + c;
                            arr.insert(result);
                        }
                    }
                }
            }
            return vector<int>(arr.begin(), arr.end());
            // return arr;
        }
    };