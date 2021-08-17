#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value):
        value(value),left(nullptr),right(nullptr){}
};

void preOrderRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->value << ",";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

bool isBSTUtil(Node* head, int min, int max) {
    if (head == nullptr) {
        return true;
    }
    if (head->value <= min || head->value >= max) {
        return false;
    }
    return isBSTUtil(head->left, min, head->value) &&
           isBSTUtil(head->right, head->value, max);
}

bool isBST(Node* head) {
    if (head == nullptr) {
        return true;
    }
    return isBSTUtil(head, INT_MIN, INT_MAX);
}

int main() {
    Node* head1 = new Node(10);
    head1->left = new Node(5);
    head1->right = new Node(15);
    head1->right->left = new Node(12);
    head1->right->right = new Node(20);
    cout << "==============Test1==============";
    cout << "\npre-order: ";
    preOrderRecur(head1);
    bool isbst1 = isBST(head1);
    cout << "\n" << isbst1 << endl;

    Node* head2 = new Node(10);
    head2->left = new Node(5);
    head2->right = new Node(15);
    head2->right->left = new Node(6);
    head2->right->right = new Node(20);
    cout << "==============Test2==============";
    cout << "\npre-order: ";
    preOrderRecur(head2);
    bool isbst2 = isBST(head2);
    cout << "\n" << isbst2 << endl;

    Node* head3 = new Node(10);
    head3->left = new Node(5);
    head3->right = new Node(15);
    head3->right->left = new Node(8);
    head3->right->right = new Node(20);
    cout << "==============Test3==============";
    cout << "\npre-order: ";
    preOrderRecur(head3);
    bool isbst3 = isBST(head3);
    cout << "\n" << isbst3 << endl;
    return 0;
}