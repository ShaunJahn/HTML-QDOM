#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    studentProcess = new QProcess(parent);
    connect(studentProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(addModule()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    studentProcess->start("GetStudent.exe");
}

void Widget::addModule()
{
    QByteArray bArray = studentProcess->readAllStandardOutput();
    QString text = QString(bArray);

    QStringList studentInfo = text.split( "," );

    QString stdNum = studentInfo[0];
    QString module = studentInfo[1];
    double mark  =  studentInfo[2].toDouble();

    studentList *studentList = studentList::getInstance();
    studentList->addStudent(stdNum,module,mark);
}

void Widget::on_btnGraduate_clicked()
{
    studentList *sList = studentList::getInstance();
    QString number = ui->edtIn->text();
    int check = sList->exists(number);

    if(check != -1)
    {
        student *S = sList->at(check);
        bool test = S->graduate();
        QString grad =test ? "Student has passed" : "Student has failed";
        ui->edtOut->setText(grad);
    }
    else
        ui->edtOut->setText("Invalid Student number. Not found");
}




void Widget::on_btnDisplay_clicked()
{
    studentList *sList = studentList::getInstance();
    QString number = ui->edtIn->text();
    int check = sList->exists(number);

    if(check != -1)
    {
        student *S = sList->at(check);
        ui->edtOut->setText(S->toString());
    }
    else
        ui->edtOut->setText("Invalid Student number. Not found");
}

void Widget::on_btnAvg_clicked()
{
    studentList *sList = studentList::getInstance();
    QString number = ui->edtIn->text();
    int check = sList->exists(number);

    if(check != -1)
    {
        student *S = sList->at(check);
        QString avg = QString::number(S->average());
        ui->edtOut->setText(QString("Student with number " + number + " has the average of ") + avg);
    }
    else
        ui->edtOut->setText("Invalid Student number. Not found");
}

void Widget::on_btnFileWrite_clicked()
{
    output.writeToXml("student.txt");
}

void Widget::on_pushButton_2_clicked()
{
     studentProcess->start("GetStudent.exe");
}
