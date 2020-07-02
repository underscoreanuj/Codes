/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
 * For example, given the following Node class
    -------------------------------------------------------------------------
    |class Node:                                                            |
    |def __init__(self, val, left=None, right=None):                        |
    |    self.val = val                                                     |
    |    self.left = left                                                   |
    |    self.right = right                                                 |
    -------------------------------------------------------------------------
 * The following test should pass:
    -------------------------------------------------------------------------
    |node = Node('root', Node('left', Node('left.left')), Node('right'))    |
    |assert deserialize(serialize(node)).left.left.val == 'left.left'       |
    -------------------------------------------------------------------------
 * 
 * Online Judge: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * 
*/

// **************************************   my approach   **************************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(root == NULL) return "x,";

//         queue<TreeNode*> Q;
//         Q.push(root);
//         TreeNode* tmp = NULL;
//         string ret;

//         while(!Q.empty()) {
//             tmp = Q.front();
//             Q.pop();

//             if(tmp) {
//                 ret += to_string(tmp->val) + ",";
//                 Q.push(tmp->left);
//                 Q.push(tmp->right);
//             }
//             else ret += "x,";
//         }

//         int ind = ret.length()-2;
//         while(ret[ind] == 'x') ind -= 2;

//         return ret.substr(0, ind+2);

//     }

//     vector<TreeNode*> getValues(string data) {
//         vector<TreeNode*> ret;
//         size_t cur_pos = 0, pos = 0;
//         pos = data.find(",", cur_pos);
//         string tmp;
//         while(pos != string::npos) {
//             tmp = data.substr(cur_pos, pos-cur_pos);
//             if(tmp == "x") ret.push_back(NULL);
//             else ret.emplace_back(new TreeNode(stoi(tmp)));
//             cur_pos = pos+1;
//             pos = data.find(",", cur_pos);
//         }

//         return ret;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         vector<TreeNode*> tree = getValues(data);
//         int ind = 1;

//         for(int i=0; i<tree.size(); ++i) {
//             if(tree[i]) {
//                 if(ind < tree.size()) tree[i]->left = tree[ind];
//                 if(ind+1 < tree.size()) tree[i]->right = tree[ind+1];
//                 ind +=2;
//             }
//         }

//         return tree[0];
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// **************************************   General approach (using preorder traversal)   **************************************

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
