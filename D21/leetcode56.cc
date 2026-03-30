class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        // 善用 range-based for loop，更現代的 C++ 寫法
        for (auto& interval : intervals) {
            // 如果 ans 是空的，或者「現在這個區間的左端點」大於「ans 最後一個區間的右端點」(代表沒重疊)
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval); // 安全放入
            } else {
                // 重疊了！我們直接把 ans 最後一個區間的右端點「拉長」
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};