//
//  longestsubstring.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/5/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    void updateLongest(pair<int, int>& longest, int start, int end)
    {
        auto num = end - start + 1;
        if (num > longest.second) {
            longest.first = start;
            longest.second = num;
        }
    }
    
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        unordered_map<char, int> check;
        pair<int, int> longest(0,-1);
        for (auto c : s) {
            auto it = check.find(c);
            if (it != check.end()) {
                auto pos = it->second;
                if (pos >= start) {
                    updateLongest(longest, start, end - 1);
                    start = pos + 1;
                }
            }
            check[c] = end;
            end ++;
        }
        
        updateLongest(longest, start, end - 1);
        return longest.second;
    }
};

int main(int argc, char** argv)
{
    return 0;
}