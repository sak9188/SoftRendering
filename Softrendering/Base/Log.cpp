#include "SFRSetting.h"
#include "Log.h"
#include <fstream>

extern const char* SFR_LOG_FILE;
extern const char* SFR_ERR_FILE;

void OutToConsole(const char* str)
{
	puts(str);
}

void OutToFile(const char* str, bool err)
{
	std::ofstream file;
	if (err)
		file.open(SFR_ERR_FILE, std::ios_base::app);
	else
		file.open(SFR_LOG_FILE, std::ios_base::app);
	if (file.is_open())
	{
		file << str << "\n";
		file.close();
	}
}

void OutToErrBox(const char* str)
{
	MessageBoxA(nullptr, str, "Error", MB_ICONERROR | MB_OK);
}

void SFR::Log(const std::string& str)
{
	OutToConsole(str.data());
	OutToFile(str.data(), false);
}

void SFR::Warn(const std::string & str)
{
	WARN_HEAD
	SFR::Log(str);
}

void SFR::Err(const std::string& str)
{
#ifdef SFR_DEBUG
	ERROR_HEAD
	OutToConsole(str.data());
	OutToFile(str.data(), true);
#else
	OutToErrBox(str.data());
	OutToFile(str.data(), true);
#endif
}

std::string SFR::Format(const char *pszFmt, ...)
{
	std::string str;
	va_list args;
	va_start(args, pszFmt);
	{
		int nLength = _vscprintf(pszFmt, args);
		nLength += 1;  //上面返回的长度是包含\0，这里加上
		std::vector<char> vectorChars(nLength);
		_vsnprintf(vectorChars.data(), nLength, pszFmt, args);
		str.assign(vectorChars.data());
	}
	va_end(args);
	return str;
}