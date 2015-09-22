#ifndef POINT_H
#define POINT_H

template <typename T>
struct Point
{
	Point();
	~Point();

	T xPos;
	T yPos;
};

#endif