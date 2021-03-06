// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet (2020)
#include <iostream>
#include "binarynode.h"

BinaryNode::BinaryNode() { }
BinaryNode::BinaryNode(char data, BinaryNode* left,
           BinaryNode* right) :
    m_data{data}, m_left{left}, m_right{right}
{ }

char BinaryNode::getData() { return m_data; }

BinaryNode *BinaryNode::find(char data)
{
    //std::cout << m_data;
    if (m_data == data)
        return this;
    else if (data < m_data && m_left!=nullptr)
        return m_left->find(data);
    else if (m_right)  // m_data <= data
        return m_right->find(data);
    // kun hvis noden ikke finnes, kommer vi hit
    return nullptr;
}
void BinaryNode::insert(char data)
{
    if (data < m_data) {
        if (m_left)
            m_left->insert(data);
        else
            m_left = new BinaryNode(data);
    }
    else if (data > m_data) {
        if (m_right)
            m_right->insert(data);
        else
            m_right = new BinaryNode(data);
    }
}
void BinaryNode::intrav()
{
   if (m_left)
       m_left->intrav();
   std::cout << m_data;
   if (m_right)
       m_right->intrav();
}


