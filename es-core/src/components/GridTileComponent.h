#pragma once
#ifndef ES_CORE_COMPONENTS_GRID_TILE_COMPONENT_H
#define ES_CORE_COMPONENTS_GRID_TILE_COMPONENT_H

#include "resources/Color.h"
#include "GridTileProperty.h"
#include "ComponentGrid.h"
#include "TextComponent.h"
#include "NinePatchComponent.h"

class GridTileComponent : public GuiComponent
{
public:
	GridTileComponent(Window* window);

	void render(const Transform4x4f& parentTrans) override;
	void update(int deltaTime) override;

	bool isSelected() const;

	void setSelected(bool selected);
	void setVisible(bool visible);
	void setResize(const Vector2f& size);
	void setImage(std::string path);
	void setImage(const std::shared_ptr<TextureResource>& texture);
	void setImageColorShift(unsigned int color);

	void setMaxSize(Vector2f maxSize);
	void setSelectedMaxSize(Vector2f maxSize);
private:
	void resize();

	GridTileProperty<Vector2f> mMaxSize;
	GridTileProperty<Color> mImageColor;
	bool mSelected;
	bool mVisible;
	Vector2f mResize;
	Vector2f mPadding;

	std::shared_ptr<GridTileImageComponent> mImage;
	NinePatchComponent mBackground;
};

#endif // ES_CORE_COMPONENTS_GRID_TILE_COMPONENT_H
