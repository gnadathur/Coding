//
//  try.cpp
//  xcode
//
//  Created by Gokul Nadathur on 8/30/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n0 = 2, n1 = 3, n2 = 4;
    vector<int> v(n0+n1+n2, 0);
    fill(v.begin()+n0, v.begin()+n0+n1, 1);
    fill(v.begin()+n0+n1, v.end(), 2);
    for (auto e : v) {
        cout << e << " ";
    }
}