#include <cstddef>
#include <climits>
#include <vector>
#include <stack>
#include <list>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct GraphNode {
    int val;
    list<GraphNode*> neighbors;
    bool visited;
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

class IterativeGraph
{
    stack<GraphNode*> s;
public:
    void dfs(GraphNode* root)
    {
        
        while (root != NULL) {
            if (!root->visited) {
                visit(root);
                for (auto it = root->neighbors.rbegin(); it != root->neighbors.rend(); ++it) {
                    s.push(*it);
                    
                }
            }
            root = getNext();
        }
    }
    
    GraphNode* getNext()
    {
        if (s.empty()) {
            return NULL;
        }
        auto res = s.top();
        s.pop();
        return res;
    }
    
    void visit(GraphNode* root)
    {
        root->visited = true;
    }
};

class IterativeTree {
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* iter = root;
        vector<int> vals;
        stack<TreeNode*> s;
        do {
            
            while (iter != NULL) {
                vals.push_back(iter->val);
                if (iter->right) {
                    s.push(iter->right);
                }
                iter = iter->left;
            }
            if (s.empty()) {
                break;
            }
            iter = s.top();
            s.pop();
        } while (1);
        return vals;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* iter = root;
        vector<int> vals;
        stack<TreeNode*> s;
        do {
            while (iter != NULL) {
                s.push(iter);
                iter = iter->left;
            }
            if (s.empty()) {
                break;
            }
            iter = s.top();
            s.pop();
            vals.push_back(iter->val);
            iter=iter->right;
        } while (1);
        return vals;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* iter = root;
        vector<int> vals;
        stack<TreeNode*> s;
        unordered_set<TreeNode*> rightVisited;
        do {
            while (iter != NULL) {
                s.push(iter);
                iter = iter->left;
            }
            while (!s.empty()) {
                iter = s.top();
                auto search = rightVisited.find(iter);
                if (search == rightVisited.end()) {
                    rightVisited.insert(iter);
                    iter=iter->right;
                    break;
                } else {
                    s.pop();
                    vals.push_back(iter->val);
                }
            }
        } while (!s.empty());
        return vals;
    }
};

int main(int argc, char** argv)
{
    return 0;
}