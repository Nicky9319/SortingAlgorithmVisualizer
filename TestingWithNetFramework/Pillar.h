#pragma once
#include<raylib.h>

using namespace std;

class Pillar
{
private:
	int number;
	int width;
	int height;

public:
	int getNumber() { return number; }
	void setNumber(int val) { number = val; }

	int getWidth() { return width; }
	void setWidth(int val) { width = val; }

	int getHeight() { return height; }
	void setHeight(int val) { height = val;}

};

