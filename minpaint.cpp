//
//  minpaint.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/19/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>
#include <utility>

using namespace std;

class Solution {
    
public:
    typedef pair<int, int> Cumulative;
    
    void initMinE(Cumulative& minE, Cumulative& nextMin, int c, int j)
    {
        if (c >= nextMin.first) {
            return;
        }
        if (c <= minE.first) {
            nextMin = minE;
            minE.first = c;
            minE.second = j;
        } else {
            nextMin.first = c;
            nextMin.second = j;
        }
        
    }
    
    int findExcl(vector<vector<Cumulative>>& v, int i, int excl)
    {
        return v[i][0].second != excl ? 0 : 1;
    }
    
    void updateMin(vector<vector<Cumulative>>& v, vector<vector<int>>& costs, int i)
    {
        Cumulative minE(INT_MAX, 0), nextMin(INT_MAX, 0);
        
        if (i == 0) {
            auto& cost = costs[i];
            for (auto j = 0; j < cost.size(); ++j) {
                auto c = cost[j];
                initMinE(minE, nextMin, c, j);
            }
        } else {
            auto& cost = costs[i];
            for (auto j = 0; j < cost.size(); ++j) {
                auto index = findExcl(v, i - 1, j);
                auto c = v[i-1][index].first + cost[j];
                initMinE(minE, nextMin, c, j);
            }
        }
        //cout << "min " << minE.first << " next " << nextMin.first << endl;
        v[i][0] = minE;
        v[i][1] = nextMin;
    }
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
            return 0;
        }
        vector<vector<Cumulative>> v(costs.size(), vector<Cumulative>(2,Cumulative(0,0)));
        
        for (auto i = 0; i < costs.size(); ++i) {
            updateMin(v, costs, i);
        }
        return v[costs.size() - 1][0].first;
    }
};