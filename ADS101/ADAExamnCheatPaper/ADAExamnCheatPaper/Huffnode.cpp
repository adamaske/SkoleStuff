#include "Huffnode.h"

Huffnode::Huffnode(Huffnode* h1, Huffnode* h2)
{
	frequency = h1->frequency + h2->frequency;
	left = h1;
	right = h2;
	h1->parent = this;
	h2->parent = this;
}
