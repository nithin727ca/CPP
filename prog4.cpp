#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* current = head;

    while (current->next) {
        if (current->val == current->next->val) {

            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next; 
        }
    }
    return head;
}


void insertNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

   
    insertNode(head, 1);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "List After Removing Duplicates: ";
    printList(head);

    return 0;
}
