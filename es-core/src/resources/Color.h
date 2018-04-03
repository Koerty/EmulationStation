#pragma once
#ifndef ES_CORE_RESOURCES_COLOR_H
#define ES_CORE_RESOURCES_COLOR_H

class Color
{
public:
	Color();
	Color(unsigned int color);
	Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

	unsigned int getValue() const;

public:
	unsigned char getRed() const;
	unsigned char getGreen() const;
	unsigned char getBlue() const;
	unsigned char getAlpha() const;

	void setRed(unsigned int r);
	void setGreen(unsigned int g);
	void setBlue(unsigned int b);
	void setAlpha(unsigned int a);

	unsigned int getColorTween(unsigned int currentColor, unsigned int endColor, int frame, int endFrame, bool reverse);
	unsigned int addAlpha(unsigned int color, unsigned char alpha);
	static unsigned int createColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	int getColorDifference(unsigned char color, unsigned char compare) const;

	unsigned int mColor;
};

Color operator+=(const Color &color1, const Color &color2);
Color operator-=(const Color &color1, const Color &color2);

Color operator-(const Color &color1, const Color &color2);

Color operator*(const Color &color1, const int value);
Color operator/(const Color &color1, const int value);

#endif // ES_CORE_RESOURCES_COLOR_H
