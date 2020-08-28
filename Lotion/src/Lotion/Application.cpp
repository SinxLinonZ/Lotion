#include "ltpch.h"
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
		
		Lotion::Log::Init();

		LT_CORE_INFO("Log System Init...");
		LT_CORE_TRACE("Trace Log!");
		LT_CORE_INFO("Info Log!");
		LT_CORE_WARN("Warn Log!");
		LT_CORE_ERROR("Error Log!");
		LT_CORE_CRITICAL("Critical Log!");
		LT_CORE_TRACE("======================\n");
		

		LT_CORE_INFO("Variable logging test...");
		int a = 12;
		LT_INFO("TEST, Hello! Var={0}", a);
		LT_CORE_TRACE("======================\n");
		LT_CORE_TRACE("");

		LT_CORE_INFO("Event system test....");
		WindowResizeEvent e(1280, 720);
		LT_TRACE(e);

		while (true);
	}
}

