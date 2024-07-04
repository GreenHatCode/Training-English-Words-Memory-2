#pragma once
class Time
{
public:
	Time(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);
	void setHours(unsigned int value);
	void setMinutes(unsigned int value);
	void setSeconds(unsigned int value);
	unsigned int getHours();
	unsigned int getMinutes();
	unsigned int getSeconds();
private:
	unsigned int hours = 0;
	unsigned int minutes = 0;
	unsigned int seconds = 0;
};