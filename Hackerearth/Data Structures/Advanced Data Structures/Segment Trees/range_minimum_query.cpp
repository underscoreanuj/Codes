// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
#include <bits/stdc++.h>

using namespace std;

vector<int> a, tree;

void build(int idx, int s, int e)
{
    if (s == e)
    {
        tree[idx] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    int left = 2 * idx + 1;
    int right = left + 1;
    build(left, s, mid);
    build(right, mid + 1, e);

    tree[idx] = min(tree[left], tree[right]);
}

void update(int idx, int s, int e, int ind, int val)
{
    if (s == e)
    {
        a[ind] = val;
        tree[idx] = val;
        return;
    }

    int mid = (s + e) >> 1;
    int left = 2 * idx + 1;
    int right = left + 1;

    if (ind <= mid)
    {
        update(left, s, mid, ind, val);
    }
    else
    {
        update(right, mid + 1, e, ind, val);
    }

    tree[idx] = min(tree[left], tree[right]);
}

int query(int idx, int s, int e, int l, int r)
{
    if (r < s || l > e)
    { // completely outside the range
        return 999999;
    }
    if (s >= l && e <= r)
    { // completely within the range
        return tree[idx];
    }
    int mid = (s + e) >> 1;
    int left = 2 * idx + 1;
    int right = left + 1;

    int o1 = query(left, s, mid, l, r);
    int o2 = query(right, mid + 1, e, l, r);

    return min(o1, o2);
}

int main()
{
    int n, q, x, y, l, r;
    char c;
    cin >> n >> q;

    a = vector<int>(1000005, 0);
    tree = vector<int>(2000005, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    build(0, 0, n - 1);

    while (q--)
    {
        cin >> c;
        if (c == 'q')
        {
            cin >> l >> r;
            --l;
            --r;
            cout << query(0, 0, n - 1, l, r) << "\n";
        }
        else
        {
            cin >> x >> y;
            --x;
            update(0, 0, n - 1, x, y);
        }
    }

    return 0;
}
