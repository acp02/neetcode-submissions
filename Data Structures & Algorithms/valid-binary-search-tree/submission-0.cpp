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
    bool isValidBST(TreeNode* root) {
        return valid(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

    bool valid(TreeNode* root, int lowest, int highest) {
        if(!root) return true;
        if(!(root->val > lowest && root->val < highest)) return false; // a characteristic of a binary tree is that left side of the node must be smaller than right side of the node. Not only that, the same pattern continues to its ancestors, and this algorithm consistently updates the boundary of highest and lowest value so a node must be within the range. Otherwise, the tree will not be a binary search tree.
        return valid(root->left, lowest, root->val) && valid(root->right, root->val, highest);
    }
};
