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

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int main() {
    Node* root = NULL;
    
    int a[] = {30, 20, 40, 10, 25, 35, 50};
    for (int i = 0; i < 7; i++) root = insert(root, a[i]);


    root = insert(root, 30); 

    cout << "Inorder after inserts: ";
    inorder(root);
    cout << endl;
    return 0;
}
