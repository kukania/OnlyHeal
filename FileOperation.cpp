// to enable CCLOG()
#define COCOS2D_DEBUG 1
#define _CRT_SECURE_NO_WARNINGS
#include "cocos2d.h"
#include "FileOperation.h"
#include <stdio.h>

using namespace std;

void FileOperation::saveFile(string buf)
{
	string path = getFilePath();
	FILE* fp = fopen(path.c_str(), "a+");

	if (! fp)
	{
		CCLOG("can not create file %s", path.c_str());
		return;
	}
	fputs(buf.c_str(), fp);
	fclose(fp);
}
void FileOperation::readFile()
{
	string path = getFilePath();
	FILE* fp = fopen(path.c_str(), "r");
	char buf[256] = {0};

	if (! fp)
	{
		CCLOG("can not open file %s", path.c_str());
		return;
	}
	while (!feof(fp)) {
		fgets(buf, 255, fp);
		readRes.push_back(buf);
	}
	fclose(fp);
}
string FileOperation::getFilePath()
{
	string path("");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// In android, every programe has a director under /data/data.
	// The path is /data/data/ + start activity package name.
	// You can save application specific data here.
	path.append("/data/data/org.cocos2dx.application/onlyHeal");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	// You can save file in anywhere if you have the permision.
	path.append("D:/onlyHeal");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
	path = cocos2d::CCApplication::sharedApplication().getAppDataPath();

#ifdef _TRANZDA_VM_
	// If runs on WoPhone simulator, you should insert "D:/Work7" at the
	// begin. We will fix the bug in no far future.
	path = "D:/Work7" + path;
	path.append("onlyHeal");
#endif

#endif
	return path;
}
std::string FileOperation::readOneByOne() {
	static int num = 0;
	return readRes[num++];
}