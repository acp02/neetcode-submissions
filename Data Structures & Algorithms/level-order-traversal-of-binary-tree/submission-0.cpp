/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);

        while(!q.empty()) {
            vector<int> subList;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                if(front) { // make sure it's not a nullptr
                    subList.push_back(front->val);
                    q.push(front->left); // push its child
                    q.push(front->right);
                }
                q.pop();
            }
            if(!subList.empty()) ans.push_back(subList);
        }
        return ans;
    }
};
