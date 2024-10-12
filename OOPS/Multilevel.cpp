#include<iostream>
using namespace std;

class Student
{
	int rn;
	char name[25];
	public:
		void getdata(){
			cout<<"\n Enter Roll no:";
			cin>>rn;
			
			cout<<"\nEnter Student Name:";
			cin>>name;
		}
		void putdata(){
			cout<<"\****Student Details****";
			cout<<"\n-----------";
			cout<<"\n Roll No:"<<rn;
			cout<<"\n Student Name:"<<name<<endl;
		cout<<endl;
		}
};

class StudentExam:public Student{
	public:
		int s1,s2,s3,s4,s5,s6;
		float per;
		public:
			void accept_data(){
				getdata();
				cout<<"\n Enter marks of subject 1";
				cout<<s1;
				cout<<"\n Enter marks of subject 2";
				cout<<s2;
				cout<<"\n Enter marks of subject 3";
				cout<<s3;
				cout<<"\n Enter marks of subject 4";
				cout<<s4;
				cout<<"\n Enter marks of subject 5";
				cout<<s5;
				cout<<"\n Enter marks of subject 6";
				cout<<s6;
			
			}
			void dispaly_data(){
				putdata();
				cout<<"\n Marks Of Subject 1"<<s1;
				cout<<"\n Marks Of Subject 1"<<s2;
				cout<<"\n Marks Of Subject 1"<<s3;
				cout<<"\n Marks Of Subject 1"<<s4;
				cout<<"\n Marks Of Subject 1"<<s5;
				cout<<"\n Marks Of Subject 1"<<s6;
				
			}
};
class StudentResult:public StudentExam{
	public:
		void calculate(){
			per=(s1+s2+s3+s4+s5+s6)/6.0;
			cout<<"\n\n Total Percentage::"<<per;
			cout<<"\n-----------"
		}
};
int main(){
	StudentResult str;
	int cnt,i;
	cout<<"\n Enter No.of Student you want?::";
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		str.accept_data();
		str.display_data();
		str.calculate();
	}
	return 0;
	}
}
