#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}


int minDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (root->left == NULL) return rightDepth + 1;
    if (root->right == NULL) return leftDepth + 1;

    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int main() {
    Node* root = NULL;

    int a[] = {8, 4, 12, 2, 6};
    for (int i = 0; i < 5; i++)
        root = insert(root, a[i]);

    cout << "Min depth is " << minDepth(root) << endl;
    return 0;
}

