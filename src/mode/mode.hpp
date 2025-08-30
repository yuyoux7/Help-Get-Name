#pragma once
#include <fstream>
#ifndef Mode_Config_File
#define Mode_Config_File "config.hgn"
#endif  

typedef enum {
	Down = 0x0001,
	Rotate = 0x0010,
	RLPick = 0x0100
}ModList;

typedef struct {
	const char* Name
}ConfigSetList;

class Mode {
	Mode() = delete;
	bool Call_Mode(ModList mode);
	ModList Get_Now_Mode();
	void Mode_Setting();
	virtual ~Mode() = delete;
private:
	ModList GameMode{};
	const char* GameModeStringGet();
};
class filestream : public std::ifstream {
	void getset(ConfigSetList type);
};