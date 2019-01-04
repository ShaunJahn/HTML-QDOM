#include "writefile.h"


WriteFile::WriteFile()
{

}

bool WriteFile::writeToXml(QString path)
{
    QList<student*> list = studentList::getInstance()->getList();

    QFile file(path);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QDomDocument doc("xml");

        QDomElement studentList = doc.createElement("StudentList");

        //and make it a child of doc
        doc.appendChild(studentList);

        foreach(student *s, list)
        {

        //make a student element
           QDomElement student = doc.createElement("Student");
        //make it a child of StudentList
           studentList.appendChild(student);

        //Make a number element
           QDomElement number = doc.createElement("number");
        //Make it a child of Student
           student.appendChild(number);
           QDomText textNode = doc.createTextNode(s->getNumber());
           number.appendChild(textNode);

        //Make a modules element
           QDomElement modules = doc.createElement("modules");
        //Make it a child of Student
           student.appendChild(modules);

            //Loop modules
           foreach(QString key, s->getModules().keys())
           {
                //and foreach module make a module element
               QDomElement module = doc.createElement("module");
                //make it a child of modules
               modules.appendChild(module);

                //make a code element and
               QDomElement code = doc.createElement("code");
                //make it a child of module
               module.appendChild(code);
               QDomText codeText = doc.createTextNode(key);
               code.appendChild(codeText);

               //make
               QDomElement mark = doc.createElement("mark");
               module.appendChild(mark);
               QDomText markText = doc.createTextNode(QString("%1").arg(s->getModules().value(key)));
               mark.appendChild(markText);
           }
        }

        //write to file
        QTextStream stream(&file);

        QString xml = doc.toString();

        stream << doc.toString() << endl;

        file.close();
        return true;
    }

    return false;
}
