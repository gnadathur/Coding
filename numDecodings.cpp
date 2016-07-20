//
//  numDecodings.cpp
//  xcode
//
//  Created by Gokul Nadathur on 7/19/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    unordered_map<int, int> _numSubDecodings;
    bool isNextValid(string& s, int index)
    {
        if (index >= s.length() - 1 || !isValid(s, index)) {
            return false;
        }
        //auto val = stoul(s.substr(index, 2));
        auto val = (s[index] - '0') * 10 + s[index] - '0';
        return val <= 26;
    }
    
    bool isValid(string& s, int index)
    {
        return s[index] != '0';
    }
    
    int findSubDecodings(string& s, int index)
    {
        auto it = _numSubDecodings.find(index);
        int numPaths = 0;
        if ( it == _numSubDecodings.end()) {
            numPaths = _numSubDecodings[index] = findDecodings(s, index);
        } else {
            numPaths = it->second;
        }
        return numPaths;
    }
    
public:
    
    int findDecodings(string& s, int start)
    {
        
        if (start >= s.length()) {
            return 0;
        }
        
        if (start == s.length() - 1 && isValid(s, start)) {
            return 1;
        }
        
        auto n = isValid(s, start) ? findSubDecodings(s, start + 1) : 0;
        if (isNextValid(s, start)) {
            int nextSeq;
            if (start + 2 == s.length()) {
                nextSeq = 1;
            } else {
                nextSeq = findSubDecodings(s, start+2);
            }
            n += nextSeq;
        }
        return n;
    }
    
    int numDecodings(string s) {
        if (s.length() == 1 && isValid(s, 0))  {
            return 1;
        }
        if (s.length() == 0) {
            return 0;
        }
        return findDecodings(s, 0);
    }
};

int main(int argc, char** argv)
{
    string inp = "110";
    Solution s;
    cout << s.numDecodings(inp) << endl;
}