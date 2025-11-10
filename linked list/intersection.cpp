#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to get intersection node
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a; // Intersection node or nullptr
}

int main() {
    // Create intersecting linked lists:
    // A: 1 -> 2 -> 3
    //                \
    //                 6 -> 7
    //                /
    // B:      4 -> 5

    ListNode* common = new ListNode(6);
    common->next = new ListNode(7);

    // List A
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = common;

    // List B
    ListNode* b = new ListNode(4);
    b->next = new ListNode(5);
    b->next->next = common;

    // Find intersection
    ListNode* intersection = getIntersectionNode(a, b);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
