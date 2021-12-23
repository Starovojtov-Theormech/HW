#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

struct Vector2D {
    double x;
    double y;
};

double operator*(Vector2D V1, Vector2D V2);
double cosangle(Vector2D V1, Vector2D V2);
double distance(int a, int b, int x0, int y0);
bool isright(int x0, int y0,int x,int y);


#endif //UNTITLED_FUNCTIONS_H
