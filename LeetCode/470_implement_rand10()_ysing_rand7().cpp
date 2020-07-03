// better solution

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int result = 0;
        while (true)
        {
            result = (rand7() - 1) * 7 + rand7();
            if (result <= 40)
                return (result - 1) % 10 + 1;
            result -= 40;
            result = (result - 1) * 7 + rand7();
            if (result <= 60)
                return (result - 1) % 10 + 1;
            result -= 60;
            result = (result - 1) * 7 + rand7();
            if (result <= 20)
                return (result - 1) % 10 + 1;
        }
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple solution

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int result = 0;
        do
        {
            result = (rand7() - 1) * 7 + rand7();
        } while (result > 40);
        return 1 + ((result - 1) % 10);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();