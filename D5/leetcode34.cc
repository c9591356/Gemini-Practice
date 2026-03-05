class Solution {
public:
    // 輔助函式：找邊界
    // isFirst = true  -> 找第一個 (往左縮)
    // isFirst = false -> 找最後一個 (往右縮)
    int searchBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int bound = -1; // 暫存答案

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; // 先記下來，可能是答案
                if (isFirst) {
                    right = mid - 1; // 繼續往「左」找，看有沒有更前面的
                } else {
                    left = mid + 1;  // 繼續往「右」找，看有沒有更後面的
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bound;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = searchBound(nums, target, true);  // 找左邊界
        
        // 如果連左邊界都找不到，那就是沒有，直接回傳 [-1, -1]
        if (first == -1) return {-1, -1};
        
        int last = searchBound(nums, target, false); // 找右邊界
        
        return {first, last};
    }
};