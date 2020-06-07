// constant space solution

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        Node *parent = root;
        Node *cur = NULL;

        while (parent->left)
        {
            cur = parent;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }

            parent = parent->left;
        }

        return root;
    }
};

// constant extra space solution (neglecting stack space for recursion)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void connectUtil(Node *root)
    {
        if (!root)
            return;

        if (root->left)
        {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;
        }

        connectUtil(root->left);
        connectUtil(root->right);
    }
    Node *connect(Node *root)
    {
        connectUtil(root);

        return root;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// space: O(N) bfs solution

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<Node *> Q;
        Node *cur = NULL;
        Node *prev = NULL;
        int q_size = 0;
        Q.push(root);

        while (!Q.empty())
        {
            q_size = Q.size();
            prev = NULL;
            while (q_size--)
            {
                cur = Q.front();
                Q.pop();

                if (prev)
                    prev->next = cur;

                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);

                prev = cur;
            }
        }

        return root;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();