#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

struct Member {
	int id;
	char nameTeam[30];
	char name[30];
	char surname[30];
	char patronymic[30];
	bool isCapitan;
	bool isMedal;
	int age;
};

int countMembers() {
	ifstream file("members.txt");
	if (file.is_open())
	{
		int temp = 0;
		char buffer[1000];

		while (!file.eof()) {
			file.getline(buffer, sizeof buffer);
			temp++;
		}
		file.close();
		int n = temp / 9;
		return n;
	}
	else return 0;
}

void addMember() {
	cout << "--Creating a new Members for Team!--\n";
	Member member;
	cout << "Add your number in team: ";
	cin >> member.id;
	cout << "Add your name team: ";
	cin >> member.nameTeam;
	cout << "Add your Name: ";
	cin >> member.name;
	cout << "Add your Surname: ";
	cin >> member.surname;
	cout << "Add your Patronymic: ";
	cin >> member.patronymic;
	cout << "Are you capitan of Team?\n\t0 - No\t1 - Yes: ";
	cin >> member.isCapitan;
	cout << "Do you have a medal?\n\t0 - No\t1 - Yes: ";
	cin >> member.isMedal;
	cout << "Add your age: ";
	cin >> member.age;
	cout << "\n";

	ofstream oFile;
	oFile.open("members.txt", ios::app);

	ifstream iFile("members.txt");
	if (!oFile.is_open() || !iFile.is_open()) cout << "Error saving!";
	else {
		bool isEmpty = iFile.peek() == EOF;
		if (!isEmpty) oFile << "\n";

		oFile << member.id << "\n"
			<< member.nameTeam << "\n"
			<< member.name << "\n"
			<< member.surname << "\n"
			<< member.patronymic << "\n"
			<< member.isCapitan << "\n"
			<< member.isMedal << "\n"
			<< member.age << "\n";

		oFile.close();
		cout << "New Member saved in File!\n";
	}

}

void displayYoung() {
	ifstream file("members.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countMembers();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			cout << "List who age less 18!\n";
			Member* member = new Member[size];
			for (int i = 0; i < size; i++)
			{
				file >> member[i].id;
				file >> member[i].name;
				file >> member[i].nameTeam;
				file >> member[i].surname;
				file >> member[i].patronymic;
				file >> member[i].isCapitan;
				file >> member[i].isMedal;
				file >> member[i].age;
			}
			file.close();
			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (member[i].age < 18)
				{
					cout << "Id: " << member[i].id << "\n";
					cout << "Name team: " << member[i].nameTeam << "\n";
					cout << "Full Name: " << member[i].surname << " " << member[i].name << " " << member[i].patronymic << "\n";
					cout << "Capitan: " << (member[i].isCapitan ? "Yes" : "No") << "\n";
					cout << "Medal: " << (member[i].isMedal ? "Yes" : "No") << "\n";
					cout << "Age: " << member[i].age << "\n";
					cout << "\n\n";
					temp++;
				}
			}

			if (temp == 0) cout << "Members Not Found!\n";
			delete[] member;
		}
	}
}

void haveMedal() {
	ifstream file("members.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countMembers();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			cout << "List who have a medal!\n";
			Member* member = new Member[size];
			for (int i = 0; i < size; i++)
			{
				file >> member[i].id;
				file >> member[i].name;
				file >> member[i].nameTeam;
				file >> member[i].surname;
				file >> member[i].patronymic;
				file >> member[i].isCapitan;
				file >> member[i].isMedal;
				file >> member[i].age;
			}
			file.close();
			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (member[i].isMedal)
				{
					cout << "Id: " << member[i].id << "\n";
					cout << "Name team: " << member[i].nameTeam << "\n";
					cout << "Full Name: " << member[i].surname << " " << member[i].name << " " << member[i].patronymic << "\n";
					cout << "Capitan: " << (member[i].isCapitan ? "Yes" : "No") << "\n";
					cout << "Medal: " << (member[i].isMedal ? "Yes" : "No") << "\n";
					cout << "Age: " << member[i].age << "\n";
					cout << "\n\n";
					temp++;
				}
			}

			if (temp == 0) cout << "Members Not Found!\n";
			delete[] member;
		}
	}
}

void isCapitan() {
	ifstream file("members.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countMembers();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			cout << "List who is the Capitan!\n";
			Member* member = new Member[size];
			for (int i = 0; i < size; i++)
			{
				file >> member[i].id;
				file >> member[i].name;
				file >> member[i].nameTeam;
				file >> member[i].surname;
				file >> member[i].patronymic;
				file >> member[i].isCapitan;
				file >> member[i].isMedal;
				file >> member[i].age;
			}
			file.close();
			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (member[i].isCapitan)
				{
					cout << "Id: " << member[i].id << "\n";
					cout << "Name team: " << member[i].nameTeam << "\n";
					cout << "Full Name: " << member[i].surname << " " << member[i].name << " " << member[i].patronymic << "\n";
					cout << "Capitan: " << (member[i].isCapitan ? "Yes" : "No") << "\n";
					cout << "Medal: " << (member[i].isMedal ? "Yes" : "No") << "\n";
					cout << "Age: " << member[i].age << "\n";
					cout << "\n\n";
					temp++;
				}
			}

			if (temp == 0) cout << "Members Not Found!\n";
			delete[] member;
		}
	}
}

struct Student {
	int id;
	char name[30];
	char surname[30];
	char patronymic[30];
	bool isMan;
	int numberGroup;
	int grades[8];
};

void addStudent() {
	cout << "--Creating a new Student!--\n";
	Student student;
	cout << "Add your number in group: ";
	cin >> student.id;
	cout << "Add your Name: ";
	cin >> student.name;
	cout << "Add your Surname: ";
	cin >> student.surname;
	cout << "Add your Patronymic: ";
	cin >> student.patronymic;
	cout << "What is your gender?\n\t0 - Woman\t1 - Man: ";
	cin >> student.isMan;
	cout << "Add your number group: ";
	cin >> student.numberGroup;
	cout << "Add your all grades:\n";
	for (int i = 0; i < 8; i++) {
		cout << "\t" << i + 1 << " grade: ";
		cin >> student.grades[i];
	}

	int temp = 0;
	for (int i = 0; i < 8; i++)
		if (student.grades[i] < 3 || student.grades[i] > 5) temp++;

	if (temp == 0) {
		ofstream oFile;
		oFile.open("students.txt", ios::app);

		ifstream iFile("students.txt");
		if (!oFile.is_open() || !iFile.is_open()) cout << "Error saving!";
		else {
			bool isEmpty = iFile.peek() == EOF;
			if (!isEmpty) oFile << "\n";

			oFile << student.id << "\n"
				<< student.name << "\n"
				<< student.surname << "\n"
				<< student.patronymic << "\n"
				<< student.isMan << "\n"
				<< student.numberGroup << "\n";
			for (int i = 0; i < 8; i++) i == 7 ? oFile << student.grades[i] << "\n" : oFile << student.grades[i] << " ";

			oFile.close();
			cout << "New student saved in File!\n";
		}
	}
	else cout << "Grade with 0 cannot be saved in File!\n";
}

int countStudents() {
	ifstream file("students.txt");
	if (file.is_open())
	{
		int temp = 0;
		char buffer[1000];

		while (!file.eof()) {
			file.getline(buffer, sizeof buffer);
			temp++;
		}
		file.close();
		int n = temp / 8;
		return n;
	}
	else return 0;
}

void displayStudents() {
	ifstream file("students.txt");

	if (!file.is_open()) cout << "File error opening!\n";

	else {
		int temp;
		temp = countStudents();
		if (temp == 0) cout << "The File is Empty!\n";
		else {
			char buffer[1000];

			while (!file.eof()) {
				file.getline(buffer, sizeof buffer);
				cout << buffer << "\n";
			}
		}
		file.close();
	}
}

void showGroup() {
	int groupNumber;
	cout << "Enter the group number: ";
	cin >> groupNumber;
	ifstream file("students.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countStudents();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			Student* student = new Student[size];
			for (int i = 0; i < size; i++)
			{
				file >> student[i].id;
				file >> student[i].name;
				file >> student[i].surname;
				file >> student[i].patronymic;
				file >> student[i].isMan;
				file >> student[i].numberGroup;
				for (int j = 0; j < 8; j++) file >> student[i].grades[j];
			}
			file.close();
			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (student[i].numberGroup == groupNumber)
				{
					cout << "Id: " << student[i].id << "\n";
					cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
					cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
					cout << "NumberGroup: " << student[i].numberGroup << "\n";
					for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
					cout << "\n\n";
					temp++;
				}
			}

			if (temp == 0) cout << "Students Not Found!\n";
			delete[] student;
		}
	}
}

void showIdStudent() {
	int idStudent;
	cout << "Enter the Id Student's: ";
	cin >> idStudent;
	ifstream file("students.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countStudents();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			Student* student = new Student[size];
			for (int i = 0; i < size; i++)
			{
				file >> student[i].id;
				file >> student[i].name;
				file >> student[i].surname;
				file >> student[i].patronymic;
				file >> student[i].isMan;
				file >> student[i].numberGroup;
				for (int j = 0; j < 8; j++) file >> student[i].grades[j];
			}
			file.close();

			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (student[i].id == idStudent)
				{
					cout << "Id: " << student[i].id << "\n";
					cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
					cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
					cout << "NumberGroup: " << student[i].numberGroup << "\n";
					for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
					cout << "\n\n";
					temp++;
				}
			}
			if (temp == 0) cout << "Students Not Found!\n";
			delete[] student;
		}
	}
}

void countGenders() {
	ifstream file("students.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countStudents();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			Student* student = new Student[size];
			for (int i = 0; i < size; i++)
			{
				file >> student[i].id;
				file >> student[i].name;
				file >> student[i].surname;
				file >> student[i].patronymic;
				file >> student[i].isMan;
				file >> student[i].numberGroup;
				for (int j = 0; j < 8; j++) file >> student[i].grades[j];
			}
			file.close();

			int countMan = 0;
			int countWoman = 0;
			for (int i = 0; i < size; i++)
			{
				if (student[i].isMan) countMan++;
				else countWoman++;
			}
			cout << "Count Man: " << countMan << "\n";
			cout << "Count Woman: " << countWoman << "\n";
			delete[] student;
		}
	}
}

void displayAcademicRecord() {
	int numberGrade;
	cout << "Enter the number of whom you want to receive:\n\t3 - Acceptable\n\t4 - Good\n\t5 - Excellent:\n";
	cin >> numberGrade;
	if (numberGrade > 2 && numberGrade < 6) {
		ifstream file("students.txt");
		if (!file.is_open()) cout << "File error opening!\n";
		else {
			int size;
			size = countStudents();
			if (size == 0) cout << "The File is Empty!\n";
			else {
				Student* student = new Student[size];
				for (int i = 0; i < size; i++)
				{
					file >> student[i].id;
					file >> student[i].name;
					file >> student[i].surname;
					file >> student[i].patronymic;
					file >> student[i].isMan;
					file >> student[i].numberGroup;
					for (int j = 0; j < 8; j++) file >> student[i].grades[j];
				}
				file.close();
				int temp = 0;
				for (int i = 0; i < size; i++)
				{
					bool isAcceptable = false, isGood = false;
					for (int j = 0; j < 8; j++) {
						if (student[i].grades[j] == 3) {
							isAcceptable = true;
							break;
						}
						else if (student[i].grades[j] == 4) isGood = true;
						else continue;
					}

					if (numberGrade == 5 && !isAcceptable && !isGood) {
						cout << "Id: " << student[i].id << "\n";
						cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
						cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
						cout << "NumberGroup: " << student[i].numberGroup << "\n";
						for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
						cout << "\n\n";
						temp++;
					}
					else if (numberGrade == 4 && !isAcceptable && isGood) {
						cout << "Id: " << student[i].id << "\n";
						cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
						cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
						cout << "NumberGroup: " << student[i].numberGroup << "\n";
						for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
						cout << "\n\n";
						temp++;
					}
					else if (numberGrade == 3 && isAcceptable) {
						cout << "Id: " << student[i].id << "\n";
						cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
						cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
						cout << "NumberGroup: " << student[i].numberGroup << "\n";
						for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
						cout << "\n\n";
						temp++;
					}
				}
				if (temp == 0) cout << "Students Not Found!\n";
				delete[] student;
			}
		}
	}
}

void editStudent() {
	int idStudent;
	cout << "Enter the Id Student's for edit: ";
	cin >> idStudent;
	int editOption;
	cout << "Enter edit option:\n\t0 - Name\n\t1 - Gender\n\t2 - Group:\n";
	cin >> editOption;
	ifstream file("students.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countStudents();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			Student* student = new Student[size];
			for (int i = 0; i < size; i++)
			{
				file >> student[i].id;
				file >> student[i].name;
				file >> student[i].surname;
				file >> student[i].patronymic;
				file >> student[i].isMan;
				file >> student[i].numberGroup;
				for (int j = 0; j < 8; j++) file >> student[i].grades[j];
			}
			file.close();

			int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (student[i].id == idStudent)
				{
					cout << "Enter your new data: ";
					if (editOption == 0) cin >> student[i].name;
					else if (editOption == 1) {
						cout << "What is new gender?\n\t0 - Woman\t1 - Man: ";
						cin >> student[i].isMan;
					}
					else if (editOption == 2) cin >> student[i].numberGroup;
					temp++;
				}
			}
			if (temp == 0) cout << "Students Not Found!\n";
			else {
				ofstream oFile;
				oFile.open("students.txt", ios::out | ios::trunc);
				if (!oFile.is_open()) cout << "Error saving!";
				else {
					for (int i = 0; i < size; i++)
					{
						oFile << student[i].id << "\n"
							<< student[i].name << "\n"
							<< student[i].surname << "\n"
							<< student[i].patronymic << "\n"
							<< student[i].isMan << "\n"
							<< student[i].numberGroup << "\n";
						for (int j = 0; j < 8; j++) j == 7 ? oFile << student[i].grades[j] << "\n" : oFile << student[i].grades[j] << " ";
						if (i != size - 1) oFile << "\n";
					}
				}
				oFile.close();
			}
			delete[] student;
		}
	}

}

int getSumGrades(Student student)
{
	int sumGrades = 0;
	for (int j = 0; j < 8; j++)
	{
		sumGrades += student.grades[j];
	}
	return sumGrades;
}

void showTopStudents() {
	ifstream file("students.txt");
	if (!file.is_open()) cout << "File error opening!\n";
	else {
		int size;
		size = countStudents();
		if (size == 0) cout << "The File is Empty!\n";
		else {
			Student* student = new Student[size];
			for (int i = 0; i < size; i++)
			{
				file >> student[i].id;
				file >> student[i].name;
				file >> student[i].surname;
				file >> student[i].patronymic;
				file >> student[i].isMan;
				file >> student[i].numberGroup;
				for (int j = 0; j < 8; j++) file >> student[i].grades[j];
			}
			file.close();
			Student tmp;
			for (int i = 0; i < size; i++)
			{
				for (int j = size - 1; j > i; j--)
				{
					if (getSumGrades(student[j-1]) < getSumGrades(student[j]))
					{
						tmp = student[j];
						student[j] = student[j - 1];
						student[j - 1] = tmp;
					}
				}
			}

			int temp = 0;
			cout << "Display Top Students on grades:\n";
			for (int i = 0; i < size; i++)
			{
				cout << "Id: " << student[i].id << "\n";
				cout << "Full Name: " << student[i].surname << " " << student[i].name << " " << student[i].patronymic << "\n";
				cout << "Gender: " << (student[i].isMan ? "Man" : "Woman") << "\n";
				cout << "NumberGroup: " << student[i].numberGroup << "\n";
				for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";
				cout << "\n\n";
				temp++;
			}

			if (temp == 0) cout << "Students Not Found!\n";
			delete[] student;
		}
	}
}


int main()
{
	bool isLive = true;
	while (isLive) {
		int optionUser;
		cout << "Please select option:\n";
		cout << "\t1 - Basic Work\n";
		cout << "\t2 - Individual Home Work\n";
		cout << "\t0 - Exit\n";
		cin >> optionUser;
		cout << "\n";
		switch (optionUser)
		{
		case 1:
			int actionUser;
			cout << "Please select action:\n";
			cout << "\t1 - Add a new Student\n";
			cout << "\t2 - Display all Students\n";
			cout << "\t3 - Display Students of Group\n";
			cout << "\t4 - Display Student by Id\n";
			cout << "\t5 - Count gender on List\n";
			cout << "\t6 - Display Academic Record\n";
			cout << "\t7 - Edit Student by Id\n";
			cout << "\t8 - Show Top Students\n";
			cout << "\t0 - Exit\n";
			cin >> actionUser;
			cout << "\n";
			switch (actionUser)
			{
			case 0: 
				isLive = false;
				break;
			case 1: 
				addStudent();
				break;
			case 2: 
				displayStudents();
				break;
			case 3: 
				showGroup();
				break;
			case 4: 
				showIdStudent();
				break;
			case 5: 
				countGenders();
				break;
			case 6: 
				displayAcademicRecord();
				break;
			case 7: 
				editStudent();
				break;
			case 8:
				showTopStudents();
				break;
			default:
				break;
			}
			cout << "\n";
			break;

		case 2:
			int acctionUser;
			cout << "Please select action:\n";
			cout << "\t1 - Add a new Member\n";
			cout << "\t2 - Display young Member\n";
			cout << "\t3 - Display who have a Medal\n";
			cout << "\t4 - Display Member is a Capitan\n";
			cout << "\t0 - Exit\n";
			cin >> acctionUser;
			switch (acctionUser)
			{
			case 0: 
				isLive = false;
				break;
			case 1: 
				addMember();
				break;
			case 2: 
				displayYoung();
				break;
			case 3: 
				haveMedal();
				break;
			case 4: 
				isCapitan();
				break;
			default:
				break;
			}
			cout << "\n";
			break;

		case 0: 
			isLive = false;
			break;

		default:
			break;
		}
	}
}

