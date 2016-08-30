//
//  wordbreak.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/30/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        auto res = false;
        for (auto i = 0; i < s.length(); ++i) {
            auto sstr = s.substr(0, s.length() - i);
            if (wordDict.count(sstr)) {
                res = i != 0 ? wordBreak(s.substr(s.length() - i), wordDict) : true;
                if (res) {
                    break;
                }
            }
        }
        return res;
    }
};