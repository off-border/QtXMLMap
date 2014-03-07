/* written by Off_Border
 *
 * gitHub: https://github.com/off-border/QtXMLMap
 *
 * Version: 0.1.0
 *
 * CREATING a new XML map:
 *
 * QtXMLMap *myxmlmap = new QtXMLMap("../path/to/../file.xml")
 *      OR  *myxmlmap = new QtXMLMap(QDomNode myNode);
 *
 *
 * NAVIGATE:
 *
 *  myxmlmap->$("tagname")                 -   Recursive search till the first tag with name "tagname"
 *                                          Returns the found node in QtXMLMap entity pointer at existing.
 *
 *  myxmlmap->$("tagname.")                -   Search all the 1st generation children of the current node
 *                                          with correspond tag names.
 *                                          Returns found nodes as children of new QtXMLMap entity.
 *                                          To access children use $("tagname.")->c;
 *
 *  myxmlmap->$("tagname*")                -   Search all children in the tree from the current node
 *                                          with correspond tag names.
 *                                          Returns found nodes as children of new QtXMLMap entity.
 *                                          To access children use $("tagname.")->c;
 *
 *  myxmlmap->$("@attrname")               -   All the same like in "tagname" case but for an attribute
 *  myxmlmap->$("@attrname.")              -   All the same like in "tagname" case but for an attribute
 *  myxmlmap->$("@attrname*")              -   All the same like in "tagname" case but for an attribute
 *
 *
 *  myxmlmap->$("@attrname=attrvalue")     -   Searching for the 1st entrance of the tag with correspond
 *                                          tagname and value.
 *  myxmlmap->$("@attrname=attrvalue.")    -    ...
 *  myxmlmap->$("@attrname=attrvalue*")    -   I thik you got it :)
 *
 *
 *  You can search recursively:
 *
 *  myxmlmap->$("tagnameq1")->$("tagname2.")->$("@attrname=attrvalue*").e.text()
 *
 *  Or even that way:
 *
 *  myxmlmap->$("tagname1>tagname2.>@attrname=attrvalue*").e.text()
 *
 *  Very simple! Isn't it? :)
 *
 * ACCESS TO ELEMENTS:
 *
 *  myxmlmap.n  - QDomNode of current QtXMLMap node.
 *  myxmlmap.e  - QDomElsment of current QtXMLMap node.
 *  myxmlmap.c  - QList<QtXMLMap*> children list of current QtXMLMap node.
 *
 *
 * INSTALLATION:
 *
 * You just need to copy qt_xmlmap.h and qt_xmlmap.cpp to you project and include the header.
 *
 * WARNING:
 * If the first element of .xml file has no children, it will be ignored.
 * (it's for skipping <?xml version="1.0" .... ?> tag)
 *
 * AND...
 * sorry my English :)
 * it will be improoved too in next versions of My :)
 *
 * */

#ifndef XMLMAP_H
#define XMLMAP_H

#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomElement>
#include <QStringList>
#include <QDebug>


class QtXMLMap{
public:
    explicit QtXMLMap(QString xml_path);
    explicit QtXMLMap(QDomNode node);

    //QDomDocument  d;
    QDomNode      n;  //node
    QDomElement   e;  //element
    QList<QtXMLMap*> c;  //children
    QtXMLMap        *p;  //parent

    QFile         *file;

    void    load_from_node (QDomNode node);
    int     loadChildren();
    void    setParent (QtXMLMap *parent);

    QtXMLMap*  findOneByTag      (QString tag_name);       //find the first elem with such tagName
    QtXMLMap*  findChildrenByTag (QString tag_name);  //find only the first generation of children
    QtXMLMap*  findAllByTag      (QString tag_name);       //find all children in tree

    QtXMLMap*  findOneByAttrName      (QString attr_name);       //find the first elem with the such attr
    QtXMLMap*  findChildrenByAttrName (QString attr_name);  //find only the first generation of children
    QtXMLMap*  findAllByAttrName      (QString tag_name);        //find all children in tree

    QtXMLMap*  findOneByAttrValue      (QString attr_name, QString attr_value);       //find the first elem with the such attr
    QtXMLMap*  findChildrenByAttrValue (QString attr_name, QString attr_value);  //find only the first generation of children
    QtXMLMap*  findAllByAttrValue      (QString attr_name, QString attr_value);        //find all children in tree

    QtXMLMap*  $(QString search_string);
};


#endif // XMLMAP_H
