#include "mode.hpp"

bool Mode::Call_Mode(ModList mode)
{
	if (this->GameMode != mode)
	{
		this->GameMode = mode;
		return true;
	}
	return false;
}

ModList Mode::Get_Now_Mode()
{
	return this->GameMode;
}

void Mode::Mode_Setting()
{
	filestream config{};
	config.open((GameModeStringGet() + Mode_Config_File));
	if (config.is_open())
	{
		config.getset(ConfigSetList::Name);
	}
	config.close();
}

const char* Mode::GameModeStringGet()
{
	switch (GameMode)
	{
	case ModList::Down:
		return "downmod";
	case ModList::Rotate:
		return "rotatemod";
	default:
		break;
	}
	return nullptr;
}

void filestream::getset(ConfigSetList type)
{
	hgnReader(type, );
}
