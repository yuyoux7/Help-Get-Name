#pragma once
#include <iostream>
#include <vector>

typedef enum
{

}ErrorList;

typedef struct _err{
	bool lock{};
	char* err_str{};
	ErrorList err_type{};
}_Error;

class Error : public _Error {
public:
	Error() {};
	Error(ErrorList errl, char* errs) { data.err_type = errl; data.err_str = errs; };
	Error(_Error err) : data(err) {};
	bool ErrorProcess(ErrorList);
	bool ErrorProcess(_Error);
	void ProccessFunc(ErrorList err, [] auto fn(...))
	{
		fn(...);
	};
	virtual ~Error() = delete;
	Error operator>>(const Error& other)
	{
		return this = other;
	};
	Error operator>>(char& other)
	{
		return this->err_str = other;
	};
	Error operator>>(std::string& other)
	{
		return this->err_str = other;
	};
	friend std::ostream& operator<<(std::ostream& io, const Error& err)
	{
		return io << err.err_str;
	};
	bool operator==(const Error& other) const
	{
		return data.err_type == other.data.err_type;
	}
private:
	_Error data{};
	std::vector<ErrorList, [] auto>{};
};