#pragma once

typedef struct _basic_sroce_ {
	double sc{};			//sc max 1000000 
	//note sc = (1000000 / ttl) * rate
	//sc = (1000000 - (1000000 / ttl * (((pf * (101.0 - 100.9)) + (gr * (101.0 - 80.0)) + (gd * (101.0 - 50.0)) + (bd * (101.0 - 10.0)) + (miss * 101.0) / 101.0)))
	//sc = (1000000 / ttl) * ((max + (pf * 100.9 + gr * 80.0 + gd * 50.0 + bd * 10.0) / 101.0) / 100)
	double acc{};			//acc = (((((max * 101.0) + (pf * 100.9) + (gr * 80.0) + (gd * 50.0) + (bd * 10.0)) / 101.0) / ttl) * 101.0)
	unsigned short max{};	//101%
	unsigned short pf{};	//100.9%
	unsigned short gr{};	//80%
	unsigned short gd{};	//50%
	unsigned short bd{};	//10%
	unsigned short miss{};	//0%
	unsigned int ttl{};
}sroce;

typedef enum : short {
	SSS	= 101,
	SS	= 99,
	S	= 93,
	AAA	= 90,
	AA	= 85,
	A	= 80,
	B	= 75,
	C	= 60,
	D	= 50,
	F	= 0
}rankACCList;

typedef enum : int
{
	SSS		= 10,
	SS		= 9,
	S		= 8,
	AAA		= 7,
	AA		= 6,
	A		= 5,
	B		= 4,
	C		= 3,
	D		= 2,
	F		= 1
}rkList;

class rank {
public:
	rank() {};
	rank(rkList func) : rk(func) {};
	rank(sroce& sc);
	rank operator=(rank& other)
	{
		this->rk = other.rk;
		this->bsc = other.bsc;
	};
	virtual ~rank() {};
private:
	int rk{};
	sroce bsc{};
};

rank callrankback(sroce sc);