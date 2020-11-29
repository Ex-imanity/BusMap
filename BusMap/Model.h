#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED
#include<string>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<windows.h>
using namespace std;
typedef struct Bus
{
	string name;//������
	int Start;//��ʼվ��
	int End;//�յ�վ��
}Bus;
typedef struct Station
{
	string name;//վ����
	struct Route* routes;//�ڽӾ��󣬸�վ������������·�����ڽӵ�
}Station;
typedef struct Route
{
    int bus;//�������
    int station;//վ����
	int distance;//��վ�����
	bool *visited;
	struct Route *next;//��һ����
}Route;
typedef struct BusMap
{
	Bus* buses;//������·����,ֻ�������й��������Լ�������·��ʼվ���յ�վ����������������·
	Station* stations;//վ������,��������վ�����Լ���վ�������Ĺ�����·
	int station_num;//վ����
	int bus_num;//������
	int route_num;//����
}BusMap;
#endif //MODEL_H_INCLUDE

