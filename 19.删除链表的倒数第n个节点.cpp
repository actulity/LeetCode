/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//     };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while(tmp){
            size++;
            tmp = tmp->next;
        }
        if(head == NULL) return head;
        tmp = head;
        if(size - n == 0) return head->next;
        if(size - n == 1) {
            if(head->next == NULL) return head;
            tmp->next = tmp->next->next;
            return head;
        }
        tmp = head;
        for(int i = 0; i < size - n - 1; ++i){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};
// @lc code=end

