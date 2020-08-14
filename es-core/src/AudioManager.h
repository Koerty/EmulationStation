#pragma once
#ifndef ES_CORE_AUDIO_MANAGER_H
#define ES_CORE_AUDIO_MANAGER_H

#include <SDL_mixer.h>
#include <memory>

class AudioManager
{
	// IList max scroll speed use 16ms delay
	// This mean the sound can be up to 16 x 64 = 1024ms length without getting cut
	const int MAX_CHANNEL = 64;

	static std::shared_ptr<AudioManager> sInstance;

	int mChannel;

	AudioManager();

public:
	static std::shared_ptr<AudioManager> & getInstance();

	virtual ~AudioManager();

	void playSound(Mix_Chunk *sound, float volume);
};

#endif // ES_CORE_AUDIO_MANAGER_H
