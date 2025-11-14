/*

7/28/2011 Ether

Convert Cartesian (X,Y) to angle
counter-clockwise 0-360 degrees from +X axis
with +/- 0.21 degree accuracy
and 0.01 degree max discontinuity at octant boundaries.

*/

#include <stdio.h>



float CCW360X(float x, float y){
float f(float t);
if(x>=0)if(y>=0)if(y<=x)if(x==0)return 0;
else return f(y/x); 
else return 90-f(x/y);
else if(-y<=x)return 360-f(-y/x);
else return 270+f(-x/y);
else if(y>=0)if(y<=-x)return 180-f(-y/x);
else return 90+f(-x/y);
else if(y>=x)return 180+f(y/x);
else return 270-f(x/y);}


float f(float t){
const float a= -15.6526435831;
const float b= 60.6626425889;
const float c= -0.0049997982;
return t*(a*t+b)+c;}




void test(float x, float y){printf("x=%f y=%f CCW360X(x,y)=%f\n",x,y,CCW360X(x,y));}
void cr(void){printf("\n");}

void main(void){
float eps=0.000001;

test(0,0);

cr();
test(1,-eps);
test(1,0);
test(1,eps);

cr();
test(1,1-eps);
test(1,1);
test(1,1+eps);

cr();
test(eps,1);
test(0,1);
test(-eps,1);

cr();
test(-1,1+eps);
test(-1,1);
test(-1,1-eps);

cr();
test(-1,eps);
test(-1,0);
test(-1,-eps);

cr();
test(-1,-1+eps);
test(-1,-1);
test(-1,-1-eps);

cr();
test(-eps,-1);
test(0,-1);
test(eps,-1);

cr();
test(1,-1-eps);
test(1,-1);
test(1,-1+eps);

}