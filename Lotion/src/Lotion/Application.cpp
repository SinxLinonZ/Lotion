#include "Application.h"

#include "Events/Event.h"
#include "Lotion/Events/ApplicationEvent.h"
#include "Lotion/Log.h"

namespace Lotion
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		LT_TRACE(e);

		while (true);
	}
}

