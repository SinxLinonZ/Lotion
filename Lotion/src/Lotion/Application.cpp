#include "ltpch.h"
#include "Application.h"

#include "Lotion/Log.h"

#include <glad/glad.h>

namespace Lotion
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		LT_CORE_TRACE("{0}", e);
		//LT_CORE_TRACE(e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}


	void Application::Run()
	{
/*
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
*/

		while (m_Running)
		{

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	

}

