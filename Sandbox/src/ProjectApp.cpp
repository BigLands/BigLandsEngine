#include <BigLandsEngine.h>

class Project : public BigLandsEngine::Application {

public:
	Project()
	{

	}

	~Project()
	{

	}
};

BigLandsEngine::Application* BigLandsEngine::CreateApplication() 
{
	return new Project();
}