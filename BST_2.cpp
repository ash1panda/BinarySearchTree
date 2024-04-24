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

void preOrderTraversal(Node * root)



int main(){

    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    


    return 0;
}