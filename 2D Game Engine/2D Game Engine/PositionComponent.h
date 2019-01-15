#ifndef PositionComponent_h
#define PositionComponent_h

#include "Components.h"

class PositionComponent : public Component {

private:

	float x, y;

public:

	void Init() override { x = 0; y = 0; }

	void Update() override {}

	float GetX() { return x; }
	float GetY() { return y; }

	void SetPos(float xPos, float yPos) { x = xPos; y = yPos; }

};

#endif