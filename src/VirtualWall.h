#pragma once

#include "ofxBox2D.h"
#include "CollisionObject.h"

class VirtualWall : public CollisionObject {
	public:
		void init(int _id);
		void update();
		void draw();

		virtual void collisionListner(CollisionObject *other);
	private:
		int x, y, w, h;
		ofxBox2dRect b2dRect;
};