#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // 請在此完成實作
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL)
        {
            /* 先找到中心 */
            fast = fast->next->next;
            
            slow = slow->next;
        }
        //slow即為中心並且她會是答案最尾巴，所以從這裡開始倒轉
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL; 
        while (curr != NULL) {
            ListNode* next_temp = curr->next;

            curr->next=prev;

            prev = curr;
            curr = next_temp;
        }
        /* 這時prev會變後半段的頭 */
        while (prev!=NULL)
        {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = prev->next;
            head->next = prev;
            prev->next = tmp1;
            prev = tmp2;
            head = tmp1;
        }
        


        
    }
};