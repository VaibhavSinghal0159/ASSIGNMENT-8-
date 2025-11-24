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

Node* insert(Node* r, int value) {
    if (r == NULL) return new Node(value);
    if (value < r->data) r->left = insert(r->left, value);
    else r->right = insert(r->right, value);
    return r;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* search(Node* r, int key) {
    while (r != NULL) {
        if (r->data == key) return r;
        if (key < r->data) r = r->left;
        else r = r->right;
    }
    return NULL;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target == NULL) return NULL;

    if (target->right != NULL)
        return findMin(target->right);

    Node* succ = NULL;
    Node* cur = root;

    while (cur != NULL) {
        if (target->data < cur->data) { 
            succ = cur; 
            cur = cur->left; 
        }
        else if (target->data > cur->data) cur = cur->right;
        else break;
    }
    return succ;
}

int main() {
    Node* root = NULL;

    int arr[] = {40,20,60,10,30,50,70}; 
    for (int i=0; i<7; i++) root = insert(root, arr[i]);

    Node* t = search(root, 20);
    Node* s = inorderSuccessor(root, t);

    if (s!=NULL) cout<<"Successor is "<<s->data<<endl;
    else cout<<"No successor  ";

    t = search(root, 60);
    s = inorderSuccessor(root, t);

    if (s!=NULL) cout<<"Successor is "<<s->data<<endl;
    else cout<<"No successor  ";

    return 0;
}
