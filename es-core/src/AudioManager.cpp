#include "AudioManager.h"

#include "Log.h"
#include "Settings.h"

std::shared_ptr<AudioManager> AudioManager::sInstance;

AudioManager::AudioManager() : mChannel(0)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
		LOG(LogError) << "Error initializing SDL Mixer!\n	" << Mix_GetError();

	Mix_AllocateChannels(MAX_CHANNEL);
}

AudioManager::~AudioManager()
{
	deinit();
}

std::shared_ptr<AudioManager> & AudioManager::getInstance()
{
	//check if an AudioManager instance is already created, if not create one
	if (sInstance == nullptr)
		sInstance = std::shared_ptr<AudioManager>(new AudioManager);

	return sInstance;
}

void AudioManager::deinit()
{
	// TODO: use Mix_ChannelFinished to wait for the launch sound to finish
	//Mix_ChannelFinished()
	Mix_CloseAudio();
	sInstance = nullptr;
}

void AudioManager::playSound(Mix_Chunk *sound, float volume)
{
	if (sound && Settings::getInstance()->getBool("EnableSounds"))
	{
		Mix_VolumeChunk(sound, (int) (MIX_MAX_VOLUME * volume));
		Mix_PlayChannel(mChannel, sound, 0);
		mChannel = (mChannel + 1) % MAX_CHANNEL;
	}
}