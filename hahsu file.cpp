//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Employee;
//class Project;
//class Department;
//
//
//class Name
//{
//private:
//	string f_name;
//	string l_name;
//
//public:
//	Name(string f, string l)
//	{
//		f_name = f;
//		l_name = l;
//	}
//
//	void displayName()
//	{
//		cout << this->f_name << " " << this->l_name;
//	}
//};
//
//
//class Address
//{
//private:
//	int houseNo;
//	char block;
//	int streetNo;
//	string city;
//
//public:
//	Address(int HN, char B, int SN, string C)
//	{
//		this->houseNo = HN;
//		this->block = B;
//		this->streetNo = SN;
//		this->city = C;
//	}
//
//	void displayAddress()
//	{
//		cout << "\n====Employee's Address====\n";
//		cout << "House number:\t" << this->houseNo << endl;
//		cout << "Block:\t\t" << this->block << endl;
//		cout << "Street number:\t" << this->streetNo << endl;
//		cout << "City:\t\t" << this->city << endl;
//	}
//};
//
//
//class Project
//{
//private:
//	int ID;
//	string projectDescription;
//	int employeeWorkingOn;
//	Employee* employee[10];
//
//public:
//	Project(int ID, string pd)
//	{
//		this->ID = ID;
//		projectDescription = pd;
//		employeeWorkingOn = 0;
//
//		for (int i = 0; i < 10; i++)
//			employee[i] = nullptr;
//	}
//
//	int getID() { return ID; }
//
//	void displayProjectinfo()
//	{
//		cout << "\n====Project Info====\n";
//		cout << "Project ID:\t\t" << ID << endl;
//		cout << "Project Description:\t" << projectDescription << endl;
//	}
//
//	bool AddEmployee(Employee* emp)
//	{
//		if (employeeWorkingOn >= 10)
//		{
//			cout << "Limit reached...cannot add employee to project.\n";
//			return false;
//		}
//		employee[employeeWorkingOn] = emp;
//		employeeWorkingOn++;
//		return true;
//	}
//
//	bool RemoveEmployee(int employeeID);
//
//	void DisplayAllEmployees();
//};
//
//
//class Department
//{
//private:
//	int ID;
//	string name;
//	Employee* employee[50];
//	int employeeCount;
//
//public:
//	Department(int ID, string name)
//	{
//		this->ID = ID;
//		this->name = name;
//		employeeCount = 0;
//
//		for (int i = 0; i < 50; i++)
//			employee[i] = nullptr;
//	}
//
//	int getID() { return ID; }
//
//	void displayDeptInfo()
//	{
//		cout << "\n====Department Information====\n";
//		cout << "Department ID:\t\t" << ID << endl;
//		cout << "Department name:\t" << name << endl;
//	}
//
//	bool AddEmployee(Employee* emp)
//	{
//		if (employeeCount >= 50)
//		{
//			cout << "Limit reached...cannot add employee to department.\n";
//			return false;
//		}
//		employee[employeeCount] = emp;
//		employeeCount++;
//		return true;
//	}
//
//	bool RemoveEmployee(int employeeID);
//
//	void DisplayAllEmployees();
//};
//
//
//class Employee
//{
//private:
//	int ID;
//	Name name;
//	Address permanentAddr;
//	bool assignedToDept;
//	Project* project[3];
//	int projectCount;
//	Department* Dept;
//
//public:
//	Employee(int ID, string f, string l, int HN, char B, int SN, string city)
//		: name(f, l), permanentAddr(HN, B, SN, city), ID(ID)
//	{
//		assignedToDept = false;
//		projectCount = 0;
//		Dept = nullptr;
//
//		for (int i = 0; i < 3; i++)
//			project[i] = nullptr;
//	}
//
//	int getID() { return ID; }
//
//	void displayEmployeeInfo()
//	{
//		cout << "\n====Employee Information====\n";
//		cout << "Employee ID:\t";
//		cout << this->ID << endl;
//		cout << "Employee Name:\t";
//		name.displayName();
//		cout << endl;
//		permanentAddr.displayAddress();
//		cout << "\n";
//	}
//
//	bool AddProject(Project* proj)
//	{
//		if (projectCount >= 3)
//		{
//			cout << "Limit reached...cannot add more projects.\n";
//			return false;
//		}
//		project[projectCount] = proj;
//		projectCount++;
//		return true;
//	}
//
//	bool RemoveProject(int ProjectID)
//	{
//		if (projectCount == 0)
//		{
//			cout << "No projects to remove.\n";
//			return false;
//		}
//
//		int index = -1;
//		for (int i = 0; i < projectCount; i++)
//		{
//			if (project[i]->getID() == ProjectID)
//			{
//				index = i;
//				break;
//			}
//		}
//
//		if (index == -1)
//		{
//			cout << "Project ID not found.\n";
//			return false;
//		}
//
//		for (int i = index; i < projectCount - 1; i++)
//			project[i] = project[i + 1];
//
//		projectCount--;
//		project[projectCount] = nullptr;
//		return true;
//	}
//
//	void displayAllProjects()
//	{
//		if (projectCount == 0)
//		{
//			cout << "No projects to display.\n";
//			return;
//		}
//		cout << "\n====Projects of Employee: ";
//		name.displayName();
//		cout << "====\n";
//
//		for (int i = 0; i < projectCount; i++)
//		{
//			project[i]->displayProjectinfo();
//			cout << endl;
//		}
//	}
//
//	void setAssignedtoDept(bool value)
//	{
//		assignedToDept = value;
//		if (!value)
//			Dept = nullptr;
//	}
//
//	bool getAssignedtoDept() { return assignedToDept; }
//
//	void setDept(Department* dept)
//	{
//		Dept = dept;
//		if (dept != nullptr)
//			assignedToDept = true;
//	}
//
//	void displaydept()
//	{
//		if (Dept == nullptr)
//		{
//			cout << "No department assigned.\n";
//			return;
//		}
//		cout << "\n====Department of Employee: ";
//		name.displayName();
//		cout << "====\n";
//		Dept->displayDeptInfo();
//		cout << endl;
//	}
//};
//
//
//bool Project::RemoveEmployee(int employeeID)
//{
//	if (employeeWorkingOn == 0)
//	{
//		cout << "No employees to remove.\n";
//		return false;
//	}
//
//	int index = -1;
//	for (int i = 0; i < employeeWorkingOn; i++)
//	{
//		if (employee[i]->getID() == employeeID)
//		{
//			index = i;
//			break;
//		}
//	}
//
//	if (index == -1)
//	{
//		cout << "Employee ID not found in project.\n";
//		return false;
//	}
//
//	for (int i = index; i < employeeWorkingOn - 1; i++)
//		employee[i] = employee[i + 1];
//
//	employeeWorkingOn--;
//	employee[employeeWorkingOn] = nullptr;
//	return true;
//}
//
//void Project::DisplayAllEmployees()
//{
//	if (employeeWorkingOn == 0)
//	{
//		cout << "No employees working on this project.\n";
//		return;
//	}
//	cout << "\n====Employees in project: " << this->projectDescription << "====\n";
//	for (int i = 0; i < employeeWorkingOn; i++)
//	{
//		employee[i]->displayEmployeeInfo();
//		cout << "\n";
//	}
//}
//
//
//bool Department::RemoveEmployee(int employeeID)
//{
//	if (employeeCount == 0)
//	{
//		cout << "No employees to remove.\n";
//		return false;
//	}
//
//	int index = -1;
//	for (int i = 0; i < employeeCount; i++)
//	{
//		if (employee[i]->getID() == employeeID)
//		{
//			index = i;
//			break;
//		}
//	}
//
//	if (index == -1)
//	{
//		cout << "Employee ID not found in department.\n";
//		return false;
//	}
//
//	for (int i = index; i < employeeCount - 1; i++)
//		employee[i] = employee[i + 1];
//
//	employeeCount--;
//	employee[employeeCount] = nullptr;
//	return true;
//}
//
//void Department::DisplayAllEmployees()
//{
//	if (employeeCount == 0)
//	{
//		cout << "No employees in this department.\n";
//		return;
//	}
//	cout << "\n====Employees in department: " << this->name << "====\n";
//	for (int i = 0; i < employeeCount; i++)
//	{
//		employee[i]->displayEmployeeInfo();
//		cout << endl;
//	}
//}
//
//
//class Company
//{
//private:
//	static Company* instance;
//
//	Employee* employees[100];
//	int         ecount;
//	Project* projects[20];
//	int         pcount;
//	Department* departments[4];
//	int         dcount;
//
//	Company()
//	{
//		ecount = 0; pcount = 0; dcount = 0;
//
//		for (int i = 0; i < 100; i++) employees[i] = nullptr;
//		for (int i = 0; i < 20; i++) projects[i] = nullptr;
//		for (int i = 0; i < 4; i++) departments[i] = nullptr;
//	}
//
//public:
//	static Company* construct()
//	{
//		if (instance == nullptr)
//			instance = new Company();
//		return instance;
//	}
//
//	void createDepartment(int ID, string name)
//	{
//		if (dcount >= 4)
//		{
//			cout << "Department limit reached.\n";
//			return;
//		}
//		departments[dcount++] = new Department(ID, name);
//		cout << "Department created successfully.\n";
//	}
//
//	void createProject(int ID, string description)
//	{
//		if (pcount >= 20)
//		{
//			cout << "Project limit reached.\n";
//			return;
//		}
//		projects[pcount++] = new Project(ID, description);
//		cout << "Project created successfully.\n";
//	}
//
//	void createEmployee(int ID, string fn, string ln, int HN, char B, int SN, string city)
//	{
//		if (ecount >= 100)
//		{
//			cout << "Employee limit reached.\n";
//			return;
//		}
//		employees[ecount++] = new Employee(ID, fn, ln, HN, B, SN, city);
//		cout << "Employee created successfully.\n";
//	}
//
//	void displayEmpID(int id)
//	{
//		cout << "\nEmployee ID:\t" << id << endl;
//	}
//
//	void DisplayProjID(int id)
//	{
//		cout << "\nProject ID:\t" << id << endl;
//	}
//
//	void displayDeptID(int id)
//	{
//		cout << "\nDepartment ID:\t" << id << endl;
//	}
//
//	bool addEmpInDep(int idE, int idD)
//	{
//		int eIdx = -1;
//		for (int i = 0; i < ecount; i++)
//			if (employees[i]->getID() == idE) { eIdx = i; break; }
//		if (eIdx == -1) { cout << "Employee not found.\n"; return false; }
//
//		if (employees[eIdx]->getAssignedtoDept())
//		{
//			cout << "Employee already assigned to a department.\n";
//			return false;
//		}
//
//		int dIdx = -1;
//		for (int i = 0; i < dcount; i++)
//			if (departments[i]->getID() == idD) { dIdx = i; break; }
//		if (dIdx == -1) { cout << "Department not found.\n"; return false; }
//
//		if (!departments[dIdx]->AddEmployee(employees[eIdx]))
//			return false;
//
//		employees[eIdx]->setDept(departments[dIdx]);
//		cout << "Employee added to department successfully.\n";
//		return true;
//	}
//
//	bool addEmpInProj(int idE, int idP)
//	{
//		int eIdx = -1;
//		for (int i = 0; i < ecount; i++)
//			if (employees[i]->getID() == idE) { eIdx = i; break; }
//		if (eIdx == -1) { cout << "Employee not found.\n"; return false; }
//
//		int pIdx = -1;
//		for (int i = 0; i < pcount; i++)
//			if (projects[i]->getID() == idP) { pIdx = i; break; }
//		if (pIdx == -1) { cout << "Project not found.\n"; return false; }
//
//		if (!employees[eIdx]->AddProject(projects[pIdx]))
//			return false;
//
//		projects[pIdx]->AddEmployee(employees[eIdx]);
//		cout << "Employee added to project successfully.\n";
//		return true;
//	}
//
//	bool displayAllProj(int id)
//	{
//		for (int i = 0; i < ecount; i++)
//			if (employees[i]->getID() == id) { employees[i]->displayAllProjects(); return true; }
//		cout << "Employee not found.\n";
//		return false;
//	}
//
//	bool displayAllEmpInDep(int id)
//	{
//		for (int i = 0; i < dcount; i++)
//			if (departments[i]->getID() == id) { departments[i]->DisplayAllEmployees(); return true; }
//		cout << "Department not found.\n";
//		return false;
//	}
//
//	bool displayAllEmpInProj(int id)
//	{
//		for (int i = 0; i < pcount; i++)
//			if (projects[i]->getID() == id) { projects[i]->DisplayAllEmployees(); return true; }
//		cout << "Project not found.\n";
//		return false;
//	}
//
//	bool displayDep(int id)
//	{
//		for (int i = 0; i < dcount; i++)
//			if (employees[i]->getID() == id) { departments[i]->displayDeptInfo(); return true; }
//		cout << "Department not found.\n";
//		return false;
//	}
//
//	bool removeEmpFromDep(int idE, int idD)
//	{
//		int eIdx = -1;
//		for (int i = 0; i < ecount; i++)
//			if (employees[i]->getID() == idE) { eIdx = i; break; }
//		if (eIdx == -1) { cout << "Employee not found.\n"; return false; }
//
//		int dIdx = -1;
//		for (int i = 0; i < dcount; i++)
//			if (departments[i]->getID() == idD) { dIdx = i; break; }
//		if (dIdx == -1) { cout << "Department not found.\n"; return false; }
//
//		if (departments[dIdx]->RemoveEmployee(idE))
//		{
//			employees[eIdx]->setAssignedtoDept(false);
//			cout << "Employee removed from department successfully.\n";
//			return true;
//		}
//		return false;
//	}
//
//	bool removeEmpFromProj(int idE, int idP)
//	{
//		int eIdx = -1;
//		for (int i = 0; i < ecount; i++)
//			if (employees[i]->getID() == idE) { eIdx = i; break; }
//		if (eIdx == -1) { cout << "Employee not found.\n"; return false; }
//
//		int pIdx = -1;
//		for (int i = 0; i < pcount; i++)
//			if (projects[i]->getID() == idP) { pIdx = i; break; }
//		if (pIdx == -1) { cout << "Project not found.\n"; return false; }
//
//		if (employees[eIdx]->RemoveProject(idP))
//		{
//			projects[pIdx]->RemoveEmployee(idE);
//			cout << "Employee removed from project successfully.\n";
//			return true;
//		}
//		return false;
//	}
//
//
//	~Company()
//	{
//		for (int i = 0; i < ecount; i++) { delete employees[i];   employees[i] = nullptr; }
//		for (int i = 0; i < pcount; i++) { delete projects[i];    projects[i] = nullptr; }
//		for (int i = 0; i < dcount; i++) { delete departments[i]; departments[i] = nullptr; }
//	}
//};
//
//Company* Company::instance = nullptr;
//
//
//int main()
//{
//	Company* c = Company::construct();
//
//	int choice;
//
//	cout << "\n\n====Company Management System====\n\n";
//
//	do
//	{
//		cout << "\n0.\tExit\n";
//		cout << "1.\tCreate a new Department (ID + name)\n";
//		cout << "2.\tCreate a new Employee (ID + name + full address)\n";
//		cout << "3.\tCreate a new Project (ID + description)\n";
//		cout << "4.\tDisplay a Department given its ID\n";
//		cout << "5.\tDisplay an Employee given their ID\n";
//		cout << "6.\tDisplay a Project given its ID\n";
//		cout << "7.\tAdd an Employee to a Department (both IDs)\n";
//		cout << "8.\tAdd an Employee to a Project (both IDs)\n";
//		cout << "9.\tDisplay all Projects of an Employee (employee ID)\n";
//		cout << "10.\tDisplay all Employees in a Department (department ID)\n";
//		cout << "11.\tRemove an Employee from a Department (both IDs)\n";
//		cout << "12.\tRemove an Employee from a Project (both IDs)\n";
//		cout << "13.\tDisplay all Employees working on a Project (project ID)\n";
//		cout << "14.\tDisplay the Department of an Employee (employee ID)\n";
//
//		cout << "\nPlease enter a choice (0-14):\t";
//		cin >> choice;
//
//		while (choice < 0 || choice > 14)
//		{
//			cout << "Please enter correct choice (0-14):\t";
//			cin >> choice;
//		}
//
//		switch (choice)
//		{
//		case 0:
//			cout << "\n\n====Exiting the System====\n\n";
//			break;
//
//		case 1:
//		{
//			int ID;
//			string name;
//			cout << "\n====Creating a New Department====\n";
//			cout << "Enter Department ID:\t";   cin >> ID;
//			cout << "Enter Department name:\t"; cin >> name;
//			c->createDepartment(ID, name);
//			break;
//		}
//
//		case 2:
//		{
//			int ID, HN, SN;
//			string f_name, l_name, city;
//			char block;
//
//			cout << "\n====Creating a New Employee====\n";
//			cout << "Enter Employee ID:\t\t";     cin >> ID;
//			cout << "Enter Employee first name:\t"; cin >> f_name;
//			cout << "Enter Employee last name:\t";  cin >> l_name;
//			cout << "Enter House number:\t\t";     cin >> HN;
//			cout << "Enter Block:\t\t\t";          cin >> block;
//			cout << "Enter Street number:\t\t";    cin >> SN;
//			cout << "Enter City:\t\t\t";           cin >> city;
//			c->createEmployee(ID, f_name, l_name, HN, block, SN, city);
//			break;
//		}
//
//		case 3:
//		{
//			int ID;
//			string pd;
//			cout << "\n====Creating a New Project====\n";
//			cout << "Enter Project ID:\t\t";    cin >> ID;
//			cout << "Enter Project Description:\t"; cin >> pd;
//			c->createProject(ID, pd);
//			break;
//		}
//
//		case 4:
//		{
//			int ID;
//			cout << "Enter Department ID to display:\t";
//			cin >> ID;
//			c->displayDeptID(ID);
//			break;
//		}
//
//		case 5:
//		{
//			int ID;
//			cout << "Enter Employee ID to display:\t";
//			cin >> ID;
//			c->displayEmpID(ID);
//			break;
//		}
//
//		case 6:
//		{
//			int ID;
//			cout << "Enter Project ID to display:\t";
//			cin >> ID;
//			c->DisplayProjID(ID);
//			break;
//		}
//
//		case 7:
//		{
//			int idE, idD;
//			cout << "Enter Employee ID:\t";   cin >> idE;
//			cout << "Enter Department ID:\t"; cin >> idD;
//			c->addEmpInDep(idE, idD);
//			break;
//		}
//
//		case 8:
//		{
//			int idE, idP;
//			cout << "Enter Employee ID:\t"; cin >> idE;
//			cout << "Enter Project ID:\t";  cin >> idP;
//			c->addEmpInProj(idE, idP);
//			break;
//		}
//
//		case 9:
//		{
//			int ID;
//			cout << "Enter Employee ID:\t";
//			cin >> ID;
//			c->displayAllProj(ID);
//			break;
//		}
//
//		case 10:
//		{
//			int ID;
//			cout << "Enter Department ID:\t";
//			cin >> ID;
//			c->displayAllEmpInDep(ID);
//			break;
//		}
//
//		case 11:
//		{
//			int idE, idD;
//			cout << "Enter Employee ID:\t";   cin >> idE;
//			cout << "Enter Department ID:\t"; cin >> idD;
//			c->removeEmpFromDep(idE, idD);
//			break;
//		}
//
//		case 12:
//		{
//			int idE, idP;
//			cout << "Enter Employee ID:\t"; cin >> idE;
//			cout << "Enter Project ID:\t";  cin >> idP;
//			c->removeEmpFromProj(idE, idP);
//			break;
//		}
//
//		case 13:
//		{
//			int ID;
//			cout << "Enter Project ID:\t";
//			cin >> ID;
//			c->displayAllEmpInProj(ID);
//			break;
//		}
//
//		case 14:
//		{
//			int ID;
//			cout << "Enter Employee ID:\t";
//			cin >> ID;
//			if (c->displayDep(ID)) { cout << "Department of employee displayed successfully" << endl; }
//			break;
//		}
//
//		}
//
//	} while (choice != 0);
//
//	return 0;
//}