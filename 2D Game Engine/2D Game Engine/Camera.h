#ifndef Camera_h
#define Camera_h

#include "GameObject.h"

class GameObject;

class Camera {

public:

	Camera(float init_x, float init_y, float init_width, float init_height);
	~Camera();

	float GetX();
	float GetY();
	float GetScale();
	float GetWidth();
	float GetHeight();

	void SetPos(float newX, float newY);
	void ChangePos(float dx, float dy);
	void SetSize(float newScale);
	void ChangeSize(float deltaScale);
	void SetTarget(GameObject * go);

	void Update();


private:

	float x, y, width, height, scale, minScale = .1f, maxScale = 5;
	GameObject * target;

};

#endif