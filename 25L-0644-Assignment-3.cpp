#include <iostream>
#include <string>
using namespace std;

class Project;
class Department;

class Name {
    string f_name;
    string l_name;
public:
    Name(string f, string l) {
        f_name = f;
        l_name = l;
    }

    void displayName() {
        cout << "Name: " << f_name << " " << l_name << endl;
    }
};

class Address {
    int    houseNo;
    char   block;
    int    streetNo;
    string city;
public:
    Address(int HN, char B, int SN, string C) {
        houseNo = HN;
        block = B;
        streetNo = SN;
        city = C;
    }

    void displayAddress() {
        cout << "Address: " << houseNo << "-" << block
            << " streetNo." << streetNo << ", " << city << endl;
    }
};
class Employee {
    int     ID;
    Name    name;
    Address permanentAddr;
    bool    assignedToDept;
    Project* project[3];
    int         projectCount;
    Department* Dept;

public:
    Employee(int ID, string f, string l,
        int HN, char B, int SN, string city)
        : name(f, l), permanentAddr(HN, B, SN, city)
    {
        this->ID = ID;
        assignedToDept = false;
        projectCount = 0;
        Dept = nullptr;
        for (int i = 0; i < 3; i++)
            project[i] = nullptr;
    }

    int getID() { return ID; }

    void displayEmployeeInfo();

    bool AddProject(Project* proj);

    bool RemoveProject(int projectID);

    void displayAllProjects();

    void SetAssignedToDept(bool value) {
        assignedToDept = value;
    }

    bool GetAssignedTODept() { return assignedToDept; }

    void SetDept(Department* dept) { Dept = dept; }

    void displayDept();
};

class Project {
    int    ID;
    string projectDescription;
    int    employeesWorkingOn;
    Employee* employee[10];

public:
    Project(int ID, string projectDescription) {
        this->ID = ID;
        this->projectDescription = projectDescription;
        employeesWorkingOn = 0;
        for (int i = 0; i < 10; i++)
            employee[i] = nullptr;
    }

    int getID() { return ID; }

    void displayProjectInfo() {
        cout << "Project ID  : " << ID << endl;
        cout << "Description : " << projectDescription << endl;
        cout << "Employees   : " << employeesWorkingOn << endl;
    }

    void IncEmployeesWorkingOn() { employeesWorkingOn++; }

    void DecEmployeeWorkingOn() {
        if (employeesWorkingOn > 0)
            employeesWorkingOn--;
    }

    bool AddEmployee(Employee* emp) {
        if (employeesWorkingOn >= 10) {
            cout << "Project full — max 10 employees." << endl;
            return false;
        }
        for (int i = 0; i < employeesWorkingOn; i++) {
            if (employee[i] != nullptr && employee[i]->getID() == emp->getID()) {
                cout << "Employee already in this project." << endl;
                return false;
            }
        }
        employee[employeesWorkingOn] = emp;
        employeesWorkingOn++;
        return true;
    }

    bool RemoveEmployee(Employee* emp) {
        int pos = -1;
        for (int i = 0; i < employeesWorkingOn; i++) {
            if (employee[i] != nullptr && employee[i]->getID() == emp->getID()) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Employee not found in this project." << endl;
            return false;
        }
        employee[pos] = nullptr;
       
        for (int i = pos; i < employeesWorkingOn - 1; i++)
            employee[i] = employee[i + 1];
        employeesWorkingOn--;
        employee[employeesWorkingOn] = nullptr;
        return true;
    }

    void DisplayAllEmployees();   
};

class Department {
    int    ID;
    string name;
    Employee* employee[50];
    int    employeeCount;

public:
    Department(int ID, string name) {
        this->ID = ID;
        this->name = name;
        employeeCount = 0;
        for (int i = 0; i < 50; i++)
            employee[i] = nullptr;
    }

    int getID() { return ID; }

    void displayDeptInfo() {
        cout << "Department ID   : " << ID << endl;
        cout << "Department Name : " << name << endl;
        cout << "Employees       : " << employeeCount << endl;
    }

    bool AddEmployee(Employee* emp) {
        if (employeeCount >= 50) {
            cout << "Department full — max 50 employees." << endl;
            return false;
        }
        employee[employeeCount] = emp;
        employeeCount++;
        return true;
    }

    bool RemoveEmployee(int employeeID) {
        int pos = -1;
        for (int i = 0; i < employeeCount; i++) {
            if (employee[i] != nullptr && employee[i]->getID() == employeeID) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Employee not found in this department." << endl;
            return false;
        }
        employee[pos] = nullptr;
        for (int i = pos; i < employeeCount - 1; i++)
            employee[i] = employee[i + 1];
        employeeCount--;
        employee[employeeCount] = nullptr;
        return true;
    }

    void DisplayAllEmployees() {
        if (employeeCount == 0) {
            cout << "No employees in this department." << endl;
            return;
        }
        cout << "Employees in [" << name << "] :" << endl;
        for (int i = 0; i < employeeCount; i++) {
            if (employee[i] != nullptr)
                employee[i]->displayEmployeeInfo();
        }
    }
};

void Employee::displayEmployeeInfo() {
    cout << "Employee ID : " << ID << endl;
    name.displayName();
    permanentAddr.displayAddress();
    cout << "Projects    : " << projectCount << endl;
    cout << "In Dept     : " << (assignedToDept ? "Yes" : "No") << endl;
}

bool Employee::AddProject(Project* proj) {
    if (projectCount >= 3) {
        cout << "Employee " << ID << " already has 3 projects." << endl;
        return false;
    }
    for (int i = 0; i < projectCount; i++) {
        if (project[i] != nullptr && project[i]->getID() == proj->getID()) {
            cout << "Employee already assigned to this project." << endl;
            return false;
        }
    }
    project[projectCount] = proj;
    projectCount++;
    return true;
}

bool Employee::RemoveProject(int projectID) {
    int pos = -1;
    for (int i = 0; i < projectCount; i++) {
        if (project[i] != nullptr && project[i]->getID() == projectID) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Project " << projectID << " not found for employee " << ID << endl;
        return false;
    }
    project[pos] = nullptr;
    for (int i = pos; i < projectCount - 1; i++)
        project[i] = project[i + 1];
    projectCount--;
    project[projectCount] = nullptr;
    return true;
}

void Employee::displayAllProjects() {
    if (projectCount == 0) {
        cout << "Employee " << ID << " has no projects." << endl;
        return;
    }
    cout << "Projects of employee [" << ID << "] :" << endl;
    for (int i = 0; i < projectCount; i++) {
        if (project[i] != nullptr)
            project[i]->displayProjectInfo();
    }
}

void Employee::displayDept() {
    if (!assignedToDept || Dept == nullptr) {
        cout << "Employee " << ID << " is not in any department." << endl;
        return;
    }
    Dept->displayDeptInfo();
}

void Project::DisplayAllEmployees() {
    if (employeesWorkingOn == 0) {
        cout << "No employees on this project." << endl;
        return;
    }
    cout << "Employees in project [" << ID << "] :" << endl;
    for (int i = 0; i < employeesWorkingOn; i++) {
        if (employee[i] != nullptr)
            employee[i]->displayEmployeeInfo();
    }
}

class Company {
    static int count;

    Employee* employees[100];  int ecount;
    Project* projects[20];    int pcount;
    Department* departments[4];  int dcount;

    Company() {
        ecount = pcount = dcount = 0;
        for (int i = 0; i < 100; i++) employees[i] = nullptr;
        for (int i = 0; i < 20; i++) projects[i] = nullptr;
        for (int i = 0; i < 4; i++) departments[i] = nullptr;
    }

public:
    static Company* construct() {
        if (count >= 1) {
            cout << "Error: a Company already exists." << endl;
            return nullptr;
        }
        count++;
        return new Company();
    }

    Employee* findEmployee(int id) {
        for (int i = 0; i < ecount; i++)
            if (employees[i] && employees[i]->getID() == id)
                return employees[i];
        return nullptr;
    }

    Project* findProject(int id) {
        for (int i = 0; i < pcount; i++)
            if (projects[i] && projects[i]->getID() == id)
                return projects[i];
        return nullptr;
    }

    Department* findDept(int id) {
        for (int i = 0; i < dcount; i++)
            if (departments[i] && departments[i]->getID() == id)
                return departments[i];
        return nullptr;
    }

  
    void createDepartment(int ID, string name) {
        if (dcount >= 4) { cout << "Max 4 departments allowed." << endl; return; }
        departments[dcount++] = new Department(ID, name);
        cout << "Department created." << endl;
    }

    void createProject(int ID, string description) {
        if (pcount >= 20) { cout << "Max 20 projects allowed." << endl; return; }
        projects[pcount++] = new Project(ID, description);
        cout << "Project created." << endl;
    }

    void createEmployee(int ID, string fn, string ln,
        int HN, char B, int SN, string city) {
        if (ecount >= 100) { cout << "Max 100 employees allowed." << endl; return; }
        employees[ecount++] = new Employee(ID, fn, ln, HN, B, SN, city);
        cout << "Employee created." << endl;
    }
    void displayDeptID(int id) {
        Department* d = findDept(id);
        if (!d) { cout << "Department not found." << endl; return; }
        d->displayDeptInfo();
    }

    void displayProjID(int id) {
        Project* p = findProject(id);
        if (!p) { cout << "Project not found." << endl; return; }
        p->displayProjectInfo();
    }

    void displayEmpID(int id) {
        Employee* e = findEmployee(id);
        if (!e) { cout << "Employee not found." << endl; return; }
        e->displayEmployeeInfo();
    }

    bool addEmpInDep(int idE, int idD) {
        Employee* e = findEmployee(idE);
        Department* d = findDept(idD);
        if (!e) { cout << "Employee not found." << endl; return false; }
        if (!d) { cout << "Department not found." << endl; return false; }

        if (e->GetAssignedTODept()) {
            cout << "Employee " << idE << " is already in a department." << endl;
            return false;
        }
        if (!d->AddEmployee(e)) return false;

        e->SetDept(d);
        e->SetAssignedToDept(true);
        return true;
    }

    bool addEmpInProj(int idE, int idP) {
        Employee* e = findEmployee(idE);
        Project* p = findProject(idP);
        if (!e) { cout << "Employee not found." << endl; return false; }
        if (!p) { cout << "Project not found." << endl; return false; }

        if (!e->AddProject(p)) return false;
        p->AddEmployee(e);
        p->IncEmployeesWorkingOn();
        return true;
    }

    bool displayAllProj(int id) {
        Employee* e = findEmployee(id);
        if (!e) { cout << "Employee not found." << endl; return false; }
        e->displayAllProjects();
        return true;
    }

    bool displayAllEmpInDep(int id) {
        Department* d = findDept(id);
        if (!d) { cout << "Department not found." << endl; return false; }
        d->DisplayAllEmployees();
        return true;
    }

    bool displayAllEmpInProj(int id) {
        Project* p = findProject(id);
        if (!p) { cout << "Project not found." << endl; return false; }
        p->DisplayAllEmployees();
        return true;
    }

    bool displayDep(int id) {
        Employee* e = findEmployee(id);
        if (!e) { cout << "Employee not found." << endl; return false; }
        e->displayDept();
        return true;
    }

    bool removeEmpFromDep(int idE, int idD) {
        Employee* e = findEmployee(idE);
        Department* d = findDept(idD);
        if (!e) { cout << "Employee not found." << endl; return false; }
        if (!d) { cout << "Department not found." << endl; return false; }

        if (!d->RemoveEmployee(idE)) return false;
        e->SetDept(nullptr);
        e->SetAssignedToDept(false);
        return true;
    }

    bool removeEmpFromProj(int idE, int idP) {
        Employee* e = findEmployee(idE);
        Project* p = findProject(idP);
        if (!e) { cout << "Employee not found." << endl; return false; }
        if (!p) { cout << "Project not found." << endl; return false; }

        // bidirectional removal — both sides
        bool r1 = p->RemoveEmployee(e);
        bool r2 = e->RemoveProject(idP);
        if (r1) p->DecEmployeeWorkingOn();
        return r1 && r2;
    }

    // ---- destructor — cleans up all owned heap objects -------------------
    ~Company() {
        for (int i = 0; i < ecount; i++) { delete employees[i];   employees[i] = nullptr; }
        for (int i = 0; i < pcount; i++) { delete projects[i];    projects[i] = nullptr; }
        for (int i = 0; i < dcount; i++) { delete departments[i]; departments[i] = nullptr; }
        count--;
    }
};

int Company::count = 0;
int main() {
    Company* co = Company::construct();
    if (!co) { cout << "Could not start. Exiting." << endl; return 1; }

    int choice;

start:
    cout << "\n--- Company Management System ---" << endl;
    cout << " 0  Exit" << endl;
    cout << " 1  Create Department" << endl;
    cout << " 2  Create Employee" << endl;
    cout << " 3  Create Project" << endl;
    cout << " 4  Display Department (by ID)" << endl;
    cout << " 5  Display Employee (by ID)" << endl;
    cout << " 6  Display Project (by ID)" << endl;
    cout << " 7  Add Employee to Department" << endl;
    cout << " 8  Add Employee to Project" << endl;
    cout << " 9  All Projects of an Employee" << endl;
    cout << " 10 All Employees in a Department" << endl;
    cout << " 11 Remove Employee from Department" << endl;
    cout << " 12 Remove Employee from Project" << endl;
    cout << " 13 All Employees in a Project" << endl;
    cout << " 14 Department of an Employee" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 0) {
        cout << "Bye!" << endl;
        delete co;
        return 0;
    }

    if (choice == 1) {
        int id; string nm;
        cout << "Dept ID: ";   cin >> id;
        cout << "Dept name: "; cin.ignore(); getline(cin, nm);
        co->createDepartment(id, nm);
        goto start;
    }

    if (choice == 2) {
        int id, hn, sn; char bl; string fn, ln, city;
        cout << "Employee ID: ";  cin >> id;
        cout << "First name: ";   cin >> fn;
        cout << "Last name: ";    cin >> ln;
        cout << "House no: ";     cin >> hn;
        cout << "Block: ";        cin >> bl;
        cout << "Street no: ";    cin >> sn;
        cout << "City: ";         cin >> city;
        co->createEmployee(id, fn, ln, hn, bl, sn, city);
        goto start;
    }

    if (choice == 3) {
        int id; string desc;
        cout << "Project ID: ";   cin >> id;
        cout << "Description: ";  cin.ignore(); getline(cin, desc);
        co->createProject(id, desc);
        goto start;
    }

    if (choice == 4) {
        int id; cout << "Dept ID: "; cin >> id;
        co->displayDeptID(id);
        goto start;
    }

    if (choice == 5) {
        int id; cout << "Employee ID: "; cin >> id;
        co->displayEmpID(id);
        goto start;
    }

    if (choice == 6) {
        int id; cout << "Project ID: "; cin >> id;
        co->displayProjID(id);
        goto start;
    }

    if (choice == 7) {
        int e, d;
        cout << "Employee ID: ";   cin >> e;
        cout << "Department ID: "; cin >> d;
        co->addEmpInDep(e, d);
        goto start;
    }

    if (choice == 8) {
        int e, p;
        cout << "Employee ID: "; cin >> e;
        cout << "Project ID: ";  cin >> p;
        co->addEmpInProj(e, p);
        goto start;
    }

    if (choice == 9) {
        int id; cout << "Employee ID: "; cin >> id;
        co->displayAllProj(id);
        goto start;
    }

    if (choice == 10) {
        int id; cout << "Department ID: "; cin >> id;
        co->displayAllEmpInDep(id);
        goto start;
    }

    if (choice == 11) {
        int e, d;
        cout << "Employee ID: ";   cin >> e;
        cout << "Department ID: "; cin >> d;
        co->removeEmpFromDep(e, d);
        goto start;
    }

    if (choice == 12) {
        int e, p;
        cout << "Employee ID: "; cin >> e;
        cout << "Project ID: ";  cin >> p;
        co->removeEmpFromProj(e, p);
        goto start;
    }

    if (choice == 13) {
        int id; cout << "Project ID: "; cin >> id;
        co->displayAllEmpInProj(id);
        goto start;
    }

    if (choice == 14) {
        int id; cout << "Employee ID: "; cin >> id;
        co->displayDep(id);
        goto start;
    }

    cout << "Invalid option. Please try again." << endl;
    goto start;

}