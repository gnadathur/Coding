/*
 * DistinctSubsequence.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: gokul
 */

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<uint64_t, uint64_t> _counts;
public:
    
    inline uint64_t indexHash(uint32_t sindex, uint32_t tindex)
    {
        return ((uint64_t)sindex << 32 | tindex);
    }
    
	uint64_t countDistinctSubSequence(const string& s, const string& t, uint32_t sindex, uint32_t tindex) {
        auto slen = s.length();
        auto tlen = t.length();
        if (sindex >= slen || tindex >= tlen) {
            return 0;
        }
        uint64_t hashVal = indexHash(sindex, tindex);
        
        if (tlen-tindex > slen - sindex) {
            _counts[hashVal] = 0;
            return 0;
        }
        unordered_map<uint64_t, uint64_t>::const_iterator it = _counts.find(hashVal);
        if (it != _counts.end()) {
            return it->second;
        }
        auto searchChar = t[tindex];
        auto numSeq = 0;
        size_t i = sindex;
        while (i < slen) {
            i = s.find(searchChar, i);
            if (i == string::npos) {
                break;
            }
            if (tindex == tlen - 1) {
                numSeq++;
            
            } else {
                numSeq += countDistinctSubSequence(s, t, i + 1, tindex+1);
            }
            ++i;
        }
        _counts[hashVal] = numSeq;
        return numSeq;
	}
};

int main(int argc, char** argv)
{
    std::string s = "ccc";
    std::string t = "c";
    Solution sol;
    
    cout << "Total = " << sol.countDistinctSubSequence(s, t, 0, 0) << endl;
    return 0;
}