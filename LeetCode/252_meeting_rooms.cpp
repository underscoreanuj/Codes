// solved on lintcode: https://www.lintcode.com/problem/meeting-rooms/description<Paste>

/**
 * Definition of Interval:
 * class Interval {
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
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        // Write your code here
        if (intervals.size() == 0)
            return true;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.end;
        });

        int prevEndTime = intervals[0].end;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start < prevEndTime)
                return false;
            prevEndTime = intervals[i].end;
        }

        return true;
    }
};
