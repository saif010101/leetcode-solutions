/*
  Basic Idea is to do Merge Sort but for linked lists
  In Merge Sort, we basically keep dividing the list in half until we get a single node then we use the logic of merging two sorted linked lists and 
  merge linked list from bottom to top

  lets say if we have 8->2->3->1->9->0

  in first step we have left = 8->2->3 , right = 1->9->0
  in second step we have left = 8, right = 2->3,     left = 1, right = 9->0
  in third step we have left = 2, right = 3          left = 9, right = 0;

  from bottom to top
  left = 2->3  , right = 0->9
  left = 2->3->8, right = 0->1->9
  finally 0->1->2->3->8->9
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeLists(ListNode* l1,ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        if (l1->val < l2->val)
        {
            l1->next = mergeLists(l1->next,l2);
            return l1;
        }

        else
        {
            l2->next = mergeLists(l1,l2->next);
            return l2;
        }
    }

    ListNode* sortList(ListNode* head) {

        // keep splitting until we have a single node i.e head->next == NULL
        // or if list was intitially empty return NULL
        if (head == NULL || head->next == NULL)
            return head;

        // use slow and fast pointers to find mid and split into left and right
        ListNode *slow = head,*fast = head->next;

        // finding middle node logic
        while (fast && fast->next)
        {
            slow = slow ->next;
            fast = fast->next->next;
        }

        
        // split lists into left and right
        ListNode *left = head,*right = slow->next;
        slow->next = NULL;

        // sort left and sort right then merge
        left = sortList(left);
        right = sortList(right);

        // return merged list
        return mergeLists(left,right);
        
    }
};
