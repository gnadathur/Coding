#include <cstddef>
#include <climits>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBSTInternal(TreeNode* root, int minVal, int maxVal)
    {
        if (root == NULL) {
            return true;
        }

        return (root->val > minVal &&
                root->val < maxVal &&
                isValidBSTInternal(root->left, minVal, root->val) &&
                isValidBSTInternal(root->right, root->val, maxVal));
    }

    bool isValidBST(TreeNode* root) {
        
        return isValidBSTInternal(root, INT_MIN, INT_MAX);
    }
};

int main(int argc, char** argv)
{
    return 0;
}