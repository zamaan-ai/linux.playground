#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy head to simplify list construction
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* curr = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        // Extract values, default to 0 if list is exhausted
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        
        int sum = carry + x + y;
        carry = sum / 10;
        
        // Allocate memory for the new digit node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Link the new node and move the current pointer
        curr->next = newNode;
        curr = curr->next;
        
        // Advance input lists
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    return dummy.next;
}