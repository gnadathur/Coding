/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    inline bool isLeaf(TreeNode* n) {
        return n->left == NULL && n->right == NULL;
    }
    bool isValidBSTInternal(TreeNode* root, int& minVal, int& maxVal)
    {
        int currMin, currMax;

        if (root == NULL) {
            return true;
        }
        if (isLeaf(root)) {
            minVal = maxVal = root->val;
            return true;
        }

        if (root->left) {
            if (!isValidBSTInternal(root->left, minVal, maxVal)) {
                return false;
            }

            if (root->val <= maxVal) {
                return false;
            }


            currMin = min(root->val, minVal);
            currMax = max(root->val, maxVal);
        } else {
            currMin = currMax = root->val;
        }

        if (root->right) {
            if (!isValidBSTInternal(root->right, minVal, maxVal)) {
                return false;
            }
            if (root->val >= minVal) {
                return false;
            }
            minVal = min(minVal, currMin);
            maxVal = max(maxVal, currMax);
        } else {
            minVal = currMin;
            maxVal = currMax;
        }


        return true;
    }

    bool isValidBST(TreeNode* root) {
        int minVal, maxVal;
        return isValidBSTInternal(root, minVal, maxVal);
    }
};
