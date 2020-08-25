#pragma once

#ifdef LT_PLATFORM_WINDOWS

extern Lotion::Application* Lotion::CreateApplication();

int main(int argc, char** argv)
{
	/*
	Lotion::Log::Init();
	LT_CORE_TRACE("Initialized Log!");
	LT_CORE_INFO("Initialized Log!");
	LT_CORE_WARN("Initialized Log!");
	LT_CORE_ERROR("Initialized Log!");
	LT_CORE_CRITICAL("Initialized Log!");
	int a = 12;
	LT_INFO("Hello! Var={0}", a);
	*/

	auto app = Lotion::CreateApplication();
	app->Run();
	delete app;
}

#endif