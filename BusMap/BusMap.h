#ifndef BUSMAP_H_INCLUDED
#define BUSMAP_H_INCLUDED
#include "Model.h"
int CountLines(const char *filename);//��ȡ��Ӧtxt�ļ�����
template<typename T>
T* realloc_p(T* a,int length);//��дrealloc����
void InitializeGraph(BusMap &g_sMap);//����ʵ�ִ���ͼ,��ʼ��������ͼ����

int FindBus(string bus);//���ҿ��й����������ڷ����������ţ������ڷ���-1
int FindStation(string station);//���ҿ���վ�������ڷ����������ţ������ڷ���-1

int GetBus(string bus);//�õ��������,���ù��������������ù���
int GetStation(string station);//�õ�վ�����,����վ�㲻����������վ��

bool AddRoute(int Line_number, int nStart, int nEnd, int distance);//���·��

void TraverseBusRoute(string bus);//����ָ��������·
bool TraverseStationByBusRoute(int nStation,int nbus);//��Ѱ��վ���ĳ��������·,�ҵ��յ㷵��true
bool HasPath(int nStart, int nEnd, bool *visited,string *p,int index);
bool QueryRoutes(string pStart, string pEnd,string *p);//��ѯ����վ�㹫��·��
#endif // BUSMAP_H_INCLUDED
