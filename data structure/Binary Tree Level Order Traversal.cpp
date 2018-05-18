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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> ret;
        vector<int> lv;
        if(root==NULL)return ret;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int s=Q.size();
            while(s--){
                TreeNode* head=Q.front();
                Q.pop();
                lv.push_back(head->val);
                if(head->left!=NULL)Q.push(head->left);
                if(head->right!=NULL)Q.push(head->right);
            }
            ret.push_back(lv);
            lv.clear();
        }
        return ret;
    }
    
};
