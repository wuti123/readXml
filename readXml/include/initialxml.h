#ifndef INITIALXML_H
#define INITIALXML_H

#include <string>
#include "tinyxml.h"
#include <iostream>
#include <vector>


struct classnameAndCoord
{
    std::string classname;
    int Xmin;
    int Ymin;
    int Xmax;
    int Ymax;
    int area;
};



class InitialXml
{
public:
    const char *xml_name;
    TiXmlDocument doc;      // 申明一个文档类型变量，用来存储读取的xml文档
    TiXmlElement *root;     // 指向xml文档的根元素
    TiXmlElement *elem;     // elem指向根的第一个孩子元素
    std::vector<classnameAndCoord> name_coord;   // 用于存储从xml提取的目标类型及其坐标值


    InitialXml(std::string xml_name);
    void loadXml();
    ~InitialXml();


};



#endif // INITIALXML_H
