class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;

        int i = m - 1, j = n - 1;
        for (int idx = nums1.size() - 1; idx >= 0; --idx)
        {
            nums1[idx] = (i >= 0 ? nums1[i] : INT_MIN) > (j >= 0 ? nums2[j] : INT_MIN) ? nums1[i--] : nums2[j--];
        }
    }
};