#pragma once

#define MAXBITS 10;
class Huffnode
{
public:
	int frequency;
	Huffnode* parent, *left, *right;
	Huffnode(Huffnode* h1, Huffnode* h2);

	char data;
	int bits[_INTEGRAL_MAX_BITS];
	int startpos;
};

