#include <iostream>
#include "AudioEngine.h"


int main()
{
	float gameTime = 0.0f;
	bool isPlaying = true;

	AudioEngine& audioEngine = AudioEngine::Instance();

	// Init FMOD
	audioEngine.Init();

	// Load a sound bank
	audioEngine.LoadBank("Master");

	// Create a music event instance									 // Right-click your event in fmod Studio -> Copy GUID
	AudioEvent& music = AudioEngine::Instance().CreateEvent("CarCrash", "{89f257e6-fa6c-4618-908a-5b59695f25c6}");

	// Play the music event
	music.Play();

	while (isPlaying) {

		gameTime += 0.01f;

		// Get a ref to the engine
		AudioEngine& audioEngine = AudioEngine::Instance();

		// Get a ref to the music event
		AudioEvent& music = audioEngine.GetEvent("CarCrash");

		// Get listener
		AudioListener& listener = audioEngine.GetListener();

		// Update fmod
		audioEngine.Update();

		std::cout << gameTime << std::endl;

		if (gameTime > 700.0f)
		{
			isPlaying = false;
		}
	}

	AudioEngine::Instance().Shutdown();
}