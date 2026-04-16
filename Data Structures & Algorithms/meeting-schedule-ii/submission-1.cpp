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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        int n = intervals.size();

        vector<int>start,end;

        //step1 : seprate start & end
        for(auto &it :intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }

        //sort both
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i=0,j=0;
        int rooms = 0,maxRooms = 0;

        //step 3: compare
        while(i<n){
            if(start[i]<end[j]){
                rooms++;
                i++;
            }
            else{
                rooms--;
                j++;
            }
            maxRooms = max(maxRooms,rooms);
        }
        return maxRooms;
    }
};
