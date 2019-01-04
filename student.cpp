#include "student.h"

student::student()
{
}

double student::average()
{
    double tot = 0;
    QList<double> studentMarks = modules.values();

    for(int k =0;k<studentMarks.size();k++)
    {
        tot += studentMarks[k];
    }

    return tot/modules.count();
}

bool student::graduate()
{

    int firstYearModules = 0;
    int thirdYearModules = 0;
    int totalPassed = 0;

    foreach(QString module, modules.keys())
    {
        int year = QString(module[3]).toInt();
        double mark = modules.value(module);

        if(mark >= 50)
        {
         totalPassed++;

         if(year == 1)
             firstYearModules++;

         if(year == 3)
             thirdYearModules++;
        }


    }

    if(totalPassed >= 1 && firstYearModules <=2 && thirdYearModules >= 1)
        return true;

    return false;
}

QString student::toString()
{
    //sutdent : 1234
    //has done the following modules
    //lsit modules with mark

    QStringList moduleDone;
    foreach(QString module,modules.keys())
    {
        QString build = "module: " + module + " with mark: " + QString::number(modules.value(module));
        moduleDone << build;
    }

    return QString("Student: " + studentNumber + "\n" + moduleDone.join("\n"));
}

void student::setNumber(QString n)
{
    studentNumber = n;
}

QString student::getNumber()
{
    return studentNumber;
}

void student::addModule(QString code, double mark)
{
    modules.insert(code,mark);
}

QMap<QString,double> student::getModules()
{
    return modules;
}
