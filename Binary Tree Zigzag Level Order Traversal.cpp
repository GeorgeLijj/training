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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        vector<vector<int>> ret;
        if(root==NULL)return ret;
        vector<int> lv;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            int size=s1.size();
            while(size--){
                TreeNode* head=s1.top();
                s1.pop();
                lv.push_back(head->val);     
                if(head->left!=NULL)s2.push(head->left);
                if(head->right!=NULL)s2.push(head->right);
            }
            ret.push_back(lv);
            lv.clear();
            if(s2.empty())break;
            size=s2.size();
            while(size--){
                TreeNode* head=s2.top();
                s2.pop();
                lv.push_back(head->val);     
                if(head->right!=NULL)s1.push(head->right);
                if(head->left!=NULL)s1.push(head->left); 
            }
            ret.push_back(lv);
            lv.clear();
        }
        return ret;
    }
};
