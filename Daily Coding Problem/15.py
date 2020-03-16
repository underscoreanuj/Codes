"""
#
# Good morning! Here's your coding interview problem for today.
# This problem was asked by Facebook.
# Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
# 
# 
#       reference:
#                   https://en.wikipedia.org/wiki/Reservoir_sampling        
#                   https://www.dailycodingproblem.com/blog/how-to-pick-a-random-element-from-an-infinite-stream/
#                   https://galaiko.rocks/posts/probability/
#                   
# """

import random


def pick(stream):
    random_element = 0

    for i, e in enumerate(stream):
        if random.randint(1, i+1) == 1:
            random_element = e

    return random_element


print(pick([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))


"""
# Online Judge: https://leetcode.com/problems/random-pick-index/
# 
# language: C++
# 
# 
# 
# 
# 



class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0, idx = -1;
        for(int i=0; i<this->nums.size(); ++i) {
            if(this->nums[i] == target) {
                ++count;
                if(1+(rand()%count) == 1) idx = i;
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
 
 
 
 
 """
