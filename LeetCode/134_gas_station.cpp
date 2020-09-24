class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total_gas = 0, total_cost = 0, start = 0, cur_cost = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            cur_cost += gas[i] - cost[i];
            if (cur_cost < 0)
            {
                start = i + 1;
                cur_cost = 0;
            }

            total_gas += gas[i];
            total_cost += cost[i];
        }

        return total_gas >= total_cost ? start : -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();