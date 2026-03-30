class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ASCII 碼只有 128 個，直接開陣列記錄每個字元「上一次出現的 index」，初始為 -1
        vector<int> dict(128, -1); 
        int max_len = 0;
        int left = 0; // 窗口的左邊界
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            // 如果這個字元曾經出現過，而且在我們當前的窗口內 (>= left)
            if (dict[c] >= left) {
                // 左邊界直接縮小到「重複字元的下一個位置」
                left = dict[c] + 1;
            }
            
            // 更新這個字元最新出現的 index
            dict[c] = right;
            
            // 計算當前窗口長度，並更新最大值
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};