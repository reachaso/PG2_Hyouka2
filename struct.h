#pragma once

static const int kScreenWidth = 1280;
static const int kScreenHeight = 720;

class Vector2 {
public:
	float x;
	float y;

	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector2() {
		x = 0.0f;
		y = 0.0f;
	}

	Vector2 operator=(Vector2 v) {
		x = v.x;
		y = v.y;
		return *this;
	}
};

enum SceneType {
	Title,
	Game
};
