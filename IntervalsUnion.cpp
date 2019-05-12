#include<vector>
#include <algorithm>

struct EndPoint{
    bool isClosed;
    int val;
};
struct Interval {
    EndPoint left, right;
};

void SortIntervals(std::vector<Interval>* intervals){
    std::sort(begin(*intervals), end(*intervals),
              [](const Interval& a, const Interval& b){
                  return a.left.val <= b.left.val;
              });
}

std::vector<Interval> IntervalsUnion(std::vector<Interval>& intervals){
    SortIntervals(&intervals);
    std::vector<Interval> result;
    Interval t = intervals[0];
    int i = 1;
    while (i < intervals.size()){
        if  ((intervals[i].right.val > t.right.val) && ( (t.right.val > intervals[i].left.val) || ( (t.right.val == intervals[i].left.val) && (t.right.isClosed || intervals[i].left.isClosed) ))) {
                t.right = intervals[i].right;
        }
        else {
            result.emplace_back(t);
            t = intervals[i];
        }
        if (i++ == intervals.size()-1) result.emplace_back(t);
    }
    return result;
}