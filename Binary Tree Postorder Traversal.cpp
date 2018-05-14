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
		 * @return: Postorder in ArrayList which contains node values.
		 */
		void search(TreeNode* root,vector<int> &ret) {
			if(root->left!=NULL)search(root->left,ret);
			if(root->right!=NULL)search(root->right,ret);
			ret.push_back(root->val);
		}
		vector<int> postorderTraversal(TreeNode * root) {
			// write your code here
			vector<int> ret;
			if(root==NULL)return ret;
			search(root,ret);
			return ret;
		}
};
