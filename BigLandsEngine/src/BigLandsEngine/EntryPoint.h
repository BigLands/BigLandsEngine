#pragma once

#ifdef BE_PLATFORM_WINDOWS

extern BigLandsEngine::Application* BigLandsEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = BigLandsEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif