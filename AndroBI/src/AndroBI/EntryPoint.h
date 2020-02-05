#pragma once

#ifdef ABI_PLATFORM_WINDOWS

extern AndroBI::Application* AndroBI::CreateApplication();

int main(int argc, char** argv)
{
	AndroBI::Log::Init();
	ABI_CORE_WARN("Initialized Log!");
	int a = 5;
	ABI_INFO("Hello! Var={0}", a);

	auto app = AndroBI::CreateApplication();
	app->Run();
	delete app;
}

#endif