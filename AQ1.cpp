#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void preorder(Node* r) {
    if (r == NULL) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (r == NULL) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void postorder(Node* r) {
    if (r == NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

void destroy(Node* r) {
    if (r == NULL) return;
    destroy(r->left);
    destroy(r->right);
    delete r;
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    cout << "In-order: ";
    inorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    destroy(root);
    return 0;
}

