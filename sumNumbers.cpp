//
//  sumNumbers.cpp
//  xcode
//
//  Created by Gokul Nadathur on 7/12/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numSet;
        for (auto i = 0; i < nums.size(); ++i) {
            auto srch = target - nums[i];
            auto it = numSet.find(srch);
            if (it != numSet.end()) {
                return vector<int>{ it->second, i};
            }
            numSet[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main(int argc, char** argv)
{
    vector<int> v = { 2, 7, 11, 15 };
    Solution s;
    s.twoSum(v, 9);
    return 0;
}