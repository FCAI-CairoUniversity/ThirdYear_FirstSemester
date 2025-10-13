#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

/*
Practise:
	Let the user enters how many persons he want to add to the file “student.txt”.
	Then he enters persons details (name,age) and save them in the file as a string and an integer.
	Note: takes input from user using “cin>>a”.
*/

class person
{
public:
	string name;
	int age;
};

void practiceB()
{
	fstream inputfile;
	inputfile.open("persons.txt",ios::in);
	vector<person> list;
	string nm; int age;
	
	while(true)
	{
		inputfile>>nm;
		if(inputfile.fail()) break;
		inputfile>>age;
		if(inputfile.fail()) break;
		person p; p.name=nm; p.age=age;
		list.push_back(p);
	}
	inputfile.close();

	person max,min;
	max=list[0]; 
	min=list[0];
	for(int i=1;i<list.size();i++)
	{
		if(list[i].age>max.age) max=list[i];
		else if(list[i].age<min.age) min=list[i];
	}

	fstream outpufile;
	outpufile.open("result.txt",ios::out);
	outpufile<<"min : "<<min.name<<","<<min.age<<endl;
	outpufile<<"max : "<<max.name<<","<<max.age<<endl;
	outpufile.close();
}

void practiceA()
{
	int size;
	string nm;
	int age;
	cout<<"How many persons : ";
	cin>>size;
	fstream outpufile;
	outpufile.open("persons.txt",ios::out);
	for(int i=0;i<size;i++){
		cout<<"Enter name and age of person "<<(i+1)<<" : ";
		cin>>nm>>age;
		outpufile<<nm<<" "<<age<<" ";
	}
	outpufile.close();
}

int main(){
	fstream outpufile;
	outpufile.open("data.txt",ios::out);
	string str = "hello files world\n";
	outpufile<<str;
	
	outpufile.close();

	fstream inputfile;
	inputfile.open("data.txt",ios::in);

	char letter;
	inputfile.unsetf(ios::skipws);
	while(true)
	{
		
		inputfile>>letter;
		if(inputfile.fail()) break;
		
		cout<<letter;
	}

	//practiceA();
	practiceB();

	system("pause");
}
