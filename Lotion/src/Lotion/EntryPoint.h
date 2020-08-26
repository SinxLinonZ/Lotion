#pragma once

#ifdef LT_PLATFORM_WINDOWS

extern Lotion::Application* Lotion::CreateApplication();

int main(int argc, char** argv)
{
	
	Lotion::Log::Init();
	LT_CORE_TRACE("Trace Log!");
	LT_CORE_INFO("Info Log!");
	LT_CORE_WARN("Warn Log!");
	LT_CORE_ERROR("Error Log!");
	LT_CORE_CRITICAL("Critical Log!");
	int a = 12;
	LT_INFO("TEST, Hello! Var={0}", a);
	

	auto app = Lotion::CreateApplication();
	app->Run();
	delete app;
}

#endif