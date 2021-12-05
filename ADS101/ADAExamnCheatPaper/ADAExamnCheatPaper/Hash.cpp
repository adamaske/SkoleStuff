#include "Hash.h"
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <list>
Hash::Hash(int x)
{
	
	Bucket = x;
	table = new std::list<int>[Bucket];
}
Hash::Hash()
{
}
void Hash::InsertItem(int key)
{
	
	int index = hashFunction(key);
	table[index].push_back(key);
}
void Hash::DeleteItem(int key)
{
	
	int index = hashFunction(key);

	std::list<int>::iterator it;
	for (it = table[index].begin(); it != table[index].end(); it++) {
		if (*it == key) {
			break;
		}
	}
	if (*it) {
		if (it != table[index].end()) {
			table[index].erase(it);
		}
	}
	
}
int Hash::hashFunction(int x)
{
	return x % Bucket;
}
void Hash::DisplayHash()
{
	for (int i = 0; i < Bucket; i++) {
		std::cout << i;
		for (auto x : table[i]) {
			std::cout << " --> " << x;
		}
		std::cout << std::endl;
	}
}
int Hash::Rehash1(int i)
{
	return (i + rehashConstant) % table->size();
}
int Hash::Rehash2(int i, int j)
{
	return (i + j) % table->size();
}
int Hash::Doublehash(long key)
{
	return (1+ key % (table->size() - 1));
}
void Hash::TestHash()
{
	std::hash<int> h;

	size_t i = h(1113335557);
	std::cout << "hash(1113335557) = " << i << std::endl;

	std::hash<Test> ht;
	Test t{ 1113335557, " blabla" };
	i = ht(t);
	std::cout << "egen hash verdi: " << i << std::endl;
}

void Hash::TestUnorderdSet()
{
	std::hash<Test> ht;
	std::unordered_set<Test> us;
	std::unordered_set<Test>::iterator usit;
	std::pair<std::unordered_set<Test>::iterator, bool> par;

	Test t;

	std::cout << "Tester egen hashfunksjon" << std::endl;
	for (auto i = 0; i < 15; i++) {
		t.key = i;
		std::cout << "hash ht(" << i << ") = " << ht(t) << std::endl;
	}

	t.key = 12;
	t.s = "tolv";
	us.insert(t);
	t.key = 14; 
	t.s = "fjorten";
	us.insert(t);

	t.key = 14;
	t.s = "fjorten_b";
	int m = us.size();

	par = us.insert(t);
	int n = us.size();
	std::cout << t.s << " satt inn " << std::boolalpha << (n - m == 1) << std::endl;

	std::cout << t.s << "satt inn " << std::boolalpha << par.second << std::endl;

	t.key = 14;
	usit = us.find(t);
	t = *usit;
	std::cout << "post funnet: " << t.key << " " << t.s << std::endl;
}

void Hash::TestUnorderdMultiset()
{
	std::unordered_multiset<Test> ums;
	std::unordered_multiset<Test>::iterator umsit;
	std::pair<std::unordered_multiset<Test>::iterator, bool> par;

	Test t1, t2;
	t1.key = 12;
	t1.s = "tolv";
	ums.insert(t1);
	t2.key = 14;
	t2.s = "fjorten";
	ums.insert(t2);

	//duplikater går i unordered mutliset
	int m = ums.size();
	t2.key = 14;
	t2.s = "fjorten_b";
	ums.insert(t2);
	int n = ums.size();
	std::cout << t2.s << " satt inn " << std::boolalpha << (n - m == 1) << std::endl;

	t2.key = 14;
	umsit = ums.find(t2);
	t2 = *umsit;
	std::cout << t2.key << " " << t2.s << std::endl;
	std::cout << "Hvor mange keys = " << t2.key << " count = " << ums.count(t2) << std::endl;
	std::cout << "load factor " << ums.load_factor() << std::endl;
	std::cout << "size " << ums.size() << std::endl;
	std::cout << "bucket count " << ums.bucket_count() << std::endl;

	std::cout << "Tenk litt voer implementeringen i stl: " << std::endl;
	std::cout << "Bucket size for key " << t1.key << " = " << ums.bucket(t1) << std::endl;
	std::cout << "Bucket size for key " << t2.key << " = " << ums.bucket(t2) << std::endl;

	std::cout << "Setter inn 17 poster" << std::endl;
	for (int i = 14; i < 30; i++) {
		ums.insert(Test{ i, "blabla" });
	}

	std::cout << "Load factor = " << ums.size() << "/" << ums.bucket_count() << " = " << ums.max_load_factor() << std::endl;
	std::cout << "Size " << ums.size() << std::endl;
	std::cout << "Bucket count " << ums.bucket_count() << std::endl;
}
