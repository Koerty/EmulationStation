#pragma once
#ifndef EMULATIONSTATION_ALL_GRIDTILEIMAGECOMPONENT_H
#define EMULATIONSTATION_ALL_GRIDTILEIMAGECOMPONENT_H

#include "ImageComponent.h"

class GridTileImageComponent : public ImageComponent
{
public:
	GridTileImageComponent(Window* window);

	void setSize(const Vector2f& size);
};

#endif //EMULATIONSTATION_ALL_GRIDTILEIMAGECOMPONENT_H
