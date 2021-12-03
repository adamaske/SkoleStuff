#pragma once

#include <vector>

struct Vector2D {
	double x;
	double y;
	Vector2D operator + (const Vector2D& v) const {
		Vector2D u;
		u.x = x + v.x;
		u.y = y + v.y;
		return u;
	}
	Vector2D operator - (const Vector2D& v) const {
		Vector2D u;
		u.x = x - v.x;
		u.y = y - v.y;
		return u;
	}
	Vector2D operator / (int d) {
		Vector2D u;
		u.x = x / d;
		u.y = y / d;
		return u;
	}
};

class QuadTree
{
public:
	QuadTree();
	QuadTree(Vector2D& vne, Vector2D& vnw, Vector2D& vse, Vector2D& vsw,
		QuadTree* qne = nullptr, QuadTree* qnw = nullptr, QuadTree* qse = nullptr, QuadTree* qsw = nullptr);
	void Subdivide(int amount);
	void Print();
	bool IsLeaf();
	QuadTree* Insert(Vector2D input);
	QuadTree* Find(Vector2D point);
	QuadTree* FindAllLeafes();
	int capacity = 5;
	int count = 0;
	bool AtCapacity();
	std::vector<Vector2D> data;
	void Rebuild();
private:
	Vector2D v_ne;
	Vector2D v_nw;
	Vector2D v_se;
	Vector2D v_sw;
public:
	QuadTree* q_ne;
	QuadTree* q_nw;
	QuadTree* q_se;
	QuadTree* q_sw;
};

