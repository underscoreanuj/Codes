class OrderedStream
{
    vector<string> stream;
    int idx;

public:
    OrderedStream(int n)
    {
        stream = vector<string>(n, "?");
        idx = 0;
    }

    vector<string> insert(int id, string value)
    {
        vector<string> result;
        --id;
        stream[id] = value;

        if (idx == id)
        {
            while (idx < stream.size() && stream[idx] != "?")
            {
                result.emplace_back(stream[idx++]);
            }
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */