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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Cases
        if(subRoot == nullptr) return false;
        if(!root && !subRoot) return true;
        if((!root && subRoot) || (root && !subRoot)) return false;

        // Recursive Steps
        bool state = false;
        if(root->val != subRoot->val) {
            bool leftState = isSubtree(root->left, subRoot);
            bool rightState = isSubtree(root->right, subRoot);
            state = leftState || rightState;
        } else if (root->val == subRoot->val) {
            state = sameTree(root, subRoot);
            if(state) return true;
            else {
                bool leftState = isSubtree(root->left, subRoot);
                bool rightState = isSubtree(root->right, subRoot);
                state = leftState || rightState;
            } 
        }
        return state;
    }

    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2)) return false;

        bool leftState = sameTree(root1->left, root2->left);
        bool rightState = sameTree(root1->right, root2->right);
        bool valState = true;
        if(root1->val != root2->val) valState = false;
        return leftState && rightState && valState;
    }
};
