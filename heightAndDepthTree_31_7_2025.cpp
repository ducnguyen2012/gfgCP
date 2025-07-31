#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* right, *left;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void insert(int data, Node*& root){
    if (root == NULL) {root = new Node(data);return;}
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        if (curr->left == NULL){
            curr->left = new Node(data);
            return;
        }else {
            q.push(curr->left);
        }
        if (curr->right == NULL){
            curr->right = new Node(data);
            return;
        } else {
            q.push(curr->right);

        }
    }
}
void deleteDeepest(Node* root, Node* deepestNode){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        if (curr == deepestNode){
            curr = NULL;
            delete(deepestNode);
            return;
        }
        if (curr->left){
            if (curr->left == deepestNode){
                curr->left = NULL;
                delete(deepestNode);
                return;
            } else {
                q.push(curr->left);
            }
        }
        if (curr->right){
            if(curr->right == deepestNode){
                curr->right = NULL;
                delete(curr->right);
                return;
            } else {
                q.push(curr->right);
            }
        }
    }
}
Node* deleteData(int data, Node* root){
    if (root == NULL)return NULL;
    if (root->left== NULL && root->right == NULL){
        if (root->data == data) {
            return NULL;
        }
        else {
            return root;
        }
    }
    queue<Node*> q;
    q.push(root);
    Node* nodeFound = NULL;
    Node* dNode = NULL;
    Node* curr = NULL;
    // searching for current node:
    while(!q.empty()){
        curr = q.front();q.pop();
        if (curr->data == data) {
            nodeFound = curr;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }

    // found the right node:
    if (nodeFound != NULL){
        int x = curr->data;
        nodeFound->data = x;
        deleteDeepest(root,curr);
    }
    return root;
}
int nodeDepth(Node* root, int data){
    if(root == NULL) return -1;
    if (root->data == data) return 0;
    int dist = nodeDepth(root->left,data);
    if (dist >= 0) return dist+1;
    dist = nodeDepth(root->right,data);
    if (dist >= 0) return dist + 1;
    return -1;
}
int MaximumDepth(Node* root){
    if (root == NULL) return -1;
    int left = MaximumDepth(root->left);
    int right = MaximumDepth(root->right);
    return max(left,right)+1;
}
void inOrder(Node* root){
    if (root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    ifstream readFile("input.txt");
    int n;
    readFile>>n;
    int edge;
    auto start = chrono::high_resolution_clock::now();
    Node* root = NULL;
    for(int i = 0; i < n; ++i){
        readFile>>edge;
        insert(edge,root);
    }
    inOrder(root);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>duration = end - start;
    cout<<"time complexity: "<<duration.count()<<"\n";
    int key =6;
    root = deleteData(key,root);
    cout<<"Data show after delete: "<<key<<"\n";
    inOrder(root);
    cout<<"This is MaximumDepth of this tree: "<<MaximumDepth(root)<<"\n";
    int findDepthThisNode = 1;
    cout<<"This is depth of node: "<<nodeDepth(root,findDepthThisNode)<<"\n";

    return 0;
}
