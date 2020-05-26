#pragma once
#include <iostream>
#include <vector>

namespace SFR
{
	extern std::string Format(const char *pszFmt, ...);
	extern void Log(const std::string& str);
	extern void Warn(const std::string& str);
	extern void Err(const std::string& str);
}

#ifdef SFR_DEBUG
#define sError(info, ...)                                                                  \
	do                                                                                     \
	{                                                                                      \
		SFR::Err(SFR::Format("Date:\t%s %s\nFile:\t%s\nFunc:\t%s\nLine:\t%d\n\t{0}\n",   \
							   __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__)       \
						+ SFR::Format(info, ##__VA_ARGS__));                               \
	} while (0)

#define sAssert(exp, info, ...)                                                                            \
	do                                                                                                     \
	{                                                                                                      \
		if (!(exp))                                                                                        \
		{                                                                                                  \
			SFR::Err(SFR::Format("Date:\t%s %s\nFile:\t%s\nFunc:\t%s\nLine:\t%d\n\t" #exp "\n\t{0}\n",   \
								   __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__)                   \
							+ SFR::Format(info, ##__VA_ARGS__));                                       \
			exit();                                                                                        \
		}                                                                                                  \
	} while (0)

#define sAssertProc(exp, proc, info, ...)                                                                  \
	do                                                                                                     \
	{                                                                                                      \
		if (!(exp))                                                                                        \
		{                                                                                                  \
			SFR::Err(SFR::Format("Date:\t%s %s\nFile:\t%s\nFunc:\t%s\nLine:\t%d\n\t" #exp "\n\t{0}\n",   \
								   __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__)                   \
							+ SFR::Format(info, ##__VA_ARGS__));                                       \
			proc();                                                                                        \
			exit();                                                                                        \
		}                                                                                                  \
	} while (0)

#define sWarning(info, ...)                                                                                                        \
	do                                                                                                                             \
	{                                                                                                                              \
		SFR::Warn(SFR::Format("%s: Func:%s Line:%d ", __TIME__, __FUNCTION__, __LINE__) + SFR::Format(info, ##__VA_ARGS__)); \
	} while (0)

#define sLog(info, ...)                                                                    \
	do                                                                                     \
	{                                                                                      \
		SFR::Log(SFR::Format("%s: {0}", __TIME__)+ SFR::Format(info, ##__VA_ARGS__));	   \
	} while (0)

#else

// 非debug模式 错误和警告先和之前一样输出  普通log不处理
#define sError(info, ...)                                                                         \
	do                                                                                            \
	{                                                                                             \
		SFR::Err(std::string("\nDate:\t%s %s\nFile:\t%s\nFunc:\t%s\nLine:\t%d\n\t{0}\n",        \
							   __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__) \
						.arg(pd::String(info, ##__VA_ARGS__)));                                   \
	} while (0)

#define sAssert(exp, info, ...)                                                      \
	do                                                                               \
	{                                                                                \
		if (!(exp))                                                                  \
			sError(SFR::String(#exp "\n\t{0}").arg(pd::String(info, ##__VA_ARGS__))); \
		exit(-1);                                                                    \
	} while (0)

#define sAssertProc(exp, proc, info, ...)                                            \
	do                                                                               \
	{                                                                                \
		if (!(exp))                                                                  \
			sError(SFR::String(#exp "\n\t{0}").arg(pd::String(info, ##__VA_ARGS__))); \
		proc();                                                                      \
		exit(-1);                                                                    \
	} while (0)

#define sWarning(info, ...)                                                                                                        \
	do                                                                                                                             \
	{                                                                                                                              \
		SFR::Log(pd::String("%s: [warning %s:%d] {0}", __TIME__, __FUNCTION__, __LINE__).arg(pd::String(info, ##__VA_ARGS__))); \
	} while (0)

#define sLog(info, ...) \
	do                  \
	{                   \
	} while (0)

#endif

#define RESET_CMD_COLOR CMD_COLOR_WHITE
#define CMD_COLOR_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define CMD_COLOR_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
#define CMD_COLOR_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define CMD_COLOR_YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

#define ERROR_HEAD CMD_COLOR_RED\
				   printf("Error:");\
				   RESET_CMD_COLOR

#define WARN_HEAD CMD_COLOR_YELLOW\
				   printf("Warning:");\
				   RESET_CMD_COLOR


#define WARN_NO_INIT sWarning("没有初始化Canvas");
#define WARN_NO_NEG sWarning("不可以有负数");