#ifndef PERLINNOISE_H
#define PERLINNOISE_H

class Noise
{

	public:
		Noise( float amp, float freq );

		float GenNum();

	private:
		float amp, freq;
};

Noise::Noise( float amp, float freq )
{


	
}

#endif