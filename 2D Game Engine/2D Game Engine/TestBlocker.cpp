#include "TestBlocker.h"

TestBlocker::TestBlocker() : GameObject("assets/Test.png", 200, 250, 32, 32, 3) { collidable = true;  }

TestBlocker::~TestBlocker() {}

void TestBlocker::Update(Game * game) {}
