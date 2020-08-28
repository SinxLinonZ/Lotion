#pragma once

#ifdef LT_PLATFORM_WINDOWS

extern Lotion::Application* Lotion::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lotion::CreateApplication();
	app->Run();
	delete app;
}

#endif