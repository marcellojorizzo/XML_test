#include <QtCore>
#include <QtXml>
#include <QDebug>

int main (int argc , char *argv[])
{
    QCoreApplication xmlWriter(argc, argv);

 //Write XML using DOM
 QDomDocument document;

 // Create Root Element
 QDomElement root = document.createElement("Books");

 // Add Root Element to Document
 document.appendChild(root);


 //Add more Elements

 for (int i=0; i < 10; i++)
 {

     QDomElement book = document.createElement("Book");
     book.setAttribute("Name", "MyBook" + QString::number(i));
     book.setAttribute("BookID", QString::number(i));
     root.appendChild(book);

     for (int h =0; h < 10; h++)
     {
         QDomElement chapter = document.createElement("Chapter");
         chapter.setAttribute("Name", "MyChapter " + QString::number(h));
         chapter.setAttribute("ID", QString::number(h));
         book.appendChild(chapter);
     }

 }






 //Write to file
 QFile file ("../MyXML.xml");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
            return -1;
        }
    else
        {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished";
        }



return xmlWriter.exec();
}
