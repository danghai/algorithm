/*
  File: bstTree.h
  Author: Hai Dang Hoang
  email: goldsea5191@gmail.com
*/

#ifndef BSTTREE_H_
#define BSTTREE_H_

#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
class bstTree
{
      public:
             //These functions have ALREADY been written for you
             bstTree(void);
             ~bstTree(void);

             int size();               // Return size of BST
             void add(int value);      // add the element to the tree
             void remove(int value);    // removes the element from the tree
             void display_all();       // display the tree
             int remove_max();         // remove and returns the maximum value from BST node
             bool search(int value);   // search a value in BST
             void preorderPrint();          // Display BST in pre order format
             void inorderPrint();           // Display BST in in order format
             void postorderPrint();         // Display BST in post order format

             // Part 3
             int countLeftNodes();
             int countEmpty();
             int depthSum();
             int countEvenBranches();
             void printLevel(int level);
             void printLeaves();
             bool isFull();
             void doublePositives();
             int numberNodes();
             void removeLeaves();
             void completeToLevel(int level);
             void trim(int min, int max);
             void tighten();

      private:
              TreeNode *root;
              // Return size of BST
              int size(TreeNode *node);
              // checks if the value is in the BST node
              bool search(TreeNode *node, int value);
              // Add the element in the BST unless value is already in the BST
              void add(TreeNode *&node, int value);
              // removes the element from BST unless value is not in the BST
              bool remove(TreeNode *&node, int value);
              // removes the elements at the root of the BST by replacing it by the maximum value in the left node
              int remove_root(TreeNode *&node);
              // remove and returns the maximum value from BST node
              int remove_max(TreeNode *&node);
              // check the node is a leaf or not
              bool isLeaf(TreeNode *node);


              void preorderPrint(TreeNode *node);          // Display BST in pre order format
              void inorderPrint(TreeNode *node);           // Display BST in in order format
              void postorderPrint(TreeNode *node);         // Display BST in post order format
              void display_all(TreeNode *node, int indent,int root_value);

              // PART 3
              int countLeftNodes(TreeNode *node);
              int countEmpty(TreeNode *node);
              int depthSum(TreeNode *node, int level);
              int countEvenBranches(TreeNode *node);
              void printLevel(TreeNode *node,int target, int level);
              void printLeaves(TreeNode *node);
              bool isFull(TreeNode *node);
              void doublePositives(TreeNode *node);
              int numberNodes(TreeNode *node,int n);
              TreeNode* removeLeaves(TreeNode *&node);
              TreeNode* completeToLevel(TreeNode *&node,int target,int level);
              TreeNode* trim(TreeNode *&node,int min, int max);
              TreeNode* tighten(TreeNode *&node);



};

#endif
