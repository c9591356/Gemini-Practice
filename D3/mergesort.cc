class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        // 1. 宣告暫存陣列 (大小只要夠放這一段就好，不用 nums.size())
        vector<int> tmp(right - left + 1);
        
        // 2. 定義三個指標
        int i = left;     // 左半邊的起點
        int j = mid + 1;  // 右半邊的起點
        int k = 0;        // tmp 陣列的寫入點

        // --- 第一階段：兩邊比大小，誰小誰進來 ---
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) { // <= 保持穩定排序 (Stable Sort)
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }

        // --- 第二階段：處理剩下的殘兵敗將 ---
        // 如果左邊還有剩 (右邊先空了)
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }

        // 如果右邊還有剩 (左邊先空了)
        while (j <= right) {
            tmp[k++] = nums[j++];
        }

        // --- 第三階段：把 tmp 抄回原本的 nums ---
        // 注意：nums 的起始點是 left，tmp 的起始點是 0
        for (int p = 0; p < tmp.size(); p++) {
            nums[left + p] = tmp[p];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};