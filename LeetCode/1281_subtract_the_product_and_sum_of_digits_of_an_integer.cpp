class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int digit_sum = 0, product_sum = 1, x = n, rem = 0;
        while (x)
        {
            rem = x % 10;
            x /= 10;
            digit_sum += rem;
            product_sum *= rem;
        }

        return product_sum - digit_sum;
    }
};