// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet (2020)

#include <iostream>
#include "binarynode.h"

using namespace std;

int main(int argc, char *argv[])
{
    BinaryNode* h = new BinaryNode('d');
    BinaryNode* v = new BinaryNode('a');
    v = new BinaryNode('b', v, h);
    // peker h er ledig
    BinaryNode* btre = new BinaryNode('g');
    h = new BinaryNode('p');
    btre = new BinaryNode('i', btre, h);
    btre = new BinaryNode('f', v, btre);

    btre->intrav();
    cout << endl;
    for (;;)
    {        
        cout << "soek etter: ";
        char ch; cin >> ch;

        BinaryNode* p = btre->find(ch);
        if (p != nullptr)
            cout << p->getData() << endl;
        else
            cout << "nullptr" << endl;
        cout << "insert: ";
        cin >> ch;
        btre->insert(ch);
        btre->intrav();
        cout << endl;

    }
}
