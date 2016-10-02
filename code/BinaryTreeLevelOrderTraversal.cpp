/**
 * 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Show Company Tags
Show Tags
Show Similar Problems

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> siblings;
        if(root==NULL){
            return result;
        }
        int count=1;
        siblings.push(root);
        TreeNode* temp;
        int i=0,j=0,ht=0;
        while(!siblings.empty()){
            vector<int> elements;
            j=0;
            //cout<<"\nCount::"<<count<<"\n";
            for(i=0;i<count;i++){
                temp=siblings.front();
                elements.push_back(temp->val);
                //cout<<" "<<temp->val;
                siblings.pop();
                if(temp->left!=NULL){siblings.push(temp->left);j++;}
                if(temp->right!=NULL){siblings.push(temp->right);j++;}
            }
            ht++;
            count=j;
            // cout<<"\n ";
            // for(int ele:elements)
            //     cout<<ele<<" ";
            result.push_back(elements);
        }
        return result;
        
    }
};