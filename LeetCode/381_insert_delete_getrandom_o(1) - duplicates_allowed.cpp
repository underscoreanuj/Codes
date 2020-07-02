class RandomizedCollection
{
    vector<int> nums;
    unordered_map<int, list<int>> mem;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool res = !mem.count(val);
        nums.emplace_back(val);
        mem[val].emplace_back(nums.size() - 1);

        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (!mem.count(val))
            return false;

        int idx = mem[val].back();
        if (idx != nums.size() - 1)
        {
            nums[idx] = nums.back();
            mem[nums.back()].pop_back();
            if (mem[nums.back()].size() == 0 || mem[nums.back()].back() < idx)
                mem[nums.back()].emplace_back(idx);
            else
                mem[nums.back()].emplace_front(idx);
        }

        nums.pop_back();
        mem[val].pop_back();
        if (mem[val].size() == 0)
            mem.erase(val);

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();