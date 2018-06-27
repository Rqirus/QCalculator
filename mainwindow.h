#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QStack>
#include <cmath>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showNumber(QString,QString);
    void pushNumber(char);
    void setExp();
public slots:
    //number
    void btn0Slot();
    void btn1Slot();
    void btn2Slot();
    void btn3Slot();
    void btn4Slot();
    void btn5Slot();
    void btn6Slot();
    void btn7Slot();
    void btn8Slot();
    void btn9Slot();
    void btnPointSlot();
    void btnPercentSlot();
    //operator
    void btnSubSlot();
    void btnAddSlot();
    void btnMulSlot();
    void btnDivSlot();
    void btnEquSlot();
    void btnSqrtSlot();
    void btnReciprocal();
    void btnNegateSlot();
   //function
    void btnBackSLot();
    void btnClearSlot();
    void btnClearErrorSlot();
   //memory
    void btnMemoryClearSlot();
    void btnMemoryReadSlot();
    void btnMemorySaveSlot();
    void btnMemoryAddSlot();
    void btnMemorySubSlot();
private:
    Ui::MainWindow *ui;
    QString cur,exp;
    char opt;
    QStack<QString> stk;
    qint64 M1;
    qreal M2;
};

#endif // MAINWINDOW_H
