#include "model\ListNode.h"

/**
 * @perf: 4ms, 93
 */
void _1(struct ListNode* node){
        node->val = node->next->val;
        node->next = node->next->next;
}

void deleteNode(struct ListNode* node) {
        _1(node);
}
