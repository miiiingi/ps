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
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.empty())
        {
            return nullptr;
        }

        int rootVal = preorder.at(0);
        TreeNode *root = new TreeNode(rootVal);

        auto rootPos = find(inorder.begin(), inorder.end(), rootVal);
        int leftSize = distance(inorder.begin(), rootPos);

        vector<int> leftInorder(inorder.begin(), rootPos);
        vector<int> rightInorder(rootPos + 1, inorder.end());

        vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + 1 + leftSize);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize,
                                  preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
}