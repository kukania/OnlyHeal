#pragma once
#include"Inventory.h"
#include"../FileOperation.h"
#include<algorithm>


void Inventory::pushItemList(Item a) {
	this->itemList.push_back(a);
}
void Inventory::deleteItemList(int index) {
	vector<Item>::iterator it = this->itemList.begin();
	for (int i = 0; i < index; i++) { it++; }
	this->itemList.erase(it,it);
}
void Inventory::equipedItemChange(int index) {
	equiped = &itemList[index];
}
void Inventory::sortItemList() {
	std::sort(itemList.begin(), itemList.end(), sortFunction);
}
bool Inventory::sortFunction(Item a, Item b) {
	return a.getTier().getLevel() > b.getTier().getLevel();
}
void Inventory::saveFile() {
	/*FTYPE TYPE SIZE LIST EQUIPEDNUM*/
	string path = FileOperation::getFilePath() + ".inven";
	FILE *fp = fopen(path.c_str(), "a+");
	char buf[256];
	sprintf(buf, "%d %d %d\n", FileOperation::FTYPE::INVENTORY, this->type, this->itemList.size());
	if (!fp)
	{
		CCLOG("can not create file %s", path.c_str());
		return;
	}
	fputs(buf, fp);
	for (int i = 0; i < this->itemList.size(); i++) {
		fputs(itemList[i].getFileString().c_str(),fp);
	}
	sprintf(buf, "%d\n", this->equipedNum);
	fputs(buf, fp);
	fclose(fp);
}
void Inventory::readFile() {
	string path = FileOperation::getFilePath() + ".inven";
	FILE *fp = fopen(path.c_str(), "r");
	char buf[256];
	int ftype, type, size;

	fgets(buf, 255, fp);
	sscanf(buf, "%d %d %d", &ftype, &type, &size);
	for (int i = 0; i < size; i++) {
		string tempS[3];
		for (int j = 0; j < 3; j++) {
			fgets(buf, 255, fp);
			tempS[j] = buf;
		}
		this->pushItemList(Item::itemByString(tempS));
	}
	
	fgets(buf, 255, fp);
	sscanf(buf, "%d", &equipedNum);
	equiped = &(this->itemList[equipedNum]);
	fclose(fp);
}