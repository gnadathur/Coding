//
//  islands.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/18/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    typedef pair<int,int> Square;
    
    bool isLand(char c)
    {
        return c == '1';
    }
    
    bool isIsland(vector<vector<char>>& grid, int r, int c, int rmax, int cmax)
    {
        
        return  (r == 0 || grid[r-1][c] == '0') &&
        (r == rmax - 1 || grid[r+1][c] == '0') &&
        (c == 0 || grid[r][c-1] == '0') &&
        (c == cmax -1 || grid[r][c+1] == '0');
    }
    
    void newLand(vector<vector<int>>& lands, int r, int c, int& landId)
    {
        ++landId;
        lands[r][c] = landId;
    }
    
    int Up(vector<vector<int>>& lands, int r, int c)
    {
        return r == 0 ? 0 : lands[r-1][c];
    }
    
    int Left(vector<vector<int>>& lands, int r, int c)
    {
        return c == 0 ? 0 : lands[r][c-1];
    }
    
    int findMinEqualent(unordered_map<int, int>& equalent, int v)
    {
        unordered_map<int, int>::iterator it;
        do {
            it = equalent.find(v);
            if (it != equalent.end()) {
                v = it->second;
            }
        } while (it != equalent.end());
        return v;
    }
    
    int findEqualent(unordered_map<int, int>& equalent, int up, int left)
    {
        auto equp = findMinEqualent(equalent, up);
        auto eqleft = findMinEqualent(equalent, left);
        if (equp == eqleft) {
            return equp;
        }
        auto eq = min(equp, eqleft);
        if (eq == equp) {
            //cout << "Inserting key " << eqleft << " val " << eq << " other " << equp << endl;
            equalent[eqleft] = eq;
        } else {
            //cout << "Inserting key " << equp << " val " << eq << " other " << eqleft << endl;
            equalent[equp] = eq;
        }
        return eq;
    }
    
    void insertInIslands(vector<vector<int>>& lands, int r, int c, int rmax, int cmax, int& landId,
                         unordered_map<int, int>& equalent,
                         vector<vector<char>>& grid)
    {
        if (isIsland(grid,r,c, rmax, cmax)) {
            newLand(lands, r, c, landId);
            return;
        }
        
        auto up = Up(lands, r, c);
        auto left = Left(lands, r, c);
        int lid = 0;
        if (up == 0 && left != 0) {
            lid = left;
        } else if (left == 0 && up != 0) {
            lid = up;
        } else if (up != 0 && left != 0) {
            if (up != left) {
                lid = findEqualent(equalent, up, left);
            } else {
                lid = up;
            }
        }
        
        if (!lid) {
            newLand(lands, r, c, landId);
            return;
        }
        lands[r][c] = lid;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        vector<vector<int>> lands(grid.size(), vector<int>(grid[0].size(),0));
        unordered_map<int, int> eq;
        int landId = 0;
        
        for (int r = 0; r < grid.size(); ++r) {
            auto& cols = grid[r];
            for (int c = 0; c < cols.size(); ++c) {
                auto val = cols[c];
                if (isLand(val)) {
                    insertInIslands(lands, r, c, grid.size(), cols.size(), landId, eq, grid);
                }
            }
        }
        int count = 0;
        for (auto i = 1; i <= landId; ++i) {
            if (eq.find(i) == eq.end()) {
                count ++;
            }
        }
        return count;
    }
};

int main(int argc, char** argv)
{
       
    vector<vector<char>>   v = {{ '1', '1', '1'},
                                { '0', '1', '0'},
                                { '1', '1', '1'} };
    Solution s;
    cout << "Number of islands " << s.numIslands(v) << endl;
    return 0;
}

