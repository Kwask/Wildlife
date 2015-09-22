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
		Noise( float amp, float freq );

		float getVal( float x, float y );

	private:
		float amp, freq;

		std::vector<float> temp;

		float vals[10];
		float genNum();
		float cosineInterpolate( float y1, float y2, float loc );

};

float Noise::genNum()
{

	int a = (rand()%100000);
	return 1-(((float)a/100000.0f)*2);

}

float Noise::cosineInterpolate( float y1, float y2, float loc )
{
 
	float loc2 = ( 1-cos( loc * pi ) )/2;
	return ( y1*(1-loc2) + y2*loc2 );

}

Noise::Noise( float amp, float freq )
{

	const int maxval = 10;

	this->amp = amp;
	this->freq = freq;

	for( int i = 0; i < maxval; i++ )
	{

		vals[i] = genNum();

	}

}

float Noise::getVal( float x, float y )
{

	return cosineInterpolate( vals[(int)floor(x)], vals[(int)ceil(x)], x-floor(x) );

}

#endif