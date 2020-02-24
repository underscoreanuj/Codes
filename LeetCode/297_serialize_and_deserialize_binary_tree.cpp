/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    void serializeUtil(TreeNode *root, ostringstream &out)
    {
        if (root == NULL)
            out << "x ";
        else
        {
            out << root->val << " ";
            serializeUtil(root->left, out);
            serializeUtil(root->right, out);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serializeUtil(root, out);
        return out.str();
    }

    TreeNode *deserializeUtil(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "x")
            return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserializeUtil(in);
        root->right = deserializeUtil(in);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserializeUtil(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));