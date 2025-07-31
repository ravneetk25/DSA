class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int> repeat;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(arr[i]==arr[i-1]){
                repeat.push_back(arr[i]);
                i++;
            }
        }
        return repeat;
    }
};