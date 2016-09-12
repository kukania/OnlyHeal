#include"PartyContent.h"

PartyContent::PartyContent(Tier t,Character *p) {
	content = ui::Button::create("images/party/partyFrame.png", "images/party/partyFrame.png", "images/party/partyFrame.png");
	content->setScale9Enabled(true);
	content->setContentSize(Size(470, 200));
	Size tempS = content->getSize();

	list[0] = Character::create(t, "Monster", 0);
	list[1] = p;
	list[2] = Character::create(t, "TankNPC", 0);
	list[3] = Character::create(t, "MeleeNPC", 0);
	list[4] = Character::create(t, "MeleeNPC", 0);
	list[5] = Character::create(t, "RangeNPC", 0);

	img[monster] = ui::Scale9Sprite::create("images/party/dragon.png");
	img[monster]->setPosition(tempS.width*0.23,tempS.height/2);
	img[2] = ui::Scale9Sprite::create("images/party/tanker.png");
	img[2]->setPosition(tempS.width*0.75, tempS.height*0.75);
	img[3] = ui::Scale9Sprite::create("images/party/melee.png");
	img[3]->setPosition(tempS.width*0.75, tempS.height*0.25);
	img[4] = ui::Scale9Sprite::create("images/party/melee.png");
	img[4]->setPosition(tempS.width*0.625, tempS.height*0.5);
	img[5] = ui::Scale9Sprite::create("images/party/range.png");
	img[5]->setPosition(tempS.width*0.875, tempS.height*0.5);

	content->addChild(img[0]);
	for (int i = 2; i < 6; i++) content->addChild(img[i]);
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