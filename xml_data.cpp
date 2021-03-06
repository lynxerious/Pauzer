#include "xml_data.h"

Xml_Data::Xml_Data()
{

}
QDomElement Xml_Data::readXml(const QString &filename)
{
    QDomElement result;
    QFile file(filename);
    QDomDocument doc;
    if (!file.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
    }
    else
    {
        doc.setContent(&file);
        file.close();
        result = doc.documentElement();
    }
    return result;
}
QString Xml_Data::writeXml(QDomElement data, const QString &filename)
{
    QString result = "";
    QFile file(filename);
    QDomDocument doc;
    QDomProcessingInstruction header = doc.createProcessingInstruction("xml", "version='1.0' encoding='UTF-16'");
    doc.appendChild(header);
    doc.appendChild(data);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        result = "Error while loading file";
    }
    QTextStream stream(&file);
    doc.save(stream, 0);
    file.close();
    return result;
}

