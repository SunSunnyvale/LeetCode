/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int>& elements,bool& isValidBST){
        if(root==NULL || !isValidBST){
            return;
        }
        inOrderTraversal(root->left,elements,isValidBST);
        if(elements.back()<root->val){
            elements.push_back(root->val);
        }else{
            if(elements.size()!=0){
                isValidBST=false;
            }else{
                elements.push_back(root->val);
            }
        }
        inOrderTraversal(root->right,elements,isValidBST);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
         return true;
         vector<int> elements;
         elements.reserve(100);
         bool isValidBST=true;
         inOrderTraversal(root,elements,isValidBST);
        return isValidBST;
    }
};
