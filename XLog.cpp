#include "XLog.h"

XLog _log;

XLog::XLog() {

	QString debugging_dir = "Log/Debugging.txt";
	QString log_dir = "Log/Log.txt";

	// TODO: check if Log folder is not existed
	if(QDir("Log").exists() == false)
		QDir().mkdir("Log");

	// TODO: file debugging managemenet

	{
		QFile m_file2(debugging_dir);
		if(m_file2.exists(debugging_dir) == false)
		{
			// TODO: if we can open file
			if(m_file2.open(QFile::ReadWrite)) {
				m_file2.write(QString::number(false).toUtf8());
				m_file2.close();
			}
		}
		else {
			if(m_file2.open(QFile::ReadOnly))
				setDebuggingMode(QString(m_file2.readLine()).toInt());
			m_file2.close();
		}
	}

	// TODO: check if is log.txt is exist, we should to clear all content in file
	if(QFile::exists(log_dir) == true)
		QFile::resize(log_dir, 0);

	m_file.setFileName(log_dir);
}

XLog::~XLog() {
	if(m_file.isOpen())
		m_file.close();
}

void XLog::setDebuggingMode(bool isActive) {
	m_debugging = isActive;
}

void XLog::addText(QString macro_file,
				   QString macro_function,
				   int macro_line,
				   QString message)
{
	// TODO: if debugging is disbale break
	if(m_debugging == false)
		return;

	if(!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		qDebug() << "cant open file";

	QString data;

	if(!message.isEmpty())
			data = QString("[ %1 ]  [ %2 ]  [ %3 ] - %4 \n").arg(
							 macro_file).arg(
							 macro_function).arg(
							 macro_line).arg(
							 message
							 );
		else
			data = QString("[ %1 ]  [ %2 ]  [ %3 ]\n").arg(
							 macro_file).arg(
							 macro_function).arg(
							 macro_line);

	m_file.write(data.toUtf8());
	m_file.close();

	qDebug() << QString("[ LOG_TRACE ] - %1").arg(data);
}
