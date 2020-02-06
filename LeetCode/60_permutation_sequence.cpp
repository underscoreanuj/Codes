class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<char> seq;
        string seq_permutation(n, '\0');
        int idx = 0;

        for (int i = 0; i < n; ++i)
        {
            seq.push_back(i + '1');
            seq_permutation[i] = i + '1';
        }
        if (k == 1)
            return seq_permutation;
        --k;
        for (int i = n; i > 0; --i)
        {
            idx = k / factorials[i - 1];
            k -= idx * factorials[i - 1];
            seq_permutation[n - i] = seq[idx];
            seq.erase(seq.begin() + idx);
        }

        return seq_permutation;
    }
};