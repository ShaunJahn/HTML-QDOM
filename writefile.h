#ifndef WRITEFILE_H
#define WRITEFILE_H

#include "studentlist.h"


#include <QFile>
#include <QTextStream>
#include <QDomDocument>

class WriteFile
{
public:
    WriteFile();
    bool writeToXml(QString path);
};

#endif // WRITEFILE_H
