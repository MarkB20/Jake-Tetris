#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Tetrominoe.h"
//#include "main.h"


void tetrominoe::Rotate() {
    if (rotate)
    {
        Point p = a[1]; //center of rotation
        for (int i = 0;i < 4;i++)
        {
            int x = a[i].y - p.y;
            int y = a[i].x - p.x;
            a[i].x = p.x - x;
            a[i].y = p.y + y;
        }
        if (!check()) for (int i = 0;i < 4;i++) a[i] = b[i];
    }
}


void tetrominoe::CheckLines() {
    
    for (int i = 20 - 1;i > 0;i--)
    {
        int count = 0;
        for (int j = 0;j < 20;j++)
        {
            if (field[i][j]) count++;
            field[k][j] = field[i][j];
        }
        if (count < 20) k--;
    }
}

void tetrominoe::Score() {
    //int points = 1;
    if (k = 20 - 2) {
        score = points * 100;
    }
    sf::Font sc;
    if (!sc.loadFromFile("C:/Users/okane/Downloads/SFML_PointsClass-master (1)/SFML_PointsClass-master/Fonts/ARCADE_I.ttf")) {
    }
    sf::Text Score;
   Score.setFont(sc);
    Score.setString("Score:  " + score);
    Score.setCharacterSize(300);
    Score.setFillColor(sf::Color::Red);
    Score.setPosition(170.f, 240.f);
}

void tetrominoe::EndGame() {
    sf::Font sc;
    if (!sc.loadFromFile("C:/Users/okane/Downloads/SFML_PointsClass-master (1)/SFML_PointsClass-master/Fonts/ARCADE_I.ttf")) {
    }
    sf::Text End;
    End.setFont(sc);
    End.setString("Game Over Final Score:  " + score);
    End.setCharacterSize(300);
    End.setFillColor(sf::Color::Red);
    End.setPosition(160.f, 240.f);
}

void tetrominoe::Tick() {
    if (timer > delay)
    {
        for (int i = 0;i < 4;i++) { b[i] = a[i]; a[i].y += 1; }
        if (!check())
        {
            for (int i = 0;i < 4;i++) field[b[i].y][b[i].x] = colorNum;
            colorNum = 1 + rand() % 7;
            int n = rand() % 7;
            for (int i = 0;i < 4;i++)
            {
                a[i].x = figures[n][i] % 2;
                a[i].y = figures[n][i] / 2;
            }
        }
        timer = 0;
    }
}

void tetrominoe::Move() {
    for (int i = 0;i < 4;i++) { b[i] = a[i]; a[i].x += dx; }
    if (!check()) for (int i = 0;i < 4;i++) a[i] = b[i];
}


