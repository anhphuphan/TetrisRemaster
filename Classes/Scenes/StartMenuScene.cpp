#include "StartMenuScene.h"
#include "CreatorReader.h"
USING_NS_CC;

cocos2d::Scene * TetrisGame::StartMenuScene::createScene()
{
	creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/scenes/StartMenu.ccreator");

	// will create the needed sprite sheets + design resolution
	reader->setup();

	// get the scene graph
	Scene* scene = reader->getSceneGraph();
	
	auto *btnExit = dynamic_cast<ui::Button*>(scene->getChildByName("btnQuit"));
	auto *btnNewGame = dynamic_cast<ui::Button*>(scene->getChildByName("btnNewGame"));
	
	
	btnExit->addClickEventListener([&](Ref*)
	{
		Director::getInstance()->end();
	});

	btnNewGame->addClickEventListener([&](Ref*)
	{
		auto scene = ChooseModeScene::create();
		Director::getInstance()->pushScene(scene);
	});
	
	return scene;
}

bool TetrisGame::StartMenuScene::init()
{
	return true;
}
