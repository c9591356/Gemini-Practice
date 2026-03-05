class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // prev1 對應上上間 (i-2)，prev2 對應上一間 (i-1)
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]); 
        
        for (int i = 2; i < n; i++) {
            // 狀態轉移方程：max(偷這間 + 上上間的錢, 不偷這間維持上一間的錢)
            int cur = max(prev1 + nums[i], prev2);
            prev1 = prev2; // 窗口滑動
            prev2 = cur;   // 窗口滑動
        }
        
        return prev2;
    }
};