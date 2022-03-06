#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <math.h>


constexpr auto PI = M_PI;

double toRadian(int x)
{
    return x * PI / 180;
}

void drawCircle(int radius, COLORREF color, double offsetX, double offsetY)
{
    int mainAngle = 0;
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    for (mainAngle; mainAngle < 360; mainAngle++)
    {
        double currentAngle = toRadian(mainAngle);
        double xLength = radius * sin(currentAngle);
        double lastAngle = PI - toRadian(90) - currentAngle;
        double yLength = radius * sin(lastAngle);
        SetPixel(hdc, offsetX+ xLength, offsetY+ yLength, color);
           

    }
    /*for (int i = 0; i < 100; i++) {
        for (size_t j = 0; j < 100; j++)
        {
            SetPixel(hdc, i, j, RGB(255, 0, 0));
        }

    }*/

}


void main() {

    for (size_t i = 150; i > 0; i--)
    {
        drawCircle(i, RGB(i ,255, 255), 255, 255);
    }
        
    std::cin.get();
    std::cin.get();
    

    
}