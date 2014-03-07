#include "qt_xmlmap.h"

// ====================== CONSTRUCT&LOADING ====================
QtXMLMap::QtXMLMap(QString xml_path){
    qDebug() << "creating new xml map from path";
    QDomDocument d;
    file = new QFile (xml_path);
    if ( file->open(QFile::ReadOnly) ){
        if ( d.setContent(file) ){
            if (d.firstChild().childNodes().length() == 0)
                d.removeChild( d.firstChild() );
                load_from_node( d.firstChild() );
        }
    }else{
        qDebug() << "wrong XML file";
    }
    file->close();
}
QtXMLMap::QtXMLMap(QDomNode node){
    load_from_node (node);
}
void QtXMLMap::load_from_node(QDomNode node){
    //qDebug() << "creating new xml map from node:" << node.toElement().tagName() << "text: " << node.toElement().text();
    n = node;
    if ( n.isElement() ){
        e = n.toElement();
    }
    loadChildren();
    return;
}
int QtXMLMap::loadChildren(){
    QDomNodeList children = n.childNodes();
    if (children.length() > 0 )
        for (unsigned int i = 0; i< children.length(); i++){
            c.append( new QtXMLMap( children.at(i) ) );
            c.at(i)->setParent( this );
        }
    return c.length();
}

void QtXMLMap::setParent(QtXMLMap *parent){
    p = parent;
}


// ====================== SEARCHING====================
QtXMLMap* QtXMLMap::findOneByTag(QString tag_name){
    //qDebug() << "searching tagName. current tag: " << e.tagName() ;
    if ( e.tagName() == tag_name ){
        //qDebug() << "node found by tagName";
        return this;
    }
    else{
        for(int i = 0 ; i< c.length(); i++){
            QtXMLMap* found = c.at(i)->findOneByTag( tag_name );
            if ( found != NULL )
                 return found;
            delete found;
        }
    }
    //qDebug() << "node not ofund by tagNAme";
    return NULL;
}
QtXMLMap* QtXMLMap::findChildrenByTag(QString tag_name){
    //qDebug() << "searching Children by tag. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );
    for(int i = 0 ; i< c.length(); i++){
        if (c.at(i)->e.tagName() == tag_name){
            found->c.append( c.at(i) );
            //qDebug() << "1st gen child found";
        }
    }
    return found;
}
QtXMLMap* QtXMLMap::findAllByTag(QString tag_name){
    //qDebug() << "searching All by tag. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );;
    for(int i = 0; i< c.length(); i++){
        found->c.append( c.at(i)->findAllByTag(tag_name)->c );
    }
    if( e.tagName() == tag_name )
        found->c.append( this );
    return found;
}
QtXMLMap* QtXMLMap::findOneByAttrName(QString attr_name){
    //qDebug() << "searching AttrName. current tag: " << e.tagName() ;
    if ( e.hasAttribute( attr_name ) ){
        //qDebug() << "node found by AttrNAme";
        return this;
    }
    else{
        for(int i = 0 ; i< c.length(); i++){
            QtXMLMap* found = c.at(i)->findOneByAttrName( attr_name );
            if ( found != NULL )
                 return found;
            delete found;
        }
    }
    //qDebug() << "node not ofund by AttrNAme";
    return NULL;
}
QtXMLMap* QtXMLMap::findChildrenByAttrName(QString attr_name){
    //qDebug() << "searching Children by attr. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );
    for(int i = 0 ; i< c.length(); i++){
        if ( c.at(i)->e.hasAttribute(attr_name) ){
            found->c.append( c.at(i) );
            //qDebug() << "1st gen child found";
        }
    }
    return found;
}
QtXMLMap* QtXMLMap::findAllByAttrName(QString attr_name){
    //qDebug() << "searching All by attr. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );;
    for(int i = 0; i< c.length(); i++){
        found->c.append( c.at(i)->findAllByAttrName(attr_name)->c );
    }
    if( e.hasAttribute(attr_name) )
        found->c.append( this );
    return found;
}
QtXMLMap* QtXMLMap::findOneByAttrValue(QString attr_name, QString attr_value){
    //qDebug() << "searching AttrValue. current tag: " << e.tagName() ;
    if ( e.attribute( attr_name ) == attr_value ){
        //qDebug() << "node found by AttrValue";
        return this;
    }
    else{
        for(int i = 0 ; i< c.length(); i++){
            QtXMLMap* found = c.at(i)->findOneByAttrValue( attr_name, attr_value );
            if ( found != NULL )
                 return found;
            delete found;
        }
    }
   // qDebug() << "node not ofund by AttrValue";
    return NULL;
}
QtXMLMap* QtXMLMap::findChildrenByAttrValue(QString attr_name, QString attr_value){
    //qDebug() << "searching Children by attr. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );
    for(int i = 0 ; i< c.length(); i++){
        if ( c.at(i)->e.attribute(attr_name) == attr_value ){
            found->c.append( c.at(i) );
            //qDebug() << "1st gen child found";
        }
    }
    return found;
}
QtXMLMap* QtXMLMap::findAllByAttrValue(QString attr_name, QString attr_value){
    //qDebug() << "searching All by attr value. current tag: " << e.tagName() << ". All children: " << c.length();
    QtXMLMap* found = new QtXMLMap( *new QDomNode() );
    for(int i = 0; i< c.length(); i++){
        found->c.append( c.at(i)->findAllByAttrValue(attr_name, attr_value)->c );
    }
    if( e.attribute(attr_name) == attr_value )
        found->c.append( this );
    return found;
}
QtXMLMap* QtXMLMap::$(QString search_string){
     //qDebug () << search_string.split("\\>").join("$gt$").split(">");
     search_string = search_string.split("\\>").join("$gt$");   //экранируем скобочки на время разбиения
     QtXMLMap     *found = this;
     QString     query;
     QString     end;
     QStringList split;
     foreach(query, search_string.split(">")){
         query = query.split("$gt$").join(">");             //возвертаем скобочки
         //qDebug() << "query: " << query;
         end = query.at(query.length()-1);
         if( end == "." || end == "*" ){
             query = query.mid(0,query.length()-1);
             //qDebug() << query;
         }

         if( query.at(0) == '@'){
           //ищем по атрибутам
             query = query.mid(1,query.length()-1);         //вырезаем собаку
             split = query.split("=");                      //разбиваем на атрибут/значение
             //qDebug() << "split: " << split;
             if ( split.length() > 2){
                 //qDebug() << "wrong @attr=value expression";
                 return found;
             }
             if ( split.length() == 2){
                //ищем по значению атрибута
                 qDebug() << "search @attr=value";
                 if ( end == "." ) {
                     //qDebug() << "children";
                     found = found->findChildrenByAttrValue(split.at(0), split.at(1));
                 }else
                     if ( end == "*" ) {
                        //qDebug() << "all";
                        found = found->findAllByAttrValue(split.at(0), split.at(1));
                     }else{
                         //qDebug() << "one";
                         found = found->findOneByAttrValue(split.at(0), split.at(1));
                     }
             }else{
                //ищем по наличию атрибута
                 //qDebug() << "search @attr";
                 if ( end == "." ) {
                     //qDebug() << "children";
                     found = found->findChildrenByAttrName(split.at(0));
                 }else
                     if ( end == "*" ) {
                        //qDebug() << "all";
                        found = found->findAllByAttrName(split.at(0));
                     }else{
                         //qDebug() << "one";
                         found = found->findOneByAttrName(split.at(0));
                     }


             }
         }else{
           //ищем по тегам
             //qDebug() << "searching the tag";
             if ( end == "." ) {
                 //qDebug() << "children";
                 found = found->findChildrenByTag( query );
             }else
                 if ( end == "*" ) {
                    //qDebug() << "all";
                    found = found->findAllByTag( query );
                 }else{
                     //qDebug() << "one";
                     found = found->findOneByTag( query );
                 }
         }
     }

     if (found == NULL){
         return new QtXMLMap( *new QDomNode() );
         qDebug() << "nodes not found";
     }

     return found;
}
//======================= HELPING =====================
