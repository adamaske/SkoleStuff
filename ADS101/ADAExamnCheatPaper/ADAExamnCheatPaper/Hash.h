#pragma once
#include <iostream>
struct Test {
	int key;
	std::string s;
	bool operator == (const Test& t2) const { return key == t2.key; }
};
namespace std {
	template<>
	class hash<Test> {
	public:
		size_t operator() (const Test& t) const {
			return t.key % 7;
		}
		bool operator() (const Test& t1, const Test& t2) {
			return t1.key == t2.key;
		}
	};
}
class Hash {
public:
	void TestHash();
	void TestUnorderdSet();
	void TestUnorderdMultiset();
};