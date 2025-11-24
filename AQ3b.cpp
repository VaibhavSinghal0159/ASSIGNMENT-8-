#include <iostream>
using namespace std;

class Node {
public:
    int data; Node* left; Node* right;
    Node(int value) { 
        data = value; 
        left = NULL; 
        right = NULL; 
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value == root->data) return root;
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* removeNode(Node* root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data) root->left = removeNode(root->left, value);
    else if (value > root->data) root->right = removeNode(root->right, value);
    else {
        
        if (root->left == NULL && root->right == NULL) {
            delete root; return NULL;
        } else if (root->left == NULL) {
            Node* t = root->right; delete root; return t;
        } else if (root->right == NULL) {
            Node* t = root->left; delete root; return t;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = removeNode(root->right, succ->data);
        }
    }
    return root;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int main() {
    Node* root = NULL;
    int a[] = {50,30,70,20,40,60,80};
    for (int i=0;i<7;i++) root = insert(root, a[i]);

    cout << "Before delete: ";
    inorder(root);
    cout << endl;

    root = removeNode(root, 30); // delete node with two children
    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;

    root = removeNode(root, 20); // delete leaf
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    root = removeNode(root, 70); // delete node with one child
    cout << "After deleting 70: ";
    inorder(root);
    cout << endl;

    return 0;
}
