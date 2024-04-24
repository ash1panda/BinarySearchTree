/*
1.) Create a BST (that also includes Insert node into BST)
2.) Level Order Traversal
3.) PostOrder, PreOrder, InOrder Traversals
4.) Find a node in BST 
*/
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertIntree(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return;
    }
    if(val<root->data){
        insertIntree(root->left, val);

    }
    else{
        insertIntree(root->right, val);
    }

    

}

void createBST(Node* &root){
    int val;
    cin >> val;

    while(val!=-1){
    insertIntree(root,val);
    cin>>val;
    }

    return;
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

    }
    
}

void inOrderTraversal(Node* root){  // LNR  
    
    if(root ==NULL){
        return;
    }
    
    //L
    inOrderTraversal(root->left);
    //N
    cout << root->data << " ";
    //R
    inOrderTraversal(root->right);

}

void preOrderTraversal(Node* root){  // NLR 
    if(root == NULL){
        return;
    }

    //N
    cout << root->data << " ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){ //LRN
    if(root ==NULL){
        return;
    }

    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->data << " ";
}

bool searchNode(Node* root, int target){
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(root->data > target){
        return searchNode(root->left, target);
    }
    else{
        return searchNode(root->right, target);
    }
}

int findMaxi(Node* root){
    Node* temp = root;
    if(root==NULL){
        return -1;
    }
    while(temp!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

int findMini(Node* root){
    Node* temp = root;
    if(root==NULL){
        return -1;
    }
    while(temp!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int main(){

    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    


    return 0;
}