#include "SnifferException.h"

SnifferException::SnifferException()
{

}

SnifferException::SnifferException(QString message)
{
    this->Message = message;
    this->Code = -1;
}

SnifferException::SnifferException(QString message, int code)
{
    this->Code = code;
    this->Message = message;
}

