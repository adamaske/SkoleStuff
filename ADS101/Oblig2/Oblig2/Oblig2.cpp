#include <iostream>
#include "BinaryNode.h"
#include "Stack.h"
#include "QuadTree.h"
#include <math.h>
void Inorder(BinaryNode* root);
void Postorder(BinaryNode* root);
int AmountOfNodes(BinaryNode* root);
int AmountOfLevels(BinaryNode* root);
bool BalancedCheck(BinaryNode* root);
int Height(BinaryNode* root);
QuadTree* MakeQuadTree();

int main() {
    //Testing
	BinaryNode* left = new BinaryNode(1);
	BinaryNode* right = new BinaryNode(4);

	right = new BinaryNode(2, left, right);

	BinaryNode* binaryTree = new BinaryNode(8);

	left = new BinaryNode(16);
	binaryTree = new BinaryNode(10, binaryTree, left);
	binaryTree = new BinaryNode(7, right, binaryTree);

	//binaryTree->Intrav();
    //Create a non recursive inorder traversal of a binary tree
    Inorder(binaryTree);
    
    std::cout << std::endl;
    //Create a non recursive postorder traversal of a binary tree
    Postorder(binaryTree);

    std::cout << std::endl;
    //Write a function that returns amount of nodes in a binary tree
    std::cout << std::endl << "Number of nodes: " << AmountOfNodes(binaryTree) << std::endl;

    //Write a function that returns amount of levels in a binary tree
    
    std::cout << std::endl << "Number of levels: " << AmountOfLevels(binaryTree) << std::endl;
    //Write a function that fins if a binary tree is balanced 
    
    std::cout << std::endl << "The binary tree is " << BalancedCheck(binaryTree) << " balanced" << std::endl << std::endl;

    //Write a quadtree where the blades lay in different levels
    QuadTree* tree = MakeQuadTree();
    Vector2D a;
    for (int i = 0; i < 16; i++)
    {
        a.x = rand() % 10;
        a.y = rand() % 10;
        tree->Insert(a);
    }
    tree->Print();
    
    //Write a function that returns all the corners to all quads which are blades 
    tree->FindAllLeafes();
    //Write a test program for these
    return 0;
}

void Inorder(BinaryNode* root) {
    BinaryNode* current, *previous;
    current = root;

    while(current != nullptr) {
        //Goes down the left, until there is no more to the left, then goes down right until there is no more
        if (current->GetLeft() != nullptr) {
            previous = current->GetLeft();
            //Get the bottom right
            while (previous->GetRight() != nullptr && previous->GetRight() != current) {
                previous = previous->GetRight();
            }
            if (previous->GetRight() == nullptr) {
                previous->right = current;
                current = current->GetLeft();
            }
            else {
                previous->right = nullptr;
                std::cout << current->GetData() << " ";
                current = current->GetRight();
            }
        }
        else {
            //Get the right instead of the left
            std::cout << current->GetData() << " ";
            current = current->GetRight();
        }
    }
}

void Postorder(BinaryNode* root)
{
    Stack<BinaryNode*> stack;
    stack.Push(root);

    while (!stack.Empty()) {
        BinaryNode* current = stack.Top();
        stack.Pop();

        std::cout << current->GetData() << " ";

        if (current->GetLeft()) {
            stack.Push(current->GetLeft());
        }

        if (current->GetRight()) {
            stack.Push(current->GetRight());
        }
    }
}

int AmountOfNodes(BinaryNode* root)
{
	Stack<BinaryNode*> stack;
	stack.Push(root);

    int count = 0;

    while (!stack.Empty()) {
		BinaryNode* current = stack.Top();
		stack.Pop();
        
        count++;

		if (current->GetLeft()) {
			stack.Push(current->GetLeft());
		}

		if (current->GetRight()) {
			stack.Push(current->GetRight());
		}
    }


    return count;
}

int AmountOfLevels(BinaryNode* root)
{
	Stack<BinaryNode*> stack;
	stack.Push(root);

	int count = 0;

	while (!stack.Empty()) {
		BinaryNode* current = stack.Top();
		stack.Pop();
        bool hasCounted = false;
		
        //Only add count if it hasnt done it already
		if (current->GetLeft()) {
			stack.Push(current->GetLeft());
            count++;
            hasCounted = true;
		}

		if (current->GetRight()) {
			stack.Push(current->GetRight());
            if (!hasCounted) {
                count++;
                hasCounted = true;
            }
		}
	}

    return count;
}

bool BalancedCheck(BinaryNode* root)
{
    //Return true if this is null
    if (!root) {
        return true;
    }
    //Find how many levels there is down from here for both left and right
    int leftHeight = Height(root->GetLeft());
    int rightHeight = Height(root->GetRight());
    //The heights must be either 0, then check this for every level of the tree
    //if any level is not balanced the whole loop returns false
    if ((leftHeight - rightHeight) <= 0 && BalancedCheck(root->GetLeft()) && BalancedCheck(root->GetRight())) {
        return true;
    }
    else {
		return false;
    }
    
}

int Height(BinaryNode* root) {
    if (!root) {
        return 0;
    }
    else {
        //Goes down the 
        int a = Height(root->GetLeft());
        int b = Height(root->GetRight());

        //returns the highest of the two
        if (a > b) {
            return 1 + a;
        }
        else {
            return 1 + b;
        }
    }

    
}

QuadTree* MakeQuadTree() {
    //Create points
    Vector2D ne{ 100, 100 };
    Vector2D nw{ 0, 100 };
    Vector2D se{ 100, 0 };
    Vector2D sw{ 0, -0 };
    QuadTree* root = new QuadTree(ne, nw, se, sw);
    return root;
}


