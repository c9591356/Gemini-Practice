#include<iostream>
#include<vector>
using namespace std;
/*
 * arr: 陣列
 * n: 陣列的總長度 (用來檢查小孩有沒有超出邊界)
 * i: 目前要往下檢查的老爸 index
 */
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // 一開始預設老爸 (i) 是最大的
    int left = 2 * i + 1;  // 左小孩的 index
    int right = 2 * i + 2; // 右小孩的 index

    // 1. 如果左小孩存在 (沒超出陣列)，而且比目前最大的還要大
    if (left < n && arr[left] > arr[largest]) {
        largest = left; // 更新最大值的位置
    }

    // 2. 請填空：如果右小孩存在 (沒超出陣列)，而且比目前最大的還要大
    if (right < n && arr[right] > arr[largest]) {
        largest = right; // 更新最大值的位置
    }

    // 3. 如果最大的不是老爸自己 (代表老爸被比下去了)
    if (largest != i) {
        // 把老爸跟最大的那個小孩交換
        swap(arr[i], arr[largest]);

        // 4. 請填空：老爸沉下去了，針對他新落腳的位置 (largest)，繼續遞迴往下檢查
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 階段 1. Build Max-Heap (把亂序陣列變成 Max-Heap)
    // 提示：從最後一個老爸 (n / 2 - 1) 開始，一路往回遞減到 Root (0)
    for (int i = n/2-1;i >= 0;i--) {
        heapify(arr,n,i);
    }

    // 階段 2. 排序 (把最大的 Root 拔出來放後面)
    // i 代表目前 Heap 尚未排好的「最後一個位置」
    for (int i = n - 1; i > 0; i--) {
        // A. 把最大的 root (在 index 0) 丟到目前 Heap 的最後面 (在 index i)
        swap(arr[i],arr[0]);

        // B. 陣列尾端已經排好最大的了，所以 heap 範圍縮小，長度變成 i。
        // 把剛剛換上來、不太合格的新 root (在 index 0) 重新沉下去！
        heapify(arr,i, 0); 
    }
}