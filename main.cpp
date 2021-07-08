#include<bits/stdc++.h>
#include"first.h"
using namespace std;
ostream& operator <<(ostream& out, carag &p)
{
    out<<p.type<<"|"<<p.model<<"|"<<p.color<<"|"<<p.price<<"|"<<p.maximumspeed<<"|"<<p.id<<"\n";
    return out;
}
//cin>>obj;
//operator >>(cin,obj)
istream& operator >>(istream& in, carag &p)
{
    in.ignore();
    cout<<"enter type:";
    getline(in,p.type);
    cout<<"enter model:";
    getline(in,p.model);
    cout<<"enter color:";
    getline(in,p.color);
    cout<<"enter price:";
    getline(in,p.price);
    cout<<"enter maximum speed:";
    getline(in,p.maximumspeed);
    cout<<"enter id:";
    getline(in,p.id);
    return in;
}



class fileoperation: public carag
{
private :
    carag split(string line)
    {
        carag ret;
        string token;
        stringstream ss(line);
        getline(ss,token,'|');
        ret.settype(token);
        getline(ss,token,'|');
        ret.setmodel(token);
        getline(ss,token,'|');
        ret.setcolor(token);
        getline(ss,token,'|');
        ret.setprice(token);
        getline(ss,token,'|');
        ret.setmaximumspeed(token);
        getline(ss,token);
        ret.setid(token);
        return ret;
    }
public:
    void write()
    {
        carag obj;
         cin>>obj;
        //write in file
        ofstream file("carag.txt",ios::app);
        file<<obj;
        file.close();
    }

    void read()
    {
        cout.setf(ios::left);
        cout<<setw(10)<<"type"<<setw(5)<<"model"<<setw(10)<<"color"<<setw(20)<<"price"<<setw(20)<<"maximum speed"<<setw(5)<<"id"<<setw(10)<<endl;
        ifstream file("carag.txt");
        string line;
        carag obj;
        while(getline(file,line))
        {
            obj=split(line);
            cout<<setw(10)<<obj.gettype()<<setw(5)<<obj.getmodel()<<setw(10)<<obj.getcolor()<<setw(20)<<obj.getprice()<<setw(20)<<obj.getmaximumspeed()<<setw(5)<<obj.getid()<<setw(10)<<endl;
        }
    }

    	bool search(string Sid){
			ifstream file("carag.txt");
			string line;  carag obj;
			while(getline(file,line)){
				obj =split(line);
				if(obj.getid()==Sid){
						cout<<"Data Found\n";
						cout<<"type :"<<obj.gettype()<<endl;
						cout<<"model :"<<obj.getmodel()<<endl;
						cout<<"color :"<<obj.getcolor()<<endl;
						cout<<"price :"<<obj.getprice()<<endl;
						cout<<"maximum speed :"<<obj.getmaximumspeed()<<endl;
						cout<<"id :"<<obj.getid()<<endl;
						return true;
				}
			}
			return false;
	}

    void update(string Sid)
    {
        fstream file("carag.txt",ios::in);
        carag a[100];
        int idx=0;
        string line;
        carag obj;
        while(getline(file,line))
        {
            obj=split(line);
            if(obj.getid()==Sid)
            {
                //read form user
                cin>>obj;
                a[idx++]=obj;
            }
            else
            {
                a[idx++]=obj;
            }
        }
        file.close();
        file.open("carag.txt",ios::out);
        for(int i=0 ; i <idx ; ++i)
        {
            file<<a[i];
        }
    }

//delete
    void dlt(string Sid)
    {
        fstream file("carag.txt",ios::in);
        carag a[100];
        int idx=0;
        string line;
        carag obj;
        while(getline(file,line))
        {
            obj=split(line);
            if(obj.getid()!=Sid)
            {
                a[idx++]=obj;
            }
        }
        file.close();
        file.open("carag.txt",ios::out);
        for(int i=0 ; i <idx ; ++i)
        {
            file<<a[i];
        }
    }
};
int main()
{
    fileoperation a;
    bool flag=1;
    while(flag)
    {
        cout<<"\n\t\t\tWelcome to Car Agency ^_^\n\n \n -To insert Press (1)\n -To display data Press (2)\n -To search Press (3)\n -To update Press (4)\n -To delete Press (5)\n -To exit press (6)\n\n  \t\tEnter your choice :";
        int x;
        cin>>x;
        string s;
        switch (x)
        {
        case 1:
            a.write();
            break;
        case 2:
            a.read();
            break;
        case 3:
            cout<<"Enter id to Search: ";
            cin>>s;
            a.search(s);
            break;
        case 4:
            cout<<"Enter id to update: ";
            cin>>s;
            a.update(s);
            break;
        case 5:
            cout<<"Enter id to delete: ";
            cin>>s;
            a.dlt(s);
            break;
        default:
            return 0;
        }
        cout<<"press 1 to continue .. \npress 0 to exit\n -->";
        cin>>flag;
        system("clear");
    }
}
