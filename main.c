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

void update(struct Variables *vars);

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    float x = -120.0f;
    struct Variables vars;
    
    printf("\n Mass(m): ");
    scanf("%f", &(vars.mass));
    
    printf("\n Initial Displacment(a): ");
    scanf("%f", &(vars.initialDisplacement));
    
    
    printf("\n Damping Factor(b): ");
    scanf("%f", (&vars.dampingFactor));
    
    printf("\n Period(T): ");
    scanf("%f", &(vars.period));
    
    
     
    vars.omega = (float)((2 * PI)/(vars.period));
    

    InitWindow(screenWidth, screenHeight, "Damped Motion");

    float y;
    float *yPtr = &y;
    
    char yDisplay[30];
    char xDisplay[30];
    
    

    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {
        
                //reset
                if(IsKeyDown(KEY_DOWN)){
                    x = 0;
                }
                
                if(IsKeyDown(KEY_UP)){
                    update(&vars);
                }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            
            
            
            
                DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, BLACK);
                DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, BLACK);
                
          
                x++;
                *yPtr = motion(&vars.mass, &vars.initialDisplacement, &vars.dampingFactor, &vars.omega, &x);
                DrawCircleV((Vector2){ screenWidth/2, y + screenHeight/2}, 50, BLUE);
                
           
           
                for(int i = 0; i < 600; i++){
                    float x_new = x - i;
                    DrawCircleLines(screenWidth/2 - i, motion(&vars.mass, &vars.initialDisplacement, &vars.dampingFactor, &vars.omega, &x_new) + screenHeight/2, 5, BLUE);
                }
            
            sprintf(yDisplay, "%f", -y);
            sprintf(xDisplay, "%f", x);
            
            
            
            DrawText("Displacment(y): ", 10, 10, 20, BLACK);
            DrawText(yDisplay, 170, 10, 20, BLACK);
            
            DrawText("Time(x): ", 10, 50, 20, BLACK);
            DrawText(xDisplay, 100, 50, 20, BLACK);
            
            
            DrawText("Down key to reset time", 10, screenHeight - 30, 20, BLACK);
            DrawText("Up key to update values", 10, screenHeight - 60, 20, BLACK);
            
        EndDrawing();
    }
    CloseWindow();       

    return 0;
}

void update(struct Variables *vars){
 
    printf("\n Mass(m): ");
    scanf("%f", &(vars -> mass));
    
    printf("\n Initial Displacment(a): ");
    scanf("%f", &(vars -> initialDisplacement));
    
    printf("\n Damping Factor(b, between 0 and 1): ");
    scanf("%f", (&vars ->dampingFactor));
    
    printf("\n Period(T): ");
    scanf("%f", &(vars -> period));
    
    vars -> omega = (float)((2 * PI)/(vars -> period));
}

