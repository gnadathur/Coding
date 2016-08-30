//
//  circustower.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/27/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <utility>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<int, int> HtWt;

bool fillLevel(int level, vector<HtWt>::iterator& it, HtWt& lastMax, vector<vector<HtWt>>& res, vector<HtWt>& inp)
{
    int needed = level;
    int htm = INT_MIN, wtm = INT_MIN;
    while (it != inp.end() && needed) {
        if (it->first >= lastMax.first && it->second >= lastMax.second) {
            res[level].emplace_back(*it);
            htm = max(htm, it->first);
            wtm = max(wtm, it->second);
            needed--;
            ++it;
        } else {
            break;
        }
    }
    lastMax.first = htm;
    lastMax.second = wtm;
    return needed == 0;
}

vector<HtWt> longestTower(vector<HtWt>& inp)
{
    HtWt m(INT_MAX, INT_MAX);
    vector<vector<HtWt>> res(inp.size(), vector<HtWt>());
    
    m = inp[0];
    auto found = false;
    for (auto& e : inp) {
        if (e.first < m.first && e.second < m.second) {
            found = true;
            m = e;
        }
        
    }
    if (!found) {
        return {};
    }
    
    for (auto& e : inp) {
        e.first -= m.first;
        e.second -= m.second;
    }
    
    std::sort(inp.begin(), inp.end(),
              [] (HtWt a, HtWt b) {
                  return (a.first * a.first + a.second * a.second <
                          b.first * b.first + b.second * b.second);
              });
    for (auto& e : inp) {
        e.first  += m.first;
        e.second += m.second;
    }
    
    int level = 1;
    HtWt lastMax(INT_MIN, INT_MIN);
    auto it = inp.begin();
    while (it != inp.end()) {
        if (fillLevel(level, it, lastMax, res, inp) == false) {
            break;
        }
        level++;
    }
    vector<HtWt> longest;
    level = 1;
    for (auto it = res.begin() + 1; it != res.end() && it->size() == level; ++it, ++level) {
        longest.insert(longest.end(), it->begin(), it->end());
    }
    return longest;
}

int main(int argc, char** argv)
{
    vector<HtWt> inp = { HtWt(65, 100), HtWt(70, 150), HtWt(56, 90), HtWt(75, 190), HtWt(60, 95), HtWt(68, 110) };
    auto outp = longestTower(inp);
    for (auto& o : outp) {
        cout << o.first << "," << o.second << endl;
    }
}