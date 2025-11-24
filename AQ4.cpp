#include <iostream>
#include <climits>
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

Node* buildSampleTree() {
   
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(20);
    return root;
}


bool isBSTvalid(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal) return false;
    if (root->data >= maxVal) return false;

    bool leftOK = isBSTvalid(root->left, minVal, root->data);
    bool rightOK = isBSTvalid(root->right, root->data, maxVal);

    if (leftOK == true && rightOK == true)
        return true;
    else
        return false;
}

bool isBST(Node* root) {
    return isBSTvalid(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = buildSampleTree();

    if (isBST(root) == true)
        cout << "Tree is BST ";
    else
        cout << "Tree is NOT BST ";

    return 0;
}
