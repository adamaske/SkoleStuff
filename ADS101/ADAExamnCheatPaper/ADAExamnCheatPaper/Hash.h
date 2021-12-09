#pragma once
#include <iostream>
#include <list>

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
	int rehashConstant = 17;
	Hash(int x);
	Hash();
	void InsertItem(int key);
	void DeleteItem(int key);
	int hashFunction(int x);
	void DisplayHash();
	int Rehash1(int i);
	int Rehash2(int i, int j);
	int Doublehash(long key);
	int Bucket = 0;
	std::list<int> *table{};

	void TestHash();
	void TestUnorderdSet();
	void TestUnorderdMultiset();
};