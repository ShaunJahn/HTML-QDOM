#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include <QList>
#include <QMap>


class studentList : public QList<student*>
{
public:
    static studentList *getInstance();
    QList<student*> getList();
    void addStudent(QString stdNum,QString module, double mark);
    int exists(QString n);
private:
    studentList();
    static studentList* instance;
};

#endif // STUDENTLIST_H
