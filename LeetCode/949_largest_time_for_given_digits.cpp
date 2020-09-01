class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        sort(A.begin(), A.end(), greater<int>());

        do
        {
            if (A[0] * 10 + A[1] < 24 && A[2] * 10 + A[3] < 60)
            {
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
            }
        } while (prev_permutation(A.begin(), A.end()));

        return "";
    }
};