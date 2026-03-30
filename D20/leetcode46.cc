class Solution {
public:
    // nums: 原始陣列, path: 目前的排列, used: 數字是否用過的標記, ans: 最終答案
void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& ans) {
    // 終止條件：如果盒子裝滿了 (收集到一個完整的排列)
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }
    
    // 站在當前的盒子前，看著手上所有的牌 (跑一個迴圈)
    for (int i = 0; i < nums.size(); i++) {
        // 如果這張牌已經在盒子裡了，跳過！
        if (used[i] == true) continue;
        
        // --- 下面這三步是回溯法的絕對核心 ---
        
        // 1. 做選擇 (把牌放進盒子，標記為已使用)
        path.push_back(nums[i]);
        used[i] = true;
        
        // 2. 遞迴進入下一層 (走向下一個盒子)
        backtrack(nums, path, used, ans);
        
        // 3. 撤銷選擇 / 回溯 (把牌從盒子拿出來，準備換下一張牌試試看)
        path.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(),false);
        vector<int> path;
        backtrack(nums,path,used,ans);
        return ans;
    }
};