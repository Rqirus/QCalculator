#include "qnumber.h"

QNumber::QNumber()
{
    isIntegerMode = true;
    iv=rv=0;
}

QNumber::QNumber(qint64 v)
{
    isIntegerMode=true;
    this->iv=v;
}
QNumber::QNumber(qreal v)
{
    isIntegerMode=false;
    this->rv=v;
}
QNumber QNumber::operator +(const QNumber &b)const
{
    QNumber ret;
    if(isIntegerMode&&b.isIntegerMode)
        return QNumber(qint64(iv+b.iv));
    else
        return QNumber(qreal(rv+b.rv));
}
QNumber QNumber::operator -(const QNumber &b)const
{
    if(isIntegerMode&&b.isIntegerMode)
        return QNumber(qint64(iv-b.iv));
    else
        return QNumber(qreal(rv-b.rv));
}
QNumber QNumber::operator *(const QNumber &b)const
{
    if(isIntegerMode&&b.isIntegerMode)
        return QNumber(qint64(iv*b.iv));
    else
        return QNumber(qreal(rv*b.rv));
}
QNumber QNumber::operator /(const QNumber &b)const
{
    if(isIntegerMode&&b.isIntegerMode)
        return QNumber(qint64(iv/b.iv));
    else
        return QNumber(qreal(rv/b.rv));
}

//with qreal
QNumber QNumber::operator +(const qreal &b)const
{
    qDebug()<<"test"<<iv+b;
    if(isIntegerMode)
        return QNumber(qint64(iv+b));
    else
        return QNumber(qreal(rv+b));
}
QNumber QNumber::operator -(const qreal &b)const
{
    if(isIntegerMode)
        return QNumber(qint64(iv-b));
    else
        return QNumber(qreal(rv-b));
}
QNumber QNumber::operator *(const qreal &b)const
{
    if(isIntegerMode)
        return QNumber(qint64(iv*b));
    else
        return QNumber(qreal(rv*b));
}
QNumber QNumber::operator /(const qreal &b)const
{
    if(isIntegerMode)
        return QNumber(qint64(iv/b));
    else
        return QNumber(qreal(rv/b));
}
QNumber QNumber::operator =(const QNumber &b)
{
    isIntegerMode = b.isIntegerMode;
    rv=b.rv;
    iv=b.iv;
}

qreal QNumber::getRealValue()
{
    if(!isIntegerMode)return this->rv;
    return 0;
}

qint64 QNumber::getIntValue()
{
    if(isIntegerMode)return this->iv;
    return 0;
}
bool QNumber::getMode()
{
    return isIntegerMode;
}

QNumber QNumber::operator =(const qreal &b)
{
    isIntegerMode=false;
    rv=b,rv=0;
}
QNumber QNumber::operator =(const qint64 &b)
{
    isIntegerMode=true;
    iv=b,rv=0;
}
