#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> zeroPos;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zeroPos.push(i);
            } else if (zeroPos.size()) {
                auto pos = zeroPos.front();
                zeroPos.pop();
                nums[pos] = nums[i];
                nums[i] = 0;
                zeroPos.push(i);
            }
        }
    }
};

int main(int argc, char** argv)
{
    Solution s;
    vector<int> v = { 0, 1, 0, 3, 12 };
    s.moveZeroes(v);
    return 0;
}