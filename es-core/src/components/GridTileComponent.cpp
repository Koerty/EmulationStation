#include <resources/TextureResource.h>
#include "GridTileComponent.h"

GridTileComponent::GridTileComponent(Window* window) : GuiComponent(window), mGrid(window, Vector2i(1, 2)), mBackground(window)
{
	mSelected = false;
	mVisible = true;
	mPadding = Vector2f(0.9f, 0.9f);

	mImage = std::make_shared<GridTileImageComponent>(mWindow);
	mText = std::make_shared<TextComponent>(mWindow, "", Font::get(FONT_SIZE_SMALL), 0x777777FF);

	mText->setHorizontalAlignment(ALIGN_CENTER);

	mGrid.setEntry(mImage, Vector2i(0, 0), false, true);
	mGrid.setEntry(mText, Vector2i(0, 1), false, true);
	mGrid.setRowHeightPerc(0, 1.0f - CELL_FOOTER_HEIGHT);
	mGrid.setRowHeightPerc(1, CELL_FOOTER_HEIGHT);
	mGrid.setOrigin(0.5f, 0.5f);

	mBackground.setImagePath(":/frame.png");
	mBackground.setOrigin(0.5f, 0.5f);

	addChild(&mBackground);
	addChild(&mGrid);
}

void GridTileComponent::render(const Transform4x4f& parentTrans)
{
	Transform4x4f trans = getTransform() * parentTrans;

	if (mVisible)
		renderChildren(trans);
}

bool GridTileComponent::isSelected() const
{
	return mSelected;
}

void GridTileComponent::setSelected(bool selected)
{
	mSelected = selected;
}

void GridTileComponent::setVisible(bool visible)
{
	mVisible = visible;
}

void GridTileComponent::setResize(const Vector2f& size)
{
	// Save for later, as we don't want to resize, then change the image and resize again
	mResize = size;
}

void GridTileComponent::setImage(std::string path) {
	mImage->setImage(path);

	// Resize after the image is changed
	resize();
}

void GridTileComponent::setImage(const std::shared_ptr<TextureResource>& texture) {
	mImage->setImage(texture);

	// Resize after the image is changed
	resize();
}

void GridTileComponent::setImageColorShift(unsigned int color)
{
	mImage->setColorShift(color);
}

void GridTileComponent::setText(const std::string& text) {
	mText->setText(text);
}

void GridTileComponent::resize()
{
	mGrid.setSize(mResize * mPadding);
	mBackground.fitTo(mResize - mBackground.getCornerSize() * 2);
	mBackground.setPosition(getSize().x() / 2, getSize().y() / 2);
}