#include "bstTree.h"
// Construct method
bstTree::bstTree()
{
  root = NULL;
}

// Destruct method
bstTree::~bstTree()
{

}

// Return size of BST tree
int bstTree::size()
{
  return size(root);
}
int bstTree::size(TreeNode *node)
{
  if(node == NULL)   // base case
    return 0;
  else    // Recursive 1 + left traversal + right traversal
    return 1 + size(node->left) + size(node->right);
}

// Search a value in BST
bool bstTree::search(int value)
{
  return search(root,value);
}
bool bstTree::search(TreeNode *node, int value)
{
  if(node==NULL)
    return false;
  else if (node->data == value)
    return true;
  else
    return search(node->left, value) || search(node->right, value);
}

// Add a element in BST tree
void bstTree::add(int value)
{
    add(root,value);
}
void bstTree::add(TreeNode *&node, int value)
{
  if(node == NULL)  // First case: the empty tree
  {
    TreeNode *newNode = new TreeNode; // Create a new node
    newNode -> data = value;          // Assign value
    newNode -> left = NULL;           // Set left = NULL
    newNode -> right= NULL;           // Set right = NULL

    node = newNode;                   // Assing root = new Node
  }
  else if (node->data == value) // Second case: the value is existing in tree
   return;
  else if (node->data > value) // Third case: node's data > value
  {
      if (node->left == NULL) // If the node does not have left node, now we add the new value to the left
      {
        TreeNode *newNode = new TreeNode; // Create a new node
        newNode -> data = value;          // Assign value
        newNode -> left = NULL;           // Set left = NULL
        newNode -> right= NULL;           // Set right = NULL
        node->left = newNode;
      }
      else
        add(node->left,value);          // Recursive for traversal to left
  }
  else // Fourth case: node's data < value
  {
     if (node -> right == NULL) // If the node does not have right node, now we add the new value to the right
     {
       TreeNode *newNode = new TreeNode; // Create a new node
       newNode -> data = value;          // Assign value
       newNode -> left = NULL;           // Set left = NULL
       newNode -> right= NULL;           // Set right = NULL
       node->right = newNode;
     }
     else
       add(node ->right,value);     // Recursive for traversal to the right
  }
}

// ** Remove a element in BST
void bstTree::remove(int value)
{
  if(root == NULL)
    cout << "! Tree is now empty" <<endl;
  else
    remove(root,value);
}
bool bstTree::remove(TreeNode *&node, int value)
{
    if(node==NULL)//first case, node is null ----> return false
        return false;
    else if(node->data==value){//if node=item, we remove this by using remove root method
        node->data=remove_root(node);
        return true;//and also return true for this case
    }else if(node->data>value){//if node>item, we will find in the left children tree
        return remove(node->left,value);
    }else//we do not need condition if(node->value<item) here
        return remove(node->right,value);//if node<item, we will find in the left children tree
}
// removes the element at the root of the BST 'node'
// by replacing it by the maximum value in the left node
int bstTree::remove_root(TreeNode *&node)
{

    if(isLeaf(node)){//first case root is leaf, we just need to set node=NULL
        node=NULL;
        return -1;
    }else if(node->left!=NULL){//if node has left, we find the maximum value, reset the value of root and delete that maximum value.
        return remove_max(node->left);//the reset is done here
    }else{
        node=node->right;
        return node->data;
    }
}
// Check this node is leaf or not
bool bstTree::isLeaf(TreeNode *node)
{
  return (node->left == NULL) &&(node -> right == NULL);
}

// Remove max value in BST
int bstTree::remove_max()
{
  if(root == NULL)
  {
    cout << "! Tree is now empty" <<endl;
    return -1;
  }
  else
    return remove_max(root);
}
int bstTree::remove_max(TreeNode *&node)
{
  int result;
  if(node == NULL)
  {
    cout << "! Tree is now empty" << endl;
    return -1;
  }
  else
  {
    if(node -> right == NULL) // Stop, no traversal to right, find the ndde to remove
    {
      if(node->left != NULL) // if node left is not NULL --> link directly to left node
      {
        result = node ->data;
        node = node -> left;
        return result;
      }
      else
      {
        result = node->data;
        node = NULL;
        return result;
      }
    }
    else // right is not NULL --> traversal to right
      return remove_max(node->right);
  }
}

// Display BST with pre order
void bstTree::preorderPrint()
{
  if(root == NULL)
    cout << "! Tree is now empty" <<endl;
  else
    preorderPrint(root);
}
void bstTree::preorderPrint(TreeNode *node)
{
  // Print all the items in the tree to which root points.
  // The item in the root is printed first, followed by the
  // items in the left subtree and then the items in the
  // right subtree.
  if ( node != NULL ) {  // (Otherwise, there's nothing to print.)
     cout << node->data << " ";      // Print the root item.
     preorderPrint( node->left );    // Print items in left subtree.
     preorderPrint( node->right );   // Print items in right subtree.
  }
}

// Display BST with in order
void bstTree::inorderPrint()
{
  if(root == NULL)
    cout << "! Tree is now empty" <<endl;
  else
    inorderPrint(root);
}
void bstTree::inorderPrint(TreeNode *node)
{
  // Print all the items in the tree to which root points.
  // The items in the left subtree are printed first, followed
  // by the item in the root node, followed by the items in
  // the right subtree.
  if ( node != NULL ) {  // (Otherwise, there's nothing to print.)
    inorderPrint( node->left );    // Print items in left subtree.
    cout << node->data << " ";     // Print the root item.
    inorderPrint( node->right );   // Print items in right subtree.
  }
}

// Display BST with post order
void bstTree::postorderPrint()
{
  if(root == NULL)
    cout << "! Tree is now empty" <<endl;
  else
    postorderPrint(root);
}
void bstTree::postorderPrint(TreeNode *node)
{
  // Print all the items in the tree to which root points.
  // The items in the left subtree are printed first, followed
  // by the items in the right subtree and then the item in the
  // root node.
   if ( node != NULL ) {  // (Otherwise, there's nothing to print.)
      postorderPrint( node->left );    // Print items in left subtree.
      postorderPrint( node->right );   // Print items in right subtree.
      cout << node->data << " ";       // Print the root item.
  }
}

void bstTree::display_all()
{
  int indent = 0;
  if (root == NULL)
    cout << "! Tree is now empty" <<endl;
  else
    display_all(root,indent,root->data);
}
void bstTree::display_all(TreeNode *node,int indent, int root_value)
{
    int i;
    if(node != NULL)
    {
 /*   ! Another way:
       display_all(node -> right, indent +1,root_value);
       cout << endl;
       if(node->data == root_value)
          cout<<"Root->:  ";
       else
       {
         for (i = 0;i < indent;i++)
               cout<<"       ";
        }
        cout<<node->data;
        display_all(node -> left, indent + 1,root_value);
        */
      display_all(node->right, indent +3,0);
      for( i = 0; i < indent; i++ )
       cout <<' ';
       cout << node->data << endl;
      display_all( node->left, indent + 3,0);
    }
}

// PART 3 : method countLeftNodes
int bstTree::countLeftNodes()
{
  return countLeftNodes(root);
}

int bstTree::countLeftNodes(TreeNode *node)
{
  if(node == NULL)
    return 0;
  else if(node->left == NULL)
    return 0 + countLeftNodes(node->right);
  else
    return 1+ countLeftNodes(node->left) + countLeftNodes(node->right);
}

// Method countEmpty
int bstTree::countEmpty()
{
  return countEmpty(root);
}

int bstTree::countEmpty(TreeNode *node)
{
  if(node == NULL)
    return 1;
  else
    return countEmpty(node->left) + countEmpty(node-> right);
}

// Method depthSum
int bstTree::depthSum()
{
  return depthSum(root,1);
}

int bstTree::depthSum(TreeNode *node,int level)
{
  if(node == NULL)
    return 0;
  else
    return level * node ->data + depthSum(node->left, level + 1) + depthSum(node->right, level + 1);
}

// Method countEvenBranches
int bstTree::countEvenBranches()
{
    return countEvenBranches(root);
}

int bstTree::countEvenBranches(TreeNode * node) {
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 0;
    else if (node->data % 2 == 0)
        return 1 + countEvenBranches(node->left) + countEvenBranches(node->right);
    else
        return countEvenBranches(node->left) + countEvenBranches(node->right);
}

// Method printLevel
void bstTree::printLevel(int target)
{
    printLevel(root, target, 1);
}

void bstTree::printLevel(TreeNode *node, int target, int level)
{
    if(node != NULL)
    {
        if(level == target)
            cout << node->data << endl;
        else
        {
            printLevel(node->left, target, level + 1);
            printLevel(node->right, target, level + 1);
        }
    }
}

// Method printLeaves
void bstTree::printLeaves()
{
    if (root == NULL)
        cout<<"! No leaves" <<endl;
    else
    {
        cout<<"Leaves: ";
        printLeaves(root);
        cout << endl;
    }
}

void bstTree::printLeaves(TreeNode *node)
{
    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL)
            cout << " " << node->data;
        else
        {
            printLeaves(node->right);
            printLeaves(node->left);
        }
    }
}

// Method isFull
bool bstTree::isFull() {
    return (root == NULL || isFull(root));
}

bool bstTree::isFull(TreeNode *node) {
    if(node->left == NULL && node->right == NULL) {
        return true;
    } else {
        return (node->left != NULL && node->right != NULL &&
        isFull(node->left) && isFull(node->right));
    }
}

// Method doublePositives
void bstTree::doublePositives() {
    doublePositives(root);
}

void bstTree::doublePositives(TreeNode *node) {
    if (node != NULL) {
        if (node->data > 0) {
            node->data *= 2;
        }
        doublePositives(node->left);
        doublePositives(node->right);
    }
}

// Method numberNodes
int bstTree::numberNodes() {
    return numberNodes(root, 1);
}

int bstTree::numberNodes(TreeNode *node, int count) {
    if (node == NULL) {
        return count - 1;
    } else {
        node->data = count;
        count = numberNodes(node->left,  count + 1);
        count = numberNodes(node->right, count + 1);
        return count;
    }
}

// Method remove leaves
void bstTree::removeLeaves() {
   root=removeLeaves(root);
}

TreeNode* bstTree::removeLeaves(TreeNode *&node) {

    if(node != NULL) {
        if(node->left == NULL && node->right == NULL) {
            node = NULL;
        } else {
            node->left  = removeLeaves(node->left);
            node->right = removeLeaves(node->right);
        }
    }
    return node;
}

// Method completeToLevel
void bstTree::completeToLevel(int target)
{
  root = completeToLevel(root,target,1);
}
TreeNode* bstTree::completeToLevel(TreeNode *&node, int target, int level) {
    if (level <= target) {
        if (node == NULL) {
           TreeNode *newNode = new TreeNode;
           newNode->data = -1;
           newNode->left = NULL;
           newNode->right= NULL;
           node = newNode;
        }
        node->left  = completeToLevel(node->left,  target, level + 1);
        node->right = completeToLevel(node->right, target, level + 1);
    }
    return node;
}

// Method trim
void bstTree::trim(int min, int max)
{
  root = trim(root,min,max);
}
TreeNode* bstTree::trim(TreeNode *&node, int min, int max) {
    if (node != NULL) {
        if (node->data < min) {
            node= trim(node->right, min, max);
        } else if (node->data > max) {
            node = trim(node->left, min, max);
        } else {
            node->left  = trim(node->left,  min, max);
            node->right = trim(node->right, min, max);
        }
    }
    return node;
}

// Method tighten
void bstTree::tighten()
{
  root = tighten(root);
}
TreeNode* bstTree::tighten(TreeNode *&node) {
    if (node != NULL) {
        node->left = tighten(node->left);
        node->right = tighten(node->right);
        if (node->left != NULL && node->right == NULL) {
            node = node->left;
        } else if (node->left == NULL && node->right != NULL) {
            node = node->right;
        }
    }
    return node;
}
