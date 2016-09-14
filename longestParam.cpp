#include <string>
#include <climits>

using namespace std;

class Solution
{
public:

	int _left, _right;
	int _max;
	
	Solution() : _left(0), _right(0), _max(INT_MIN) {}

	inline void increment(char c) {
		if (c == '(') {
			_left ++;
		} else {
			_right ++;
		}
	}

	int longestValidParentheses(string s) {
		
		for (auto c : s) {
			increment(c);
			if (_right > _left) {
				_left = _right = 0;
			} else if (_left == _right) {
				auto chrs = _right - _left + 1;
				_max = max(chrs, _max);
				_left = _right = 0;
			} 
		}
		return 0;
	}
};

int main(int argc, char** argv)
{
	return 0;
}
