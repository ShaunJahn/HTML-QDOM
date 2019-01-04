#include "studentlist.h"

studentList* studentList::instance = NULL;

studentList::studentList()
{
}

studentList *studentList::getInstance()
{
    if(instance == NULL)
        instance = new studentList();

    return instance;
}

QList<student*> studentList::getList()
{
    return *this;
}

void studentList::addStudent(QString stdNum, QString module, double mark)
{
    student *s;
    int index = exists(stdNum);

    if(index == -1)
    {
     s = new student();
     s->setNumber(stdNum);
     instance->append(s);
    }
    else
    {
        s = instance->at(index);
    }

    s->addModule(module,mark);
}

int studentList::exists(QString n)
{
    for(int i = 0; i < instance->count(); i++)
    {
        if(instance->at(i)->getNumber() == n)
        {
            return i;
        }
    }

    return -1;
}



