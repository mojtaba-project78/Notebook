#include "XStringManagement.h"

XStringManagement::XStringManagement()
{

}

QString XStringManagement::toString(std::string text) {
	return QString::fromStdString(text);
}

std::string XStringManagement::toString(QString text) {
	return text.toStdString();
}

QString XStringManagement::b64_encode(QString message) {
	return message.toUtf8().toBase64();
}

QString XStringManagement::b64_decode(QString message) {
	return QByteArray::fromBase64(message.toUtf8());
}
