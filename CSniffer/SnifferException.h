#ifndef SNIFFEREXCEPTION_H
#define SNIFFEREXCEPTION_H
#include <QException>
#include <QString>

class SnifferException : public QException
{
public:
    void raise() const override { throw *this; }
    SnifferException();
    SnifferException(QString message);
    SnifferException(QString message, int code);
    SnifferException *clone() const override { return new SnifferException(*this); }
    QString Message;
    int Code;
};

#endif // SNIFFEREXCEPTION_H
