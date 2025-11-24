#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) { data = value; left = NULL; right = NULL; }
};

Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth > rightDepth) return leftDepth + 1;
    else return rightDepth + 1;
}

int main() {
    Node* root = NULL;
    int a[] = {15, 10, 20, 8, 12, 17, 25, 6};
    for (int i = 0; i < 8; i++) root = insert(root, a[i]);

    cout << "Max depth is " << maxDepth(root) << endl;
    return 0;
}
