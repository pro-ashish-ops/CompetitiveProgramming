#include <bits/stdc++.h>
using namespace std;
#define int long long

struct LinkedListNode {
    int data;
    LinkedListNode* next;

    LinkedListNode(int val) : data(val), next(nullptr) {}
};

void insertAtBeginning(LinkedListNode*& head, int value) {
    LinkedListNode* newNode = new LinkedListNode(value);
    newNode->next = head;
    head = newNode;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedListNode* head = nullptr;
    int n, value;   
    cout << "Enter number of elements to insert at beginning: ";
    cin >> n;   
    cout << "Enter values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtBeginning(head, value);
    }   
    cout << "Linked List after inserting elements at the beginning: ";
    LinkedListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }   
    cout << endl;
    

    return 0;
}