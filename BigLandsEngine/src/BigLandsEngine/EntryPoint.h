#pragma once

#ifdef BE_PLATFORM_WINDOWS

extern BigLandsEngine::Application* BigLandsEngine::CreateApplication();

int main(int argc, char** argv) {
	BigLandsEngine::Log::Init();
	BE_CORE_WARN("LOGGER WORK");
	int a = 5;
	BE_INFO("LOGGER WORK Var={0}", a);

	auto app = BigLandsEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif