#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data; 
    Node* left; 
    Node* right;

    Node(int val){
        this->data = val;
        this->left  = NULL;
        this->right = NULL;
    }
};

// Insert into BST
void insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }
    if(data < root->data){
        insertIntoBST(root->left, data);
    }
    else{
        insertIntoBST(root->right, data);
    }
}

// Create BST
void createBST(Node* &root){
    cout << "Enter data for nodes (enter -1 to stop): ";
    int data;
    cin >> data;
    while(data != -1){
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Levelorder Traversal
void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++){
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

// Inorder Traversal 
void inorderTraversal(Node* root){  // LNR
    // Base Case
    if(root==NULL){
        return;
    }
    // Left
    inorderTraversal(root->left);
    // Node
    cout << root->data << " ";
    // Right
    inorderTraversal(root->right);
}

// Preoreder Traversal 
void preorderTraversal(Node* root){  // NLR 
    // Base Case
    if(root==NULL){
        return;
    }
    // Node
    cout << root->data << " ";
    // Left
    preorderTraversal(root->left);
    // Right
    preorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(Node* root){  // LRN
    // Base Case
    if(root==NULL){
        return;
    }
    // Left
    postorderTraversal(root->left);
    // Right
    postorderTraversal(root->right);
    // Node 
    cout << root->data << " ";
}

int findMax(Node* root){  // Find Maximum Element 
    Node* temp = root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int findMin(Node* root){  // Find Minimum Element 
    Node* temp = root;
    if(temp==NULL){
        return -1;
    }
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

bool findNode(Node* root, int target){
    // Base Case
    if(root == NULL){
        return false;
    }
    // Check Current Node
    if(root->data == target){
        return true;
    }
    // Check Left Node
    else if(root->data > target){
        return findNode(root->left, target);
    }
    // Check Right Node
    else { 
        return findNode(root->right, target);        
    }
}

bool searchNode(Node* root, int target){
    // Base Case 
    if(root == NULL){
        return false;
    }
    // Check Current Node
    if(root->data == target){
        return true;
    }
    // using recursion to check at left and right
    bool searchRight = false; 
    bool searchLeft = false; 

    if(root->data < target){
        searchRight = searchNode(root->right,target);
    }

    else{
        searchLeft = searchNode(root->left,target);
    }

    if(searchLeft==true) return true;
    if(searchRight==true) return true;
    if(searchLeft==false && searchRight==false) return false;

    return false;
}


Node *deleteNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == target)
    {
        // Case 1 : Leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2 : Left child not exist
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }
        // Case 3 : Right child not exist
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            return child;
        }
        // Case 4 : Both child exists
        else
        {
            int maxi = findMax(root->left);  // Left Subtree ka max lelo (Left subtree mein jaao fir right-right jaate rho), ya right subtree ka min lelo (right subtree jao aur left-left krte rho)
            root->data = maxi;
            root->left = deleteNodeInBST(root->left, maxi);
            return root;
        }
    }
    else if (root->data > target)
    {
        // left
        root->left =  deleteNodeInBST(root->left, target);
    }
    else
    {
        // right
        root->right = deleteNodeInBST(root->right, target);
    }
    return root;
}


int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    cout << endl << endl << "Printing InOrder Traversal" << endl;
    inorderTraversal(root);
    cout << endl << endl << "Printing PreOrder Traversal" << endl;
    preorderTraversal(root);
    cout << endl << endl << "Printing PostOrder Traversal" << endl;
    postorderTraversal(root);

    cout << endl << "Maximum Element: " << findMax(root);
    cout << endl << "Maximum Element: " << findMin(root);

    int target;
    cout << endl << "Enter the Element to find: ";
    cin >> target;
    cout << "Element " << target << " found: " << findNode(root, target) << "   " <<  searchNode(root, target) << endl;



    return 0;

}


/*
In Binary search the very first requirement is that the data should be in monotonic function which means it should be in increasing order. We would be given a specific target to find in the array. First of all we find the mid element based on the index and if the mid element is greater than the target we search for the target in left of the mid eleemnt And if the target is greater than the mid element then we find for the target in the right of mid element. Hence we are breaking the array in every iteration based on the mid element hence the time complexity will be O(log n)


HomeWork --> Complete Binary Tree and Perfect Binary Tree

In Binary Search Tree (BST) every node will follow a property that property would be that the value of every node at the left subtree of a specific node will be smaller than the value of that specific node and the value at the right subtree should be greater than the value of that specific node. This property will be applied to every node of the Binary Search Tree (BST)
RightSubTree->data < Node->data < LeftSubTreeData


Given Input : 50, 30, 40, 20, 60, 55, 70, 80, 25

Binary Search Tree Generated:
    50
   / \
  30  60
 /   / \
20  40  55
 /       \
25       70
          \
          80

We will Solve One case, Baaki Recursion Sambhaal Lega 

1.) Taking inputs and generating a BST
2.) Every possible traversal -> LevelOrder, Inorder, Postorder, Preorder
3.) Find Maximum and Minimum node 
4.) Check if node is present or not (search in BST)
5.) Jabb target mil jaaye to uska left subtree return kar
6.) Jabb target mil jaaye to uska right subtree return kar
7.) Add a node to the prescribed position in Binary tree
8.) Path Sum in BST
9.) New Questions of Linked Lists are being added....
10.) How to build a tree if the sequence of inorder, preorder, postorder, levelorder traversals are mentioned




In order to do all questions of trees efficiently we are supposed to knoe the following things:
1.) You should know all possible traversals on Tree 
2.) How Recursive Calls go to handle the cases
3.) Kisi ek value ko recursion ka use krke oopar se neeche bhejna hai, you should know this 
3.) Kisi ek value ko recursion ka use krke neeche se oopar bhejna hai, you should know this 
*/



