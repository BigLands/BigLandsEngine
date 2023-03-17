#pragma once

#ifdef BE_PLATFORM_WINDOWS

extern BigLandsEngine::Application* BigLandsEngine::CreateApplication();

int main(int argc, char** argv)
{
	BigLandsEngine::Log::Init();
	BE_CORE_WARN("Initialized Log!");
	int a = 5;
	BE_INFO("Hello! Var={0}", a);

	auto app = BigLandsEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif