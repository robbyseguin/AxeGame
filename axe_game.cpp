#include "raylib.h"

int main()
{
    //Score
    int score = 0;

    // Window dimensions
    int width = 800;
    int height = 450;

    // Circle Coordinates
    int x = 175;
    int y = 100;

    //Circle Radius
    int radius = 25;

    //Circle Collision Detection
    int l_circle_x = x - radius;
    int r_circle_x = x + radius;
    int up_circle_y = y - radius;
    int down_circle_y = y + radius;

    // Rectangle Coordinates
    int rectX = 400;
    int rectY = 0;

    // Rectangle Direction and Speed
    int directionV = 1;
    int directionH = 1;
    // Rectangle Dimensions
    int rectWidth = 50;
    int rectHeight = 50;

    //Rectangle Collision Detection

    int l_rectX = rectX;
    int r_rectX = rectX + rectWidth;
    int up_rectY = rectY;
    int down_rectY = rectY + rectHeight;

    // Player and Axe Speed
    int axeSpeed = 5;
    int playerSpeed = 30;
    bool collision = 
        (down_rectY >= up_circle_y) &&
        (up_rectY <= down_circle_y) && 
        (r_rectX >= l_circle_x) && 
        (l_rectX <= r_circle_x);


    InitWindow(width , height, "Axe Game"); 

    // Setting frames per second
    SetTargetFPS(60);

    while(WindowShouldClose() == false)
    {
        if(collision)
      {
        BeginDrawing();
        DrawText("Game Over", 400, 200, 20, RED);
        EndDrawing();
      }
      else
      {
        BeginDrawing();
        ClearBackground(WHITE);

        // Begin Game Logic

        //update variables
        l_circle_x = x - radius;
        r_circle_x = x + radius;
        up_circle_y = y - radius;
        down_circle_y = y + radius;
        l_rectX = rectX;
        r_rectX = rectX + rectWidth;
        up_rectY = rectY;
        down_rectY = rectY + rectHeight;

        // update collision
        collision = 
        (down_rectY >= up_circle_y) &&
        (up_rectY <= down_circle_y) && 
        (r_rectX >= l_circle_x) && 
        (l_rectX <= r_circle_x);

        DrawCircle(x, y, radius, BLUE);
        DrawRectangle(rectX, rectY, rectWidth, rectHeight, RED);
        DrawText(TextFormat("Score = %i", score), 0, 0, 50, BLACK);
        DrawText("Controls : Arrow keys to Move", 0, 350, 20, BLACK);
        DrawText("Dodge the Red Square", 0, 400, 20, BLACK);
        // Move The Rectangle ( Axe )

        rectY += directionV * axeSpeed;

        if(rectY > (height - rectHeight) || rectY < 0)
        {
            directionV *= -1;
            score += 1;
        }

        rectX += directionH * axeSpeed;

        if (rectX > (width - rectWidth ) || rectX < 0)
            {
                directionH *= -1;
                score += 1;
            }

        // use a switch statement to check for key presses
        switch(GetKeyPressed())
        {
            case KEY_UP:  
            if(y > 0){y -= playerSpeed;} 
                break;
            case KEY_DOWN: 
            if(y < height){y += playerSpeed;}
                break;
            case KEY_LEFT: 
            if(x > 0){x -= playerSpeed;}
                break;
            case KEY_RIGHT:
            if(x < width){x += playerSpeed;}
                break;
        };
      
        
        // End Logic
        EndDrawing();   
      }   
    }


}