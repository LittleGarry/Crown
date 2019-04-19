#include "cwpch.h"
#include "Application.h"

#include "Crown/Events/ApplicationEvent.h"
#include "Crown/Log.h"

#include <GLFW/glfw3.h>

namespace Crown {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}

	
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}


	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		CW_CORE_TRACE("{0}", event);
	}


	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;

		return true;
	}
}