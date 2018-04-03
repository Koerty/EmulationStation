#include <resources/TextureResource.h>
#include "GridTileComponent.h"

GridTileComponent::GridTileComponent(Window* window) : GuiComponent(window), mBackground(window), mMaxSize(), mImageColor()
{
	mSelected = false;
	mVisible = true;
	mPadding = Vector2f(0.1f, 0.1f);

	mImage = std::make_shared<ImageComponent>(mWindow);
	mImage->setOrigin(0.5f, 0.5f);

	mImageColor.setUnselectedValue(0xFF0000BB);
	mImageColor.setSelectedValue(0x00FFFFFF);

	mBackground.setImagePath(":/frame.png");
	mBackground.setOrigin(0.5f, 0.5f);

	addChild(&mBackground);
	addChild(&(*mImage));
}

void GridTileComponent::render(const Transform4x4f& parentTrans)
{
	Transform4x4f trans = getTransform() * parentTrans;

	if (mVisible)
		renderChildren(trans);
}

void GridTileComponent::update(int deltaTime)
{
	mMaxSize.update(deltaTime, isSelected());
	mResize = mMaxSize.getCurrentValue();
	resize();
	mImageColor.update(deltaTime, isSelected());
	mImage->setColorShift(mImageColor.getCurrentValue().getValue());
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
	// Resize after the image is changed
	resize();
}

void GridTileComponent::setImage(std::string path)
{
	mImage->setImage(path);
}

void GridTileComponent::setImage(const std::shared_ptr<TextureResource>& texture)
{
	mImage->setImage(texture);
}

void GridTileComponent::setImageColorShift(unsigned int color)
{
	mImage->setColorShift(color);
}

void GridTileComponent::resize()
{
	mImage->setMaxSize(mMaxSize.getCurrentValue() - mPadding);
	mBackground.fitTo(mImage->getSize() + mPadding);// - mBackground.getCornerSize() * 2);
	mBackground.setPosition(getSize().x() / 2, getSize().y() / 2);
}

void GridTileComponent::setMaxSize(Vector2f maxSize)
{
	mMaxSize.setUnselectedValue(maxSize);
	mResize = maxSize;
	resize();
}

void GridTileComponent::setSelectedMaxSize(Vector2f maxSize)
{
	mMaxSize.setSelectedValue(maxSize);
}