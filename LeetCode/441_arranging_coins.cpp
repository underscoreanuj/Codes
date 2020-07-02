// O(1) solution

class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(2*(long)n+0.25)-0.5;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(logN) solution

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n, ans = 0;
        long mid = 0;
        
        while(l <= r) {
            mid = l + ((r-l)>>1);
            
            if(((mid*(mid+1))>>1) <= n) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        
        return ans;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(N) solution

class Solution {
public:
    int arrangeCoins(int n) {
        long long int res = 1;
        
        while(true) {
            if((res*(res+1))>>1 <= n) ++res;
            else break;
        }
        return res-1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();