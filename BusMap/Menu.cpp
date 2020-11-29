#include "Menu.h"
extern BusMap g_sMap;
//Menu��Ľ��溯��
void gotoxy(int x, int y) //���꺯��
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void HideCursor(int n) /*���ع��*/
{
    CONSOLE_CURSOR_INFO cursor_info={1,n};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void LoginScreen()//��������
{
    int i,j,k;
    HideCursor(0);
    for(i=0;i<=27;i++)
    {
        cout<<Login[i]<<endl;
        Sleep(100);
    }
    for (k=1;k<=2;k++)//��̬����
    {
        for (i = 31; i <= 66; i = i + 2)
        {
            for (j = i - 4; j <= i; j = j + 2)
            {
                if (j >= 31 && j <= 65)
                {
                    gotoxy(j,21);
                    cout<<"[]";
                }
                Sleep(100);
            }
            for (j = i - 4; j <= i; j = j + 2)
            {
                if (j >= 31 && j <= 65)
                {
                    gotoxy(j, 21);
                    cout<<"  ";
                }
            }
        }
    }
    system("cls");
    gotoxy(0,0);
    HideCursor(1);
    MainMenu();
}
void Shutdown()//�ػ�����
{
    system("cls");
    gotoxy(0,0);
    HideCursor(0);
    for(int i=0;i<=12;i++)
    {
        cout<<Shut[i]<<endl;
        Sleep(100);
    }
    for (int i=1;i<=4;i++)//��̬����
    {
        gotoxy(49,12);
        for(int j=1;j<=4;j++)
        {
            cout<<".";
            Sleep(300);
        }
        for(int k=4;k>=0;k--)
        {
            gotoxy(49+k,12);
            cout<<" ";
        }
    }
    system("cls");
    exit(-1);
}
void MainMenu()//���˵�
{
    while(1)
    {
        int num;
        cout<<" ===========================  ��ӭʹ�ù�������ϵͳ!  ==========================="<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<"|                                0.�ػ�                                         |"<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<"|                                1.����Ա��¼                                   |"<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<"|                                2.�˿͵�¼                                     |"<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<" =============================================================================== "<<endl;
        do
        {
             cout<<"������Ҫʹ�õĹ���(����>>0/1/2>>):";
             cin>>num;
        }while(num>2||num<0);
        switch(num)
        {
            case 0:
                {
                    system("cls");
                    Shutdown();
                    break;
                }
            case 1:
                {
                    system("cls");
                    LoginScreeForAdministrator();
                    break;
                }
            case 2:
                {
                    system("cls");
                    MenuForCustomer();
                    break;
                }
        }
        system("cls");
    }
}
void LoginScreeForAdministrator()//����Ա��¼����
{
    string Administrator,Password;
    string administrator,password;
    int count=0;
    ifstream i;
    i.open("ADandPA.txt",ios::in); //��ȡADandPa.txt�ļ��б�����û���������
    i>>Administrator;
    i>>Password;
    i.close();
    do
    {
        system("cls");
        cout<<"------------------------   ��ã����¼  ------------------------"<<endl;
        cout<<endl;
        cout<<"               ------------------------------"<<endl;
        cout<<"       �û���:                                 "<<endl;
        cout<<"               ------------------------------"<<endl;
        cout<<"       ��  ��:                                 "<<endl;
        cout<<"               ------------------------------"<<endl;
        cout<<"                 (�û����������ʼ��ΪAdmin)   "<<endl;
        cout<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        gotoxy(15,3);
        cin>>administrator;
        gotoxy(15,5);
        cin>>password;
        cout<<endl;
        ++count;
        if(count==5)
        {
            break;
        }
        gotoxy(0,11);
        if(administrator==Administrator&&password!=Password)
        {
            cout<<"       �����û�����ȷ,����������㻹��"<<5-count<<"�λ���"<<endl;
        }
        else if(administrator!=Administrator)
        {
            cout<<"       �û��������㻹��"<<5-count<<"�λ���"<<endl;
        }
        else
        {
            cout<<"       �û�����������ȷ��"<<endl;
        }
        cout<<endl;
        system("pause");
    }while(administrator!=Administrator||password!=Password);
    if(count<5)
    {
        MenuForAdministrator();
    }
}
void MenuForAdministrator() //����Ա�˵�
{
        int num;
        system("cls");
        cout<<"------------------  ����Ա,��ã� ------------------"<<endl;
        cout<<endl;
        cout<<"       1.�鿴�������й���"<<endl;
        cout<<"       2.�鿴��������վ��"<<endl;
        cout<<"       3.��ѯ����ĳ����������·"<<endl;
        cout<<"       4.��ѯ����ĳվ�������Ϣ"<<endl;
        cout<<"       5.������ӡ�ɾ�����޸�"<<endl;
        cout<<"       6.վ����ӡ�ɾ�����޸�"<<endl;
        cout<<"       7.�޸��û���������"<<endl;
        cout<<"       8.�������˵�"<<endl;
        cout<<endl;
        cout<<"----------------------------------------------------"<<endl;
        do
        {
            cout<<"��������Ҫʹ�õĹ���:";
            cin>>num;
        }while(num>8||num<1);
        system("cls");
        switch(num)
        {
        case 1:
            {
                OutPutAllBusName();
                system("pause");
                MenuForAdministrator();
                break;
            }
        case 2:
            {
                OutPutAllStationName();
                system("pause");
                MenuForAdministrator();
                break;
            }
        case 3:
            {
                OutPutBusRoute();
                system("pause");
                MenuForAdministrator();
                break;
            }
        case 4:
            {
                OutPutStationInf();
                system("pause");
                MenuForAdministrator();
                break;
            }
        case 5:
            {
                MenuForBus();
                MenuForAdministrator();
                break;
            }
        case 6:
            {
                MenuForStation();
                MenuForAdministrator();
                break;
            }
        case 7:
            {
                ChangeInfo();
                system("pause");
                MenuForAdministrator();
                break;
            }
        case 8:
            {
                MainMenu();
                break;
            }
        }
}
void OutPutAllBusName()//����������й�����������յ�
{
    cout<<"���й���"<<g_sMap.bus_num<<"������,����:"<<endl;
    for(int i=0;i<g_sMap.bus_num;i++)
    {
            cout<<g_sMap.buses[i].name<<"   ���:"<<g_sMap.stations[g_sMap.buses[i].Start].name<<"   �յ�:"<<g_sMap.stations[g_sMap.buses[i].End].name<<endl;
    }
    cout<<endl;
}
void OutPutAllStationName()//�����������վ������
{
    cout<<"���й���"<<g_sMap.station_num<<"��վ��,����:"<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
            cout<<g_sMap.stations[i].name<<endl;
    }
    cout<<endl;
}
void MenuForBus()//������������
{
    system("cls");
    int num;
    cout<<"-----------------------"<<endl;
    cout<<endl;
    cout<<"  1.��ӹ���·��"<<endl;
    cout<<"  2.ɾ������·��"<<endl;
    cout<<"  3.�޸Ĺ�����Ϣ"<<endl;
    cout<<"  4.���ع���Ա�˵�"<<endl;
    cout<<endl;
    cout<<"-----------------------"<<endl;
    do
    {
        cout<<"������Ҫʹ�ù���:";
        cin>>num;
    }while(num>4||num<1);
    system("cls");
    if(num!=4)
    {
        switch(num)
        {
            case 1:
                {
                    AddBus();
                    system("pause");
                    MenuForBus();
                    break;
                }
            case 2:
                {
                    DeleteBus();
                    system("pause");
                    MenuForBus();
                    break;
                }
            case 3:
                {
                    ChangeBusInfo();
                    system("pause");
                    MenuForBus();
                    break;
                }
        }
    }
}
void AddBus()//������С����й���(����������㣬�յ�)
{
    string upBus,downBus;
    string BusName;
    do
    {
        system("cls");
        cout<<"Tip:�ù����������ӹ�����,������·."<<endl;
        cout<<endl;
        OutPutAllBusName();
        cout<<endl;
        cout<<"����������(����):"<<endl;
        cout<<endl;
        cout<<"�������������й�������վ��(����#����):"<<endl;
        gotoxy(17,5+g_sMap.bus_num);
        cin>>BusName;
    }while(FindBus(BusName+"����")!=-1);
    upBus=BusName+"����";
    downBus=BusName+"����";
    int nBusUp=GetBus(upBus);
    int nBusDown=GetBus(downBus);
    gotoxy(0,6+g_sMap.bus_num);
    vector<string> station;
    string temp;
    while(cin>>temp&&temp!="#")
    {
        station.push_back(temp);
    }
    int Distance[station.size()];
    for(int i=1;i<station.size();i++)
    {
        cout<<"������ "<<station[i-1]<<" �� "<<station[i]<<" ��վ��ľ���:";
        cin>>Distance[i];
    }
    int index[station.size()];
    for(int i=0;i<station.size();i++)
    {
        if(FindStation(station[i])==-1)//��վ��д��Stations.txt�ļ�
        {
            index[i]=GetStation(station[i]);//�����ռ�
            ofstream out;
            out.open("Stations.txt",ios::app);
            out<<station[i]<<endl;
            out.close();
        }
        else
        {
            index[i]=FindStation(station[i]);
        }
    }
    //��������������Buses.txt�ļ�
    ofstream out;
    out.open("Buses.txt",ios::app);
    out<<upBus<<endl;
    out<<index[0]<<endl;
    out<<index[station.size()-1]<<endl;
    out<<downBus<<endl;
    out<<index[station.size()-1]<<endl;
    out<<index[0]<<endl;
    out.close();
    //��·��д��Routes.txt�ļ�
    ofstream outR;
    outR.open("Routes.txt",ios::app);
    for(int i=0;i<station.size()-1;i++)//����
    {
        outR<<nBusUp<<"     "<<index[i]<<"     "<<index[i+1]<<"     "<<Distance[i+1]<<endl;
    }
    for(int i=station.size()-1;i>=1;i--)//����
    {
        outR<<nBusDown<<"     "<<index[i]<<"     "<<index[i-1]<<"     "<<Distance[i]<<endl;
    }
    outR.close();
    station.clear();
    InitializeGraph(g_sMap);//�����ļ��ٴγ�ʼ��g_sMap;
}
void DeleteBus()//ɾ������
{
    cout<<"Tip:�˺���ɾ��������·,**����/**����,һ��ɾ������,**����/**����Ϊ����"<<endl;
    cout<<endl;
    OutPutAllBusName();
    cout<<endl;
    string BusName;
    do
    {
        cout<<"������Ҫɾ���Ĺ�����(**����/**����):";
        cin>>BusName;
    }while(FindBus(BusName)==-1);
    int index=FindBus(BusName);
    //�޸�Buses.txt�ļ�
    string Temp;
    int t;
    if(index%2==0)//���й���
    {
        Temp=g_sMap.buses[index+1].name;
        t=index+1;
    }
    else//���й���
    {
        Temp=g_sMap.buses[index-1].name;
        t=index-1;
    }
    string B;
    int S,E;
    fstream Bfile("Buses.txt");
    ofstream Btempfile("temp.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        Bfile>>B>>S>>E;
        if(B!=BusName&&B!=Temp)
        {
            Btempfile<<B<<endl;
            Btempfile<<S<<endl;
            Btempfile<<E<<endl;
        }
    }
    Btempfile.close();
    Bfile.close();
    ofstream Boutfile("Buses.txt",ios::out|ios::trunc);
    fstream Binfile("temp.txt");
    for(int i=0;i<g_sMap.bus_num-2;i++)
    {
        Binfile>>B>>S>>E;
        Boutfile<<B<<endl;
        Boutfile<<S<<endl;
        Boutfile<<E<<endl;
    }
    Boutfile.close();
    Binfile.close();
    //�޸�Routes.txt�ļ�
    int L,D;
    fstream Rfile("Routes.txt");
    ofstream Rtempfile("temp.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.route_num;i++)
    {
        Rfile>>L>>S>>E>>D;
        if(L!=index&&L!=t)
        {
            Rtempfile<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
        }
    }
    Rtempfile.close();
    Rfile.close();
    ofstream Routfile("Routes.txt",ios::out|ios::trunc);
    fstream Rinfile("temp.txt");
    while(!Rinfile.eof())
    {
        Rinfile>>L>>S>>E>>D;
        Routfile<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
    }
    Routfile.close();
    Rinfile.close();
    InitializeGraph(g_sMap);//�����ļ��ٴγ�ʼ��g_sMap;
}
void ChangeBusInfo()//�޸Ĺ�����Ϣ����
{
    int num;
    cout<<"Tip:�ù��ܿ����޸Ĺ��������ƺ�(��㡢�յ�)--ͬʱ�޸�����/����."<<endl;
    cout<<endl;
    cout<<"-----------------------"<<endl;
    cout<<endl;
    cout<<"  1.�޸Ĺ�������"<<endl;
    cout<<"  2.�޸�վ����Ϣ"<<endl;
    cout<<endl;
    cout<<"-----------------------"<<endl;
    cout<<endl;
    do
    {
        cout<<"������Ҫʹ�õĹ���:";
        cin>>num;
    }while(num>2||num<1);
    cout<<endl;
    switch(num)
    {

        case 1:
            {
                ChangeBusName();
                break;
            }
        case 2:
            {
                ChangeBusStartandEnd();
                break;
            }
    }
}
void ChangeBusName()//�޸Ĺ�������
{
    string BusName;
    string NewName;
    string te;
    string a;
    string b;
    do
    {
        system("cls");
        cout<<"Tip:���빫����·���ּ���"<<endl;
        cout<<endl;
        for(int i=0;i<g_sMap.bus_num;i++)
        {
        if(i==0)
        {
            cout<<"���й���:"<<g_sMap.buses[i].name;
        }
        else
        {
            cout<<"  "<<g_sMap.buses[i].name;
        }
        }
        cout<<endl;
        cout<<endl;
        cout<<"������Ҫ�޸ĵĹ�������:"<<endl;
        cout<<endl;
        cout<<"�������µĹ�������:"<<endl;
        gotoxy(23,4);
        cin>>BusName;
        gotoxy(19,6);
        cin>>NewName;
        a=BusName+"����";
        b=NewName+"����";
        te=BusName+"����";
    }while(FindBus(a)==-1||FindBus(b)!=-1);
    cout<<endl;
    fstream in;
    ofstream outfile;
    in.open("Buses.txt");
    outfile.open("temp.txt",ios::out|ios::trunc);
    string B;
    int S,E;
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        in>>B>>S>>E;
        if(B!=a&&B!=te)
        {
            outfile<<B<<endl;
            outfile<<S<<endl;
            outfile<<E<<endl;
        }
        else
        {
            if(B==a)
            {
                outfile<<b<<endl;
                outfile<<S<<endl;
                outfile<<E<<endl;
            }
            else
            {
                outfile<<NewName+"����"<<endl;
                outfile<<S<<endl;
                outfile<<E<<endl;
            }
        }
    }
    in.close();
    outfile.close();
    ofstream out;
    fstream infile;
    out.open("Buses.txt",ios::out|ios::trunc);
    infile.open("temp.txt");
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        infile>>B>>S>>E;
        out<<B<<endl;
        out<<S<<endl;
        out<<E<<endl;
    }
    infile.close();
    out.close();
    cout<<"  �޸ĳɹ�!"<<endl;
    cout<<endl;
    InitializeGraph(g_sMap);//�����ļ��ٴγ�ʼ��g_sMap;
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        if(i==0)
        {
            cout<<"�޸ĺ���й���:"<<g_sMap.buses[i].name;
        }
        else
        {
            cout<<"  "<<g_sMap.buses[i].name;
        }
    }
    cout<<endl;
    cout<<endl;
}
void ChangeBusStartandEnd()//�޸Ĺ�����㡢�յ�
{
    string BusName;
    string Start,End;
    do
    {
        system("cls");
        cout<<"Tip:���������޸����й�����ʼ��,���빫�����ּ���,������㡢�յ������������վ��."<<endl;
        cout<<endl;
        OutPutAllBusName();
        cout<<endl;
        cout<<"������Ҫ�޸���㡢�յ�Ĺ�����:";
        cin>>BusName;
        cout<<"�����������:";
        cin>>Start;
        cout<<"���������յ�:";
        cin>>End;
    }while(FindBus(BusName+"����")==-1||FindStation(Start)==-1||FindStation(End)==-1);
    int nB=FindBus(BusName+"����");
    int s=g_sMap.buses[nB].Start;
    int e=g_sMap.buses[nB].End;
    int nS=FindStation(Start);
    int nE=FindStation(End);
    int L,S,E,D;
    //�޸�Routes.txt�ļ�
    fstream in;
    ofstream out;
    in.open("Routes.txt");
    out.open("temp.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.route_num;i++)
    {
        in>>L>>S>>E>>D;
        if(L!=nB||L!=(nB+1))
        {
            out<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
        }
        else
        {
            if(L==nB&&S==s)
            {
                out<<L<<"     "<<nS<<"     "<<E<<"     "<<D<<endl;
            }
            else if(L==nB&&E==e)
            {
                out<<L<<"     "<<S<<"     "<<nE<<"     "<<D<<endl;
            }
            else
            {
                out<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
            }
            if(L==(nB+1)&&S==e)
            {
                out<<L<<"     "<<nE<<"     "<<E<<"     "<<D<<endl;
            }
            else if(L==(nB+1)&&E==s)
            {
                out<<L<<"     "<<S<<"     "<<nS<<"     "<<D<<endl;
            }
            else
            {
                out<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
            }
        }
    }
    in.close();
    out.close();
    ofstream outr;
    fstream inr;
    inr.open("temp.txt");
    outr.open("Routes.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.route_num;i++)
    {
        inr>>L>>S>>E>>D;
        outr<<L<<"     "<<S<<"     "<<E<<"     "<<D<<endl;
    }
    inr.close();
    outr.close();
    //�޸�Buses.txt�ļ�
    fstream ins;
    ofstream outfile;
    ins.open("Buses.txt");
    outfile.open("temp.txt",ios::out|ios::trunc);
    string B;
    string up=BusName+"����";
    string down=BusName+"����";
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        ins>>B>>S>>E;
        if(B!=up&&B!=down)
        {
            outfile<<B<<endl;
            outfile<<S<<endl;
            outfile<<E<<endl;
        }
        else
        {
            if(B==up)
            {
                outfile<<B<<endl;
                outfile<<nS<<endl;
                outfile<<nE<<endl;
            }
            else
            {
                outfile<<B<<endl;
                outfile<<nE<<endl;
                outfile<<nS<<endl;
            }
        }
    }
    ins.close();
    outfile.close();
    ofstream outt;
    fstream infile;
    outt.open("Buses.txt",ios::out|ios::trunc);
    infile.open("temp.txt");
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        infile>>B>>S>>E;
        outt<<B<<endl;
        outt<<S<<endl;
        outt<<E<<endl;
    }
    infile.close();
    outt.close();
    InitializeGraph(g_sMap);
    OutPutAllBusName();
    cout<<endl;
}
void MenuForStation()//����վ�����
{
    int num;
    cout<<"-----------------------"<<endl;
    cout<<endl;
    cout<<"  1.���վ��"<<endl;
    cout<<"  2.ɾ��վ��"<<endl;
    cout<<"  3.�޸�վ����Ϣ"<<endl;
    cout<<"  4.���ع���Ա�˵�"<<endl;
    cout<<endl;
    cout<<"-----------------------"<<endl;
    do
    {
        cout<<"������Ҫʹ�ù���:";
        cin>>num;
    }while(num>4||num<1);
    system("cls");
    if(num!=4)
    {
        switch(num)
        {
            case 1:
                {
                    AddStation();
                    system("pause");
                    MenuForStation();
                    break;
                }
            case 2:
                {
                    DeleteStation();
                    system("pause");
                    MenuForStation();
                    break;
                }
            case 3:
                {
                    ChangeStationInfo();
                    system("pause");
                    MenuForStation();
                    break;
                }
        }
    }
}
void AddStation()//���վ��
{
    cout<<"Tip:�ù�������Station�����������վ��."<<endl;
    cout<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        if(i==0)
            cout<<"��ǰ����վ��:"<<g_sMap.stations[i].name;
        else
            cout<<"  "<<g_sMap.stations[i].name;
    }
    cout<<endl;
    cout<<endl;
    string StationName;
    do
    {
        cout<<"������Ҫ��ӵ��µ�վ��:";
        cin>>StationName;
    }while(FindStation(StationName)!=-1);
    int n=GetStation(StationName);
    ofstream out;
    out.open("Stations.txt",ios::app);
    out<<StationName<<endl;
    out.close();
    cout<<endl;
    cout<<"   ��ӳɹ�!"<<endl;
    cout<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        if(i==0)
            cout<<"��ǰ����վ��:"<<g_sMap.stations[i].name;
        else
            cout<<"  "<<g_sMap.stations[i].name;
    }
    cout<<endl;
}
void DeleteStation()//ɾ��վ��
{
    cout<<"Tip:�ù�������Station������ɾ������վ��."<<endl;
    cout<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        if(i==0)
            cout<<"��ǰ����վ��:"<<g_sMap.stations[i].name;
        else
            cout<<"  "<<g_sMap.stations[i].name;
    }
    cout<<endl;
    cout<<endl;
    string StationName;
    do
    {
        cout<<"������Ҫɾ��������վ��:";
        cin>>StationName;
    }while(FindStation(StationName)==-1);
    string te;
    fstream in;
    ofstream out;
    in.open("Stations.txt");
    out.open("temp.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.station_num;i++)
    {
        in>>te;
        if(te!=StationName)
        {
            out<<te<<endl;
        }
    }
    in.close();
    out.close();
    fstream inr;
    inr.open("temp.txt");
    ofstream outr;
    outr.open("Stations.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.station_num-1;i++)
    {
        inr>>te;
        outr<<te<<endl;
    }
    inr.close();
    outr.close();
    cout<<endl;
    cout<<"   ɾ���ɹ�!"<<endl;
    cout<<endl;
    InitializeGraph(g_sMap);
    for(int i=0;i<g_sMap.station_num;i++)
    {
        if(i==0)
            cout<<"ɾ�������վ��:"<<g_sMap.stations[i].name;
        else
            cout<<"  "<<g_sMap.stations[i].name;
    }
    cout<<endl;
}
void ChangeStationInfo()//�ı�վ������
{
    string StationName;
    string NewName;
    do
    {
        system("cls");
        cout<<"Tip:�ù�������Station�������޸�վ��."<<endl;
        cout<<endl;
        for(int i=0;i<g_sMap.station_num;i++)
        {
            if(i==0)
                cout<<"��ǰ����վ��:"<<g_sMap.stations[i].name;
            else
                cout<<"  "<<g_sMap.stations[i].name;
        }
        cout<<endl;
        cout<<endl;
        cout<<"������Ҫ�޸ĵ�վ��:"<<endl;;
        cout<<endl;
        cout<<"����������:"<<endl;
        gotoxy(19,4);
        cin>>StationName;
        gotoxy(11,6);
        cin>>NewName;
    }while(FindStation(StationName)==-1||FindStation(NewName)!=-1);
    int index=FindStation(StationName);
    fstream in;
    ofstream out;
    in.open("Stations.txt");
    out.open("temp.txt",ios::out|ios::trunc);
    string te;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        in>>te;
        if(te!=StationName)
        {
            out<<te<<endl;
        }
        else
        {
            out<<NewName<<endl;
        }
    }
    in.close();
    out.close();
    fstream inr;
    ofstream outr;
    inr.open("temp.txt");
    outr.open("Stations.txt",ios::out|ios::trunc);
    for(int i=0;i<g_sMap.station_num;i++)
    {
        inr>>te;
        outr<<te<<endl;
    }
    inr.close();
    outr.close();
    cout<<endl;
    cout<<"    �޸ĳɹ�!"<<endl;
    g_sMap.stations[index].name=NewName;
    cout<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        if(i==0)
            cout<<"��ǰ����վ��:"<<g_sMap.stations[i].name;
        else
            cout<<"  "<<g_sMap.stations[i].name;
    }
    cout<<endl;
}
void ChangeInfo()//����Ա�˻���������ĺ���
{
    string Administrator,Password;
    ifstream change;
    change.open("ADandPA.txt",ios::in);
    change>>Administrator;
    change>>Password;
    change.close();
    cout<<"Tip:�ù������޸Ĺ���Ա�˺�����,�޸ĺ����ñ���!"<<endl;
    cout<<endl;
    cout<<"��ǰ�û���:"<<Administrator<<"   ��ǰ����:"<<Password<<endl;
    ofstream out;
    out.open("ADandPA.txt",ios::trunc);
    cout<<endl;
    cout<<"�������µ��û���:"<<endl;
    cout<<"�������µ�����:"<<endl;
    gotoxy(17,4);
    cin>>Administrator;
    gotoxy(15,5);
    cin>>Password;
    out<<Administrator<<endl;
    out<<Password<<endl;
    out.close();
    cout<<endl;
    cout<<endl;
    cout<<"�����û���������ɹ���"<<endl;
    cout<<endl;
}
void MenuForCustomer()
{
    system("cls");
    int num;
    cout<<"------------------  �˿�,��ã� ------------------"<<endl;
    cout<<endl;
    cout<<"--------     ��ӭʹ�ñ��й�������ϵͳ     --------"<<endl;
    cout<<endl;
    cout<<"       1.��ѯ�������й���"<<endl;
    cout<<"       2.��ѯ��������վ��"<<endl;
    cout<<"       3.��ѯ����ĳ����������·"<<endl;
    cout<<"       4.��ѯ����ĳվ�������Ϣ"<<endl;
    cout<<"       5.��ѯ������վ����οɴ�(��໻��1��)"<<endl;
    cout<<"       6.�������˵�"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    do
    {
        cout<<"��������Ҫʹ�õĹ���(����):";
        cin>>num;
    }while(num>5||num<1);
    system("cls");
    switch(num)
    {
        case 1:
            {
                OutPutAllBusName();
                system("pause");
                MenuForCustomer();
                break;
            }
        case 2:
            {
                OutPutAllStationName();
                system("pause");
                MenuForCustomer();
                break;
            }
        case 3:
            {
                OutPutBusRoute();
                system("pause");
                MenuForCustomer();
                break;
            }
        case 4:
            {
                OutPutStationInf();
                system("pause");
                MenuForCustomer();
                break;
            }
        case 5:
            {
                SearchRoute();
                system("pause");
                MenuForCustomer();
                break;
            }
        case 6:
            {
                MainMenu();
                break;
            }
    }
}
void OutPutBusRoute()
{
    string BusName;
    cout<<"��ǰ���еĹ�����·��:";
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        if(i==0)
            cout<<g_sMap.buses[0].name;
        else
            cout<<" "<<g_sMap.buses[i].name;
    }
    cout<<endl;
    do
    {
        cout<<"������Ҫ��ѯ�Ĺ�����·(����):";
        cin>>BusName;
    }while(FindBus(BusName)==-1);
    TraverseBusRoute(BusName);
}
void OutPutStationInf()   //�����վ��������������·
{
    string StationName;
    cout<<"��ǰ���е�վ����:"<<endl;
    for(int i=0;i<g_sMap.station_num;i++)
    {
        cout<<g_sMap.stations[i].name<<endl;
    }
    cout<<endl;
    do
    {
        cout<<"������Ҫ��ѯ��վ��:";
        cin>>StationName;
    }while(FindStation(StationName)==-1);
    int nStation=FindStation(StationName);
    Route *temp=g_sMap.stations[nStation].routes;
    int count=0;
    while(temp!=NULL)
    {
        ++count;
        cout<<g_sMap.buses[temp->bus].name<<"    ������һվ:"<<g_sMap.stations[temp->station].name<<"    ����:"<<temp->distance<<"���ף�    �����յ�վ:"<<g_sMap.stations[g_sMap.buses[temp->bus].End].name<<endl;
        temp=temp->next;
    }
    cout<<endl;
    int flag=-1;
    for(int i=0;i<g_sMap.bus_num;i++)
    {
        if(g_sMap.buses[i].End==nStation)
        {
            flag=i;
            break;
        }
    }
    if(flag==-1)
        cout<<"��վ�㹲��"<<count<<"����·����"<<endl;
    else
    {
        cout<<"��վ����"<<g_sMap.buses[flag].name<<"���յ�վ"<<endl;
        cout<<endl;
        cout<<"��վ�㹲��"<<count+1<<"����·����"<<endl;
    }
}
void SearchRoute()//�����û�������㡢�յ��ж��Ƿ���·�������������
{
    string stationStart,stationEnd;
    int stationS,stationE;
    do
    {
        system("cls");
        cout<<"��ǰ���е�վ����:"<<endl;
        for(int i=0;i<g_sMap.station_num;i++)
        {
            cout<<g_sMap.stations[i].name<<endl;
        }
        cout<<endl;
        cout<<"������Ҫ��ѯ�����:"<<endl;
        cout<<"������Ҫ��ѯ���յ�:"<<endl;
        gotoxy(19,g_sMap.station_num+2);
        cin>>stationStart;
        gotoxy(19,g_sMap.station_num+3);
        cin>>stationEnd;
        stationS=FindStation(stationStart);
        stationE=FindStation(stationEnd);
        if(stationS==-1||stationE==-1)
        {
            cout<<"����վ���ڿ��в�����"<<endl;
        }
    }while(FindStation(stationStart)==-1||FindStation(stationEnd)==-1);
    if(stationS==stationE)
    {
            cout<<"������㡢�յ�һ��,�����ѯ."<<endl;
    }
    else
    {
        string Path[10];
        bool Has=QueryRoutes(stationStart,stationEnd,Path);
        if(Has)
        {
            for(int i=0;Path[i]!=stationEnd;i++)
            {
                if(i==0)
                   cout<<Path[i];
                else
                    cout<<"--->>"<<Path[i];
            }
            cout<<"--->>"<<stationEnd<<endl;
        }
        else
        {
            cout<<"δ���ҵ���"<<stationStart<<"��"<<stationEnd<<"��·��."<<endl;
        }
    }
}

