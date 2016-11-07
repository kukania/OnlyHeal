#include"consumableInventory.h"
#include"../FileOperation.h"
void ConsumableInventory::pushConsumable(Consumable* input) {
	input->it=this->consumableList.insert(consumableList.end(),input);
}
void ConsumableInventory::useConsumable(Consumable* input) {
	input->consume();
	deleteConsumable(input);
}
void ConsumableInventory::deleteConsumable(Consumable* input) {
	this->checkChange = true;
	this->consumableList.erase(input->it);
}
void ConsumableInventory::saveFile() {
	string path = FileOperation::getFilePath() + ".cinven";
	FILE *fp = fopen(path.c_str(), "a+");
	if (!fp) {
		CCLOG("Can not create file %s", path.c_str());
		return;
	}
	/*FTYPE CHECKCHANGE SIZE LIST*/
	char buf[256];
	sprintf(buf, "%d %d %d\n",FileOperation::FTYPE::CINVENTORY,checkChange?1:0, this->consumableList.size());
	fputs(buf, fp);

	list<Consumable*>::iterator it = this->consumableList.begin();
	for (it; it != this->consumableList.end(); it++) {
		fputs((*it)->getFileString().c_str(), fp);
	}
	fclose(fp);
}
void ConsumableInventory::readFile(Character *owner) {
	string path = FileOperation::getFilePath() + ".cinven";
	FILE *fp = fopen(path.c_str(), "r");
	if (!fp) {
		CCLOG("Can not create file %s", path.c_str());
		return;
	}
	char buf[256];
	fgets(buf, 255, fp);
	int ftype, cChange, size;
	sscanf(buf, "%d %d %d", &ftype, &cChange, &size);

	for (int i = 0; i < size; i++) {
		fgets(buf, 255, fp);
		this->consumableList.push_back(Consumable::consumableByString(owner,buf));
	}
	fclose(fp);
}