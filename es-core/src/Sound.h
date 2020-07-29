#pragma once
#ifndef ES_CORE_SOUND_H
#define ES_CORE_SOUND_H

#include "SDL_audio.h"
#include <map>
#include <memory>
#include <string>
#include <SDL_mixer.h>

class ThemeData;

class Sound
{
	std::string mPath;
	Mix_Chunk *mSound;

public:
	static std::shared_ptr<Sound> get(const std::string& path);
	static const std::string getPath(const std::shared_ptr<ThemeData>& theme, const std::string& view, const std::string& element);
	static std::shared_ptr<Sound> getFromTheme(const std::shared_ptr<ThemeData>& theme, const std::string& view, const std::string& element);

	~Sound();

	void init();
	void deinit();

	void loadFile(const std::string & path);

	void play();

private:
	Sound(const std::string & path = "");
	static std::map< std::string, std::shared_ptr<Sound> > sMap;
};

#endif // ES_CORE_SOUND_H
