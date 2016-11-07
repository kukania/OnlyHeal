#include"PartyContent.h"
#include"../OHLabel.h"
#include"../../ConvertKorean.h"
PartyContent::PartyContent(Tier t,Character *p) {
	list[0] = Character::create(t, "Monster", 0);
	list[1] = p;
	list[2] = Character::create(t, "TankNPC", 0);
	list[3] = Character::create(t, "MeleeNPC", 0);
	list[4] = Character::create(t, "MeleeNPC", 0);
	list[5] = Character::create(t, "RangeNPC", 0);

	selected = false;
	content = ui::Button::create("images/party/bigwhite.png", "images/party/bigwhite.png", "images/party/bigwhite.png");
	content->setScale9Enabled(true);
	content->setColor(Color3B(255 - list[0]->getStatus()->getMyRGBDamage().getR(), 255 - list[0]->getStatus()->getMyRGBDamage().getG(), 255 - list[0]->getStatus()->getMyRGBDamage().getB()));
	content->setContentSize(Size(470, 200));
	Size tempS = content->getSize();

	//"images/party/partyFrame.png", "images/party/partyFrame.png", "images/party/partyFrame.png"
	/*auto backGround = Sprite::create("images/party/bigwhite.png");
	backGround->setScale(1.6f);
	backGround->setAnchorPoint(Point(0, 0));
	backGround->setPosition(Point(5, 5));
	backGround->setColor(Color3B(255-list[0]->getStatus()->getMyRGBDamage().getR(), 255 - list[0]->getStatus()->getMyRGBDamage().getG(), 255 - list[0]->getStatus()->getMyRGBDamage().getB()));
	content->addChild(backGround);*/


	img[monster] = Sprite::create("images/party/dragon.png");
	img[monster]->setPosition(tempS.width*0.23,tempS.height/2);
	OHLabel *tempLabel;
	
	img[2] = Sprite::create("images/party/character.png");
	tempLabel = new OHLabel(img[2]->getContentSize(), "ÅÊÄ¿", 35);
	tempLabel->moveBy(Point(-3, -20));
	tempLabel->addedTo(img[2]);
	img[2]->setPosition(tempS.width*0.75, tempS.height*0.75);
	
	img[3] = Sprite::create("images/party/character.png");
	tempLabel = new OHLabel(img[3]->getContentSize(), "¿øµô", 35);
	tempLabel->moveBy(Point(-3, -20));
	tempLabel->addedTo(img[3]);
	img[3]->setPosition(tempS.width*0.75, tempS.height*0.25);
	
	img[4] = Sprite::create("images/party/character.png");
	tempLabel = new OHLabel(img[4]->getContentSize(), "¿øµô", 35);
	tempLabel->moveBy(Point(-3, -20));
	tempLabel->addedTo(img[4]);
	img[4]->setPosition(tempS.width*0.625, tempS.height*0.5);

	img[5] = Sprite::create("images/party/character.png");
	tempLabel = new OHLabel(img[5]->getContentSize(), "±Ùµô", 35);
	tempLabel->moveBy(Point(-3, -20));
	tempLabel->addedTo(img[5]);
	img[5]->setPosition(tempS.width*0.875, tempS.height*0.5);

	for (int i = 0; i < 6; i++) {
		if (i == 1)continue;
		img[i]->setColor(Color3B(list[i]->getStatus()->getMyRGBDamage().getR(), list[i]->getStatus()->getMyRGBDamage().getG(), list[i]->getStatus()->getMyRGBDamage().getB()));
		content->addChild(img[i]);
	}

	content->setOpacity(150);
}

std::string PartyContent::getStringContent() {
	string res = "";
	for (int i = 0; i < 6; i++) {
		if (i == 1)continue;
		switch(list[i]->getType()) {
		case monster:
			res += "¸ó½ºÅÍ: ";
			break;
		case tanker:
			res += "ÅÊÄ¿: ";
			break;
		case melee:
			res += "±Ùµô: ";
			break;
		case range:
			res += "¿øµô: ";
			break;
		}
		short level=list[i]->getStatus()->evalTier().getLevel()+1;
		if (level / 10) res += '0' + level / 10;
		res += '0' + (level % 10);
		res += "\n";
	}
	return res;
}