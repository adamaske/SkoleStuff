// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet (2020)
#ifndef BINARYNODE_H
#define BINARYNODE_H


class BinaryNode
{
public:
    BinaryNode();
    BinaryNode(char data, BinaryNode* left=nullptr,
               BinaryNode* right=nullptr);
    char getData();
    void print();
    BinaryNode *find(char data);
    void insert(char data);
    void intrav();
private:
    char m_data;
    BinaryNode* m_left;
    BinaryNode* m_right;
};

#endif // BINARYNODE_H
