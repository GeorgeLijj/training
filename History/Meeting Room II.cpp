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

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n=intervals.size();
        int total=n;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(intervals[j].start<intervals[i].start){
                    int tmp=intervals[j].start;
                    intervals[j].start=intervals[i].start;
                    intervals[i].start=tmp;
                    tmp=intervals[j].end;
                    intervals[j].end=intervals[i].end;
                    intervals[i].end=tmp;


                }
            }
        }
        int max_=1;
        vector<int> vec;
        for(int i=0;i<1;i++){
            int count=1;
            vec.clear();
            for(int j=i+1;j<n;j++){
                if(intervals[j].start>=intervals[i].end)break;
                if(intervals[j].end<=intervals[i].end)vec.push_back(intervals[j].end);
                for(int k=0;k<vec.size();k++){
                    if(intervals[j].start>=vec[i]){
                        count--;
                        vec[i]=INT_MAX;
                    }
                }
                //if(count<1)count=1;
                count++;
            }
            max_=max(max_,count);
        }
        return max_;
    }
};
