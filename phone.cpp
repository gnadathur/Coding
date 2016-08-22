//
//  phone.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/21/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> ntos = {{ '2', string("abc")},
            { '3', string("def")},
            { '4', string("ghi")},
            { '5', string("jkl")},
            { '6', string("mno")},
            { '7', string("pqrs")},
            { '8', string("tuv")},
            { '9', string("wxyz")}};
        vector<string> res;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            char c = *it;
            auto strs = ntos[c];
            vector<string> tmp;
            for (auto chr : strs) {
                if (it == digits.rbegin()) {
                    tmp.push_back(string(1,chr));
                } else {
                    for (auto& s : res) {
                        tmp.push_back(string(1, chr) + s);
                    }
                }
            }
            res = tmp;
        }
        return res;
        
    }
};

int main(int argc, char** argv)
{
    string inp("2");
    Solution s;
    s.letterCombinations(inp);
    return 0;
}