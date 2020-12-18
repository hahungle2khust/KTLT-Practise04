#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// print the list content on a line
void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* newHead{};
    while (head != NULL) {
        newHead = prepend(newHead, head->data);
        head = head->next;
    }
    return newHead;
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}