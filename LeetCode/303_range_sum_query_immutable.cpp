class NumArray
{
    vector<int> preSum;

public:
    NumArray(vector<int> &nums)
    {
        preSum = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
            preSum[i + 1] = nums[i] + preSum[i];
    }

    int sumRange(int i, int j)
    {
        return preSum[j + 1] - preSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */