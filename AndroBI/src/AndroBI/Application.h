#pragma once
#include "Core.h"

namespace AndroBI {

	class ANDROBI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

