//
//  powerset.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/6/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    void appendSet(vector<vector<int>>& v, int i, vector<int>& nums)
    {
        
        for (auto index = 0; index < nums.size(); ++index) {
            auto bit = (i & (1 << index));
            if (bit) {
                v[i].push_back(nums[index]);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        auto maxSets = 1 << nums.size();
        vector<vector<int>> v(maxSets, vector<int>{});
        for (auto i = 0; i < maxSets; ++i) {
            appendSet(v, i, nums);
        }
        return v;
    }
};

int main(int argc, char** argv)
{
    
    return 0;
}