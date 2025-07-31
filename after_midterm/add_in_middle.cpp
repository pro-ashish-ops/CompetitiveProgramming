#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head; Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    
    void search(int val){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == val){
                cout << "Value " << val << " found in the list." << endl;
                return;
            }else{
                temp = temp->next;
            }
        }
    }

    void addStart(int val){
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void nth_from_end(int n){
        int sz = 0;
        Node* temp = head;
        while(temp != nullptr){
            sz++;
            temp = temp->next;
        }
        cout<<"sz"<<sz<<endl;
        n = sz - n + 1;
        cout<<"n"<<n<<endl;
        Node* curr;
        Node* prev;
        curr = head;
        int count = 0;
        while(curr != nullptr && count < n-1){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr != nullptr){
            prev->next = curr->next;
        }
    }
   
    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev; // Update head to the new first node
        return head;
    }

    Node* findMid(Node* head){
        Node* slow= head;
        Node* fast = head;
        while(fast != nullptr and fast->next != nullptr){
            slow = slow->next;//+1
            fast = fast->next->next;//+2
        }
        return slow;
    }

    Node* helper(Node* head1, Node* head2){
        Node* newNode = new Node(-1);
        Node* temp =  newNode;
        while(head1 != nullptr and head2 != nullptr){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;

            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return newNode->next;
    }

    Node* zigzag(Node* head){
        if(head == nullptr or head->next == nullptr) return head;
        Node* revHead = reverse(head);
        return helper(head, revHead);
    }

    bool checkPalindrome(Node* head){
        if(head == nullptr || head->next == nullptr) return true;
        Node* mid = findMid(head);
        //reverse the 2nd half
        Node* sec_half = reverse(mid);

        //check if 1st half is equal to 2nd half
        Node* head_one = head;
        Node* head_two = sec_half;
        while(head_two != nullptr){
            if(head_one->data != head_two->data){
                return false;
            }
            head_one = head_one->next;
            head_two = head_two->next;
        }
        return true;
    }
    
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) break; // To avoid infinite loop in circular linked list
        }
        cout << endl;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, value;
    cin>>n;
    LinkedList ll;
    for(int i = 0; i < n; ++i) {
        cin >> value;
        ll.addStart(value);
    }
    ll.print();
    ll.zigzag(ll.head);
    ll.print();
    return 0;
}