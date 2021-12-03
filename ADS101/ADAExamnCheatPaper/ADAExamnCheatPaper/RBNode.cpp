#include "RBNode.h"

#define LEFT 0
#define RIGHT 1

RBNode::RBNode()
{
}

RBNode::RBNode(int _data)
{
    data = _data;
}

RBNode* RBNode::GetParent(RBNode* node)
{
    return node == nullptr ? nullptr : node->parent;
}

RBNode* RBNode::GetGrandParent(RBNode* node)
{
    return GetParent(GetParent(node));
}

RBNode* RBNode::GetSibling(RBNode* node)
{
    RBNode* p = GetParent(node);
    if (p) {
        return p->left != node ? p->left : p->right;
    }
    return nullptr;
}

RBNode* RBNode::GetUncle(RBNode* node)
{
    RBNode* p = GetParent(node);
    if (p) {
        return GetSibling(p);
    }
    return nullptr;
}

RBNode* RBNode::GetCloseNephew(RBNode* node)
{
    RBNode* p = GetParent(node);
    int dir;
    RBNode* s;
    if (p) {
        if (node == node->parent->right) {
            s = p->left;
            return s->left;
        }
        else if (node == node->parent->left) {
            s = p->right;
            return s->right;
        }
    }
    return nullptr;
}

RBNode* RBNode::GetDistantNephew(RBNode* node)
{
    RBNode* p = GetParent(node);
    int dir;
    RBNode* s;
    if (p) {
        if (node == node->parent->right) {
            s = p->left;
            return s->right;
        }
        else if (node == node->parent->left) {
            s = p->right;
            return s->left;
        }
    }
    return nullptr;
}

