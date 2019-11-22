#include "include/initialxml.h"
#include <sstream>
using namespace std;

InitialXml::InitialXml(std::string xml_name)
{
    this->xml_name = xml_name.c_str();
    loadXml();
}

void InitialXml::loadXml()
{
    if (!doc.LoadFile(xml_name))      //检测xml文档是否存在
    {
        std::cout << doc.ErrorDesc() << std::endl;
    }

    root = doc.FirstChildElement();
    if (NULL == root)
    {
        std::cout << "Failed to load file: No root element." << std::endl;
//        doc.Clear();
        return;
    }

    classnameAndCoord classname_coord;

    string tmp1 = "object";
    string tmp2 = "bndbox";

    // 元素的value()值是节点的名称，元素的FirstChild()->Value()值是节点存储的标签值
    for (elem = root->FirstChildElement(); NULL != elem; elem = elem->NextSiblingElement())
    {
//        cout << elem->Value() << endl;
        if (tmp1 != elem->Value())
            continue;

        TiXmlElement *elem1 = elem->FirstChildElement();
        cout << elem1->FirstChild()->Value() << endl;
        classname_coord.classname = elem1->FirstChild()->Value();     // 保存类别的名称

        for (; NULL != elem1; elem1 = elem1->NextSiblingElement())
        {
            if (tmp2 != elem1->Value())
                continue;

//            cout << elem1->Value() << endl;
            TiXmlElement *elem2 = elem1->FirstChildElement();
//            cout << elem2->FirstChild()->Value() << endl;

            for (int i = 0; NULL != elem2; elem2 = elem2->NextSiblingElement(), i++)
            {
                stringstream ss;                                     // 从xml中读取的都是字符串，用于将字符串转成数字

                switch (i)                                           // 坐标
                {
                case 0:
                    ss << elem2->FirstChild()->Value();
                    ss >> classname_coord.Xmin;
//                    cout << "xmin: " << classname_coord.Xmin << endl;;
                    break;
                case 1:
                    ss << elem2->FirstChild()->Value();
                    ss >> classname_coord.Ymin;
//                    cout << "Ymin: " << classname_coord.Ymin << endl;;
                    break;
                case 2:
                    ss << elem2->FirstChild()->Value();
                    ss >> classname_coord.Xmax;
//                    cout << "Xmax: " << classname_coord.Xmax << endl;;
                    break;
                case 3:
                    ss << elem2->FirstChild()->Value();
                    ss >> classname_coord.Ymax;
//                    cout << "Ymax: " << classname_coord.Ymax << endl;;
                    break;
                }
            }
        }

        classname_coord.area = (classname_coord.Xmax - classname_coord.Xmin) * (classname_coord.Ymax - classname_coord.Ymin);  // 面积

        name_coord.push_back(classname_coord);
//        std::cout << node->Value() << std::endl;
    }

    for (int i = 0; i < name_coord.size(); i++)
        cout << "area: " << name_coord[i].area << endl;

}


InitialXml::~InitialXml()
{
    doc.Clear();
}
