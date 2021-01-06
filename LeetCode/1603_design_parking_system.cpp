class ParkingSystem
{
    vector<int> space;

public:
    ParkingSystem(int big, int medium, int small)
    {
        this->space = {0, big, medium, small};
    }

    bool addCar(int carType)
    {
        return this->space[carType]-- > 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */