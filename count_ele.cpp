class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n= nums.size();
        if(k>=n) return 0;
        if(k==0) return n;
        vector<int> temp= nums;
        sort(temp.begin(), temp.end());
        int ans=0;
        for(int nums: nums){
            auto it= upper_bound(temp.begin(), temp.end(), nums);
            int count= temp.end()-it;
            if(count>=k){
                ans++;
            }
        }
        return ans;
        
    }
};