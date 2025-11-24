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

Node* findMax(Node* r) {
    while (r && r->right) r = r->right;
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

Node* inorderPredecessor(Node* root, Node* target) {
    if (target == NULL) return NULL;

    if (target->left != NULL)
        return findMax(target->left);

    Node* pred = NULL;
    Node* cur = root;

    while (cur != NULL) {
        if (target->data > cur->data) { 
            pred = cur; 
            cur = cur->right; 
        }
        else if (target->data < cur->data) cur = cur->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;

    int arr[] = {40,20,60,10,30,50,70};  
    for (int i=0; i<7; i++) root = insert(root, arr[i]);

    Node* t = search(root, 20);
    Node* p = inorderPredecessor(root, t);

    if (p!=NULL) cout<<"Predecessor is "<<p->data<<endl;
    else cout<<"No predecessor  ";

    t = search(root, 50);
    p = inorderPredecessor(root, t);

    if (p!=NULL) cout<<"Predecessor is "<<p->data<<endl;
    else cout<<"No predecessor  ";

    return 0;
}
