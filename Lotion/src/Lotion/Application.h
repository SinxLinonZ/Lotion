#pragma once

#include "Core.h"

namespace Lotion
{
	class LOTION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

