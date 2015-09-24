#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

const float pi = 3.14159;

class Noise
{

	public:
		Noise( float seed );

		float getVal( float x, float y );

	private:

		float genNum( float seed );
		inline float genNum2D( float x, float y );

		float cosineInterpolate( float y1, float y2, float loc );

};

float Noise::genNum( float seed )
{
	int x = (x<<13) ^ x;

 	return (double)( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) *( 0x7fffffff)) / 1073741824.0);   

}

inline float Noise::genNum2D( float x, float y )
{

	int n=(int)x+(int)y*57;
	n=(n<<13)^n;
	
	int nn=(n*(n*n*60493+19990303)+1376312589)*(0x7fffffff);
	
	return 1.0-((float)nn/1073741824.0);

}

inline float Noise::cosineInterpolate( float a, float b, float x )
{
 
	 float ft=x * 3.1415927;
	 float f=(1.0-cos(ft))* 0.5;
	 return a*(1.0-f)+b*f;

}

Noise::Noise( float seed )
{

}

float Noise::getVal( float x, float y )
{

	double floorx=(double)((int)x);//This is kinda a cheap way to floor a double integer.
	double floory=(double)((int)y);
	double s,t,u,v;//Integer declaration
	
	s=genNum2D(floorx,floory); 
	t=genNum2D(floorx+1,floory);
	u=genNum2D(floorx,floory+1);//Get the surrounding pixels to calculate the transition.
	v=genNum2D(floorx+1,floory+1);
	
	double int1=cosineInterpolate(s,t,x-floorx);//Interpolate between the values.
	double int2=cosineInterpolate(u,v,x-floorx);//Here we use x-floorx, to get 1st dimension. Don't mind the x-floorx thingie, it's part of the cosine formula.
	
	return cosineInterpolate(int1,int2,y-floory);//Here we use y-floory, to get the 2nd dimension.

}

#endif