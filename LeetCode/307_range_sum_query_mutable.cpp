// BIT based solution

class NumArray
{
    vector<int> f, nums;

    void update_tree(int idx, int val)
    {
        while (idx < f.size())
        {
            f[idx] += val;
            idx += (idx & -idx);
        }
    }

    int get_from_tree(int idx)
    {
        int res = 0;
        while (idx > 0)
        {
            res += f[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->f = vector<int>(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); ++i)
            update_tree(i + 1, nums[i]);
    }

    void update(int index, int val)
    {
        update_tree(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        return get_from_tree(right + 1) - get_from_tree(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
