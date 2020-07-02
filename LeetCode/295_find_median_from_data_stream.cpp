// heap solution

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> h_left;
    priority_queue<int, vector<int>, greater<int>> h_right;
    int count = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ++count;
        if(h_left.empty()) {
            h_left.push(num);
            return;
        }
        
        if(num <= h_left.top()) h_left.push(num);
        else h_right.push(num);
        
        if(h_left.size() > h_right.size() + 1) {
            h_right.push(h_left.top());
            h_left.pop();
        }
        else if(h_right.size() > h_left.size()) {
            h_left.push(h_right.top());
            h_right.pop();
        }
    }
    
    double findMedian() {
        if(count&1) return h_left.top();
        return double(h_left.top() + h_right.top())/2.0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



 // multiset solution

 class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> nums;
    multiset<int>::iterator mid;
    
    MedianFinder() {
        mid = nums.end();
    }
    
    void addNum(int num) {
        int n = nums.size();
        nums.emplace(num);
        
        if(!n) {
            mid = nums.begin();
        }
        else if(num < *mid) {
            mid = ((n&1) ? --mid : mid);
        }
        else {
            mid = ((n&1) ? mid : ++mid);
        }
    }
    
    double findMedian() {
        if(nums.size()&1) return *mid;
        return (*mid + *next(mid)) * 0.5;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */