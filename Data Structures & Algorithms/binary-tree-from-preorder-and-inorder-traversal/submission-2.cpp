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
    unordered_map<int,int> indexMap;
    int prev = 0; // this is a index tracking preorder Vector, adding a node one by one
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if(left > right) return nullptr; // ask Gemini for example if forgot

        TreeNode* root = new TreeNode(preorder[prev++]); // create a new node using the prev, which tracks the index. It creates all the nodes in the same order of the vector preorder
        int mid = indexMap[root->val]; // so we know the left and right subtree's indices

        root->left = dfs(preorder, left, mid - 1); // the second and third argument are very important, makes sure i understand
        // why left?? because all left nodes are smaller than the mid node.
        // what if it's recursively looping and making a sub-sub, sub-sub-sub or even more trees?  
        // look at the next line of code, dfs(preorder, mid + 1, right); 
        // (mid + 1) takes care of the left side, so it won't go beyond or mis-identify left = 0
        root->right = dfs(preorder, mid + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i; // key: val, value: index
        }
        return dfs(preorder, 0, preorder.size() - 1);
    }
};
