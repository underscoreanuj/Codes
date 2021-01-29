// fastest priority queue version

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef tuple<int, int, int> t3_int;

auto compare = [](const t3_int &a, const t3_int &b) {
    if (get<0>(a) > get<0>(b))
        return true;
    else if (get<0>(a) < get<0>(b))
        return false;
    else
    {
        if (get<1>(a) > get<1>(b))
            return true;
        else if (get<1>(a) < get<1>(b))
            return false;
        else
        {
            return get<2>(a) > get<2>(b);
        }
    }
};

class Solution
{
public:
    void verticalTraversalUtil(TreeNode *root, priority_queue<t3_int, vector<t3_int>, decltype(compare)> &pq, int x = 0, int y = 0)
    {
        if (root)
        {
            pq.push(make_tuple(x, y, root->val));

            verticalTraversalUtil(root->left, pq, x - 1, y + 1);
            verticalTraversalUtil(root->right, pq, x + 1, y + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> result;
        priority_queue<t3_int, vector<t3_int>, decltype(compare)> pq(compare);

        verticalTraversalUtil(root, pq);

        int x = 0, y = 0, cur = 0, prev_x, idx = 0;

        while (pq.size())
        {
            tie(x, y, cur) = pq.top();
            pq.pop();

            if (result.empty())
            {
                result.emplace_back();
                idx = 0;
                result[idx].emplace_back(cur);
            }
            else
            {
                if (prev_x == x)
                {
                    result[idx].emplace_back(cur);
                }
                else
                {
                    result.emplace_back();
                    ++idx;
                    result[idx].emplace_back(cur);
                }
            }
            prev_x = x;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// bfs solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> result;
        map<int, map<int, multiset<int>>> res;
        queue<tuple<int, int, TreeNode *>> Q;

        Q.push(make_tuple(0, 0, root));

        TreeNode *cur = NULL;
        int x = 0, y = 0;

        while (Q.size())
        {
            tie(x, y, cur) = Q.front();
            Q.pop();

            res[x][y].insert(cur->val);

            if (cur->left)
                Q.push(make_tuple(x - 1, y + 1, cur->left));
            if (cur->right)
                Q.push(make_tuple(x + 1, y + 1, cur->right));
        }

        for (auto x_r : res)
        {
            vector<int> tmp;
            for (auto y_r : x_r.second)
                tmp.insert(tmp.end(), y_r.second.begin(), y_r.second.end());
            result.emplace_back(tmp);
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dfs solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void verticalTraversalUtil(TreeNode *root, map<int, map<int, multiset<int>>> &res, int x = 0, int y = 0)
    {
        if (root)
        {
            res[x][y].insert(root->val);

            verticalTraversalUtil(root->left, res, x - 1, y + 1);
            verticalTraversalUtil(root->right, res, x + 1, y + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        map<int, map<int, multiset<int>>> res;

        verticalTraversalUtil(root, res);

        for (auto x_r : res)
        {
            vector<int> tmp;

            for (auto y_r : x_r.second)
                tmp.insert(tmp.end(), y_r.second.begin(), y_r.second.end());

            result.emplace_back(tmp);
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();