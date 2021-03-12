#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


float motion(float *m, float *a, float *b, float *w, float *x){
    return (*a)*exp((-1*(*b)*(*x))/(2*(*m)))   *  cosf(sqrt( pow((2*PI)/(*a), 2) - pow((*b)/(4*(*m)), 2) ) * (*x));
}

struct Variables {
  float mass;
  float initialDisplacement;
  float dampingFactor;
  float period;
  float omega;
};

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    float x = -120.0f;
    
    struct Variables vars = {35.0, 100.0, .3, 4.0};
    /*
    vars.mass = 35.0f;
    vars.initialDisplacement = 5.0f;
    vars.dampingFactor = 0.5f;
    vars.period = 3.0f;
    vars.omega = (float)((2 * PI)/(vars -> period));
    */

    InitWindow(screenWidth, screenHeight, "Damped Motion");

    //Vector2 agentP = ;
    
    char yDisplay[30];
    char xDisplay[30];

    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            
            //printf("%f\n", motion(&vars.mass, &vars.initialDisplacement, &vars.dampingFactor, &vars.omega, &x));
            
            
                DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, BLACK);
                
            //for(int i = 0; i < (screenWidth/2); i++){
                x+=1;
                float y = motion(&vars.mass, &vars.initialDisplacement, &vars.dampingFactor, &vars.omega, &x);
                DrawCircleV((Vector2){ screenWidth/2, y + screenHeight/2}, 50, BLUE);
            //}
            sprintf(yDisplay, "%f", y);
            sprintf(xDisplay, "%f", x);
            //strcpy(yDisplay, "Displacment");
            
            
           // strcpy(xDisplay, "<- time");
            
            DrawText("Displacment(y): ", 10, 10, 20, BLACK);
            DrawText(yDisplay, 170, 10, 20, BLACK);
            
            DrawText("Time(x): ", 10, 50, 20, BLACK);
            DrawText(xDisplay, 100, 50, 20, BLACK);
            
        EndDrawing();
    }
    CloseWindow();       

    return 0;
}
/*
float motion(float *m, float *a, float *b, float *w, float *x){
    return ((*a) * exp((-((*b) * (*x)) /(2 *(*m))))) * cosf(sqrt( pow(( (2*PI)/(*a) ), 2) - pow(((*b)/(4*(*m)) ), 2) ) * (*x));
}*/