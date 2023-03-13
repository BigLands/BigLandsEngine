#pragma once

#include "Core.h"
#include "Events/Event.h"


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

