#include <Lotion.h>

class Sandbox : public Lotion::Application
{
//public:
//	Sandbox()
//	{}
//
//	~Sandbox()
//	{}
};

Lotion::Application* Lotion::CreateApplication()
{
	return new Sandbox();
}