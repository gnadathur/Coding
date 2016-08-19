//
//  version.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/18/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int firstBadVersion(int n) {
        
        auto l = 1, h = n;
        if (n == 1) {
            return isBadVersion(n) ? n : 0;
        }
        while (h >= l) {
            auto mid = l/2 + h/2;
            auto res = isBadVersion(mid);
            auto ismid = res && (mid == 1 || !isBadVersion(mid-1));
            
            if (ismid) {
                return mid;
            }
            if (!res && isBadVersion(mid+1)) {
                return mid + 1;
            }
            if (res) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};