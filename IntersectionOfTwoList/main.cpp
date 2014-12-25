#include <iostream>
#include <string>
#include "Intersection.h"

using namespace std;

void unitTest()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution solution;

    if (2 == solution.listLength(head)) {
        if (1 == solution.listLength(head->next)) {
            if (0 == solution.listLength(head->next->next)) {
                cout<<"length ok"<<endl;
            }
        }
    }
    
    ListNode *p1 = solution.listElement(head, 1);
    ListNode *p2 = solution.listElement(head, 2);
    ListNode *pn = solution.listElement(head, 3);
    if (1 == p1->val && 2 == p2->val && 0 == pn) {
        cout<<"get value ok"<<endl;
    }

}

void systemTest()
{
    ListNode *headA = new ListNode(5);
    ListNode *headB = new ListNode(8);
    ListNode *headTemp = headA;
    for (int i = 4; i > 0; --i)
    {
        headTemp->next = new ListNode(i);
        headTemp = headTemp->next;
    }
    headTemp = headB;
    for (int i = 7; i > 0; --i)
    {
        headTemp->next = new ListNode(i);
        headTemp = headTemp->next;
    }
    Solution solution;
    ListNode *result = solution.getIntersectionNode(headA, headB);
    if (!result) {
        cout<<"empty test ok"<<endl;
    }
    else {
        cout<<"error when test empty set"<<endl;
    }

    headA->next->next->next = headB->next;
    result = solution.getIntersectionNode(headA, headB);
    cout<<"function ok"<<endl;
    if (result) {
        cout<<result->val<<endl;
    } else {
        cout<<"error when test ok set"<<endl;
    }



}


int main()
{
    systemTest();
}
