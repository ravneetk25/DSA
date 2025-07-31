class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int mc=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1) count++;
            else{
                count=0;
            }
            mc=max(mc, count);
        }
        return mc;
    }
};