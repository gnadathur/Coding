//
//  stockdiff.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/21/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int start, end, curr;
        start = end = curr = 0;
        
        for (auto i = 0; i < prices.size(); ++i) {
            if (prices[i] > prices[end]) {
                end = i;
            }
            if (prices[i] < prices[start]) {
                curr = max(curr, prices[end] - prices[start]);
                start = end = i;
            }
        }
        return max(curr, prices[end] - prices[start]);
    }
};