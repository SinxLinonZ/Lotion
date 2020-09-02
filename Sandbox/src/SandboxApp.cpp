#include <Lotion.h>

class ExampleLayer : public Lotion::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lotion::Event& event) override
	{
		LT_TRACE("{0}", event);
	}
};

class Sandbox : public Lotion::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{}
};

Lotion::Application* Lotion::CreateApplication()
{
	return new Sandbox();
}