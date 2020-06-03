#include "pbxclientpch.h"
#include "Parbox.h"

class Game : public pbx::Engine
{
public:
	pbx::Sprite* spr;
	//pbx::Sprite* spr2;
public:
	Game()
	{
		SetWindow("Parbox Engine", 800, 600);
	}

	void Create() override
	{
		spr = new pbx::Sprite("res/images/wall.jpg");
		//spr2 = new pbx::Sprite("res/images/wall.jpg");
		PBX_LOG_INFO("Engine Started");		
	}

	void Update() override
	{
		Clear(pbx::CYAN);
		spr->Draw(pbx::Vector2i(300, 400), 0.0f, pbx::Vector2i(200, 200), pbx::WHITE);
		//spr2->Draw(pbx::Vector2i(100, 200), 25.0f, pbx::Vector2i(200, 200), pbx::WHITE);
	}

	void Destroy() override
	{
	}
};

int main()
{
	Game* game = new Game();
	game->Run();
	delete game;
	return 0;
}