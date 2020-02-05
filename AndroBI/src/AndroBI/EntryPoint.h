#pragma once

#ifdef ABI_PLATFORM_WINDOWS

extern AndroBI::Application* AndroBI::CreateApplication();

int main(int argc, char** argv)
{
	auto app = AndroBI::CreateApplication();
	app->Run();
	delete app;
}

#endif