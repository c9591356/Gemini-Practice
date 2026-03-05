#include<iostream>
#include<vector>
using namespace std;

// 交換函式 (幫你寫好了)
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

/*
 * arr: 陣列
 * low: 起點 index
 * high: 終點 index (也是 pivot 的位置)
 * 回傳值: pivot 最終排在哪個位置 (index)
 */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 1. 選最後一個當大哥 (70)
    
    // i 負責守住「小於區」的邊界
    // 一開始小於區是空的，所以 i 在起點的前一格
    int i = (low - 1);     

    // j 是斥候，負責從頭掃描到尾 (不包含最後一個 pivot)
    for (int j = low; j <= high - 1; j++) {
        
        // 如果目前的數 (arr[j]) 比大哥小...
        if (arr[j] < pivot) {
            // 2. 請填空：
            // 我們要把這個小的數，丟到「小於區」
            // 步驟 A: 把小於區的邊界 (i) 往右擴張一格
            
            i++;
            // 步驟 B: 把發現的這個小數 (arr[j]) 跟邊界上的數 (arr[i]) 交換
            swap(&arr[j],&arr[i]);
        }
    }
    
    // 3. 掃描結束後，把大哥 (arr[high]) 換到「小於區」的下一個位置 (i+1)
    // 這樣大哥就會剛好站在中間
    swap(&arr[i + 1], &arr[high]);
    
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    // 終止條件：如果陣列只剩下一個元素，或是不存在，就不用排了
    if (low < high) {
        
        // 1. 找大哥的位置，順便把陣列分成兩半
        int pi = partition(arr, low, high);

        // 2. 遞迴排序「左半邊」
        // 請問左半邊的範圍是從哪裡到哪裡？
        quickSort(arr,low,pi-1);

        // 3. 遞迴排序「右半邊」
        // 請問右半邊的範圍是從哪裡到哪裡？
        quickSort(arr,pi+1,high);
    }
}