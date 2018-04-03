#include <iostream>
#include "resources/TextureResource.h"
#include "GridTileImageComponent.h"

GridTileImageComponent::GridTileImageComponent(Window* window) : ImageComponent(window)
{

}

void GridTileImageComponent::setSize(const Vector2f& size)
{
	setMaxSize(size);
}