#include <iostream>
#include "AudioEngine.h"

float gameTime = 0.0f;

int main()
{
	AudioEngine& audioEngine = AudioEngine::Instance();

	// Init FMOD
	audioEngine.Init();

	// Load a sound bank
	audioEngine.LoadBank("Master");

	// Create a music event instance									 // Right-click your event in fmod Studio -> Copy GUID
	AudioEvent& music = AudioEngine::Instance().CreateEvent("UniqueName", "{b56cb9d2-1d47-4099-b80e-7d257b99a823}");

	// Play the music event
	music.Play();

	while (true) {

		// Get a ref to the engine
		AudioEngine& audioEngine = AudioEngine::Instance();

		// Get a ref to the music event
		AudioEvent& music = audioEngine.GetEvent("UniqueName");

		// Get listener
		AudioListener& listener = audioEngine.GetListener();

		// Update fmod
		audioEngine.Update();
	}

	AudioEngine::Instance().Shutdown();
}