#pragma once

#include "Core.h"


namespace BigLandsEngine {
	class BIGLANDSENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defind in client
	Application* CreateApplication();

}

