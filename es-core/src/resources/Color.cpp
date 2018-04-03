#include "Color.h"

Color::Color()
{
	mColor = 0xFFFFFFFF;
}

Color::Color(unsigned int color)
{
	mColor = color;
}

Color::Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	mColor = createColor(r, g, b, a);
}

unsigned int Color::getValue() const
{
	return mColor;
}

unsigned char Color::getRed() const
{
	unsigned char red;
	red = mColor >> 24;
	return red;
}

unsigned char Color::getGreen() const
{
	unsigned char green;
	green = mColor >> 16;
	return green;
}

unsigned char Color::getBlue() const
{
	unsigned char blue;
	blue = mColor >> 8;
	return blue;
}

unsigned char Color::getAlpha() const
{
	unsigned char alpha;
	alpha = mColor >> 0;
	return alpha;
}

void Color::setRed(unsigned int r)
{
	mColor |= r;
}

void Color::setGreen(unsigned int g)
{
	mColor |= g << 8;
}

void Color::setBlue(unsigned int b)
{
	mColor |= b << 16;
}

void Color::setAlpha(unsigned int a)
{
	mColor |= a << 24;
}

unsigned int Color::getColorTween(unsigned int currentColor, unsigned int endColor, int frame, int endFrame, bool reverse)
{
/*
	// Reversed frame
	if (reverse) {
		frame = endFrame - frame;
		if (frame < 0) frame = 0;
	}

	// Get bytes of source and targer colors
	unsigned char r = getRed(currentColor);
	unsigned char g = getGreen(currentColor);
	unsigned char b = getBlue(currentColor);
	unsigned char a = getAlpha(currentColor);
	unsigned char er = getRed(endColor);
	unsigned char eg = getGreen(endColor);
	unsigned char eb = getBlue(endColor);
	unsigned char ea = getAlpha(endColor);

	// get Color differences and divide to get amount per frame
	int tar = (int)(getColorDifference(er, r) / endFrame);
	int tag = (int)(getColorDifference(eg, g) / endFrame);
	int tab = (int)(getColorDifference(eb, b) / endFrame);
	int tae = (int)(getColorDifference(ea, a) / endFrame);

	// Get per frame iteration
	r = (unsigned char)(r + (tar * frame));
	g = (unsigned char)(g + (tag * frame));
	b = (unsigned char)(b + (tab * frame));
	a = (unsigned char)(a + (tae * frame));

	// shift back to color format and return (return target if at final frame)
	if (frame == endFrame) return endColor;
	return createColor(r, g, b, a);
 */
}

unsigned int Color::addAlpha(unsigned int color, unsigned char alpha) {
	/*
	//  Shift all bytes down
	color << 8;

	color = getRed(color) << 24 | getGreen(color) << 16 | getBlue(color) << 8 | alpha;
	return color;
	*/
	return 0;
}

unsigned int Color::createColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	unsigned int c;
	c = r << 24 | g << 16 | b << 8 | a;
	return c;
}

int Color::getColorDifference(unsigned char color, unsigned char compare) const
{
	int diff = (color - compare);
	//if (diff < 0) diff *= -1;
	return diff;
}

Color operator-(const Color &color1, const Color &color2)
{
	int r = color1.getColorDifference(color2.getRed(), color1.getRed());
	int g = color1.getColorDifference(color2.getGreen(), color1.getGreen());
	int b = color1.getColorDifference(color2.getBlue(), color1.getBlue());
	int a = color1.getColorDifference(color2.getAlpha(), color1.getAlpha());

	return Color(r, g, b, a);
}

Color operator+=(const Color &color1, const Color &color2)
{
	int r = color2.getRed() + color1.getRed();
	int g = color2.getGreen() + color1.getGreen();
	int b = color2.getBlue() + color1.getBlue();
	int a = color2.getAlpha() + color1.getAlpha();

	return Color(r, g, b, a);
}

Color operator-=(const Color &color1, const Color &color2)
{
	int r = color2.getRed() - color1.getRed();
	int g = color2.getGreen() - color1.getGreen();
	int b = color2.getBlue() - color1.getBlue();
	int a = color2.getAlpha() - color1.getAlpha();

	return Color(r, g, b, a);
}

Color operator*(const Color &color1, const int value)
{
	int r = color1.getRed();
	int g = color1.getGreen();
	int b = color1.getBlue();
	int a = color1.getAlpha();

	return Color(r * value, g * value, b * value, a * value);
}

Color operator/(const Color &color1, const int value)
{
	int r = color1.getRed();
	int g = color1.getGreen();
	int b = color1.getBlue();
	int a = color1.getAlpha();

	return Color(r / value, g / value, b / value, a / value);
}