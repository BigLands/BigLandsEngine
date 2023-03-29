#include <BigLandsEngine.h>

class ExampleLayer : public BigLandsEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		BE_INFO("ExampleLayer::Update");
	}

	void OnEvent(BigLandsEngine::Event& event) override
	{
		BE_TRACE("{0}", event);
	}

};

class Project : public BigLandsEngine::Application
{
public:
	Project()
	{
		PushLayer(new ExampleLayer());
	}

	~Project()
	{

	}

};

BigLandsEngine::Application* BigLandsEngine::CreateApplication()
{
	return new Project();
}