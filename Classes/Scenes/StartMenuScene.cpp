#include "StartMenuScene.h"

USING_NS_CC;

void TetrisGame::StartMenuScene::onClickStartMenu(cocos2d::Ref *)
{
	auto scene = ChooseModeScene::create();
	Director::getInstance()->pushScene(scene);
}

void TetrisGame::StartMenuScene::onClickLoadGame(cocos2d::Ref *)
{
}

cocos2d::Scene * TetrisGame::StartMenuScene::createScene()
{
	//auto scene = Scene::create();
	//auto layer = StartMenuScene::create();
	//scene->addChild(layer);

	return StartMenuScene::create();
}

bool TetrisGame::StartMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Game Menu
	auto menuItem1 = MenuItemFont::create("Start Game", CC_CALLBACK_1(StartMenuScene::onClickStartMenu, this));
	auto menuItem2 = MenuItemFont::create("Load Game", CC_CALLBACK_1(StartMenuScene::onClickLoadGame, this));

	menuItem1->setPosition(
		visibleSize.width / 2,
		(visibleSize.height / 10) * 5
	);

	menuItem2->setPosition(
		visibleSize.width / 2,
		(visibleSize.height / 10) * 4
	);
	
	auto menu = Menu::create(menuItem1, menuItem2, nullptr);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	return true;
}
