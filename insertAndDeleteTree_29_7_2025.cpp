#include <bits/stdc++.h>

using namespace std;


class Node{
public:
    int data;
    Node* left, *right;
    Node(){
        this->left = this->right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
void deleteDeepest(Node*& root, Node*& curr){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        if (temp == curr){
            temp=NULL;
            delete(curr);
            return;
        }
        if (temp->right){
            if (temp->right == curr){
                temp->right = NULL;
                delete(curr);
                return;
            }
            q.push(temp->right);
        }
        if (temp->left){
            if (temp->left == curr){
                temp->left = NULL;
                delete(curr);
                return;
            }
            q.push(temp->left);
        }

    }
}
Node* deleteData(int data, Node*& root){
    if (!root) return NULL;
    if (!root->left && !root->right){
        if (root->data == data) return NULL;

        else{
            return root;
        }
    }
    queue<Node*>q;
    q.push(root);
    Node* keyNode = NULL;
    Node* curr = NULL;
    while(!q.empty()){
        curr = q.front(); q.pop();
        if (curr->data == data) {
            keyNode = curr;
        }
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }
    if (keyNode) {
        int x = curr->data; // deepest
        keyNode->data = x;

        deleteDeepest(root,curr);
    }
    return root;
}

void insertData(int data, Node*& root){
    if (root == NULL){
        root = new Node(data);
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        if (curr->left){
            q.push(curr->left);
        } else {
            curr->left = new Node(data);
            return;
        }

        if (curr->right){
            q.push(curr->right);
        } else {
            curr->right = new Node(data);
            return;
        }
    }
}
void inorder(Node* root){
    if (!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main(){

    ifstream readFile("input.txt");
    int numNode;
    readFile>>numNode;
    int data;
    Node* root = NULL;
    auto start = chrono::high_resolution_clock::now();


    for(int i = 0; i < numNode; ++i){
        readFile>>data;
        insertData(data,root);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    inorder(root);
    int key = 12;
    root = deleteData(key,root);
    cout<<"after delete: "<<key<<"\n";
    inorder(root);
    cout<<"time complexity: "<<duration.count()<<"\n";
    return 0;
}
