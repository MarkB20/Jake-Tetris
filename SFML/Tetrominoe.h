#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
//#include "main.h"
//#define const int M = 20; 
//#define const int N = 20;
class tetrominoe {
    
public:  int field[20][20] = { 0 };

public:  struct Point
    {
        int x, y;
    } a[4], b[4];

public:    int points = 1;
public: int score;
   
 int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };

    bool check()
    {
        for (int i = 0;i < 4;i++)
            if (a[i].x < 0 || a[i].x >= 20 || a[i].y >= 20) return 0;
            else if (field[a[i].y][a[i].x]) return 0;

        return 1;
    };

    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;

    sf::Clock clock;

    int k = 20 - 1;

   

public:

	void Rotate();
	void Score();
	void EndGame();
	void CheckLines();
	void Tick();
	void Move();

};