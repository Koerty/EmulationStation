#ifndef ES_CORE_GRID_TILE_PROPERTY_H
#define ES_CORE_GRID_TILE_PROPERTY_H

#include "math/Vector2f.h"

template <typename T>
class GridTileProperty
{
public:
	GridTileProperty()
	{
		frames = 0;
		enableAnimations = true;
	}

	void setUnselectedValue(T unselectedValue)
	{
		mUnselectedValue = unselectedValue;
		mSelectedValue = unselectedValue;
		mCurrentValue = unselectedValue;
	}

	void setSelectedValue(T selectedValue)
	{
		mSelectedValue = selectedValue;
	}

	T getCurrentValue()
	{
		return mCurrentValue;
	}

	void update(int deltaTime, bool selected)
	{
		if (selected)
		{
			frames += deltaTime;
			if (!enableAnimations || frames >= animationSpeed)
			{
				mCurrentValue = mSelectedValue;
				frames = animationSpeed;
			}
			else
			{
				mCurrentValue += (mSelectedValue - mUnselectedValue) * deltaTime / animationSpeed;
			}
		}
		else
		{
			frames -= deltaTime;
			if (!enableAnimations || frames <= 0)
			{
				mCurrentValue = mUnselectedValue;
				frames = 0;
			}
			else
			{
				mCurrentValue -= (mSelectedValue - mUnselectedValue) * deltaTime / animationSpeed;
			}
		}
	}

private:
	// Animation speed in milliseconds
	const int animationSpeed = 100;

	bool enableAnimations;
	int frames;
	T mUnselectedValue;
	T mSelectedValue;
	T mCurrentValue;
};



#endif // ES_CORE_GRID_TILE_PROPERTY_H
