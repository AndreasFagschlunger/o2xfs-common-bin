#include "o2xfs-logger.h"

#include <windows.h>

#include <ctime>
#include <stdarg.h>
#include <stdio.h>

namespace o2xfs {

	void Logger::doLog(Level level, _TCHAR* message, va_list argptr) {
		time_t rawtime;
		time(&rawtime);
		std::tm* now = std::localtime(&rawtime);
		if (file != NULL) {
			_ftprintf(file, _T("%04d-%02d-%02d %02d:%02d:%02d "), 1900 + now->tm_year, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
			switch (level) {
			case Level::LOG_DEBUG:
				_fputts(_T("DEBUG "), file);
				break;
			case Level::LOG_ERROR:
				_fputts(_T("ERROR "), file);
				break;
			case Level::LOG_FATAL:
				_fputts(_T("FATAL "), file);
				break;
			case Level::LOG_INFO:
				_fputts(_T("INFO  "), file);
				break;
			case Level::LOG_WARN:
				_fputts(_T("WARN  "), file);
				break;
			}
			_ftprintf(file, _T("[0x%x] "), GetCurrentThreadId());
			_vftprintf(file, message, argptr);
			_fputts(_T("\n"), file);
		}
		fflush(file);
	}

	Logger::~Logger() {
		if (file != NULL) {
			log(Level::LOG_INFO, _T("Logger::~Logger()"));
			fclose(file);
		}
	}

	void Logger::setFileName(_TCHAR* fileName) {
		if (file == NULL) {
			file = _tfopen(fileName, _T("a"));
		}
	}

	void Logger::log(Level level, _TCHAR* message, ...) {
		time_t rawtime;
		time(&rawtime);
		std::tm* now = std::localtime(&rawtime);
		va_list argptr;
		va_start(argptr, message);
		doLog(level, message, argptr);
		va_end(argptr);
		fflush(file);
	}

	void Logger::debug(_TCHAR* message, ...) {
		va_list argptr;
		va_start(argptr, message);
		doLog(Level::LOG_DEBUG, message, argptr);
		va_end(argptr);
	}

	void Logger::error(_TCHAR* message, ...) {
		va_list argptr;
		va_start(argptr, message);
		doLog(Level::LOG_DEBUG, message, argptr);
		va_end(argptr);
	}

	void Logger::info(_TCHAR* message, ...) {
		va_list argptr;
		va_start(argptr, message);
		doLog(Level::LOG_DEBUG, message, argptr);
		va_end(argptr);
	}

	void Logger::warn(_TCHAR* message, ...) {
		va_list argptr;
		va_start(argptr, message);
		doLog(Level::LOG_DEBUG, message, argptr);
		va_end(argptr);
	}

}