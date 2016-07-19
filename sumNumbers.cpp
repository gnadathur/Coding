//
//  sumNumbers.cpp
//  xcode
//
//  Created by Gokul Nadathur on 7/12/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, vector<pair<int, int>>> _sums;
    unordered_map<int, unordered_set<int>> _singles;
    
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
    
    void findSums(int i, vector<int>& nums)
    {
        
        for (auto j = i + 1; j < nums.size(); ++j) {
            vector<pair<int, int>> res;
            auto srch = -1 * (nums[i] + nums[j]);
            auto it = _singles.find(srch);
            if (it == _singles.end()) {
                continue;
            }
            
            it->second.erase(j);
            for (auto val : it->second) {
                
                res.push_back(pair<int, int>(j, val));
            }
            _sums[-nums[i]] = res;
        }
        return;
    }
    
    vector<vector<int>> zeroSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        
        for (auto i = 0; i < nums.size(); ++i) {
            auto it = _singles.find(nums[i]);
            if (it == _singles.end()) {
                _singles[nums[i]] = unordered_set<int>({i});
            } else {
                it->second.insert(i);
            }
        }
        for (auto i = 0; i < nums.size() - 2; ++i) {
            auto it = _sums.find(-nums[i]);
            if (it == _sums.end()) {
                findSums(i, nums);
                it = _sums.find(-nums[i]);
            }
            it = _sums.find(-nums[i]);
            auto& sums = it->second;
            for (auto sumIt = sums.begin(); sumIt != sums.end(); ++sumIt) {
                if (sumIt->first <= i || sumIt->second <= i) {
                    continue;
                }
                res.push_back({nums[i], nums[sumIt->first], nums[sumIt->second]});
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    
    //vector<int> v = { 2, 7, 11, 15 };
    //s.twoSum(v, 9);
    // zero Sum 3 numbers input
    vector<int> v = { -1, 0, 1, 2, -1, -4 };
    auto res = s.zeroSum(v);
    for (auto v : res) {
        cout << endl;
        for ( auto i : v) {
            cout << i << " ";
        }
    }
    return 0;
}