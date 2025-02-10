#include "Object.h"

void Object::Update() {
}

void Object::Draw() {
}

void Object::SetPos(Vector2 pos) {
	pos_ = pos;
}

Vector2 Object::GetPos() {
	return pos_;
}

void Object::SetRadius(Vector2 radius) {
	radius_ = radius;
}

Vector2 Object::GetRadius() {
	return radius_;
}
