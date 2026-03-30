#include <stdio.h>
#include <string.h>
void reverse_string(char *s) {
    if (s == NULL) return;

    char *left = s;
    char *right = s;

    // 1. 找尾巴：只要還沒撞到 '\0'，right 就一直往前走
    while (*right != '\0') {
        right++;
    }
    // 撞到 '\0' 了！但我們要交換的是最後一個英文字母，所以要退一步
    right--; 

    // 2. 開始交換：只要 left 還沒跟 right 交會，就繼續換
    while (left < right) {
        // 🤔 換你表現了！請用你說的 tmp，把 *left 和 *right 交換，
        // 並且記得讓 left 往前走，right 往後退！
        
        /* 你的交換程式碼寫在這裡 */
        // 迴圈內的交換邏輯
        char tmp = *left;  // tmp 記住左邊的字母
        *left = *right;    // 右邊的字母丟給左邊
        *right = tmp;      // tmp 丟給右邊

        left++;            // 左指標往右走一步
        right--;           // 右指標往左退一步
    }
}
int main(){
    //printf("100");
    reverse_string("abc");
    //printf("hello");
}