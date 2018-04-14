#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
using namespace std;
#define SIZE 1000
char line[SIZE];

string int2str(int &x)
{
	string s;
	stringstream ss(s);
	ss<<x;
	return ss.str();
}
int compare(string s1,string s2){
	int type=0;
	if (s1==s2 && s1=="./."){type=1;}
	if (s1!=s2 && s1=="./."){type=2;}
	if (s1!=s2 && s2=="./."){type=3;}
	if (s1!="./." && s2!="./."){type=4;}
	return type;
}
int main()
{
	int count=0;
	fstream fin,fout,myfile;
	string pos_list[1076][6];
	int rst_count[4]={0,0,0,0};
	string outfile[7]={"Sample_data1.txt","output_data1.txt","csv_output_data1.csv",
						"Sample_data2.txt","output_data2.txt","csv_output_data2.csv",
						"total_csv_ouput_data.csv"};

	//Data1
	fin.open(outfile[0],ios::in);
	fout.open(outfile[1],ios::out);

	//CSV_output1 define
	myfile.open(outfile[2],ios::out);
	myfile<<"Output_data1\n";
	myfile<<"Counter,Site,pos_X,pos_Y,Bin Results\n";
	
	//regex
	string str;
	regex pattern("Head(.*)Site\((.)\)(.*)=\((.*)\,(.*)\)");
	regex pattern2("Bin(.*)");
	cout<<"================================"<<endl;
	cout<<"Data1 is loading..."<<endl;
	cout<<"================================"<<endl;
	while(fin.getline(line,sizeof(line)))
	{
		int site,x,y;
		string pos;
		str=line;
		bool match=regex_match(str,pattern);
		if(match){
			count++;
			int length=str.length();
			int index1=str.find("S",0);
			site=str[index1+5]-'0';
			int index2=str.find("=",0);
			pos=str.substr(index2+2,length-index2-4);

			/*
			for(int i=0;i<length;i++)
			{
				if(str[i]=='S'){site=str[i+5]-'0';}
				if(str[i]=='='){pos=str.substr(i+2,length-i-4);}
			}
			*/

			pos_list[count-1][0]=int2str(count);
			pos_list[count-1][1]=int2str(site);
			pos_list[count-1][2]=pos;
			cout<<count<<endl;
			//cout<<count<<"\t"<<site<<"\t"<<setw(8)<<pos;
			fout<<count<<"\t"<<site<<"\t"<<setw(8)<<pos;
			myfile<<count<<","<<site<<","<<pos;
			continue;
		}

		bool match2=regex_match(str,pattern2);
		if(match2){
			int length=str.length();
			string t1,t2;
			for(int i=0;i<length;i++)
			{
				if((str[i]=='(') && (i!=length-3)){t1=str[i+1];}
				if((str[i]==')') && (i==length-1)){t2=str[i-1];}
			}
			pos_list[count-1][3]=t1+"/"+t2;

			//cout<<"\t"<<t1<<"/"<<t2<<endl;
			fout<<"\t"<<t1<<"/"<<t2<<endl;
			myfile<<","<<t1<<"/"<<t2<<"\n";
			continue;
		}
		
	}
	fin.close();
	fout.close();
	myfile.close();
	cout<<"================================"<<endl;
	cout<<"Data1 is finished."<<endl;
	cout<<"Output file: "<<outfile[1]<<endl;
	cout<<"Output file: "<<outfile[2]<<endl;
	cout<<"================================"<<endl;

	//Data2
	fin.open(outfile[3],ios::in);
	fout.open(outfile[4],ios::out);

	//CSV_output2 define
	myfile.open(outfile[5],ios::out);
	myfile<<"Output_data2\n";
	myfile<<"Counter,Site,pos_X,pos_Y,Bin Results\n";

	cout<<"================================"<<endl;
	cout<<"Data2 is loading..."<<endl;
	cout<<"================================"<<endl;

	count=0;
	while(fin.getline(line,sizeof(line)))
	{
		int site,x,y;
		string pos;
		str=line;
		bool match=regex_match(str,pattern);
		if(match){
			count++;
			int length=str.length();
			int index1=str.find("S",0);
			site=str[index1+5]-'0';
			int index2=str.find("=",0);
			pos=str.substr(index2+2,length-index2-4);
			/*
			for(int i=0;i<length;i++)
			{
				if(str[i]=='S'){site=str[i+5]-'0';}
				if(str[i]=='='){pos=str.substr(i+2,length-i-4);}
			}
			*/
			cout<<count<<endl;
			//cout<<count<<"\t"<<site<<"\t"<<setw(8)<<pos;
			fout<<count<<"\t"<<site<<"\t"<<setw(8)<<pos;
			myfile<<count<<","<<site<<","<<pos;
			continue;
		}

		bool match2=regex_match(str,pattern2);
		if(match2){
			int length=str.length();
			int type=0;
			string t1,t2;
			for(int i=0;i<length;i++)
			{
				if((str[i]=='(') && (i!=length-3)){t1=str[i+1];}
				if((str[i]==')') && (i==length-1)){t2=str[i-1];}
			}
			pos_list[count-1][4]=t1+"/"+t2;
			//cout<<"\t"<<t1<<"/"<<t2<<endl;
			fout<<"\t"<<t1<<"/"<<t2<<endl;
			myfile<<","<<t1<<"/"<<t2<<"\n";

			//§PÂ_¬O§_ÅÜ²§
			type=compare(pos_list[count-1][3],pos_list[count-1][4]);
			if(type==1){
				rst_count[0]++;
				pos_list[count-1][5]="Pass2Pass";}
			if(type==2){
				rst_count[1]++;
				pos_list[count-1][5]="Pass2Fail";}
			if(type==3){
				rst_count[2]++;
				pos_list[count-1][5]="Fail2Pass";}
			if(type==4){
				rst_count[3]++;
				pos_list[count-1][5]="Fail2Fail";}
			continue;
		}
		
	}
	fin.close();
	fout.close();
	myfile.close();
	cout<<"================================"<<endl;
	cout<<"Data2 is finished."<<endl;
	cout<<"Output file: "<<outfile[4]<<endl;
	cout<<"Output file: "<<outfile[5]<<endl;
	cout<<"================================"<<endl;

	//CSV_output_total define
	myfile.open("total_csv_output_data.csv",ios::out);
	myfile<<"Output_data_total\n";
	myfile<<"Counter,Site,pos_X,pos_Y,Result1,Result2,Compare Results\n";
	for(int i=0;i<count;i++)
	{
		myfile<<pos_list[i][0]<<","<<pos_list[i][1]<<","
			<<pos_list[i][2]<<","<<pos_list[i][3]<<","
			<<pos_list[i][4]<<","<<pos_list[i][5]<<"\n";
	}

	myfile<<"Pass2Pass,"<<rst_count[0]<<"\n";
	myfile<<"Pass2Fail,"<<rst_count[1]<<"\n";
	myfile<<"Fail2Pass,"<<rst_count[2]<<"\n";
	myfile<<"Fail2Fail,"<<rst_count[3]<<"\n";
	myfile.close();
	cout<<"Output file: "<<outfile[6]<<endl;

	return 0;
}