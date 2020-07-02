// constant space iterative solution

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
        Node *parent = root;
        Node *cur = new Node(999);
        Node *prev = cur;

        while (parent)
        {
            cur->next = parent->left;
            if (cur->next)
                cur = cur->next;
            cur->next = parent->right;
            if (cur->next)
                cur = cur->next;
            parent = parent->next;
            if (!parent)
            {
                parent = prev->next;
                cur = prev;
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
    Node *getNext(Node *root)
    {
        while (root)
        {
            if (root->left)
                return root->left;
            if (root->right)
                return root->right;

            root = root->next;
        }
        return NULL;
    }

    void connectUtil(Node *root)
    {
        if (!root)
            return;

        if (root->left)
        {
            if (root->right)
                root->left->next = root->right;
            else
                root->left->next = getNext(root->next);
        }

        if (root->right)
            root->right->next = getNext(root->next);

        connectUtil(root->right);
        connectUtil(root->left);
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

// space: O(logN) bfs solution

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