//
//  nim.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/5/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool _canWinNim(int n, vector<int>& v, int player)
    {
        if (player == 0 && n <= 3) {
            return true;
        }
        if (player == 1 && n <= 3) {
            return false;
        }
        
        if (v[n-1] == -1) {
            bool res = _canWinNim(n-1, v, !player) ||
                       _canWinNim(n-2, v, !player) ||
                       _canWinNim(n-3, v, !player);
            v[n-1] = res ? 1 : 0;
        }
        return v[n-1];
    }
    
    bool __canWinNum(int n) {
        return n % 4 != 0;
    }
    
    bool canWinNim(int n) {
        if (n == 0) {
            return false;
        }
        vector<int> v(n, -1);
        return _canWinNim(n, v, 0);
    }
};

int main(int argc, char** argv)
{
    return 0;
}