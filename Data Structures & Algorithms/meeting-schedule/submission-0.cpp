/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        

        //step1 : sort by the start time
        sort(intervals.begin(),intervals.end());

        //step2: check overlap
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]){
                return false;
            }
        }
        return false;
    }
};
