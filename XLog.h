#ifndef XLOG_H
#define XLOG_H

#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>

#include "XStringManagement.h"

class XLog
{
public:
	XLog();
	~XLog();

	void setDebuggingMode(bool isActive);

	void addText(QString macro_file, QString macro_function, int macro_line, QString message = "");
private:
	QFile m_file;
	bool m_debugging;
};

extern XLog _log;

#define LOG_TRACE(x) _log.addText(__FILE__, __FUNCTION__, __LINE__, x)


#endif // XLOG_H
