class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int boats = 0, l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());

        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
                ++l;
            --r;
            ++boats;
        }

        return boats;
    }
};