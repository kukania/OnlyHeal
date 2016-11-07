#ifndef __HELLOWORLD_FILE_OPERATION__
#define __HELLOWORLD_FILE_OPERATION__

#include <string>
#include <vector>
#include "./parts/Tier.h"
#include "./parts/consumableItem.h"
#include "./parts/MyRGB.h"
#include "./parts/Item.h"
#include "./parts/Status.h"

/*
**ORDER**
1. TIER
2. MyRGB
3. Item
4. Status
5. consumableItem
6. itemInventory
7. cInventory
8. player
*/
class FileOperation 
{
public:
	enum FTYPE {
		TIER,MYRGB,ITEM,STATUS,CONSUMABLEITEM,INVENTORY,CINVENTORY,PLAYER,END
	};
	FileOperation() {
		string pathW = getFilePath()+"_W.txt";
		string pathR = getFilePath() + "_R.txt";
		CCLOG("filepath:%s", getFilePath().c_str());
		this->fpW = fopen(pathW.c_str(), "w");
		this->fpR = fopen(pathR.c_str(), "r");
	}
	~FileOperation() {
		if (fpW != NULL)fclose(fpW);
		if (fpR != NULL)fclose(fpR);
	}
	FILE* fpW;
	FILE* fpR;
	static void saveFile(string buf);
	void readFile();
	std::vector<std::string>readRes;
	std::string readOneByOne();
	static std::string getFilePath();
};

#endif
