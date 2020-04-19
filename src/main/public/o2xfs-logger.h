#ifndef O2XFS_LOGGER_H
#define O2XFS_LOGGER_H

#ifdef _WIN32
#define O2XFS_LOGGER_EXPORT_FUNC __declspec(dllexport)
#else
#define O2XFS_LOGGER_EXPORT_FUNC
#endif

#include <tchar.h>
#include <stdio.h>

namespace o2xfs {
    
    enum class Level { LOG_DEBUG, LOG_ERROR, LOG_FATAL, LOG_INFO, LOG_WARN };
    
    class Logger {

    private:
        void doLog(Level level, _TCHAR* message, va_list argptr);
    
    public:
    
    	~Logger();
    
    	void debug(_TCHAR* message, ...);
    	void error(_TCHAR* message, ...);
    	void info(_TCHAR* message, ...);
    	void warn(_TCHAR* message, ...);
    	void setFileName(_TCHAR* fileName);
    	void log(Level level, _TCHAR* message, ...);
    
    private:
    
    	FILE* file = NULL;
    };
}

#endif
