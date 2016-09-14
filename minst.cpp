//
//  minst.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/13/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    struct trackMin {
        int val;
        int index;
        trackMin() : val(0), index(0) {}
        trackMin(int v, int i) : val(v), index(i) {}
    };
    
    stack<int> vals;
    stack<trackMin> mins;
    int currentMin;
    
    /** initialize your data structure here. */
    MinStack() {
        currentMin = INT_MAX;
    }
    
    void push(int x) {
        vals.push(x);
        if (x <= currentMin) {
            currentMin = x;
            mins.push(trackMin(x,vals.size()));
        }
    }
    
    void pop() {
        auto mintop = mins.top();
        
        if (vals.size() == mintop.index) {
            mins.pop();
            currentMin = mins.size() != 0 ? mins.top().val : INT_MAX;
        }
        vals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top().val;
    }
};

int main(int argc, char** argv)
{
    return 0;
}