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

 bool ok(TreeNode*a,TreeNode*b){
     if(!a &&!b) return 1;
     if(!a || !b) return 0;
      if(a->val != b->val) return 0;
       return ok(a->left,b->left) && ok(a->right,b->right);
 }
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        if(ok(root,subRoot)) return 1;
        return   isSubtree(root->left,subRoot)|isSubtree(root->right,subRoot);
      
        
    }
    
};