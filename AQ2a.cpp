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

Node* searchRec(Node* r, int key) {
    if (r == NULL) return NULL;
    if (r->data == key) return r;
    if (key < r->data) return searchRec(r->left, key);
    return searchRec(r->right, key);
}

Node* searchItr(Node* r, int key) {
    while (r != NULL) {
        if (r->data == key) return r;
        if (key < r->data) r = r->left;
        else r = r->right;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    int arr[] = {50,30,70,20,40,60,80};
    for (int i=0;i<7;i++) root = insert(root, arr[i]);

    Node* a = searchRec(root,40);
    if(a!=NULL) cout<<"Element found "<< endl;
    else cout<<"Element not found " << endl << endl ;

    Node* b = searchItr(root,65);
    if(b!=NULL) cout<<"Element found ";
    else cout<<"Element not found ";

    return 0;
}

