#include "pch.h"
#include "Time.h"

Time::Time(unsigned int h, unsigned int m, unsigned int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

void Time::setHours(unsigned int value)
{
	hours = value;
}

void Time::setMinutes(unsigned int value)
{
	minutes = value;
}

void Time::setSeconds(unsigned int value)
{
	seconds = value;
}

unsigned int Time::getHours()
{
	return hours;
}

unsigned int Time::getMinutes()
{
	return minutes;
}

unsigned int Time::getSeconds()
{
	return seconds;
}
