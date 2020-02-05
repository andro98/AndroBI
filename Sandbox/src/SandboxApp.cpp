#include<Androbi.h>


class Sandbox : public AndroBI::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

AndroBI::Application* AndroBI::CreateApplication()
{
	return new Sandbox();
}