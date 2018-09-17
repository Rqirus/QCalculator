#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    this->setMaximumHeight(this->height());
    this->setMinimumHeight(this->height());
    this->setMaximumWidth(this->width());
    this->setMinimumWidth(this->width());

    exp="&nbsp;";
    M1=M2=0;
    stk.push(0);
    showNumber("&nbsp;","0");


    QObject::connect(ui->btn0,SIGNAL(clicked()),this,SLOT(btn0Slot()));
    QObject::connect(ui->btn1,SIGNAL(clicked()),this,SLOT(btn1Slot()));
    QObject::connect(ui->btn2,SIGNAL(clicked()),this,SLOT(btn2Slot()));
    QObject::connect(ui->btn3,SIGNAL(clicked()),this,SLOT(btn3Slot()));
    QObject::connect(ui->btn4,SIGNAL(clicked()),this,SLOT(btn4Slot()));
    QObject::connect(ui->btn5,SIGNAL(clicked()),this,SLOT(btn5Slot()));
    QObject::connect(ui->btn6,SIGNAL(clicked()),this,SLOT(btn6Slot()));
    QObject::connect(ui->btn7,SIGNAL(clicked()),this,SLOT(btn7Slot()));
    QObject::connect(ui->btn8,SIGNAL(clicked()),this,SLOT(btn8Slot()));
    QObject::connect(ui->btn9,SIGNAL(clicked()),this,SLOT(btn9Slot()));
    QObject::connect(ui->btnPoint,SIGNAL(clicked()),this,SLOT(btnPointSlot()));
    QObject::connect(ui->btnPercent,SIGNAL(clicked()),this,SLOT(btnPercentSlot()));


    QObject::connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(btnAddSlot()));
    QObject::connect(ui->btnSub,SIGNAL(clicked()),this,SLOT(btnSubSlot()));
    QObject::connect(ui->btnMul,SIGNAL(clicked()),this,SLOT(btnMulSlot()));
    QObject::connect(ui->btnDiv,SIGNAL(clicked()),this,SLOT(btnDivSlot()));
    QObject::connect(ui->btnReciprocal,SIGNAL(clicked()),this,SLOT(btnReciprocal()));
    QObject::connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnSqrtSlot()));
    QObject::connect(ui->btnEqual,SIGNAL(clicked()),this,SLOT(btnEquSlot()));
    QObject::connect(ui->btnNegate,SIGNAL(clicked()),this,SLOT(btnNegateSlot()));

    QObject::connect(ui->btnBack,SIGNAL(clicked()),this,SLOT(btnBackSLot()));
    QObject::connect(ui->btnClear,SIGNAL(clicked()),this,SLOT(btnClearSlot()));
    QObject::connect(ui->btnClearError,SIGNAL(clicked()),this,SLOT(btnClearErrorSlot()));

    QObject::connect(ui->btnMemoryClear,SIGNAL(clicked()),this,SLOT(btnMemoryClearSlot()));
    QObject::connect(ui->btnMemoryRead,SIGNAL(clicked()),this,SLOT(btnMemoryReadSlot()));
    QObject::connect(ui->btnMemorySave,SIGNAL(clicked()),this,SLOT(btnMemorySaveSlot()));
    QObject::connect(ui->btnMemorySub,SIGNAL(clicked()),this,SLOT(btnMemorySubSlot()));
    QObject::connect(ui->btnMemoryAdd,SIGNAL(clicked()),this,SLOT(btnMemoryAddSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNumber(QString exp,QString number)
{
    if(number.isEmpty())number="0";
    if(exp.isEmpty())
    ui->textBrowser->setHtml("<br>"
                             "<div style=\"font-size:25px\" align=\"right\">"+number+"</p>");
    else
    ui->textBrowser->setHtml("<div style=\"font-size:15px\" align=\"right\">"+exp+"</div>"
                             "<div style=\"font-size:25px\" align=\"right\">"+number+"</p>");
}


void MainWindow::setExp()
{
    exp = "&nbsp;";
}

void MainWindow::btn0Slot()
{
    cur=cur+"0";
    showNumber(exp,cur);
}
void MainWindow::btn1Slot()
{
    cur = cur + "1";
    showNumber(exp,cur);
}
void MainWindow::btn2Slot()
{
    cur = cur + "2";
    showNumber(exp,cur);
}
void MainWindow::btn3Slot()
{
    cur = cur + "3";
    showNumber(exp,cur);
}
void MainWindow::btn4Slot()
{
    cur = cur + "4";
    showNumber(exp,cur);
}
void MainWindow::btn5Slot()
{
    cur = cur + "5";
    showNumber(exp,cur);
}
void MainWindow::btn6Slot()
{
    cur = cur + "6";
    showNumber(exp,cur);
}
void MainWindow::btn7Slot()
{
    cur = cur + "7";
    showNumber(exp,cur);
}
void MainWindow::btn8Slot()
{
    cur = cur + "8";
    showNumber(exp,cur);
}
void MainWindow::btn9Slot()
{
    cur = cur + "9";
    showNumber(exp,cur);
}
void MainWindow::btnPointSlot()
{
    cur = cur + ".";
    showNumber(exp,cur);
}
void MainWindow::btnPercentSlot()
{
    cur = cur + "%";
    showNumber(exp,cur);
}

//operator
void MainWindow::pushNumber(char o)
{
    if(!cur.isEmpty())
        stk.push(cur);
    exp = stk.top() + o;
    cur="";
    opt = o;
    showNumber(exp,cur);
}

void MainWindow::btnSubSlot()
{
    if(stk.size()>1)
        btnEquSlot();
    pushNumber('-');
}
void MainWindow::btnAddSlot()
{
    if(stk.size()>1)
        btnEquSlot();
    pushNumber('+');
}
void MainWindow::btnMulSlot()
{
    if(stk.size()>1)
        btnEquSlot();
    pushNumber('*');
}
void MainWindow::btnDivSlot()
{
    if(stk.size()>1)
        btnEquSlot();
    pushNumber('/');
}
void MainWindow::btnReciprocal()
{
    if(!cur.isEmpty())
    stk.push(cur);
    exp = "1/" + stk.top();
    bool ok;
    qreal t2 = stk.top().toDouble(&ok);
    qint64 t1 = stk.top().toLongLong(&ok);
    stk.pop();
    QString res;
    if(ok)res=QString::number(double(1/(1.0*t1)));
    else res=QString::number(double(1/t2));
    stk.push(res);
    cur="";
    showNumber(exp,res);
}
void MainWindow::btnSqrtSlot()
{
    if(!cur.isEmpty())
    stk.push(cur);
    exp = "√" + stk.top();
    cur="";
    bool ok;
    double r=sqrt(stk.top().toDouble(&ok));
    QString res = QString::number(r);

    stk.push(res);
    showNumber(exp,res);
}

//最经计算的结果一定放到stack中
void MainWindow::btnEquSlot()
{
    bool ok1,ok2;
    stk.push(cur);
    QString v1 = stk.top();
    stk.pop();
    if(stk.isEmpty())return;
    QString v2 = stk.top();
    stk.pop();
    double c = v1.toDouble(&ok1);
    double d = v2.toDouble(&ok2);
    qint64 a = v1.toLongLong(&ok1);
    qint64 b = v2.toLongLong(&ok2);
    bool f = ok1&&ok2;// 运算结果为整数
    int p = 0;
    for(int i=0;i<v1.size();i++)
        if(v1[i]=='%')p++;
    if(p==1)
    {
        qreal v = 0;
        char ch;
        for(int i=0;i<v1.size();i++)
        {
            ch = v1[i].toLatin1();
            if(ch!='%')v=v*10+(ch-'0');
        }
        v/=100.0;
        f=false;
        c = v*d;
    }
    if(p>1)
    {
        btnClearSlot();
        showNumber("&nbsp;","");
        return;
    }
    cur.clear();
    switch(opt)
    {
    case '+':
        if((a>0&&b>0&&(a+b)<0)||(a<0&&b<0&&(a+b>0)))
        {
            btnClearSlot();
            showNumber("&nbsp;","数据溢出");
            return ;
        }
        v1=f?v1.number(b+a):v1.number(d+c);
        break;
    case '-':
        v1=f?v1.number(b-a):v1.number(d-c);
        break;
    case '*':
        if(a>0&&b>0&&a*b<0||(a>0&&b<0&&a*b>0||a<0&&b>0&&a*b>0))
        {
            btnClearSlot();
            showNumber("&nbsp;","数据溢出");
            return ;
        }
        v1=f?v1.number(a*b):v1.number(c*d);
        break;
    case '/':
        if(a==0)
        {
            btnClearSlot();
            showNumber("&nbsp;","除零错误");
            return;
        }
        if(b/a==(qint64)(d*1.0)/c)v1=v1.number(b/a);
        else v1=v1.number(d*1.0/c);
        break;

    default:
        return;
    }
    stk.push(v1);
    exp = "&nbsp;";
    showNumber(exp,v1);
}
void MainWindow::btnNegateSlot()
{
    QString tmp=cur;
    if(cur.isEmpty())tmp=stk.top();
    if(tmp.startsWith("-"))
    {
        for(int i=0;i<tmp.size()-1;i++)
            tmp[i] = tmp[i+1];
        tmp.resize(tmp.size()-1);
    }
    else
    {
        tmp.resize(tmp.size()+1);
        for(int i=tmp.size()-1;i>=1;i--)
            tmp[i]=tmp[i-1];
        tmp[0]='-';
    }
    cur = tmp;
    showNumber(exp,tmp);
}

//fun
void MainWindow::btnClearSlot()
{
    cur.clear();
    stk.clear();
    exp="&nbsp;";
    showNumber(exp,cur);
}


void MainWindow::btnBackSLot()
{
    if(cur.size()>0)
    cur.resize(cur.size()-1);
    showNumber(exp,cur);
}

void MainWindow::btnClearErrorSlot()
{
    cur="";
    showNumber(exp,cur);
}


//memory
void MainWindow::btnMemoryClearSlot()
{
    M1=M2=0;
}

void MainWindow::btnMemoryReadSlot()
{
    if(M1!=0)cur=QString::number(M1);
    if(M2!=0)cur=QString::number(M2);
    showNumber("&nbsp;",cur);
}

void MainWindow::btnMemorySaveSlot()
{
    bool ok;
    qreal tmp2 = cur.toDouble(&ok);
    qint64 tmp = cur.toLongLong(&ok);
    if(ok)M1=tmp,M2=0;
    else M1=0,M2=tmp2;
}
void MainWindow::btnMemoryAddSlot()
{
    bool ok;

    qint64 t1=cur.toLongLong(&ok);
    qreal t2=cur.toDouble(&ok);

    if(ok)M2 = M2 + M1 + t2,M1 = 0;
    else M1 = M1 + t1,M2 = 0;
    if(M1!=0)cur=QString::number(M1);
    if(M2!=0)cur=QString::number(M2);
    showNumber("&nbsp;",cur);
}
void MainWindow::btnMemorySubSlot()
{
    bool ok;
    qint64 t1=cur.toLongLong(&ok);
    qreal t2=cur.toDouble(&ok);

    if(ok)
    {
        if(M1)M2 = M1*1.0 - t2,M1=0;
        else M2 = M2 - t1,M1=0;
    }
    else M1 = M1 - t1,M2=0;
    if(M1!=0)cur=QString::number(M1);
    if(M2!=0)cur=QString::number(M2);
    if(!(M1||M2))cur="";
    showNumber("&nbsp;",cur);
}
