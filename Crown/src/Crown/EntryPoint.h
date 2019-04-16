#pragma once

#ifdef CW_PLATFORM_WINDOWS

extern Crown::Application* Crown::CreateApplication();

int main(int argc, char** argv)
{
	Crown::Log::Init();

	CW_CORE_TRACE("Core");
	CW_INFO("Client");

	auto app = Crown::CreateApplication();
	app->Run();

	delete app;
}

#endif