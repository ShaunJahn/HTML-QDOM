#ifndef STUDENT_H
#define STUDENT_H

#include <QMap>
#include <QString>
#include <QStringList>

class student
{
public:
    student();
    double average();
    bool graduate();

    QString toString();
    QString getNumber();

    void setNumber(QString n);
    void addModule(QString code, double mark);

    QMap<QString, double> getModules();

private:
    QString studentNumber;
    QMap<QString,double> modules;
};

#endif // STUDENT_H
