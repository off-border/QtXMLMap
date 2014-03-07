QtXMLMap
========

Simple wrapper ove Qt XML classes for more easy working with an XML documents.

/* written by Off_Border
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
 *
 * AND...
 * sorry my English :)
 * it will be improoved too in next versions of My :)
 *
 * */
