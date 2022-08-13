#ifndef XSTRINGMANAGEMENT_H
#define XSTRINGMANAGEMENT_H

#include <QString>

using namespace std;

#include <iostream>
#include <string>

class XStringManagement
{
public:
	XStringManagement();

	static QString toString(std::string text);
	static std::string toString(QString text);

	static QString b64_encode(QString message);
	static QString b64_decode(QString message);
};

#endif // XSTRINGMANAGEMENT_H
