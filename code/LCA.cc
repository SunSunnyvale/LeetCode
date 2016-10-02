/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

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
    void pList(TreeNode* root, TreeNode* p,vector<TreeNode*>& path){
        TreeNode* temp;
        temp=root;
        while(temp!=NULL){
            path.push_back(temp);
            if(p->val==temp->val){
                return;
            }
            if(p->val < temp->val){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        pList(root,p,path);
        
        TreeNode* temp;
        temp=root;
        uint16_t counter=0;
        while(temp!=NULL){
            if(temp->val!=path[counter]->val){
                return path[counter-1];
            }
            counter++;
            if(q->val==temp->val){
                return temp;
            }
            if(q->val < temp->val){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        return NULL;
    }
};