//Problem Statement

// Given a binary tree root, find if it is height-balanced or not.

// A tree is height-balanced if the difference between the heights of left and right subtrees is not more than one for all nodes of the tree. 


#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight == -1 || rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};