#pragma once
#include"Startsetting.h"
#include"BoxColider.h"
#include <vector>

class Obstacles
{
public:

	Startsetting startsetting;
	


	Obstacles(int x, int y);
	void Update();
	void Draw();
	void Init();
	
	int y; 
	int x;
	int vy;
	int vx;
	int playerImg;

};
//
//inline static std::vector<Obstacles> allObstacles;