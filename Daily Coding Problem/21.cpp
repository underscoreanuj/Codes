/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Snapchat.
 * Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
 * For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/meeting-rooms/
 * Online Judge used: https://www.lintcode.com/problem/meeting-rooms-ii/description
 * 
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {
        // Write your code here
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> PQ;
        PQ.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i)
        {
            // non-overlapping time interval -> can be assigned an existing room
            if (intervals[i].start > PQ.top())
            {
                PQ.pop();
            }
            PQ.push(intervals[i].end);
        }

        return PQ.size();
    }
};