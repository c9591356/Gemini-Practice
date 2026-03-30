/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur_copy;
        Node* cur = head;
        unordered_map<Node*,Node*> mp;
        while(cur!=NULL){
            cur_copy = new Node(cur->val);
            mp[cur] = cur_copy;
            cur = cur->next;
        }
        cur = head;
        while(cur!=NULL){
            Node* tmp = mp[cur];
            tmp->next = mp[cur->next];
            tmp->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};