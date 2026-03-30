class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // 我們渴望找的「另一半」
            
            // 如果在之前的記錄中找到了另一半
            if (mp.find(complement) != mp.end()) {
                // 直接回傳 {另一半的 Index, 自己的 Index}
                return {mp[complement], i}; 
            }
            // 沒找到，就把自己記錄下來，等待後面的數字來找我
            mp[nums[i]] = i; 
        }
        return {}; 
    }
};