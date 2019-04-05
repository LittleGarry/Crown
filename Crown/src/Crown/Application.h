#pragma once

#include "Core.h"

namespace Crown {

	class CROWN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}