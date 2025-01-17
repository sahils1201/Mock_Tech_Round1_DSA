#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* createLinkedList() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) return nullptr;

    cout << "Enter the node values: ";
    int value;
    cin >> value;
    Node* head = new Node(value);
    Node* tail = head;

    for (int i = 1; i < n; ++i) {
        cin >> value;
        tail->next = new Node(value);
        tail = tail->next;
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();

    head = reverse(head);
    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}