// Softrendering.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Base\Canvas.h"

int main()
{
	SFR::Canvas* app = SFR::Canvas::GetInstance();
	app->Init(800, 600);
	app->DrawLineDescartes(10, 10, 200, 100);
	app->DrawLineDDA(10, 20, 200, 110);
	app->DrawLineBresenham(10, 30, 200, 120);
	getch();
    return 0;
}