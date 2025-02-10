#pragma once
#include "struct.h"

class Object {

private:

	Vector2 pos_;
	Vector2 radius_;
	int color_;

public:

	virtual void Update();
	virtual void Draw();
	
	void SetPos(Vector2 pos);
	Vector2 GetPos();

	void SetRadius(Vector2 radius);
	Vector2 GetRadius();

};

