QtXMLMap
========

  written by Off_Border<br>
  <br>
  gitHub: https://github.com/off-border/QtXMLMap<br>
  <br>
  Version: 0.1.0<br>
  <br>
  CREATING a new XML map:<br>
  <br>
  QtXMLMap *myxmlmap = new QtXMLMap("../path/to/../file.xml")<br>
       OR  *myxmlmap = new QtXMLMap(QDomNode myNode);<br>
  <br>
  <br>
  NAVIGATE:<br>
  <br>
   myxmlmap->$("tagname")                 -   Recursive search till the first tag with name "tagname"<br>
                                           Returns the found node in QtXMLMap entity pointer at existing.<br>
  <br>
   myxmlmap->$("tagname.")                -   Search all the 1st generation children of the current node<br>
                                           with correspond tag names.<br>
                                           Returns found nodes as children of new QtXMLMap entity.<br>
                                           To access children use $("tagname.")->c;<br>
  <br>
   myxmlmap->$("tagname**")                -   Search all children in the tree from the current node<br>
                                           with correspond tag names.<br>
                                           Returns found nodes as children of new QtXMLMap entity.<br>
                                           To access children use $("tagname.")->c;<br>
                                           (one * symbol. github is gad guy)
  <br>
   myxmlmap->$("@attrname")               -   All the same like in "tagname" case but for an attribute<br>
   myxmlmap->$("@attrname.")              -   All the same like in "tagname" case but for an attribute<br>
   myxmlmap->$("@attrname*")              -   All the same like in "tagname" case but for an attribute<br>
  <br>
  <br>
   myxmlmap->$("@attrname=attrvalue")     -   Searching for the 1st entrance of the tag with correspond<br>
                                           tagname and value.<br>
   myxmlmap->$("@attrname=attrvalue.")    -    ...<br>
   myxmlmap->$("@attrname=attrvalue*")    -   I thik you got it :)<br>
  <br>
  <br>
   You can search recursively:<br>
  <br>
   myxmlmap->$("tagnameq1")->$("tagname2.")->$("@attrname=attrvalue*").e.text()<br>
  <br>
   Or even that way:<br>
  <br>
   myxmlmap->$("tagname1>tagname2.>@attrname=attrvalue*").e.text()<br>
  <br>
   Very simple! Isn't it? :)<br>
  <br>
  ACCESS TO ELEMENTS:<br>
  <br>
   myxmlmap.n  - QDomNode of current QtXMLMap node.<br>
   myxmlmap.e  - QDomElsment of current QtXMLMap node.<br>
   myxmlmap.c  - QList<QtXMLMap*> children list of current QtXMLMap node.<br>
  <br>
  <br>
  INSTALLATION:<br>
  <br>
  You just need to copy qt_xmlmap.h and qt_xmlmap.cpp to you project and include the header.<br>
  <br>
  WARNING:<br>
  If the first element of .xml file has no children, it will be ignored.<br>
  (it's for skipping <?xml version="1.0" .... ?> tag)<br>
  <br>
  AND...<br>
  sorry my English :)<br>
  <br>
  <br>
