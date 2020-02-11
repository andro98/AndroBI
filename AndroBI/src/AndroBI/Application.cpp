#include"abipch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace AndroBI
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		ABI_TRACE(e);

		while (true);
	}
}