#include "QuadTree.h"
#include <iostream>
QuadTree::QuadTree()
{
}

QuadTree::QuadTree(Vector2D& vne, Vector2D& vnw, Vector2D& vse, Vector2D& vsw, 
	QuadTree* qne, QuadTree* qnw, QuadTree* qse, QuadTree* qsw) : 
	v_ne(vne), v_nw(vnw), v_se(vse), v_sw(vsw), 
	q_ne(qne), q_nw(qnw), q_se(qse), q_sw(qsw)
{
}

void QuadTree::Subdivide(int amount)
{
	std::cout << "NE: " << "(" << v_ne.x << ", " << v_ne.y << ")" << std::endl;
	std::cout << "NW: " << "(" << v_nw.x << ", " << v_nw.y << ")" << std::endl;
	std::cout << "SE: " << "(" << v_se.x << ", " << v_se.y << ")" << std::endl;
	std::cout << "SW: " << "(" << v_sw.x << ", " << v_sw.y << ")" << std::endl;
	if (amount > 0) {
		Vector2D v1 = (v_nw + v_se) / 2; //0,10
		Vector2D v2 = (v_se + v_sw) / 2; //0.-10
		Vector2D v3 = (v_ne - v_nw) / 2; //10,10
		Vector2D v4 = (v_nw - v_se) / 2; //-10,0
		Vector2D v5 = (v_se - v_sw) / 2; //10,0
		Vector2D v6 = (v_sw - v_ne) / 2; //-10,-10
		Vector2D m = (v_ne + v_sw) / 2; // 0,0
		/*
		std::cout << "(" << v1.x << ", " << v1.y << ")" << std::endl;
		std::cout << "(" << v2.x << ", " << v2.y << ")" << std::endl;
		std::cout << "(" << v3.x << ", " << v3.y << ")" << std::endl;
		std::cout << "(" << v4.x << ", " << v4.y << ")" << std::endl;
		std::cout << "(" << v5.x << ", " << v5.y << ")" << std::endl;
		std::cout << "(" << v6.x << ", " << v6.y << ")" << std::endl;
		
		std::cout << "(" << m.x << ", " << m.y << ")" << std::endl;
		*/
		//new North East Corner (10,10), (0,10), (10,0), (0,0)
		q_ne = new QuadTree(v3, v1, v5, m);
		q_ne->Subdivide(amount - 1);
		//new North West Corner (0,10), (-10,10), (0,0), (-10,0)
		q_nw = new QuadTree(v1, v_nw, m, v4);
		q_nw->Subdivide(amount - 1);
		//new South East Corner (0,10), (0,0), (10,-10), (0,-10)
		q_se = new QuadTree(v1, m, v_se, v2); 
		q_se->Subdivide(amount - 1);
		//new South West Corner (0,0), (-10, 0), (0,-10), (-10,-10)
		q_sw = new QuadTree(m, v4, v2, v6);
		q_sw->Subdivide(amount - 1);
		
	}
}

void QuadTree::Print()
{
	Vector2D m = (v_ne + v_sw) / 2;
	std::cout << "senter = (" << m.x << ", " << m.y << ")" << std::endl;
	/*
	for (auto i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}*/
}

bool QuadTree::IsLeaf()
{
	//If its a leaf, all QuadTree pointers should be null
	if (q_ne == nullptr && q_nw == nullptr && q_se == nullptr && q_sw == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

QuadTree* QuadTree::Insert(Person* input)
{
	if (IsLeaf()) {
		data.push_back(input);
		return this;
	}
	else {
		//Get middle to determine where it should go
		Vector2D middle = (v_ne + v_sw) / 2;
		//if the y is smaller than the middle it should land in one of the south trees
		if (input->y < middle.y) {
			//If the x is smaller than the middle x, it should land in the left tree. X goes from left to right with size
			if (input->x < middle.x) {
				q_sw->Insert(input);
			}
			else {
				q_se->Insert(input);
			}
		}
		else {
			//Opposite of the south
			if (input->x < middle.x) {
				q_nw->Insert(input);
			}
			else {
				q_ne->Insert(input);
			}
		}
	}
}

QuadTree* QuadTree::Find(Vector2D point)
{
	if (IsLeaf()) {
		return this;
	}
	else {
		Vector2D middle = (v_ne + v_sw) / 2;
		//Find what quad it should be in
		//Same as insert function
		if (point.y < middle.y) {
			if (point.x < middle.x) {
				q_sw->Find(point);
			}
			else {
				q_se->Find(point);
			}
		}
		else {
			if (point.x < middle.x) {
				q_nw->Find(point);
			}
			else {
				q_ne->Find(point);
			}
		}

	}
	return nullptr;
}

QuadTree* QuadTree::FindAllLeafes()
{
	if (IsLeaf()) {
		std::cout << "(" << v_ne.x << ", " << v_ne.y << "), " << "(" << v_nw.x << ", " << v_nw.y << "), "
			<< "(" << v_se.x << ", " << v_se.y << "), " << "(" << v_sw.x << ", " << v_sw.y << ")" << std::endl;
		return this;
	}
	if (q_ne) {
		q_ne->FindAllLeafes();
	}
	if (q_nw) {
		q_nw->FindAllLeafes();
	}
	if (q_se) {
		q_se->FindAllLeafes();
	}
	if (q_sw) {
		q_sw->FindAllLeafes();
	}
	return nullptr;
}
