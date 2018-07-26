#pragma once

#include "vector2D.h"
#include "vector3D.h"
#include "matrix33.h"

class Transform
{
public:
	Vector2D position;
	float rotation;
	float scale;

	Matrix33 matrix;

public:
	Transform() {}
	Transform(const Vector2D& position, float rotation = 0.0f, float scale = 1.0f) :
		position(position), 
		rotation(rotation), 
		scale(scale)
		{}

	void Update();

	//friend std::istream& operator >> (std::istream& stream, Transform& transform);
};
