class Solution
{
public:
	string getSmallestString(int n, int k)
	{
		string result(n, 'a');
		int idx = n - 1, rem = 0;
		k -= n;

		while (k)
		{
			rem = min(k, 25);
			result[idx--] += rem;
			k -= rem;
		}

		return result;
	}
};
