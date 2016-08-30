//
//  ganag.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/29/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<char, int>> _check;
    
    void generateMap(unordered_map<char, int>& outp, string& s) {
        
        for (auto c : s) {
            outp[c] ++;
        }
    }
    
    bool theSame(unordered_map<char, int>& a, unordered_map<char, int>& b)
    {
        for (auto it = a.begin(); it != a.end(); ++it) {
            auto k = it->first;
            auto dit = b.find(k);
            if (dit == b.end() || dit->second != it->second) {
                return false;
            }
        }
        return true;
    }
    
    void findPlace(string& s, unordered_map<string, vector<string>>& res) {
        unordered_map<char, int> gen;
        generateMap(gen, s);
        for (auto it = _check.begin(); it != _check.end(); ++it) {
            if (theSame(gen, it->second)) {
                res[it->first].push_back(s);
                return;
            }
        }
        res[s] = { s };
        _check[s] = gen;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> res;
        
        for (auto& s : strs) {
            findPlace(s, res);
        }
        
        vector<vector<string>> fres;
        for (auto it = res.begin(); it != res.end(); ++it) {
            fres.push_back(it->second);
        }
        return fres;
    }
};

int main(int argc, char** argv)
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    s.groupAnagrams(strs);
    
    return 0;
}