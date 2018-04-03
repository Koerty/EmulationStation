#pragma once
#ifndef ES_CORE_COMPONENTS_HELP_COMPONENT_H
#define ES_CORE_COMPONENTS_HELP_COMPONENT_H

#include "ComponentGrid.h"
#include "TextComponent.h"
#include "GridTileImageComponent.h"
#include "NinePatchComponent.h"

class GridTileComponent : public GuiComponent
{
public:
	GridTileComponent(Window* window);

	void render(const Transform4x4f& parentTrans) override;

	bool isSelected() const;

	void setSelected(bool selected);
	void setVisible(bool visible);
	void setResize(const Vector2f& size);
	void setImage(std::string path);
	void setImage(const std::shared_ptr<TextureResource>& texture);
	void setImageColorShift(unsigned int color);
	void setText(const std::string& text);

private:
	void resize();

	const float CELL_FOOTER_HEIGHT = 0.15f;

	bool mSelected;
	bool mVisible;
	Vector2f mResize;
	Vector2f mPadding;

	std::shared_ptr<GridTileImageComponent> mImage;
	std::shared_ptr<TextComponent> mText;
	NinePatchComponent mBackground;

	ComponentGrid mGrid;
};

#endif // ES_CORE_COMPONENTS_HELP_COMPONENT_H
