#pragma once

#ifdef SFR_TYPE
#endif

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <ShlObj.h>
#endif

#ifdef _DEBUG
#define SFR_DEBUG
#define SHOW_CONSOLE
#endif

#define SINGLETON(CLASS) \
private: \
	CLASS(){}; \
	CLASS& operator = (const CLASS& t) = delete; \
	CLASS(const CLASS &) = delete; \
	static CLASS m_pInstance;\
public: \
	static CLASS* GetInstance() \
	{ \
		return &m_pInstance;\
	};

#define SET_SINGLETON(CLASS) \
CLASS CLASS::m_pInstance;\

#define BAN_COPY(CLASS)\
	CLASS& operator = (const CLASS& t) = delete; \
	CLASS(const CLASS &) = delete; \

extern const char* SFR_LOG_FILE;
extern const char* SFR_ERR_FILE;