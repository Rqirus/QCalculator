#ifndef QNUMBER_H
#define QNUMBER_H

#include <QObject>
#include <QDebug>
class QNumber
{
private:
    qreal rv;
    qint64 iv;
    bool isIntegerMode;
public:
    explicit QNumber();
    explicit QNumber(qint64);
    explicit QNumber(qreal);
    QNumber operator + (const QNumber &b)const;
    QNumber operator - (const QNumber &b)const;
    QNumber operator * (const QNumber &b)const;
    QNumber operator / (const QNumber &b)const;

    QNumber operator + (const qreal &b)const;
    QNumber operator - (const qreal &b)const;
    QNumber operator * (const qreal &b)const;
    QNumber operator / (const qreal &b)const;


    QNumber operator = (const QNumber &b);

    QNumber operator = (const qint64 &b);
    QNumber operator = (const qreal &b);
    qreal getRealValue();
    qint64 getIntValue();
    bool getMode();


};

#endif // QNUMBER_H
