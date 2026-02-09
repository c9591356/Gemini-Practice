//🎯 任務 1：反轉鏈結串列 (Iterative)
//題目描述： 給你看一個單向 Linked List：1 -> 2 -> 3 -> 4 -> 5 -> NULL 請你把它反轉成：5 -> 4 -> 3 -> 2 -> 1 -> NULL
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 封裝成函式，回傳新的頭 (New Head)
ListNode* reverseList(ListNode* head) {
    ListNode *past = NULL;
    ListNode *curr = head; // 習慣上用 curr 代表 current node

    // 使用 while 迴圈處理任意長度，直到 curr 變成 NULL
    while (curr != NULL)
    {
        ListNode *tmp = curr->next; // 1. 暫存下一步
        curr->next = past;          // 2. 轉向
        past = curr;                // 3. past 前移
        curr = tmp;                 // 4. curr 前移
    }
    return past; // past 最後會停在原本的最後一個節點 (New Head)
}

class Solution {
public:
    ListNode* reverseList2(ListNode* head) {
        // 1. Base Case (終止條件)
        // 如果是空 List 或只剩一個節點，它反轉後還是自己，直接回傳
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // 2. 遞迴呼叫 (Leap of Faith)
        // 這一行執行完，我們假設 "head->next" 之後的所有節點都已經反轉好了
        // newHead 會是原本的最後一個節點 (例如 5)，它將是新的頭
        ListNode* newHead = reverseList(head->next);

        // 3. 處理當層邏輯 (關鍵時刻！)
        // 目前狀況： head -> [head->next] -> ... (反轉好的部分) ... -> NULL
        // 我們要讓 [head->next] 指回來 head
        
        // 請填空：讓下一個節點指向自己
        head->next->next = head; 

        // 請填空：斷開原本指向下一個節點的連結 (避免無限迴圈)
        head->next = NULL;

        return newHead;
    }
};

int main(){
    // 建置 List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    for(int i=2;i<=5;i++){
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    // 執行反轉
    ListNode *new_head = reverseList(head);

    // 輸出驗證
    // 預期輸出: 5 4 3 2 1
    cout << "Reversed List: ";
    while(new_head != NULL){
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    
    system("pause");
    return 0;
}