//
//  serializeBT.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/30/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <string>

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

class Codec {
public:
    
    int getVal(string& s, int& index) {
        auto res = 1;
        if (s[index] == '-') {
            index ++;
            res = -1;
        }
        res *= (s[index] - '0');
        index++;
        return res;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return string(1, '0');
        }
        auto s = serialize(root->left);
        s += serialize(root->right);
        s = to_string(root->val) + s;
        return s;
        
    }
    
    TreeNode* deserInternal(string& data, int& index) {
        if (data.length() == 0 || index >= data.length()) {
            return NULL;
        }
        
        if (data[index] == '0') {
            index ++;
            return NULL;
        }
        auto val = getVal(data, index);
        auto n = new TreeNode(val);
        n->left = deserInternal(data, index);
        n->right = deserInternal(data, index);
        return n;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserInternal(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));