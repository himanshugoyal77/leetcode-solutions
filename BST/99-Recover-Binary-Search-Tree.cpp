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
    void inOrder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second){
        if(!root) return;

        inOrder(root->left, prev, first, second);
        if(prev){
            if(prev->val > root->val){
                if(!first){
                    first = prev;
                }
                second = root;
            }
        }
        prev = root;
        inOrder(root->right, prev, first, second);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        inOrder(root, prev, first, second);
        swap(first->val, second->val);

    }
};