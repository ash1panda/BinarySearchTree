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
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

int findMini(Node* root){
    Node* temp = root;
    if(root==NULL){
        return -1;
    }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

Node* deleteNode(Node* root, int target) {

    //Base Case 
    if (root == NULL) {
        return NULL;
    }

    if (root->data == target) { // We have to do main operations for this case only

        // if the node is "Leaf Node"
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // if right subtree exists
        else if (root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            delete root;
            return child;
        }

        // if left subtree exists
        else if (root->right == NULL && root->left != NULL) {
            Node* child = root->left;
            delete root;
            return child;
        }

        // if both left and right subtrees exist 
        else if (root->right != NULL && root->left != NULL) {
            // find maximum element from the left subtree
            int maxiLeft = findMaxi(root->left); // Change findMini to findMaxi
            root->data = maxiLeft;
            root->left = deleteNode(root->left, maxiLeft);
            return root;
        }

    }
    else if (root->data > target) {
        // target is in left 
        root->left = deleteNode(root->left, target);
    }
    else {
        // target is in right
        root->right = deleteNode(root->right, target);
    }
    return root;
}
// 50 30 60 25 40 70 80 55 -1

int main(){

    Node* root = NULL;
    createBST(root);
    cout << endl << endl << "This the Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    cout << endl << endl << "This is InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl << endl << "This is preOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl << endl << "This is postOrder Traversal: ";
    postOrderTraversal(root);

    int node1;
    cout << endl << endl << "Enter the node to find: ";
    cin >> node1;
    if (searchNode(root, node1)==1){
        cout << "Node Found !";
    }
    else{
        cout << "Node Not Found !";
    }

    cout << endl << endl << "Maximum Element of the BST is: " << findMaxi(root);
    cout << endl << endl << "Minimum Element of the BST is: " << findMini(root);

    int node2;
    while(node2!=-1){
    cout << endl << endl << "Enter the node to delete (Enter -1 to end): ";
    cin >> node2;
    cout << endl << endl << "This the Level Order Traversal (Before Deletion): "<<endl;
    levelOrderTraversal(root);
    deleteNode(root, node2);
    cout << endl << "This the Level Order Traversal (After Deletion): "<<endl;
    levelOrderTraversal(root);
    }

    

    

    


    return 0;
}