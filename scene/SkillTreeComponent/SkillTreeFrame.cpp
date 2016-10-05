/* ==================================================
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/10/02 by PorcaM
================================================== */

#include "scene/SkillTreeComponent/SkillTreeFrame.h"

#include "scene/OHDialog.h"

void SkillTreeFrame::set_skillinfo(SkillInfo *skillinfo){
	if (skillinfo == NULL) {
		assert(false);
	}
	skillinfo_ = skillinfo;
	return;
}
void SkillTreeFrame::set_playerinfo(PlayerInfo *playerinfo){
	if (playerinfo == NULL) {
		assert(false);
	}
	playerinfo_ = playerinfo;
	return;
}
void SkillTreeFrame::set_playerinfoframe(PlayerInfoFrame *playerinfoframe) {
	if (playerinfoframe == NULL) {
		assert(false);
	}
	playerinfoframe_ = playerinfoframe;
	return;
}
/* ==================================================
	Public
================================================== */
SkillTreeFrame::SkillTreeFrame(SkillInfo *skillinfo, PlayerInfo *playerinfo, PlayerInfoFrame *playerinfoframe){
	set_skillinfo(skillinfo);
	set_playerinfo(playerinfo);
	set_playerinfoframe(playerinfoframe);
	InitScrollview();
	InitIconList();
	DrawFrame(skillinfo->get_skilltree_by_type(Skill::Type::kHeal));
}
SkillTreeFrame::~SkillTreeFrame(){
	delete scrollview_;
	ClearFrame();
	return;
}
void SkillTreeFrame::UpdateByType(Skill::Type type){
	ClearFrame();
	DrawFrame(skillinfo_->get_skilltree_by_type(type));
}
/* ==================================================
	Private
================================================== */
void SkillTreeFrame::InitScrollview(){
	int scrollview_height = 330;
	int scrollview_inner_width = 7*100;
	scrollview_ = ui::ScrollView::create();
	scrollview_->setContentSize(Size(280, scrollview_height));
	scrollview_->setInnerContainerSize(Size(
											scrollview_inner_width, 
											scrollview_height));
	scrollview_->setBackGroundImageScale9Enabled(true);
	scrollview_->setBackGroundImage("images/skilltree/rect.png");
	scrollview_->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollview_->setBounceEnabled(true);
	scrollview_->setTouchEnabled(true);
	scrollview_->setSwallowTouches(false);
	scrollview_->setName("skilltreeframe_scrollView");
	scrollview_->setAnchorPoint (Vec2 (0.5f, 0.98f));
	this->addChild(scrollview_);
	return;
}
void SkillTreeFrame::InitIconList(){
	icon_list_.clear();
	return;
}
void SkillTreeFrame::DrawFrame(SkillTree *skilltree){
	for (auto it = skilltree->getBegin(); it != skilltree->getEnd(); ++it) {
		InsertIcon(it->second, skilltree->findSkill(it->second->getPrev()));
	}
	return;
}
void SkillTreeFrame::ClearFrame(){
	scrollview_->removeAllChildren();
	for (auto it = icon_list_.begin(); it != icon_list_.end(); ++it) {
		delete *it;
	}
	icon_list_.clear();
	return;
}
void SkillTreeFrame::InsertIcon(SkillNode *node, SkillNode *prev){
	auto skill = skillinfo_->RetrieveSkillByID(node->getID());
	if (skill == NULL) return;
	auto icon = new SkillIcon(skill);
	if (node->getLearn() == false) {
		string path = "images/skilltree/icon_d.png";
		icon->get_button()->loadTextures(path, path, path);
	}
	int col = node->get_col();
	int row = node->get_row();
	icon->setPosition(Vec2(50 + col * 100, 330 - 50 - row * 100));
	auto playerinfo = playerinfo_;
	auto playerinfoframe = playerinfoframe_;
	icon->get_button()->addTouchEventListener([=](
			Ref *pSender,
			ui::Button::Widget::TouchEventType type
			) {
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			printf("id?: %d\n", node->getID());
			if (node->getLearn() == false) {
				string title = "LEARN_SKILL";
				string prompt = "Do you want to learn this skill?\n";
				string info = "SkillName: " + icon->get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](
						Ref *pSender, 
						ui::Button::Widget::TouchEventType type) {
					if (type == ui::Button::Widget::TouchEventType::ENDED) {
						bool learn = prev->getLearn();
						auto point = playerinfo->get_point();
						auto need = 5;
						if (learn == false) {
							printf("Learn prev skill first!\n");
						} else if (point < need) {
							printf("No point\n");
						} else {
							node->setLearn(true);
							playerinfo->AddPoint(-need);
							playerinfo->get_slot()->InsertSkill(icon->get_skill());
							playerinfoframe->UpdateWithPlayerInfo(playerinfo);
							string path = "images/skilltree/icon_a.png";
							icon->get_button()->loadTextures(path, path, path);
							printf("Success learn!\n");
						}
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
			} else {
				string title = "EQUIP_SKILL";
				string prompt = "Do you want to equip this skill?\n";
				string info = "SkillName: " + icon->get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](
						Ref *pSender, 
						ui::Button::Widget::TouchEventType type) {
					if (type == ui::Button::Widget::TouchEventType::ENDED) {
						if (true) {
							auto slot = playerinfo->get_slot();
							auto skill = icon->get_skill();
							slot->InsertSkill(skill);
							playerinfoframe_->UpdateWithPlayerInfo(playerinfo);
							printf("Success equip");
						} else {
							printf("Fail to equip\n");
						}
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
			}
		}
	});
	scrollview_->addChild(icon);
	return;
}