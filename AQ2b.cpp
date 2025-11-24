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
    if (r == NULL) return NULL;
    while (r->right != NULL) r = r->right;
    return r;
}

int main() {
    Node* root = NULL;
    int arr[] = {50,30,70,20,40,60,80};
    for (int i=0;i<7;i++) root = insert(root, arr[i]);

    Node* m = findMax(root);

    if(m!=NULL) cout<<"Maximum is "<<m->data<<endl;
    else cout<<"Tree is empty ";

    return 0;
}
