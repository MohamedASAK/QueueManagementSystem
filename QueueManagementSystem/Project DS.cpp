#include <iostream>
#include <fstream> // file stream
#include <string>

using namespace std;

/* Data */
struct Clinet_Data
{
    int Client_Numbre;
    string service;
    string Type;
    string Name;
    string Mobile_Number;
};

/* Node */
struct node
{
    Clinet_Data data;
    node* next;
};

/* Global Pointers */
node* current = NULL;
node* front = NULL;
node* rear = NULL;
node* Vfront = NULL;
node* Vrear = NULL;

/* Global Variable */
string service_T = "Teller";
string service_C = "Customer_Service";
string Type_V = "VIP";
string Type_C = "Clinet";
int counter_EC = 1, counter_EV = 1; // count number of vip or regular clinet in Enqueue
bool numberCheckisE11 = true;
bool checkPrint = true;
bool check_Loop = true;
bool checkSearch = true;
bool quit = true;

/* All functions */
void Main_View();
void Enqueue(bool);
void Dequeue();
void Print_All_Clinets();
void Print_VIP_Clinets();
void Search();
void update();

int main() //main function
{
    
    Main_View();
    return 0;
}

void Main_View() // main view for user 
{
    char service, Print, type_Of_Client;
    bool type_Check;
    do
    {
        cout << "-------------------------------------\n";
        cout << "|--Welcome to banking queue system--|\n";
        cout << "| Press the button -> E for Enqueue  |\n";
        cout << "| Press the button -> D for Dnqueue  |\n";
        cout << "| Press the button -> P for Print    |\n";
        cout << "| Press the button -> S for Search   |\n";
        cout << "| Press the button -> Q for Quit     |\n";
        cout << "| Press the button -> U for Update   |\n";
        cout << "-------------------------------------\n";
        cin >> service;
        switch (service)
        {
        case 'E': case 'e':
            cout << "-----------------" << endl;
            cout << "|--Are you VIP--|" << endl;
            cout << "|If yes press Y |" << endl;
            cout << "|If no press N  |" << endl;
            cout << "-----------------" << endl;
            do
            {
                cin >> type_Of_Client;
                if (type_Of_Client == 'y' || type_Of_Client == 'Y')
                {
                    check_Loop = true; // loop condition
                    type_Check = true;
                    Enqueue(type_Check);
                }
                else if (type_Of_Client == 'n' || type_Of_Client == 'N')
                {
                    check_Loop = true;// loop condition
                    type_Check = false;
                    Enqueue(type_Check);
                }
                else {
                    check_Loop = false;// loop condition
                    cout << "Wrong Entry - Try Again\n";
                }
                cout << endl;

            } while (check_Loop = false);
            break; // break case E or e

        case 'D': case 'd':
            Dequeue();
            break;// break case D or d

        case 'P': case 'p':
            do
            {
                cout << "---------------------------------\n";
                cout << "|Enter -> V for print VIP Clients|\n";
                cout << "|Enter -> A for print All Clients|\n";
                cout << "---------------------------------\n";
                cin >> Print;
                switch (Print)
                {
                case 'V': case'v':
                    checkPrint = true;
                    Print_VIP_Clinets();
                    cout << endl;
                    break; // break case V or v

                case 'A': case'a':
                    checkPrint = true;
                    Print_All_Clinets();
                    cout << endl;
                    break; // break case A or a

                default:
                    checkPrint = false;
                    cout << "Wrong Entry - Try Again" << endl;
                    cout << endl;
                    break;
                }
            } while (checkPrint == false);
            break; // break case P or p

        case 'S': case 's':
            Search();
            cout << endl;
            break;  // break case S or s

        case 'U': case 'u':
            update();
            cout << endl;
            break;// break case U or u

        case 'Q': case 'q':
            quit = false;
            cout << "End the program \n";
            break;  // break case Q or q

        default:
            cout << "Wrong Entry - Try Again" << endl;
            break;
        }
        cout << endl;
    } while (quit == true);
}

void Enqueue(bool type_Check)
{
    int i = 0;
    char Banking_service;
    node* current = new node(); // create a new node

    if (type_Check == true) // VIP Clinet
    {
        if (Vrear != NULL)
        {
            Vrear->next = current;
            Vrear = current;
        }
        else {
            Vfront = current;
            Vrear = current;
        }
        Vrear->next = NULL;

        current->data.Client_Numbre = counter_EV++;
        current->data.Type = "VIP";
        cout << "Give me your Mobile Number please\n";
        do {
            cin >> current->data.Mobile_Number;

            if (current->data.Mobile_Number.length() == 11)
            {
                numberCheckisE11 = true;
            }
            else {
                numberCheckisE11 = false;
                cout << "\nNumber is less or more than 11 number - please try again\n";
            }
        } while (numberCheckisE11 != true);

        cout << "Give me your name please\n";
        cin >> current->data.Name;

        cout << "Enter your service you want\n";
        cout << "Press the button -> C for Customer Service\n";
        cout << "Press the button -> T for Teller\n";
        cin >> Banking_service;

        switch (Banking_service)
        {
        case 'C':case 'c':
            current->data.service = service_C;
            break;

        case 'T':case 't':
            current->data.service = service_T;
            break;

        default: cout << "Wrong input - Try Again\n";
            break;
        }
    }

    else // Clinet
    {
        if (rear != NULL)
        {
            rear->next = current;
            rear = current;
        }
        else {
            front = current;
            rear = current;
            front->next = Vrear;
        }
        rear->next = NULL;

        current->data.Client_Numbre = counter_EC++;
        current->data.Type = "Clinet";
        cout << "Give me your Mobile Number please\n";
        do {
            cin >> current->data.Mobile_Number;

            if (current->data.Mobile_Number.length() == 11)
            {
                numberCheckisE11 = true;
            }
            else {
                numberCheckisE11 = false;
                cout << "\nNumber is less or more than 11 number - please try again\n";
            }
        } while (numberCheckisE11 != true);

        cout << "Enter your service you want\n";
        cout << "Press the button -> C for Customer Service\n";
        cout << "Press the button -> T for Teller\n";
        cin >> Banking_service;

        switch (Banking_service)
        {
        case 'C':case 'c':
            current->data.service = service_C;
            break;

        case 'T':case 't':
            current->data.service = service_T;
            break;

        default:
            cout << "Wrong input - Try Again\n";
            break;
        }
    }
}

void Dequeue()
{
    if (Vfront != NULL) {
        current = Vfront;
        Vfront = Vfront->next;
        delete current;
    }

    else if (front != NULL)
    {
        current = front;
        front = front->next;
        delete current;
    }

    else
    {
        cout << "All clients have been served or There are no clients\n";
    }
}

void Print_VIP_Clinets()
{
    if (Vfront != NULL)
    {
        current = Vfront;
        while (current != NULL) {
            if (current->data.Type == "VIP")
            {
                cout << (current->data.Client_Numbre) << " --> ";
                cout << (current->data.Type) << " : ";
                cout << (current->data.Name) << " : ";
                cout << (current->data.Mobile_Number) << " : ";
                cout << (current->data.service) << endl;

                current = current->next;
            }
        }
    }

    else
    {
        cout << "There are no VIP clients\n";
    }
}

void Print_All_Clinets()
{
    if (Vfront != NULL)
    {
        current = Vfront;
        while (current != NULL) {
            if (current->data.Type == "VIP")
            {
                cout << (current->data.Client_Numbre) << " --> ";
                cout << (current->data.Type) << " : ";
                cout << (current->data.Name) << " : ";
                cout << (current->data.Mobile_Number) << " : ";
                cout << (current->data.service) << endl;
                current = current->next;
            }
        }
    }

    else {
        cout << "\nThere are no vip clients\n";
    }

    if (front != NULL) {
        current = front;
        while (current != NULL) {

            cout << (current->data.Client_Numbre) << " --> ";
            cout << (current->data.Type) << " : ";
            cout << (current->data.Mobile_Number) << " : ";
            cout << (current->data.service) << endl;
            current = current->next;
        }
    }

    else {
        cout << "\nThere are no regular clients\n";
    }
}

void Search()
{
    int Type_of_search;
    char Type_of_service, Type_of_client;
    string mobileNumber;

    do {
        cout << "Enter type of search\n";
        cout << "If you want Search by type of service push -> 1\n";
        cout << "If you want Search by mobile number push -> 2\n";
        cin >> Type_of_search;
        switch (Type_of_search)
        {

        case 1:
            checkSearch = true;
            cout << "Enter type of service \n";
            cout << "Enter -> T for Teller \n";
            cout << "Enter -> C for Customer Service \n";
            cin >> Type_of_service;
            switch (Type_of_service)
            {
            case 'T':case't': // Teller
                checkSearch = true;
                cout << "Enter Type of client\n";
                cout << "Push A -> All VIP and Client\n";
                cout << "Push V -> VIP\n";
                cout << "Push C -> Client\n";
                cin >> Type_of_client;

                switch (Type_of_client)
                {
                case 'A': case 'a':
                    checkSearch = true;
                    if (Vfront != NULL)
                    {
                        cout << "VIP founded is :" << endl;
                        current = Vfront;
                        while (current != NULL) {
                            if (current->data.Type == "VIP" && current->data.service == "Teller")
                            {
                                cout << (current->data.Client_Numbre) << " --> ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Name) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;

                            }
                            current = current->next;
                        }
                    }

                    if (front != NULL) {
                        cout << "Regular client founded is :" << endl;
                        current = front;
                        while (current != NULL) {
                            if (current->data.Type == "Clinet" && current->data.service == "Teller") {
                                cout << (current->data.Client_Numbre) << " : ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }

                    else {
                        cout << "\nThere are not find at all\n";
                    }

                    break;//find at All Teller

                case 'V': case 'v':
                    checkSearch = true;
                    if (Vfront != NULL)
                    {
                        cout << "VIP founded is :" << endl;
                        current = Vfront;
                        while (current != NULL) {
                            if (current->data.Type == "VIP" && current->data.service == "Teller")
                            {
                                cout << (current->data.Client_Numbre) << " --> ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Name) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }
                    

                    else {
                        cout << "\nThere are not find at vip clients\n";
                    }

                    break; // teller vip

                case 'C': case 'c':
                    checkSearch = true;
                    if (front != NULL) {
                        cout << "Regular client founded is :" << endl;
                        current = front;
                        while (current != NULL) {
                            if (current->data.Type == "Clinet" && current->data.service == "Teller") {
                                cout << (current->data.Client_Numbre) << " : ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }

                    else {
                        cout << "\nThere are not find at regular clients\n";
                    }

                    break; // teller client
                default: cout << "Wrong Entry\n";
                    break;
                }
                break; // teller break

            case 'C': case 'c': // Customer Service 
                checkSearch = true;
                cout << "Enter Type of client\n";
                cout << "Push A -> All VIP and Client\n";
                cout << "Push V -> VIP\n";
                cout << "Push C -> Client\n";
                cin >> Type_of_client;
                switch (Type_of_client)
                {
                case 'A':case'a':
                    checkSearch = true;
                    if (Vfront != NULL)
                    {
                        cout << "VIP founded is :" << endl;
                        current = Vfront;
                        while (current != NULL) {
                            if (current->data.Type == "VIP" && current->data.service == "Customer_Service")
                            {
                                cout << (current->data.Client_Numbre) << " --> ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Name) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }
                    else {
                        cout << "\nThere are not find at all VIP client \n";
                    }
                    if (front != NULL) {
                        cout << "Regular client founded is :" << endl;
                        current = front;
                        while (current != NULL) {
                            if (current->data.Type == "Clinet" && current->data.service == "Customer_Service")
                            {
                                cout << (current->data.Client_Numbre) << " : ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }

                    else {
                        cout << "\nThere are not find at all regular client \n";
                    }
                break; // find at All Customer Service
                case 'V': case 'v':
                    checkSearch = true;
                    if (Vfront != NULL)
                    {
                        cout << "VIP founded is :" << endl;
                        current = Vfront;
                        while (current != NULL) {
                            if (current->data.Type == "VIP" && current->data.service == "Customer_Service")
                            {
                                cout << (current->data.Client_Numbre) << " --> ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Name) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }
                    else {
                        cout << "\nThere are no vip clients\n";
                    }
                break; // Customer Service vip

                case 'C': case 'c':
                    checkSearch = true;
                    if (front != NULL) {
                        cout << "Regular client founded is :" << endl;
                        current = front;
                        while (current != NULL) {
                            if (current->data.Type == "Clinet" && current->data.service == "Customer_Service") {
                                cout << (current->data.Client_Numbre) << " : ";
                                cout << (current->data.Type) << " : ";
                                cout << (current->data.Mobile_Number) << " : ";
                                cout << (current->data.service) << endl;
                            }
                            current = current->next;
                        }
                    }
                    else {
                        cout << "\nThere are no regular clients\n";
                    }

                    break; // Customer Service client
                }
            default:
                break;
            }
            break;
        case 2:
            cout << "Enter mobile you want to Search about it \n";
            cin >> mobileNumber;
            cout << "Enter Type of client\n";
            cout << "Push A -> All VIP and Client\n";
            cout << "Push V -> VIP\n";
            cout << "Push C -> Client\n";
            cin >> Type_of_client;
            switch (Type_of_client)
            {
            case 'A':case 'a':
                checkSearch = true;
                if (Vfront != NULL)
                {
                    cout << "VIP founded is :" << endl;
                    current = Vfront;
                    while (current != NULL) {
                        if (current->data.Type == "VIP" && current->data.Mobile_Number == mobileNumber)
                        {
                            cout << (current->data.Client_Numbre) << " --> ";
                            cout << (current->data.Type) << " : ";
                            cout << (current->data.Name) << " : ";
                            cout << (current->data.Mobile_Number) << " : ";
                            cout << (current->data.service) << endl;
                        }
                        current = current->next;
                    }
                }
                else {
                    cout << "\nThere are not find at all VIP client \n";
                }
                checkSearch = true;
                if (front != NULL) {
                    cout << "Regular client founded is :" << endl;
                    current = front;
                    while (current != NULL) {
                        if (current->data.Type == "Client" && current->data.Mobile_Number == mobileNumber)
                        {
                            cout << (current->data.Client_Numbre) << " --> ";
                            cout << (current->data.Type) << " : ";
                            cout << (current->data.Mobile_Number) << " : ";
                            cout << (current->data.service) << endl;

                        }
                        current = current->next;
                    }
                }
                
                else {
                    cout << "\nThere are not find at all Regular client \n";
                }
                break;
            case 'V':case 'v':
                checkSearch = true;
                if (Vfront != NULL)
                {
                    cout << "VIP founded is :" << endl;
                    current = Vfront;
                    while (current != NULL) {
                        if (current->data.Type == "VIP" && current->data.Mobile_Number == mobileNumber)
                        {
                            cout << (current->data.Client_Numbre) << " --> ";
                            cout << (current->data.Type) << " : ";
                            cout << (current->data.Name) << " : ";
                            cout << (current->data.Mobile_Number) << " : ";
                            cout << (current->data.service) << endl;

                        }
                        current = current->next;
                    }
                }
                else {
                    cout << "\nThere are not find at VIP client\n";
                }
                break;
            case'C':case'c':
                checkSearch = true;
                if (front != NULL) {
                    cout << "Regular client founded is :" << endl;
                    current = front;
                    while (current != NULL) {
                        if (current->data.Type == "Client" && current->data.Mobile_Number == mobileNumber)
                        {
                            cout << (current->data.Client_Numbre) << " --> ";
                            cout << (current->data.Type) << " : ";
                            cout << (current->data.Mobile_Number) << " : ";
                            cout << (current->data.service) << endl;

                        }
                        current = current->next;
                    }
                }

                else {
                    cout << "\nThere are not find at all Regular client \n";
                }
                break;
            default:
                break;
            }
        }
    } while (checkSearch = false);
}

void update()
{
    fstream update;
    cout << "Last update happened\n";
    update.open("All_Clients_Data.txt", ios::out);

    cout << "Data of Clinets: \n";
    update << "Data of Clinets: \n";

    if (Vfront != NULL) {
        current = Vfront;
        cout << "\nVIP Client\n";
        update << "\nVIP Client\n";
        while (current != NULL) {
            cout << (current->data.Client_Numbre) << " --> ";
            cout << (current->data.Type) << " : ";
            cout << (current->data.Name) << " : ";
            cout << (current->data.Mobile_Number) << " : ";
            cout << (current->data.service) << endl;

            update << (current->data.Client_Numbre) << " --> ";
            update << (current->data.Type) << " : ";
            update << (current->data.Name) << " : ";
            update << (current->data.Mobile_Number) << " : ";
            update << (current->data.service) << endl;

            current = current->next;
        }
        cout << endl;
        update << endl;
    }
    else {
        cout << "There are no vip clients\n";
        update << "There are no vip clients\n";
    }
    if (front != NULL) {
        cout << "\nClient\n";
        update << "\nClient\n";
        current = front;
        while (current != NULL) {
            cout << (current->data.Client_Numbre) << " --> ";
            cout << (current->data.Type) << " : ";
            cout << (current->data.Mobile_Number) << " : ";

            cout << (current->data.service) << endl;

            update << (current->data.Client_Numbre) << " --> ";
            update << (current->data.Type) << " : ";
            update << (current->data.Mobile_Number) << " : ";
            update << (current->data.service) << endl;

            current = current->next;
        }
    }
    else {
        cout << "There are no clients\n";
        update << "There are no clients\n";
    }
    update.close();
}
