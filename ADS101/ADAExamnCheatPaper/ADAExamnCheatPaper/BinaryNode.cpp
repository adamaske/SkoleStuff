#include "BinaryNode.h"
#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <queue>
=======
#include "TQueue.h"
#include "TStack.h"
>>>>>>> a40aec551ab31a016b196c0b2db70ee80ec145d0
BinaryNode::BinaryNode()
{
	data = 0;
}

BinaryNode::BinaryNode(int _data, BinaryNode* _left, BinaryNode* _right) :
	data(_data)
{
	data = _data;
	left = _left;
	right = _right;
}

int BinaryNode::GetData()
{
	return data;
}

BinaryNode* BinaryNode::Find(int _data)
{
	if (data == _data) {
		return this;
	}
	else if (_data < data && left != nullptr) {	//If the _data is smaller than this->data and the left node is not null, return the find in left
		return left->Find(_data);
	}
	else if (_data > data && right != nullptr) { //If the _Data is bigger than this-> data, return the right find
		return right->Find(_data);
	}
	//If none of the above returns, return a nullptr
	return nullptr;
}

void BinaryNode::Insert(int _data)
{
	if (_data < data) {
		if (left) {
			left->Insert(_data);
		}
		else {
			left = new BinaryNode(_data);
			left->parent = this;
		}
	}
	else if (_data > data) {
		if (right) {
			right->Insert(_data);
		}
		else {
			right = new BinaryNode(_data);
			right->parent = this;

		}
	}

	
	DoBalance(this, _data);
}

void BinaryNode::Intrav()
{
	if (left) {
		left->Intrav();
	}
	std::cout << data << std::endl;
	if (right) {
		right->Intrav();
	}
}

void BinaryNode::Insert(char data)
{
	std::queue<BinaryNode*> list;
	//Finn hvis det er noen lingende i treet
	list.push(this);
	BinaryNode* node;
	//Wont run if there is no right
	while (!list.empty()) {
		node = list.front();
		list.pop();
		
		if (node->m_data == data) {
			node->m_frekvens++;
		}

		if (node->m_left) {
			list.push(node->m_left);
		}
		if (node->m_right) {
			list.push(node->m_right);
		}
	}

	if (data < m_data) {
		if (m_left) {
			m_left->Insert(data);
		}
		else {
			left = new BinaryNode(data);
		}
	}
	else if (data > m_data) {
		if (m_right) {
			m_right->Insert(data);
		}
		else {
			m_right = new BinaryNode(data);

		}
	}


}

void BinaryNode::Print() const
{
	if (m_left) {
		m_left->Print();
	}
	std::cout << m_data << "=" << m_frekvens << ", ";
	if (m_right) {
		m_right->Print();
	}
}

bool operator > (const BinaryNode& b1, const BinaryNode& b2){ return b1.m_frekvens > b2.m_frekvens; };

void BinaryNode::PrintSorted()
{
	//Erklerer en kø for de sorterte binary nodesa
	std::priority_queue<BinaryNode*, std::vector<BinaryNode*>, std::greater<BinaryNode*>> apq;
	//En queue for å itterere gjennom alle nodene i treet og legge de til apq
	std::queue<BinaryNode*> list;
	//Pusher først seg selv inn inn i list
	list.push(this);
	//Erklerer en peker til en BinaryNode
	BinaryNode* node;
	while (!list.empty()) {
		node = list.front();
		list.pop();
		//Add it to the priorty queue
		apq.push(node);
		//Hvis denne noden har høyre eller vesntre barn, legg de til
		if (node->m_left) {
			list.push(node->m_left);
		}
		if (node->m_right) {
			list.push(node->m_right);
		}
		//Gjentas til det ikke er noen flere noder å finne
	}
	//Så lenge apq ikke er tom, 
	while (!apq.empty()) {
		//Sett node til toppen, den laveste frekvensen
		node = apq.top();
		//Pop den ut av køen
		apq.pop();
		//Printer dataen og frekvensen
		std::cout << node->m_data << "=" << node->m_frekvens << ",  ";
	}
	std::cout << std::endl;

}

void BinaryNode::DoBalance(BinaryNode* root, int _data)
{
	//If Right Height is larger than left it returns negative
	int balanace = Height(root->GetLeft()) - Height(root->GetRight());
	//Left is taller than right
	//Data is smaller than left
	if (balanace > 1 && _data < root->GetLeft()->data) {
		//Unbalanced
		RightRotation(root);
	}
	//Right is taller than left
	//Data is larger than right
	if (balanace < -1 && _data > root->GetRight()->data) {
		//Unbalanced
		LeftRotation(root);
	}
	//Left is taller than right
	//Data is larger than left
	if (balanace > 1 && _data > root->GetLeft()->data) {
		//Unbalanced
		root->left = LeftRotation(root->GetLeft());
		RightRotation(root);
	}
	//Right is taller than left
	//Data is smaller than right
	if (balanace < -1 && _data < root->GetRight()->data) {
		//Unbalanced
		root->right = RightRotation(root->GetRight());
		LeftRotation(root);
	}
}

int BinaryNode::Height(BinaryNode* root)
{
	if (!root) {
		return 0;
	}
	int a = 0;
	int b = 0;
	if (root->GetLeft()) {
		a = 1 + Height(root->GetLeft());
	}
	if (root->GetRight()) {
		b = 1 + Height(root->GetRight());
	}
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}

	return 0;
}

BinaryNode* BinaryNode::RightRotation(BinaryNode* root)
{

	BinaryNode* temp1 = root->GetLeft();
	BinaryNode* temp2 = temp1->GetRight();

	temp1->right = root;
	root->left = temp2;


	return temp1;
}

BinaryNode* BinaryNode::LeftRotation(BinaryNode* root)
{
	BinaryNode* temp1 = root->GetRight();
	BinaryNode* temp2 = temp1->GetLeft();

	root->left = temp1;
	temp1->right = temp2;

	return temp1;
}

void BinaryNode::Stigende()
{
	if (left)
		left->Stigende();
	std::cout << data << std::endl;
	if (right)
		right->Stigende();
}

void BinaryNode::Avtakende()
{
	if (right)
		right->Avtakende();
	std::cout << data << std::endl;
	if (left)
		left->Avtakende();
}

BinaryNode* BinaryNode::DeleteNode(BinaryNode* node)
{
	if (right) {
		if (node->right) {
			if (node != right) {
				node->right->parent = node->parent;
			}
			else {
				node->right->parent = parent;
			}
			if (node != right) {
				node->parent->left = node->right;
				node->right = right;
				right->parent = node;
			}
			node->left = left;
			if (left) {
				left->parent = node;
			}
		}
		if (node) {
			node->parent = parent;
		}
		if (parent) {
			if (parent->left == this) {
				parent->left = node;
			}
			else if (parent->right == this) {
				parent->right = node;
			}
		}
		
	}
	return this;
}

BinaryNode* BinaryNode::FindInorderReplacement()
{
	BinaryNode* replacement;
	if (right) {
		replacement = right;
		while(replacement->right) {
			replacement = replacement->right;
		}
	}
	else {
		replacement = left;
	}
	return replacement;
}

double BinaryNode::Sum()
{
	double totalsum = data;
	if (left)
		totalsum += left->Sum();
	if (right)
		totalsum += right->Sum();
	return totalsum;
}

void BinaryNode::WidthFirstTraversal()
{
	BinaryNode* p = this;
	TQueue<BinaryNode*> queue;
	queue.Push(p);
	while (queue.Size() != 0) {
		p = queue.Front();
		queue.Pop();
		std::cout << data << ", ";
		if (p->left) {
			queue.Push(p->left);
		}
		if (p->right) {
			queue.Push(p->right);
		}
	}
	std::cout << std::endl;
}

void BinaryNode::NonRecursivePreorderTraversal()
{
	BinaryNode* p = this;
	TStack<BinaryNode*> stack;
	
	while (!stack.Empty()) {
		p = stack.Top();
		std::cout << p->data << ", ";
		stack.Pop();
		if (p->left) {
			stack.Push(p->left);
		}

		if (p->right) {
			stack.Push(p->right);
		}

	}
	std::cout << std::endl;
}
