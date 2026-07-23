class Solution {
public:
    int ans = 0;

    // 0 -> not covered
    // 1 -> has camera
    // 2 -> covered

    int dfs(TreeNode* root) {

        if (!root)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 || right == 0) {
            ans++;
            return 1;
        }

        if (left == 1 || right == 1)
            return 2;

        return 0;
    }

    int minCameraCover(TreeNode* root) {

        if (dfs(root) == 0)
            ans++;

        return ans;
    }
};