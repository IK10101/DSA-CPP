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
    void recursivePostorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;
        arr.push_back(root->data);
        recursivePostorder(root->left, arr);
        recursivePostorder(root->right, arr);
    }

   public:
    vector<int> postorder(TreeNode* root) {
        vector<int> arr;
        recursivePostorder(root, arr);
        return arr;
    }
};

