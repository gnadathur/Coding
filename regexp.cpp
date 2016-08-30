//
//  regexp.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/30/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <array>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    struct child {
        char e;
        int index;
        bool optional;
    };
    
    struct node {
        char c;
        array<child, 2> chld;
        node() : c('\0') {
            chld[0].e = chld[1].e = '\0';
            chld[0].optional = chld[1].optional = false;
        }
    };
    
    typedef pair<int, int> point;
    
    int chIndex(node& n) {
        return n.chld[0].e == '\0' ? 0 : 1;
    }
    
    void setOptional(node& n, char c, int index) {
        for (auto i = 0; i < 2; ++i) {
            if (n.chld[i].e == c && n.chld[i].index == index) {
                n.chld[i].optional = true;
                return;
            }
        }
    }
    
    void initChild(vector<node>& v, char c, int index, int& parent, int& last) {
        if (c == '*') {
            auto& n = v[parent];
            auto i = chIndex(n);
            n.chld[i].e = n.c;
            n.chld[i].index = parent;
            n.chld[i].optional = true;
            cout << "*INIT: parent = " << parent << " e = " << n.c << " index = " << index << endl;
            last = parent;
            setOptional(v[parent-1], n.c, parent);
            parent --;
        } else {
            for (auto j = parent; j <= last; ++j) {
                auto& n = v[j];
                auto i = chIndex(n);
                n.chld[i].e = c;
                n.chld[i].index = last + 1;
                cout << "INIT: parent = " << j << " e = " << c << " index = " << index << endl;
            }
            parent = ++last;
            v[parent].c = c;
        }
    }
    
    void createSM(vector<node>& v, string& p, int& last)
    {
        int parent = 0;
        
        for (auto i = 0; i < p.length(); ++i) {
            initChild(v, p[i], i, parent, last);
        }
        
        //cout << " last " << last << endl;
    }
    
    bool charMatch(char c, char d)
    {
        return c == d || d == '.';
    }
    
    
    bool dfsMatch(string& s, vector<node>& v, int scur, int vcur, int last)
    {
        cout << "DFS: scur = " << scur << " vcur = " << vcur << endl;
        if (vcur == last) {
            return false;
        }
        if (scur == s.length()) {
            return false;
        }
        auto& n = v[vcur];
        bool res = false;
        auto c = s[scur];
        for (auto& chld : n.chld) {
            
            if (charMatch(c,chld.e)) {
                cout << "vcur = " << vcur << " e = " << chld.e << " c = " << c << " next = " << chld.index << endl;
                if (scur == s.length() - 1 && chld.index == last) {
                    return true;
                }
                res = dfsMatch(s, v, scur + 1, chld.index, last);
                if (res) {
                    return res;
                }
            }
        }
        return res;
    }
    
    bool isMatch(string s, string p) {
        
        if (s.length() == 0 && p.length() == 0) {
            return true;
        }
        if (s.length() == 0) {
            return false;
        }
        
        vector<node> v(p.length() + 1, node());
        int last;
        createSM(v, p, last);
        return dfsMatch(s,v,0,0,last);
    }
    
};