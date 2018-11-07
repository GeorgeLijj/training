/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
     void search(TreeNode* root,vector<int> &ret ){
      ret.push_back(root->val);
         if(root->left!=NULL){
             search(root->left,ret);
         }
               
         if(root->right!=NULL){
            search(root->right,ret);
         }
         return ;
     } 
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> ret;
        if(root==NULL)return ret;
        search(root,ret);
        return ret;
    }
};
