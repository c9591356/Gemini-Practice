class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2];
        if(nums.size()==1)
            return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        int cur=dp[1];
        for(int i=2;i<nums.size();i++){
            cur = max(dp[1],dp[0]+nums[i]);
            dp[0] = dp[1];
            dp[1] = cur;
        }
        return cur;

    }
};