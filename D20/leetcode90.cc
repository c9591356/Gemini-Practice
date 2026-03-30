class Solution {
public:
    // startIndex 用來控制「接下來只能從哪個位置之後挑數字」，避免往回挑
    void backtrack(vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& ans) {
        // 1. 收集答案：在這裡，每次進來函式，就直接把目前的 path 塞進 ans！
        ans.push_back(path);
        // 2. 站在當前節點，看看後面還有哪些數字可以選
        for (int i = startIndex; i < nums.size(); i++) {
            // 💡 關鍵剪枝邏輯：如果遇到重複的數字，該怎麼跳過？
            // (請在這裡加上你的剪枝 if 判斷)
            if(i!=startIndex&&nums[i]==nums[i-1])
                continue;
            // --- 經典三步曲 ---
            // 選擇
            path.push_back(nums[i]);
            // 遞迴 (注意傳入的下一層起點是 i + 1)
            backtrack(nums, i+1, path, ans);
            // 撤銷選擇
            path.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        
        // 💡 面試官最愛看的起手式：對付重複元素，第一步永遠是...？
        sort(nums.begin(),nums.end());
        backtrack(nums, 0, path, ans);
        return ans;
    }
};