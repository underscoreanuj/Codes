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
            // overlapping time interval
            if (intervals[i].start <= PQ.top())
            {
                PQ.push(intervals[i].end);
            }
            else
            {
                PQ.pop();
                PQ.push(intervals[i].end);
            }
        }

        return PQ.size();
    }
};