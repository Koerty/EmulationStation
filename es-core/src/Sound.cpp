#include "Sound.h"

#include "Log.h"
#include "Settings.h"
#include "ThemeData.h"

std::map< std::string, std::shared_ptr<Sound> > Sound::sMap;

std::shared_ptr<Sound> Sound::get(const std::string& path)
{
	auto it = sMap.find(path);
	if(it != sMap.cend())
		return it->second;

	std::shared_ptr<Sound> sound = std::shared_ptr<Sound>(new Sound(path));
	sMap[path] = sound;
	return sound;
}

const std::string Sound::getPath(const std::shared_ptr<ThemeData>& theme, const std::string& view, const std::string& element)
{
	LOG(LogInfo) << " req sound [" << view << "." << element << "]";

	const ThemeData::ThemeElement* elem = theme->getElement(view, element, "sound");
	if(!elem || !elem->has("path"))
	{
		LOG(LogInfo) << "   (missing)";
		return "";
	}

	return elem->get<std::string>("path");
}

std::shared_ptr<Sound> Sound::getFromTheme(const std::shared_ptr<ThemeData>& theme, const std::string& view, const std::string& element)
{
	return get(getPath(theme, view, element));
}

Sound::Sound(const std::string & path)
{
	loadFile(path);
}

Sound::~Sound()
{
	deinit();
}

void Sound::loadFile(const std::string & path)
{
	mPath = path;
	init();
}

void Sound::init()
{
	if(mPath.empty())
	{
		mSound = NULL;
		return;
	}

	mSound = Mix_LoadWAV(mPath.c_str());
}

void Sound::deinit()
{
	Mix_FreeChunk(mSound);
}

int channel = 0;

void Sound::play()
{
	if(!Settings::getInstance()->getBool("EnableSounds"))
		return;

	if(mSound)
	{
		Mix_VolumeChunk(mSound, MIX_MAX_VOLUME);
		Mix_PlayChannel(channel, mSound, 0);
		channel = (channel + 1) % 64;
	}
}