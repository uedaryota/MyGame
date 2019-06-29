/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	//Sprite�̐���
	Sprite* spr = Sprite::create("neko.png");
	this->addChild(spr);
	spr->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));

	JumpBy* action1 = JumpBy::create(0.5f, Vec2(100.0f, 0.0f), 100, 7);
	JumpBy* action2 = JumpBy::create(0.5f, Vec2(-100.0f, .0f), 100, 7);
	Sequence* action3 = Sequence::create(action1, action2, nullptr);
	RotateTo* action4 = RotateTo::create(1.0f, Vec3(7200, 100, 100));
	Spawn* action5 = Spawn::create(action3, action4, nullptr);
	//�w��A�N�V������3��J��Ԃ��A�N�V����
	RepeatForever* action6 = RepeatForever::create(action5);
	//�A�g�A�N�V���������s
	spr->runAction(action6);

	//�ړ��A�N�V�����̐���
	//MoveTo* action1 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));
	//�W�����v�A�N�V�����̐���
	//JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//�J���[�A�N�V�����H
	//TintTo* action3 = TintTo::create(2.0f, Color3B(255, 255, 0));
	//�A�g�A�N�V����(�ړ����W�����v)�̐���
	//Sequence* action3 = Sequence::create(action1, action2, nullptr);
	//�����A�N�V����(�ړ����W�����v)�̐���
	//Spawn* action4 = Spawn::create(action2, action3, nullptr);
	//Sequence* action5 = Sequence::create(action1, action4, nullptr);
	//�A�g�A�N�V���������s
	//spr->runAction(action3);
	//spr->runAction(action5);

	//for (int i = 0; i < 10; i++)
	//{
	//	//float sx, sy;
	//	//sx = (float)rand() / RAND_MAX * visibleSize.width;
	//	//sy = (float)rand() / RAND_MAX * visibleSize.height;
	//	float sx, sy;
	//	sx = (float)rand() / RAND_MAX * visibleSize.width;
	//	sy = (float)rand() / RAND_MAX * visibleSize.height;

	//	sprite[i] = Sprite::create("neko.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(100 * i, visibleSize.height / 2.0f));
	//	//sprite[i]->setPosition(Vec2(sx, sy));
	//	//sprite[i]->setPosition(Vec2(100 * i, visibleSize.height/2.0f));
	//	sprite[i]->setPosition(Vec2(sx, sy));
	//	sprite[i]->setScale(0.1f);

	//	//float ex, ey;
	//	//ex = (float)rand()/ RAND_MAX * visibleSize.width;
	//	//ey = (float)rand()/ RAND_MAX * visibleSize.height;
	//	float ex, ey;
	//	ex = (float)rand() / RAND_MAX * visibleSize.width;
	//	ey = (float)rand() / RAND_MAX * visibleSize.height;

	//	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(ex, ey));
	//	JumpBy* action1 = JumpBy::create(1.0f, Vec2(300, 0), 300, 1);
	//	MoveTo* action2 = MoveTo::create(1.0f, Vec2(ex, ey));
	//	//JumpBy* action1 = JumpBy::create(1.0f, Vec2(300,0), 300, 1);
	//	sprite[i]->runAction(action1);
	//}

	//�����̏����� C#��(Random r = new Random();)
	//srand(time(nullptr));

	//for (int i = 0; i < 3000; i++)
	//{
	//	sprite[i] = Sprite::create("neko.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(100 * i, 0));
	//	sprite[i]->setScale(0.3f);

	//	float mx, my;

	//	mx = (float)rand() / RAND_MAX;
	//	my = (float)rand() / RAND_MAX;

	//	FadeIn* action1 = FadeIn::create(5.0f);
	//	RotateTo* action2 = RotateTo::create(10.0f, Vec3(10800, 29000, 36000));
	//	EaseIn* action3 = EaseIn::create(action2, 5.0f);
	//	MoveBy* action4 = MoveBy::create(10.0f, Vec2(-1000 * mx, 400 * my));
	//	EaseBounceInOut* action5 = EaseBounceInOut::create(action4);
	//	//JumpTo* action6 = JumpTo::create(5.0f, Vec2(-150, -100), 50.0f, 2);
	//	sprite[i]->runAction(action1);
	//	sprite[i]->runAction(action2);
	//	sprite[i]->runAction(action3);
	//	sprite[i]->runAction(action4);
	//	sprite[i]->runAction(action5);
	//	//sprite[i]->runAction(action6);
	//}

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}

	// �e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬
	/*sprite = Sprite::create("neko.png");*/
	//sprite = Sprite::create("sample01.png");
	// �V�[���O���t�ɂȂ�
	/*this->addChild(sprite);*/

	//�A�N�V�����̍쐬(1�b�����ĉE��200�A���100����)
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	//ScaleTo* action1 = ScaleTo::create(1.0f, 5.0f);
	//JumpTo* action1 = JumpTo::create(1.5f, Vec2(200, 100), 500.0f, 2);
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(500, 500);
	conf.controlPoint_2 = Vec2(-700, -700);
	conf.endPosition = Vec2(700, 700);
	BezierTo* action1 = BezierTo::create(3.0f, conf);*/
	/*sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	sprite->setScale(0.3f, 0.3f);
	sprite->setOpacity(0);*/
	/*FadeIn* action1 = FadeIn::create(5.0f);
	RotateTo* action2 = RotateTo::create(10.0f, Vec3(10800, 29000, 36000));
	EaseIn* action3 = EaseIn::create(action2, 5.0f);
	MoveTo* action4 = MoveTo::create(10.0f, Vec2(500, 500));
	EaseBounceIn* action5 = EaseBounceIn::create(action4);
	JumpTo* action6 = JumpTo::create(5.0f, Vec2(-500, -500), 500.0f, 2);*/

	/////////sprite2
	/*sprite2 = Sprite::create("neko.png");*/
	// �V�[���O���t�ɂȂ�
	/*this->addChild(sprite2);

	sprite2->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	sprite2->setScale(0.3f, 0.3f);
	sprite2->setOpacity(0);*/
	//sprite2->runAction(action1->clone());

	//�m�[�h�ɑ΂��ăA�N�V���������s����
	//{

	//	FadeIn* action1 = FadeIn::create(5.0f);
	//	RotateTo* action2 = RotateTo::create(10.0f, Vec3(10800, 29000, 36000));
	//	EaseIn* action3 = EaseIn::create(action2, 5.0f);
	//	MoveTo* action4 = MoveTo::create(10.0f, Vec2(1500, 1000));
	//	EaseBounceIn* action5 = EaseBounceIn::create(action4);
	//	JumpTo* action6 = JumpTo::create(5.0f, Vec2(-300, -300), 50.0f, 2);
	//	sprite->runAction(action1);
	//	sprite->runAction(action2);
	//	sprite->runAction(action3);
	//	sprite->runAction(action4);
	//	sprite->runAction(action5);
	//	sprite->runAction(action6);
	//}

	////Action2
	//{

	//	FadeIn* action1 = FadeIn::create(5.0f);
	//	RotateTo* action2 = RotateTo::create(10.0f, Vec3(10800, 29000, 36000));
	//	EaseIn* action3 = EaseIn::create(action2, 5.0f);
	//	MoveTo* action4 = MoveTo::create(10.0f, Vec2(500, 500));
	//	sprite2->runAction(action1);
	//	sprite2->runAction(action2);
	//	sprite2->runAction(action3);
	//	sprite2->runAction(action4);
	//}


	//�\�����W���w��
	//sprite->setPosition(Vec2(700.0f, 350.0f));
	//sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//sprite->setPosition(Vec2(visibleSize.width / 3.0f, visibleSize.height / 3.0f));
	//��]�p���w��(45�x)
	//sprite->setRotation(45.0f);
	//�g�k���w��(��3�{�A�c4�{)
	//sprite->setScale(3.0f, 4.0f);
	//sprite->setScale(0.3f, 0.3f);
	//sprite->setScale(10.0f, 10.0f);
	//���E���]
	//sprite->setFlippedX(true);
	//�㉺���]
	//sprite->setFlippedY(true);
	//��\���ɂ���
	//sprite->setVisible(false);
	//�F������ݒ�
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	//�s�����x��ݒ�
	//sprite->setOpacity(0x80);
	//sprite->setOpacity(255);
	//�摜�̍�����(0,0)
	//�摜�̉E�オ(0,0)�̍��W�n��
	//��_���w�肷��
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));

	//sprite->setRotation(405.0f);
	//sprite->setRotation3D();

	//                          R    G    B
	//sprite->setColor(Color3B(  0,   0, 255));

	//���E���]
	//sprite->setFlippedX(true);

	//�摜�J�b�g                   X   Y    W    H
	//sprite->setTextureRect(Rect(120, 20, 320, 320));
	//sprite->setTextureRect(Rect(0, 32, 32, 32));
    /*
	sprite2 = Sprite::create("sample02.png");
	this->addChild(sprite);
	sprite2->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	sprite2->setScale(10.0f, 10.0f);
	sprite2->setOpacity(255);
	sprite2->setAnchorPoint(Vec2(0.0f, 1.0f));
	sprite2->setTextureRect(Rect(0, 32, 32, 32));*/

	//update���Ăяo�����悤�ɂ���
	/*this->scheduleUpdate();

	counter = 0;

	state = 0;

	rot = 0;

	blue = 0;*/

	//opacity = 0;

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	/*opacity += 1.0f;
	sprite2->setOpacity(opacity);
	sprite->setOpacity(255 - opacity);
	if (opacity > 255.0f)
	{
		opacity = 255.0f;
	}*/
	
	/*Vec2 pos;
	rot += 10.0f;
	sprite->setRotation(rot);
	
	blue += 255.0f / 180.0f;
	if (blue > 255.0f)
	{
		blue = 255.0f;
	}
	sprite->setColor(Color3B(255 - blue, 0, blue));*/

	//switch (state)
	//{
	//case 0:
	//	// ���ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.x <= 100)
	//	{
	//		state = 1; // ���ړ��ɐ؂�ւ���
	//	}
	//	break;
	//case 1:
	//	// ���ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, -5.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.y <= 100)
	//	{
	//		state = 2; // �E�ړ��ɐ؂�ւ���
	//	}
	//	break;
	//case 2:
	//	// �E�ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.x >= 1080)
	//	{
	//		state = 3; // �E�ړ��ɐ؂�ւ���
	//	}
	//	break;
	//default:
	//	// ��ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, 5.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.y >= 520)
	//	{
	//		state = 0; // �E�ړ��ɐ؂�ւ���
	//	}
	//	break;
	//switch (state)
	//{
	//case 0:
	//	// ���ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.x <= 100)
	//	{
	//		state = 1; // ���ړ��ɐ؂�ւ���
	//	}
	//	sprite->setFlippedX(false);
	//	break;
	//default:
	//	// ���ړ�
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// ���[�ɒB������
	//	if (pos.x >= 1180)
	//	{
	//		state = 0; // �E�ړ��ɐ؂�ւ���
	//	}
	//	sprite->setFlippedX(true);
	//	break;
	//}
	// �X�v���C�g�̌��ݍ��W���擾
	//Vec2 pos = sprite->getPosition();
	// ���W���ړ�������
	//pos += Vec2(1.0f, 1.0f);
	//pos.x -= 4.0f;
	//pos += Vec2(-5.0f, 0.0f);
	// �ړ���̍��W�𔽉f
	//sprite->setPosition(pos);

	//���񂾂񓧖��ɂ��鏈��
	//5�b = 300frm
	/*counter++;
	float opacity = 255 - counter / 300.0f * 255.0f;
	sprite->setOpacity(opacity);*/
}