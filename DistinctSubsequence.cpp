/*
 * DistinctSubsequence.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: gokul
 */

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) int(c) - int('a')
struct Trie {
	Trie *children[ALPHABET_SIZE];
	bool isLeaf;
	Trie() : isLeaf(false) {}
};

class Solution {
public:
	int countDistinctSubSequence(const string& s) {
		auto len = s.length();
		Trie* root = nullptr;
		for (auto i = 0; i < len; ++i) {
			for (auto j = i + 1; j < len; ++j) {
				auto node = new Trie();

			}
		}
	}
};
