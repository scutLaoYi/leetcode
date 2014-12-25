/**
  Definition for singly-linked list.
**/
#include <cmath>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
    public:
        int listLength(ListNode *head) {
            if (!head) {
                return 0;
            }
            int size = 1;
            while (head->next) {
                ++size;
                head = head->next;
            }
            return size;
        }

        ListNode *listElement(ListNode *head, int position) {
            for (int p = 1; p < position; ++p) {
                if (!head) {
                    return 0;
                }
                head = head->next;
            }
            return head;
        }

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int mergePoint = listLength(headA) - listLength(headB);
            if (mergePoint > 0) {
                headA = listElement(headA, mergePoint+1);
            } else {
                headB = listElement(headB, -mergePoint+1);
            }
            while(headA) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
            return 0;

        }
};
