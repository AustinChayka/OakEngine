#include "TestObject.h"

TestObject::TestObject() : GameObject("Test.png", 10, 10, 32, 32, 3) {

	vX = 1;
	vY = 1;

}

TestObject::~TestObject() {




}

void TestObject::Update() {

	x += vX;
	y += vY;

}
