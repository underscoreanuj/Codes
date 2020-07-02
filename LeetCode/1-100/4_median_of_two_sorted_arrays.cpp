class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size(), y = nums2.size();
        int l = 0, r = nums1.size(), mid1 = 0, mid2 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, left = 0, right = 0;

        while (l <= r)
        {
            mid1 = l + ((r - l) >> 1);
            mid2 = ((x + y) >> 1) - mid1;

            x1 = mid1 > 0 ? nums1[mid1 - 1] : -999999;
            y1 = mid1 < x ? nums1[mid1] : 999999;

            x2 = mid2 > 0 ? nums2[mid2 - 1] : -999999;
            y2 = mid2 < y ? nums2[mid2] : 999999;

            if (y1 < x2)
                l = mid1 + 1;
            else if (x1 > y2)
                r = mid1 - 1;
            else
            {
                left = max(x1, x2);
                right = min(y1, y2);

                if ((x + y) & 1)
                    return right;
                else
                    return (left + right) / 2.0;
            }
        }

        return -1;
    }
};