/*
 * mergeIntervals.cpp
 *
 *  Created on: Jun 26, 2016
 *      Author: gokul
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // b is contained in a
    bool containedIn(Interval* a, Interval* b) {
        return (a->start <= b->start && a->end >= b->end);
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty() || intervals.begin() == intervals.end()) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.end == b.end ? a.start < b.start : a.end < b.end; });
        vector<Interval> res;
        res.push_back(intervals[0]);
        for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            auto last = &res.back();
            if (it->start > last->end) {
                res.push_back(*it);
                continue;
            }
            if (it->start <= last->end) {
                last->end = it->end;
            }
            if (it->start < last->start) {
                last->start = it->start;
            }
        }
        std::sort(res.begin(), res.end(), [](Interval a, Interval b) { return a.start < b.start; });
        vector<Interval> final;
        final.push_back(res[0]);
        for (auto it = res.begin() + 1; it != res.end(); ++it) {
            auto last = &final.back();
            if (containedIn(last, &(*it))) {
                continue;
            }
            if (it->start <= last->end) {
                last->end = it->end;
                continue;
            }

            final.push_back(*it);
        }
        return final;
    }
};
