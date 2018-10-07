#include "TXLib.h"

void DrawMountains (int x, int y, double zoomX = 1.0, double zoomY = 1.0);
void DrawBackground ();
void DrawHouse (int x, int y, double zoomX = 1.0, double zoomY = 1.0,  int dxDoor = 0, int dxWindow = 0, int dyWindow = 0, int dypipe = 0);
void DrawBirdt (int x, int y);
void DrawPBear (int x, int y, double zoomX = 1.0, double zoomY = 1.0, int lapa = 0, int rightLeg = 0, int leftLeg = 0, int eyes = 0, int smile = 0, int smileSkew = 0);
void DrawTree (int x, int y, double zoomX = 1.0, double zoomY = 1.0, int eyes = 1,  int smile = 1, int smileSkew = 1, int nTriangles = 3);
void DrawBear (int x, int y, double zoomX = 1.0, double zoomY = 1.0, int eyes = 0, int smile = 1, int smileSkew = 1, int move = 0, int appart = 0);
void DrawTriangle (int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color1, COLORREF color2);
void TestDrawSmile ();
void GreensTriangle (int x, int y, int nTriangles);

int main ()
    {
 

    txCreateWindow (1500, 1000);

    DrawBackground ();

    DrawTree (595, 630, 1.0, 1.0, 1, 1, 1, 6);
    DrawTree (680, 620, 1.0, 1.0, 1, 1, 1, 4);
    DrawTree (560, 640, 1.0, 1.0, 1, 1, 1, 5);
    DrawTree (650, 650, 1.0, 1.0);
    DrawTree (720, 640, 1.0, 1.0);
    DrawTree (780, 610, 1.0, 1.0);
    DrawTree (800, 640, 1.0, 1.0);
    DrawTree (900, 600, 1.0, 1.0, 2, 35, 145, 5);

    DrawPBear (235, 900, 1, 1, 50,  0, 40 , 1, 10, 90);

    //TestDrawSmile ();

    DrawBear (645, 810, 1, 1, 3, 20, 235);
    DrawBear (700, 910, 0.7, 0.7);

    return 0;
    }
//-----------------------------------------------------------------------------

void DrawBackground ()
    {

    DrawMountains (790, 400, 1.6);

    txSetFillColor (RGB (1, 255, 255)); // рисует небо
    txFloodFill (60, 150);
    txFloodFill (540, 100);
    txFloodFill (800, 110);

    DrawBirdt (530, 180);
    DrawBirdt (505, 170);
    DrawBirdt (480, 160);

    DrawBirdt (800, 170);
    DrawBirdt (780, 190);
    DrawBirdt (760, 210);


    txSetFillColor (RGB (0, 166, 0)); // рисует землю
    txRectangle (-1, 399, 1501, 1001);

    DrawHouse (250, 610, 1, 1, 10, 6, 6, 50);
    DrawHouse (1100, 660);
    DrawHouse (1200, 960);

    }

//-----------------------------------------------------------------------------
void TestDrawSmile ()
    {
    int skew = 0, smileSkew = 0;
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        if (GetAsyncKeyState (VK_LEFT))  skew -= 5;
        if (GetAsyncKeyState (VK_RIGHT)) skew += 5;
        if (GetAsyncKeyState (VK_UP))   smileSkew +=5;
        if (GetAsyncKeyState (VK_DOWN)) smileSkew -=5;
        cout << "skew = " << skew << ", smileSkew = " << smileSkew << "\n" ;


        txSetFillColor (RGB (0, 0, 0));
        txClear ();

        //DrawPBear (500, 900, 1, 1, 50,  0, 40 , 1, skew, smileSkew);
        //DrawTree (900, 600, 1.0, 1.0, 2, skew, smileSkew);
        DrawBear (645, 810, 1, 1, 3, skew, smileSkew);

        txSleep (20);
        } 
    }

//-----------------------------------------------------------------------------

void DrawPBear (int x, int y, double zoomX, double zoomY, int lapa, int leftLeg, int rightLeg, int eyes, int smile , int smileSkew )
    {
    txSetFillColor (RGB (185, 122, 87));
    txSetColor (RGB (185, 122, 87));

    txCircle (x+5 * zoomX, y-200 * zoomY, 35);
    txEllipse (x+25 * zoomX, y-160 * zoomY, x+75 * zoomX, y-70 * zoomY);
    txEllipse (x-(65+lapa) * zoomX, y-160 * zoomY, x-15 * zoomX, y-(70+lapa) * zoomY); // лапа
    txEllipse ( x+5 * zoomX,  y-80 * zoomY, x+55 * zoomX, y-rightLeg * zoomY);
    txEllipse (x-55 * zoomX,  y-80 * zoomY,  x-5 * zoomX, y-leftLeg * zoomY); //нога
    txEllipse (x-45 * zoomX, y-170 * zoomY, x+55 * zoomX, y-55 * zoomY);
    
    
    txSetColor (RGB (0, 0, 0));
    txLine (x-41 * zoomX, y-(20+leftLeg) * zoomY, x-41 * zoomX, y-(5+leftLeg) * zoomY);
    txLine (x-31 * zoomX, y-(20+leftLeg) * zoomY, x-31 * zoomX, y-(0+leftLeg) * zoomY);
    txLine (x-21 * zoomX, y-(20+leftLeg) * zoomY, x-21 * zoomX, y-(5+leftLeg) * zoomY);

    txLine (x+19 * zoomX, y-(20+rightLeg) * zoomY, x+19 * zoomX, y-(5+rightLeg) * zoomY);
    txLine (x+29 * zoomX, y-(20+rightLeg) * zoomY, x+29 * zoomX, y-(0+rightLeg) * zoomY);
    txLine (x+39 * zoomX, y-(20+rightLeg) * zoomY, x+39 * zoomX, y-(5+rightLeg) * zoomY);

    txEllipse (x-20 * zoomX, y-(220-eyes) * zoomY,    x, y-(210+eyes) * zoomY);
    txEllipse ( x+5 * zoomX, y-(220-eyes) * zoomY, x+25 * zoomX, y-(210+eyes) * zoomY);
    txArc (x-15 * zoomX, y-200 * zoomY, x+35 * zoomX, y-180 * zoomY, 190+smileSkew, 90+smile);

    }


//-----------------------------------------------------------------------------

void DrawBirdt (int x, int y) 
    {

    txSetColor (RGB (0, 0, 0), 3);
    txArc (x-10, y-30, x+10, y, 180, 200); 
    txSetColor (RGB (0, 0, 0), 0);
    
    } 

//-----------------------------------------------------------------------------

void DrawMountains (int x, int y, double zoomX, double zoomY)
    {
    txSetFillColor (RGB (127, 127, 127));
    txSetColor (RGB (127, 127, 127));

    POINT mountains [10] = {{0, y}, {x-320 * zoomX, y-350 * zoomY}, {x-200 * zoomX, y-130 * zoomY}, {x-100 * zoomX, y-290 * zoomY}, {x, y-10 * zoomY}, {x+160 * zoomX, y-320 * zoomY}, {x+247 * zoomX, y-120 * zoomY}, {x+385 * zoomX, 0}, {x+470 * zoomX, 0}, {x+470 * zoomX, y}};
    txPolygon (mountains, 10);
    
    txSetColor (RGB (255, 255, 255));
    txSetFillColor (RGB (255, 255, 255));

    POINT mountainsONE [7] = {{x-350 * zoomX, y-288 * zoomY}, {x-320 * zoomX, y-350 * zoomY}, {x-287 * zoomX, y-290 * zoomY}, {x-310 * zoomX, y-270 * zoomY}, {x-320 * zoomX, y-290 * zoomY}, {x-330 * zoomX, y-270 * zoomY}, {x-350 * zoomX, y-288 * zoomY}};
    txPolygon (mountainsONE, 7);
    
    POINT mountainsTWO [4] = {{x-130 * zoomX, y-245 * zoomY}, {x-100 * zoomX, y-290 * zoomY}, {x-85 * zoomX, y-250 * zoomY}, {x-120 * zoomX, y-205 * zoomY}};
    txPolygon (mountainsTWO, 4);
                                                 
    POINT mountainsTREE [7] = {{x+145 * zoomX, y-290 * zoomY}, {x+160 * zoomX, y-320 * zoomY}, {x+175 * zoomX, y-290 * zoomY}, {x+170 * zoomX, y-275 * zoomY}, {x+160 * zoomX, y-280 * zoomY}, {x+150 * zoomX, y-275 * zoomY}, {x+145 * zoomX, y-290 * zoomY}};
    txPolygon (mountainsTREE, 7);

    }


//-----------------------------------------------------------------------------

void DrawHouse (int x, int y, double zoomX, double zoomY, int dxDoor, int dxWindow, int dyWindow, int dypipe)
    {
    txSetColor (RGB (0, 0, 0));
    txSetFillColor (RGB (232, 201, 93));
    POINT HOME [7] = {{x-150 * zoomX, y}, {x-150 * zoomX, y-150 * zoomY}, {x-70 * zoomX, y-260 * zoomY}, {x, y-150 * zoomY}, {x+170 * zoomX, y-180 * zoomY}, {x+170 * zoomX, y-30 * zoomY}, {x, y}};
    txPolygon (HOME, 7);
    txLine (x, y-150 * zoomY, x, y); 

   
    txSetFillColor (RGB (207, 67, 66));
    POINT ROOF [4] = {{x-70 * zoomX, y-260 * zoomY}, {x+100 * zoomX, y-280 * zoomY}, {x+170 * zoomX, y-180 * zoomY}, {x, y-150 * zoomY}};
    txPolygon (ROOF, 4); 

    txSetFillColor (RGB (61, 156, 255));

    POINT leftWindow [4] = {{x+(30-dxWindow) * zoomX, y-(120+dyWindow) * zoomY}, {x+(70+dxWindow) * zoomX, y-(127+dyWindow) * zoomY}, {x+(70+dxWindow) * zoomX,  y-(80-dyWindow) * zoomY}, {x+(30-dxWindow) * zoomX,  y-(73-dyWindow) * zoomY}};
    txPolygon (leftWindow, 4);

    POINT rightWindow [4] = {{x+(100-dxWindow) * zoomX, y-(130+dyWindow) * zoomY}, {x+(140+dxWindow) * zoomX, y-(137+dyWindow) * zoomY}, {x+(140+dxWindow) * zoomX,  y-(90-dyWindow) * zoomY}, {x+(100-dxWindow) * zoomX,  y-(83-dyWindow) * zoomY}};
    txPolygon (rightWindow, 4);


    txSetColor (RGB (0, 0, 0));
    txEllipse (x-90 * zoomX, y-200 * zoomY, x-60 * zoomX, y-180 * zoomY);
    txRectangle (x-90 * zoomX, y-190 * zoomY, x-60 * zoomX, y-150 * zoomY);
    txSetColor (RGB (61, 156, 255));
    txLine (x-90 * zoomX, y-190 * zoomY, x-60 * zoomX, y-190 * zoomY);
    txSetColor (RGB (0, 0, 0));

    txSetFillColor (RGB (240, 146, 48));                    // дверь
    txRectangle(x-(75+dxDoor) * zoomX,    y,  x-30 * zoomX, y-90 * zoomY);
    txSetColor (RGB (240, 146, 48));
    txLine (x-70, y-1, x-20, y-1);
    txSetColor (RGB (0, 0, 0));

    txSetFillColor (RGB (74, 74, 74)); // Труба
    POINT trumpet [4] = {{x-5 * zoomX, y-(300+dypipe) * zoomY}, {x+10 * zoomX, y-(280+dypipe) * zoomY}, {x+40 * zoomX, y-(285+dypipe) * zoomY}, {x+25 * zoomX, y-(305+dypipe) * zoomY}};
    txPolygon (trumpet, 4);
    txSetFillColor (RGB (232, 201, 93));
    POINT trumpetWall [6] = {{x+10 * zoomX, y-220 * zoomY}, {x+40 * zoomX, y-225 * zoomY}, {x+40 * zoomX, y-(285+dypipe) * zoomY}, {x+10 * zoomX, y-(280+dypipe) * zoomY}, {x-5 * zoomX, y-(300+dypipe) * zoomY}, {x-5 * zoomX, y-240 * zoomY}};
    txPolygon (trumpetWall, 6);
    txLine (x+10 * zoomX, y-220 * zoomY, x+10 * zoomX, y-(280+dypipe) * zoomY);

    }

//-----------------------------------------------------------------------------

void DrawTree (int x, int y, double zoomX, double zoomY, int eyes, int smile , int smileSkew, int nTriangles)
    {
    txSetColor (RGB (145, 89, 60));
    txSetFillColor (RGB (145, 89, 60));
    txRectangle (x-15*zoomX, y-50 * zoomY, x+15 * zoomX, y);
    txSetColor (RGB (20, 105, 46));

    GreensTriangle (x, y-30*zoomY, nTriangles);

    txSetFillColor (RGB (0, 0, 0));
    txSetColor (RGB (0, 0, 0));

    txEllipse (x-10 * zoomX, y-(70 - eyes + 35 * nTriangles) * zoomY,    x, y-(60 + eyes + 35 * nTriangles) * zoomY);
    txEllipse ( x+zoomX, y-(70 - eyes + 35 * nTriangles) * zoomY, x+11 * zoomX, y-(60 + eyes + 35 * nTriangles) * zoomY);

    txArc (x-10 * zoomX, y - (60 + 35 * nTriangles) * zoomY, x+11 * zoomX, y-(40 + 35 * nTriangles) * zoomY, 200+smileSkew, 160+smile);
    }

//-----------------------------------------------------------------------------

void GreensTriangle (int x, int y, int nTriangles)
    {
    int dy = 0;
    for (int i = 0; i < nTriangles; i++)
    {
     
        DrawTriangle(x+35, y-dy, x-35, y-dy, x, y-80-dy, RGB(34, 177, 76), RGB(22, 114, 50)); 
        dy = dy + 40;
    }
    }

//-----------------------------------------------------------------------------

void DrawBear (int x, int y, double zoomX, double zoomY, int eyes, int smile, int smileSkew, int move, int appart)
    {
    txSetFillColor (RGB (185, 122, 87));
    txSetColor (RGB (185, 122, 87));

    if appart = 1:
        {
        txEllipse (x-75 * zoomX, y-140 * zoomY, x+95 * zoomX, y-40 * zoomY);
        txEllipse (x-85 * zoomX,  y-70 * zoomY, x-35 * zoomX, y);
        txEllipse (x+45 * zoomX,  y-70 * zoomY, x+95 * zoomX, y);
        }
    txCircle (x-105 * zoomX, y-100 * zoomY, 35 * zoomX);
    txCircle ( x+95 * zoomX, y-110 * zoomY, 15 * zoomX);

    txSetColor (RGB (0, 0, 0));
    txSetFillColor (RGB (128, 0, 255));
    txEllipse (x-135 * zoomX, y-(120 - eyes) * zoomY, x-115 * zoomX, y-(105 + eyes) * zoomY);
    txEllipse (x-110 * zoomX, y-(120 - eyes) * zoomY,  x-90 * zoomX, y-(105 + eyes) * zoomY);
    txArc (x-125 * zoomX, y-100 * zoomY, x-75 * zoomX, y-80 * zoomY, 190 + smileSkew, 90 + smile);
    }
	
void DrawTriangle (int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color1, COLORREF color2)
	{
	txSetColor (color1);
	txSetFillColor (color2);

	POINT triangle[3] = { {x1, y1}, {x2, y2}, {x3, y3} };
	txPolygon(triangle, 3);
	}