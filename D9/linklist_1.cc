#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        // 1. 備份：先把 curr 的下一個節點記下來，不然等一下線條切斷就找不到了
        ListNode* next_temp = curr->next;

        // 2. 叛變：把 curr 的箭頭反轉，指向前面的節點 (prev)
         curr->next=prev;

        // 3. 前進：大軍往前推進一格
        // 把 prev 移到 curr 的位置
        // 把 curr 移到 next_temp 的位置
        prev = curr;
        curr = next_temp;
    }
    
    // 當 curr 跑到 NULL 時，prev 剛好會停在原本的最後一個節點 (新的頭)
    return prev;
}