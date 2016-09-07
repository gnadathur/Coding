//
//  minsubstr.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/6/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    struct GraphNode {
        char label;
        int index;
        int cost;
        GraphNode(char l, int i) : label(l), index(i), cost(-1) {}
        void print() {
            cout << label << ':' << index << ':' << cost << endl;
        }
    };
    
    void findMinSeq(vector<GraphNode>& g, char c) {
        while (g.size() && g[0].label == c) {
            g.erase(g.begin());
        }
    }
    
    void updatePrev(vector<GraphNode>& g, int index) {
        if (g.size() == 1) {
            return;
        }
        auto& e = g[g.size()-2];
        e.cost = index - e.index;
    }
    
    string minWindow(string s, string t) {
        vector<GraphNode> g;
        unordered_set<char> tset;
        if (s.length() < t.length()) {
            return string();
        }
        
        if (s.length() == 1) {
            return s == t ? s : string();
        }
        for (auto c : t) {
            tset.insert(c);
        }
        int index = 0;
        for (auto c : s) {
            if (tset.count(c)) {
                g.push_back(GraphNode(c, index));
                updatePrev(g, index);
            }
            index ++;
        }
        if (g.empty()) {
            return string();
        }
        int end = 0;
        bool compacted;
        do {
            compacted = false;
            end = 0;
            for (; end < g.size(); ++end) {
                if (end > 0 && g[0].label == g[end].label) {
                    findMinSeq(g, g[end].label);
                    compacted = true;
                }
            }
        } while (compacted);
        
        return s.substr(g[0].index, g[g.size()-1].index - g[0].index + 1);
    }
};

int main(int argc, char** argv) {
    //string s = "ADOBECODEBANC", t = "ABC";
    string s = "ab", t = "b";
    Solution sol;
    auto res = sol.minWindow(s, t);
    cout << "Result = " << res << endl;
    return 0;
}