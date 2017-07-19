#include <stdio.h>
#include "tinyxml.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
	TiXmlDocument���ĵ��࣬������������xml�ļ�
	TiXmlDeclaration�������࣬����ʾ�ļ�����������
	TiXmlComment��ע���࣬����ʾ�ļ���ע�Ͳ���
	TiXmlElement��Ԫ���࣬�����ļ�����Ҫ���֣�����֧��Ƕ�׽ṹ��һ��ʹ�����ֽṹ������Ĵ洢��Ϣ�������԰�����������ı���
	TiXmlAttribute/TiXmlAttributeSet��Ԫ�����ԣ���һ��Ƕ����Ԫ���У����ڼ�¼��Ԫ�ص�һЩ����
	TiXmlText���ı�������Ƕ����ĳ��Ԫ���ڲ�
*/


//����xml�ļ�
int writeXmlFile()
{
	TiXmlDocument* writeDoc = new TiXmlDocument;//xml�ĵ�ָ��

	//�ĵ�˵��
	TiXmlDeclaration* xmlDeclaration = new TiXmlDeclaration("1.0", "utf-8", "yes");
	writeDoc->LinkEndChild(xmlDeclaration);

	//��Ԫ��
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

	//TiXmlDocument *writeDoc = new TiXmlDocument;//xml�ĵ�ָ��

	////�ĵ���ʽ˵��
	//TiXmlDeclaration* dec1 = new TiXmlDeclaration("1.0", "UFT-8", "yes");
	//writeDoc->LinkEndChild(dec1);//д���ĵ�

	//int n = 3;

	//TiXmlElement* RootElement = new TiXmlElement("Info");//��Ԫ��
	//RootElement->SetAttribute("num", n);//����
	//writeDoc->LinkEndChild(RootElement);

	//for (int i = 0; i < n; i++)
	//{
	//	TiXmlElement* stuElement = new TiXmlElement("Stu");

	//	//��������
	//	stuElement->SetAttribute("class", "A");
	//	if (2 == i)
	//	{
	//		stuElement->SetAttribute("class", "B");
	//	}

	//	stuElement->SetAttribute("id", i + 1);
	//	stuElement->SetAttribute("falg", (i + 1) * 10);
	//	RootElement->LinkEndChild(stuElement);//���ڵ�д���ĵ�

	//	//����
	//	TiXmlElement* nameElement = new TiXmlElement("name");
	//	stuElement->LinkEndChild(nameElement);

	//	TiXmlText* nameContent = new TiXmlText("mike");
	//	nameElement->LinkEndChild(nameContent);

	//	//����
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

	//�����ýڵ�
	for (TiXmlElement* stuElement = pFile->FirstChildElement(); 
		stuElement != NULL; 
		stuElement = stuElement->NextSiblingElement())
	{
		cout << stuElement->Value() << " ";
		TiXmlAttribute* pAttr = stuElement->FirstAttribute();//First Attribute

		//�����������
		while (NULL != pAttr)
		{
			cout << pAttr->Name() << ":" << pAttr->Value() << " ";
			pAttr = pAttr->Next();
		}

		//���������Ԫ�ص�ֵ
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