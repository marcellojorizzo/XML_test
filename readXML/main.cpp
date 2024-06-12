
#include <QtCore>
#include <QtXml>
#include <QDebug>


// reading XML using DOM Method

void ListElements(QDomElement root, QString tagname, QString attribute)


{

    QDomNodeList items = root.elementsByTagName(tagname);

       qDebug() << "Total items = " << items.count();

       for (int i= 0; i < items.count(); i++)

       {
           QDomNode itemnode = items.at(i);

           // covert to element

           if(itemnode.isElement())
           {
               QDomElement itemele = itemnode.toElement();
                  qDebug() << itemele.attribute(attribute);
           }

       }



}


int main (int argc , char *argv[])
{
    QCoreApplication a(argc, argv);


        QDomDocument document;


        //Load the File
        QFile file ("../MyXML.xml");

         if(!file.open(QIODevice::ReadOnly | QIODevice::Text))

         {

             qDebug() << "Failed to open File";
             return -1;

         }

         else

         {
             if(!document.setContent(&file))
             {

                 qDebug() << "Failed to load document";
                 return -1;
             }
             file.close();

         }

         // get the root Element

         QDomElement root = document.firstChildElement();

         // list all elements
            ListElements(root, "Book", "Name");

             qDebug() << "\r\nMore Advanced\r\n";

             //Get the all Nodes

             QDomNodeList books = root.elementsByTagName("Book");
             for (int i = 0; i < books.count(); i++)

             {
                 QDomNode booknode = books.at(i);
                 //convert to an Element

                 if (booknode.isElement() )


                 {

                     QDomElement book = booknode.toElement();
                     ListElements(book, "Chapter", "Name");
                 }



             }

         qDebug() << "Finished";


return a.exec();
}
