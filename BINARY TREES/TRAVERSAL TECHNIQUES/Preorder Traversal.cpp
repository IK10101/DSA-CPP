#include <iostream>
#include <vector>
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
    void recursivePreorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;
        arr.push_back(root->data);
        recursivePreorder(root->left, arr);
        recursivePreorder(root->right, arr);
    }

   public:
    vector<int> preorder(TreeNode* root) {
        vector<int> arr;
        recursivePreorder(root, arr);
        return arr;
    }
};

