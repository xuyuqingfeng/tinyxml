#include <stdio.h>
#include "tinyxml.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
	TiXmlDocument：文档类，它代表了整个xml文件
	TiXmlDeclaration：声明类，它表示文件的声明部分
	TiXmlComment：注释类，它表示文件的注释部分
	TiXmlElement：元素类，它是文件的主要部分，并且支持嵌套结构，一般使用这种结构来分类的存储信息，它可以包含属性类和文本类
	TiXmlAttribute/TiXmlAttributeSet：元素属性，它一般嵌套在元素中，用于记录此元素的一些属性
	TiXmlText：文本对象，它嵌套在某个元素内部
*/


//创建xml文件
int writeXmlFile()
{
	TiXmlDocument* writeDoc = new TiXmlDocument;//xml文档指针

	//文档说明
	TiXmlDeclaration* xmlDeclaration = new TiXmlDeclaration("1.0", "utf-8", "yes");
	writeDoc->LinkEndChild(xmlDeclaration);

	//根元素
	TiXmlElement* rootElement = new TiXmlElement("Strategy");
	writeDoc->LinkEndChild(rootElement);

	TiXmlElement* strategyElement = new TiXmlElement("Strategy_name");
	strategyElement->SetAttribute("name", "BladeFinish");
	rootElement->LinkEndChild(strategyElement);

	TiXmlElement* methodElement = new TiXmlElement("Method");
	methodElement->SetAttribute("name", "method");
	strategyElement->LinkEndChild(methodElement);

	TiXmlElement* methodtypeElement = new TiXmlElement("Method_type");
	methodtypeElement->SetAttribute("name", "method_type");
	methodtypeElement->SetAttribute("para1", "main");
	methodtypeElement->SetAttribute("para2", "left");
	methodtypeElement->SetAttribute("para3", "right");
	methodElement->LinkEndChild(methodtypeElement);

	TiXmlElement* cuttingtypeElement = new TiXmlElement("Cutting_type");
	cuttingtypeElement->SetAttribute("name", "cutting_type");
	cuttingtypeElement->SetAttribute("para1", "main");
	cuttingtypeElement->SetAttribute("para2", "left");
	cuttingtypeElement->SetAttribute("para3", "right");
	methodElement->LinkEndChild(cuttingtypeElement);
	

	writeDoc->SaveFile("123.xml");
	delete writeDoc;

	return 1;

	//TiXmlDocument *writeDoc = new TiXmlDocument;//xml文档指针

	////文档格式说明
	//TiXmlDeclaration* dec1 = new TiXmlDeclaration("1.0", "UFT-8", "yes");
	//writeDoc->LinkEndChild(dec1);//写入文档

	//int n = 3;

	//TiXmlElement* RootElement = new TiXmlElement("Info");//根元素
	//RootElement->SetAttribute("num", n);//属性
	//writeDoc->LinkEndChild(RootElement);

	//for (int i = 0; i < n; i++)
	//{
	//	TiXmlElement* stuElement = new TiXmlElement("Stu");

	//	//设置属性
	//	stuElement->SetAttribute("class", "A");
	//	if (2 == i)
	//	{
	//		stuElement->SetAttribute("class", "B");
	//	}

	//	stuElement->SetAttribute("id", i + 1);
	//	stuElement->SetAttribute("falg", (i + 1) * 10);
	//	RootElement->LinkEndChild(stuElement);//父节点写入文档

	//	//姓名
	//	TiXmlElement* nameElement = new TiXmlElement("name");
	//	stuElement->LinkEndChild(nameElement);

	//	TiXmlText* nameContent = new TiXmlText("mike");
	//	nameElement->LinkEndChild(nameContent);

	//	//分数
	//	TiXmlElement* scoreElement = new TiXmlElement("score");
	//	stuElement->LinkEndChild(scoreElement);

	//	TiXmlText* socreContent = new TiXmlText("88");
	//	scoreElement->LinkEndChild(socreContent);
	//}

	//writeDoc->SaveFile("stu_info.xml");
	//delete writeDoc;
	//return 1;
}

int readXmlFile()
{
	TiXmlDocument readDoc("stu_info.xml");
	bool loadOk = readDoc.LoadFile();

	if (!loadOk)
	{
		cout << "could not load the test file.Error:" << readDoc.ErrorDesc() << endl;
		exit(1);
	}

	TiXmlElement* rootElement = readDoc.RootElement();
	cout << "[root name]" << rootElement->Value() << endl;

	TiXmlElement* pFile = rootElement;

	//遍历该节点
	for (TiXmlElement* stuElement = pFile->FirstChildElement(); 
		stuElement != NULL; 
		stuElement = stuElement->NextSiblingElement())
	{
		cout << stuElement->Value() << " ";
		TiXmlAttribute* pAttr = stuElement->FirstAttribute();//First Attribute

		//输出所有属性
		while (NULL != pAttr)
		{
			cout << pAttr->Name() << ":" << pAttr->Value() << " ";
			pAttr = pAttr->Next();
		}

		//输出所有子元素的值
		for (TiXmlElement* childElement = stuElement->FirstChildElement();
			NULL != childElement;
			childElement = childElement->NextSiblingElement())
		{
			cout << childElement->FirstChild()->Value() << endl;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	
	writeXmlFile();
	printf("\nafter write\n");
	
	//readXmlFile();

	system("pause");

	return 0;
}