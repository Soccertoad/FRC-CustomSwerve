/*

7/28/2011 Ether

Convert Cartesian (X,Y) to angle
zero to 360 degrees clockwise from +Y axis
with accuracy +/-0.21 degree
and discontinuity 0.01 degree maximum at octant boundaries

*/

#include <stdio.h>



float CW360Y(float x, float y){
float f(float t);
if(x>=0)if(y>=0)if(y>x)return f(x/y);else
if(x==0)return 0; else return 90-f(y/x);else
if(-y<=x)return 90+f(-y/x);else return 180-f(-x/y);else
if(y<=0)if(y<=x)return 180+f(x/y);else return 270-f(y/x);else
if(y<=-x)return 270+f(-y/x);else return 360-f(-x/y);}

float f(float t){
const float a= -15.6526435831;
const float b= 60.6626425889;
const float c= -0.0049997982;
return t*(a*t+b)+c;}



// here's code to test the function:

void test(float x, float y){printf("x=%f y=%f CW360Y(x,y)=%f\n",x,y,CW360Y(x,y));}
void cr(void){printf("\n");}

void main(void){
float eps=0.000001;

test(0,0);

cr();
test(-eps,1);
test(0,1);
test(eps,1);

cr();
test(1,1+eps);
test(1,1);
test(1,1-eps);

cr();
test(1,eps);
test(1,0);
test(1,-eps);

cr();
test(1,-1+eps);
test(1,-1);
test(1,-1-eps);

cr();
test(eps,-1);
test(0,-1);
test(-eps,-1);

cr();
test(-1,-1-eps);
test(-1,-1);
test(-1,-1+eps);

cr();
test(-1,-eps);
test(-1,0);
test(-1,eps);

cr();
test(-1,1-eps);
test(-1,1);
test(-1,1+eps);

cr();
test(-eps,1);
}