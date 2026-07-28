/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    ListNode* head;
    int getLength(ListNode* node) {
        int len = 0;
        while (node) {
            len++;
            node = node->next;
        }
        return len;
    }
    TreeNode* BuildBST(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* leftChild = BuildBST(left, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        head = head->next;
        root->right = BuildBST(mid + 1, right);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        int n = getLength(head);
        return BuildBST(0, n - 1);
    }
};