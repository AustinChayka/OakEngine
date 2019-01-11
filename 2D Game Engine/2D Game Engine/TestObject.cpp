#include "TestObject.h"

TestObject::TestObject() : GameObject("assets/Test.png", 10, 10, 32, 32, 5) {

	vX = 1.5f;
	vY = 1;

}

TestObject::~TestObject() {




}

void TestObject::Update() {

	x += vX;
	y += vY;

	scale -= .01f;

}
