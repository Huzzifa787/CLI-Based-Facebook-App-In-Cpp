#include <iostream>
#include <string>
using namespace std;

class str // Student Input and Output
{
public:
    string uname;
    string password;

    void input()
    {
        cout << "\n\n\t\t===========================================\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t\t\t SIGN UP\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t===========================================\n\n\n";

        cout << "\t\tEnter User Name   :      ";
        cin.ignore();
        getline(cin, uname);
        cout << "\n\t\tEnter Password    :      ";
        cin >> password;
    }
    void output1()
    {

        cout << "\n\t\t UNIQUE USER NAME Is:  " << uname;
        cout << "\n\t\tPASSWORD  Is  :      " << password;
    }
};
class Post // Post Input and Output
{
public:
    string pname;
    int pno;
    string pcontent;

    Post()
    {
        pname = "NULL";
        pno = 0;
        pcontent = "NULL";
    }
    void addPost()
    {
        cout << "\n\t\t\t========================================" << endl;
        cout << "\t\t\t\t ADD POST INFORMATION" << endl;
        cout << "\t\t\t========================================\n\n\n";
        cout << "\n\t\tEnter Post No        :       ";
        cin >> pno;
        while (pno < 0)
        {
            cout << "ERROR ! POST NO CAN NOT BE LESSED THAN ZERO , SO AGAIN INPUT   :   ";
            cin >> pno;
        }
        cout << "\n\t\tEnter Post Name      :      ";
        cin.ignore();
        getline(cin, pname);
        cout << "\n\t\tEnter Post Content   :      ";
        cin.ignore();
        getline(cin, pcontent);
    }
    void ViewPost()
    {
        cout << "\n\t\t\t======================================================" << endl;
        cout << "\t\t\t\t USER " << pname << "  HAS POST  " << pno << "  INFORMATION " << endl;
        cout << "\t\t\t======================================================\n\n\n";
        cout << "\n\t\tPost No  :    " << pno;
        cout << "\t\t\t\t\t\tPost Name : " << pname << endl;
        cout << "\n\t\tPost Content  :    " << pcontent << endl;
    }
};
class PNode // Post Node
{
public:
    Post p;
    PNode *next;
    PNode *prev;

    PNode(Post p1)
    {
        p = p1;
        next = NULL;
        prev = NULL;
    }
};
class PostLinking // Add, Update, Delete Post
{
public:
    PNode *head;
    PNode *tail;
    Post p1;

    PostLinking()
    {
        head = NULL;
        tail = NULL;
    }
    void InsertPost()
    {
        PNode *mynode;
    in:
        p1.addPost();
        PNode *n = head;
        int input = 0;

        while (n != NULL)
        {
            if (n->p.pno == p1.pno)
            {
                input++;
                break;
            }
            n = n->next;
        }
        if (input == 1)
        {
            cout << "\n\n\t\t\t-------------------------------------";
            cout << "\n\t\t\t\tPOST NO MUST BE UNIQUE ! " << endl;
            cout << "\t\t\t-------------------------------------\n\n\n";
            system("Pause");
            system("CLS");
            goto in;
        }

        mynode = new PNode(p1);
        if (head == NULL)
        {
            head = mynode;
            tail = head;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            PNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = mynode;
            mynode->prev = temp;
            mynode->next = NULL;
            tail = mynode;
        }
    }
    void remove(int no)
    {
        PNode *mynode = new PNode(p1);
        if (head == NULL)
        {
            cout << "\n\t\t LIST IS EMPTY\n";
            cout << "\t\t DELETION IS NOT POSSIBLE IN THE LIST\n";
        }
        else if (head->p.pno == no)
        {
            PNode *temp = head;
            head = head->next;
            delete temp;
        }
        else if (tail->p.pno == no)
        {
            PNode *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        else
        {
            PNode *temp = head;
            while (temp->next != NULL)
            {
                if (temp->p.pno != no)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }
    void Update(int pno)
    {
        int choice;
        char ch;
        PNode *mynode = new PNode(p1);
        if (head == NULL)
        {
            cout << "\n\t\t LIST IS EMPTY\n";
            cout << "\t\t UPDATION IS NOT POSSIBLE IN THE LIST\n";
        }
        else
        {
            PNode *temp = head;
            // Node* t2 = tail;
            while (temp != NULL)
            {
                if (temp->p.pno != pno)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            cout << "\n\t\tYES, I HAVE FOUND THE POST  \n\n";
            temp->p.ViewPost();
            cout << endl
                 << endl;
            system("pause");
        label:
            system("CLS");
            cout << "\n\t\t====================================\n";
            cout << "\t\t\t MAIN MENU \n";
            cout << "\t\t====================================\n\n";
            cout << "\n\n\t\t Press 1) To Update Post Name\n";
            cout << "\t\t Press 2) To Update Post Content\n";

            cout << "\n\t\t Enter Choice   :   ";
            cin >> choice;
            while (choice < 1 || choice > 3)
            {
                cout << "\n\n\tInvaled Input, Enter Again    :      ";
                cin >> choice;
            }
            if (choice == 1)
            {
                cout << "\n\n\t\tEnter Post Name    :     ";
                cin >> temp->p.pname;
                cout << "\n\n\n\t\t Name Updated Successfully\n\n\n";
                system("pause");
            }
            else if (choice == 2)
            {
                cout << "\n\n\t\tEnter Post Content    :     ";
                cin.ignore();
                getline(cin, temp->p.pcontent);
                cout << "\n\n\n\t\t Content Updated Successfully\n\n\n";
                system("pause");
            }

            cout << "\n\n\n\t\t Do You Want to Perform Another Updation (Y/N) :    ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                system("CLS");
                goto label;
            }
            else if (ch == 'N' || ch == 'n')
            {
                cout << "\n\nTHANKS.........................";
            }
        }
    }
    void displayPost()
    {
        PNode *temp = head;
        if (head == NULL)
        {
            cout << "\n\n\t List is Empty\n";
        }
        else
        {
            while (temp != NULL)
            {
                temp->p.ViewPost();
                temp = temp->next;
            }
        }
    }
};
class FNode // Friend Node
{
public:
    string name;
    FNode *next;
    FNode *prev;
    // PostLinking* p;
    FNode(string n)
    {
        name = n;
        next = prev = NULL;
        // p = new PostLinking;
    }
};
class FriendLinking // Add Friend and View Friend
{
public:
    FNode *head;
    FNode *tail;

    FriendLinking()
    {
        head = tail = NULL;
    }

    void AddFriendList(string name)
    {
        FNode *mynode = new FNode(name);
        if (head == NULL)
        {
            head = mynode;
            tail = head;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            FNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = mynode;
            mynode->prev = temp;
            mynode->next = NULL;
            tail = mynode;
        }
    }
    void UnfollowFrnd(string name)
    {
        FNode *mynode = new FNode(name);
        if (head == NULL)
        {
            cout << "\n\t\t LIST IS EMPTY\n";
            cout << "\t\t DELETION IS NOT POSSIBLE IN THE LIST\n";
        }
        else if (head->name == name)
        {
            FNode *temp = head;
            head = head->next;
            delete temp;
        }
        else if (tail->name == name)
        {
            FNode *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        else
        {
            FNode *temp = head;
            while (temp->next != NULL)
            {
                if (temp->name != name)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }
    void ViewFriends()
    {
        FNode *temp = head;
        if (head == NULL)
        {
            cout << "\n\n\t List is Empty\n";
        }
        else
        {
            while (temp != NULL)
            {

                cout << "\n\n\t\t\t USER NAME IS   :     " << temp->name << "\n";

                temp = temp->next;
            }
        }
    }
    string Friends()
    {
        FNode *temp = head;
        if (head == NULL)
        {
            cout << "\n\n\t List is Empty\n";
        }
        else
        {
            while (temp != NULL)
            {
                return temp->name;
                temp = temp->next;
            }
        }
    }
};
class Node // Node Class
{
public:
    Node *next;
    PostLinking *p2;
    FriendLinking *f2;
    str i1;

    Node(str i)
    {
        i1 = i;
        p2 = new PostLinking;
        f2 = new FriendLinking;
        next = NULL;
    }
};
class SignUp // SignUp and LogIn
{
private:
public:
    Node *head;
    string uname;
    string password;

    SignUp()
    {
        head = NULL;
    }
    void insertUser()
    {
        Node *myNode;
        str u1;
    ll:
        u1.input();
        Node *n = head;
        int co = 0;
        uname = u1.uname;
        while (n != NULL)
        {
            if (n->i1.uname == uname)
            {
                co++;
                break;
            }
            n = n->next;
        }
        if (co == 1)
        {
            cout << "\n\n\t\t\t-------------------------------------";
            cout << "\n\t\t\t\tUSERNAME MUST BE UNIQUE ! " << endl;
            cout << "\t\t\t-------------------------------------\n\n\n";
            system("Pause");
            system("CLS");
            goto ll;
        }
        myNode = new Node(u1);
        if (head == NULL)
        {
            head = myNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = myNode;
        }
    }
    void Display()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "EMPTY" << endl;
        }
        while (temp != NULL)
        {
            temp->i1.output1();
            temp = temp->next;
        }
    }
    bool Search(string n)
    {
        Node *no = head;
        while (no != NULL)
        {
            if (no->i1.uname == n)
            {
                return true;
            }
            no = no->next;
        }
        return false;
    }
    Node *SearchN(string n)
    {
        Node *my = head;
        while (my != NULL)
        {
            if (my->i1.uname == n)
            {
                return my;
            }
            my = my->next;
        }
        return NULL;
    }
    Node *input11()
    {
        string unam;
        string pass;
        cout << "\n\n\t\t===========================================\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t\t\t LOG IN\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t===========================================\n\n\n";
        cout << "\n\t\tEnter User Name  :    ";
        cin.ignore();
        getline(cin, unam);
        cout << "\n\t\tEnter Password   :    ";
        cin >> pass;
        Node *n = head;
        int co = 0;
        while (n != NULL)
        {
            if (n->i1.uname == unam && n->i1.password == pass)
            {
                co++;
                break;
            }
            n = n->next;
        }
        if (co == 1)
        {
            return n;
        }
        return NULL;
    }
};
// class FriendTab
//{
// public:
//	Node* n;
//	string name;
//
//	FriendTab()
//	{
//		n = NULL;
//	}
//	Node* AddFriend(Node* tmp)
//	{
//		n = tmp;
//		system("CLS");
//		cout << "\n\n\n\t\t==================================================\n";
//		cout << "\t\t\t\t FRIENDS TAB\n";
//		cout << "\t\t==================================================\n\n";
//		cout << "\n\t\tEnter the name you want to Follow:     ";
//		cin.ignore();
//		getline(cin, name);
//		while (n != NULL)
//		{
//			if (n->i1.uname == name)
//			{
//				return n;
//			}
//			else
//			{
//				n = n->next;
//			}
//
//		}
//		return NULL;
//	}
//	void Display()
//	{
//		cout << "NAMES  :     " << n->i1.uname << endl;
//	}
// };
class Comment // Comment Input and Output
{
public:
    string name;
    string content;

    Comment()
    {
        name = " ";
        content = " ";
    }
    void Input()
    {
        cout << "\n\t\tEnter Name  :    ";
        cin.ignore();
        getline(cin, name);
        cout << "\n\t\tEnter Comment, Do You Want to Add :  ";
        getline(cin, content);
    }
    void Output()
    {
        cout << "\n\n\t\t==========================================\n";
        cout << "\t\t Name is  :    " << name << endl;
        cout << "\n\t\tContent is  :     " << content << endl
             << endl;
        cout << "\t\t==========================================\n\n";
    }
};
class CNode // Comment Node
{
public:
    Comment c;
    CNode *pre;
    CNode *next;
    CNode(Comment n)
    {
        c = n;
        pre = NULL;
        next = NULL;
    }
};
class CommentLinking // Comment add and View
{
public:
    string name;
    int postname;
    CNode *head;
    CNode *tail;

    CommentLinking()
    {
        name = " ";
        postname = 0;
        head = tail = NULL;
    }

    void addComment(Node *ne, int postname)
    {
        Comment c;
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t Comment Tab" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        cout << "\n\t\tEnter Post Number:      ";
        cin >> postname;
        while (ne != NULL)
        {
            if (ne->p2->p1.pno == postname)
            {

                cout << "\n\t\tYes I Have Found The Post In The List:  ";
                ne->p2->displayPost();
                break;
            }
            else
            {
                cout << "\n\t\tPost Not Found In The List   :  \n";
                ne = ne->next;
            }
        }
        system("pause");
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\tADD Comment" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        c.Input();
        CNode *myNode;
        myNode = new CNode(c);
        if (head == NULL)
        {
            head = myNode;
            tail = head;
            head->next = NULL;
            head->pre = NULL;
        }
        else
        {
            CNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = myNode;
            myNode->pre = temp;
            myNode->next = NULL;
            tail = myNode;
        }
    } // add CommentLinking

    void viewComment(Node *ne, int pno)
    {
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t Comment Tab" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        cout << "\n\t\tEnter Post Number:      ";
        cin >> pno;
        if (head == NULL)
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            CNode *temp = head;
            while (temp != NULL)
            {

                while (ne != NULL)
                {
                    if (ne->p2->p1.pno == pno)
                    {

                        // cout << "\n\t\tYes I Have Found The Post In The List\n\n";
                        break;
                    }
                    else
                    {
                        cout << "\n\t\tPst Not Found In The List   :  \n";
                        ne = ne->next;
                    }
                }
                cout << "\n\t\t-------------------------------------------" << endl;
                cout << "\t\t\t\t View Comment" << endl;
                cout << "\t\t-------------------------------------------\n"
                     << endl;
                temp->c.Output();
                temp = temp->next;
            }
        }
    }
};
class Message // Message Input and Output
{
public:
    string content;

    Message()
    {
        content = " ";
    }
    void addmessage()
    {
        cout << "\n\t\tEnter Message          :  ";
        getline(cin, content);
    }
    void viewmessage()
    {
        cout << "\n\n\t\t==========================================\n";
        cout << "\n\t\tMessage is  :     " << content << endl
             << endl;
        cout << "\t\t==========================================\n\n";
    }
};
class MNode // Message Node
{
public:
    Message m;
    MNode *pre;
    MNode *next;

    MNode(Message n)
    {
        m = n;
        pre = NULL;
        next = NULL;
    }
};
class MessageLinking // Message add, Delete and view
{
public:
    string nam;
    string name;
    // FriendLinking f1;

    Message m;
    MNode *head;
    MNode *na = head;
    MNode *tail;
    MessageLinking()
    {
        nam = " ";
        name = " ";
        head = NULL;
        tail = NULL;
    }

    void SendMessage(FNode *n)
    {
        // Node* head;
        // Node* n = head;
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t Message Tab" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        cout << "\n\t\tEnter The Name Of Friend Do You Want to Send The Message   :     ";
        cin.ignore();
        getline(cin, nam);
        while (n != NULL)
        {
            if (n->name == nam)
            {

                cout << "\n\t\tYes I Have Found The Friend:  \n";
                n->name;
                cout << "\n";
                break;
            }
            else
            {
                cout << "\n\t\tFriend Not Found In The List   :  \n";
                n = n->next;
            }
        }
        system("pause");
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\tSend Message" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        m.addmessage();
        MNode *myNode;
        myNode = new MNode(m);
        if (na == NULL)
        {
            head = myNode;
            tail = head;
            head->next = NULL;
            head->pre = NULL;
        }
        else
        {
            MNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = myNode;
            myNode->pre = temp;
            myNode->next = NULL;
            tail = myNode;
        }
    }

    void DeleteMsg(FNode *n)
    {

        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t Message Tab" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        cout << "\n\t\tEnter The Name Of Friend Do You Want to Delete The Message   :     ";
        cin.ignore();
        getline(cin, nam);
        while (n != NULL)
        {
            if (n->name == nam)
            {

                cout << "\n\t\tYes I Have Found The Friend  :  " << n->name;
                cout << "\n";
                break;
            }
            else
            {
                cout << "\n\t\tFriend Not Found In The List   :  \n";
                n = n->next;
            }
        }
        system("pause");
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\tDelete Message" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        MNode *myNode;
        myNode = new MNode(m);
        if (head == NULL)
        {
            cout << "\n\t\t LIST IS EMPTY\n";
            cout << "\t\t DELETION IS NOT POSSIBLE IN THE LIST\n";
        }
        else if (head->m.content == m.content)
        {
            MNode *temp = head;
            head = head->next;
            // head->pre = NULL;
            delete temp;
        }
        else if (tail->m.content == myNode->m.content)
        {
            MNode *temp = tail;
            tail = tail->pre;
            tail->next = NULL;
            temp->pre = NULL;
            delete temp;
        }
        else
        {
            MNode *temp = head;
            // Node* t2 = tail;
            while (temp != NULL)
            {
                if (temp->m.content != myNode->m.content)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            temp->next = NULL;
            temp->pre = NULL;
            delete temp;
        }
    }
    void DisplayMessage()
    {
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t Message Tab" << endl;
        cout << "\t\t-------------------------------------------\n"
             << endl;
        MNode *temp = head;
        if (head == NULL)
        {
            cout << "\t\tEMPTY" << endl;
        }

        else
        {
            do
            {

                cout << "\n\t\t-------------------------------------------" << endl;
                cout << "\t\t\t\t View Message" << endl;
                cout << "\t\t-------------------------------------------\n"
                     << endl;
                temp->m.viewmessage();
                temp = temp->next;

            } while (temp != NULL);
        }
    }
};

int main()
{
    // FriendTab
    // Classes objects
    SignUp S1;

    MessageLinking m1;
    FriendLinking f3;
    // PostLinking p;
    string name;
    Node *match = NULL;
    Node *input = NULL;
    FNode *in = NULL;

    int choice1;
l1:
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\n\t\t\tWELCOME THE SYSTEM OF" << endl;
    cout << " \n\t\tHAFIZ ABDUL REHMAN AND HUAIFA HAFEEZ" << endl;
    // cout << "\t\t-------------------------------------------"<<endl;
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\tGENERAL MENU" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. For Sign Up    :  " << endl;
    cout << "\t\tPress 2. For Sign In    :  " << endl;
    cout << "\t\tPress 3. For End/Break  :  ";
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice1;
    while (choice1 < 1 || choice1 > 3)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 3)    :     ";
        cin >> choice1;
    }
    if (choice1 == 1)
    {
        system("CLS");
        S1.insertUser();
        cout << "\n\n\n\t\t==================================================\n";
        cout << "\t\t\t USER SIGN UP SUCCESSFULLY\n";
        cout << "\t\t==================================================\n\n";
        system("Pause");

        system("CLS");
        goto l1; // go to Main Menu
    }
    else if (choice1 == 2)
    {
    lab1:
        system("CLS");
        match = S1.input11();
        if (match)
        {

            cout << "\n\n\n\t\t==================================================\n";
            cout << "\t\t\t USER LOG IN SUCCESSFULLY\n";
            cout << "\t\t==================================================\n\n";
            system("Pause");
            goto l2; // go to personal Tab after successfully log in
        }
        else
        {
            cout << "\n\n\t\t\t-----------------------------------";
            cout << "\n\t\t\t\tUSER NOT EXIT !      " << endl;
            cout << "\t\t\t-----------------------------------" << endl;

            cout << "\n\t\tPRESS 1) TO Retry     :   " << endl;
            cout << "\t\tPRESS 2) TO Go Back   :   " << endl;
            cout << "\t\t-----------------------------------\n";
            int cho;
            cout << "\n\n\t\tENTER CHOICE   :     ";
            cin >> cho;
            while (cho < 0 || cho > 3)
            {
                cout << "\n\t\tEnter Nuber between range(1 OR 2)    ";
                cin >> cho;
            }
            if (cho == 1)
            {
                goto lab1; // go to again check
            }
            else
            {

                system("CLS");
                goto l1; // go to Main Menu
            }
        }
    }
    else if (choice1 == 3)
    {
        system("CLS");
        exit(0);
    }

l2:
    system("CLS");
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\tSUCCESSFUL LOGIN/MAIN MENU" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. For Personal Tab    :  " << endl;
    cout << "\t\tPress 2. For Home Tab        :  " << endl;
    cout << "\t\tPress 3. For Friend Tab      :  " << endl;
    cout << "\t\tPress 4. For Messages Tab    :  " << endl;
    cout << "\t\tPress 5. For Log Out         :  ";
    int choice2;
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice2;
    while (choice2 < 1 || choice2 > 5)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 5)    :     ";
        cin >> choice2;
    }
    if (choice2 == 1)
    {
        system("CLS");
        goto l3; // Personal Tab
    }
    else if (choice2 == 2)
    {
        system("CLS");
        goto l4; // Home Tab
    }
    else if (choice2 == 3)
    {
        system("CLS");
        goto l5; // Friends Tab
    }
    else if (choice2 == 4)
    {
        system("CLS");
        goto l6; // Message Tab
    }
    else if (choice2 == 5)
    {
        system("CLS");
        goto l1; // go to Main Menu
    }
l3:
    system("CLS");
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\tPERSONAL TAB" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. For Add Post              :  " << endl;
    cout << "\t\tPress 2. For View Post             :  " << endl;
    cout << "\t\tPress 3. For Delete/Update Post    :  " << endl;
    cout << "\t\tPress 4. For Back The Main Menu    :  ";
    int choice3;
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice3;
    while (choice3 < 1 || choice3 > 4)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 4)    :     ";
        cin >> choice3;
    }
    if (choice3 == 1)
    {
        // Add Post
        system("CLS");
        match->p2->InsertPost();
        cout << "\n\n";
        system("Pause");
        system("CLS");
        goto l3; // Personal Tab
    }
    else if (choice3 == 2)
    {
        // View post
        system("CLS");
        match->p2->displayPost();
        cout << "\n\n";
        system("Pause");
        system("CLS");
        goto l3; // Personal Tab
    }
    else if (choice3 == 3)
    {
        // Delete Post
    del:
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\tDELETE/UPDATE MAIN MENU" << endl;
        cout << "\t\t-------------------------------------------" << endl;
        cout << "\n\t\tPress 1) To Delete a Post                         :  " << endl;
        cout << "\t\tPress 2) To Update a Post                         :  " << endl;
        cout << "\t\tPress 3) To Go back To Personal Tab               :  " << endl;
        int c, pno;
        cout << "\n\n\n\t\tEnter Choice   :       ";
        cin >> c;
        while (c < 1 || c > 3)
        {
            cout << "\n\n\t\tError ! Again Input in a Range (1 to 3)    :     ";
            cin >> c;
        }
        if (c == 1)
        {
            system("CLS");
            cout << "\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\tDELETE POST" << endl;
            cout << "\t\t-------------------------------------------\n\n"
                 << endl;
            cout << "\n\t\t Enter Post No  :     ";
            cin >> pno;
            while (pno < 0)
            {
                cout << "\n\n\t\tERROR ! INVALED POST NO \n\n";
                cin >> pno;
            }
            match->p2->remove(pno);
            cout << "\n\n\n\t\t==================================================\n";
            cout << "\t\t\t DELETE POST SUCCESSFULLY\n";
            cout << "\t\t==================================================\n\n";
            system("pause");
            goto del; // for Updation and Deletion
        }
        // Update Post
        else if (c == 2)
        {
            char in;
            system("CLS");
            cout << "\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\tUPDATE POST" << endl;
            cout << "\t\t-------------------------------------------\n\n"
                 << endl;
            cout << "\n\t\t Enter Post No  :     ";
            cin >> pno;
            while (pno < 0)
            {
                cout << "\n\n\t\tERROR ! INVALED POST NO \n\n";
                cin >> pno;
            }
            match->p2->Update(pno);
            cin.ignore();
            cout << "\n\n\n\t\t\t Do You Want to Go Back To Personal Tab  (Y/N)  :      ";
            cin >> in;
            if (in == 'Y' || in == 'y')
            {
                system("CLS");
                goto l3; // Personal Tab
            }
            else if (in == 'N' || in == 'n')
            {
                system("CLS");
            }
        }
        // Personal Tab
        else if (c == 3)
        {
            system("pause");
            system("CLS");
            goto l3; // go to Personal Tab
        }
    }
    else if (choice3 == 4)
    {
        system("CLS");
        goto l2; // go to Main Menu
    }

l4:
    system("CLS");
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\tHOME TAB" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. To Add Post                        :  " << endl;
    cout << "\t\tPress 2. For View Post                      :  " << endl;
    cout << "\t\tPress 3. For Delete/Update Post             :  " << endl;
    cout << "\t\tPress 4. For Add/View Comment		    :  " << endl;
    cout << "\t\tPress 5. For Back The Main Menu	            :  ";
    int choice4;
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice4;
    while (choice4 < 1 || choice4 > 5)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 5)    :     ";
        cin >> choice4;
    }
    if (choice4 == 1)
    {

        // Add post / upload
        system("CLS");
        match->p2->InsertPost();
        cout << "\n\n";
        system("Pause");
        system("CLS");
        goto l4;
    }
    else if (choice4 == 2)
    {
        system("CLS");
        // User Post
        match->p2->displayPost();
        cout << "\n\n";
        // Friends Post
        try
        {
            if (input == NULL)
            {
                throw input;
            }
            if (input = S1.SearchN(match->f2->Friends()))
            {
                while (input != NULL)
                {
                    input->p2->displayPost();
                    input = input->next;
                }
            }
        }
        catch (Node *input)
        {
            cout << "\n\t\tException Throw\n\n";
        }
        if (input = S1.SearchN(match->f2->Friends()))
        {
            while (input != NULL)
            {
                input->p2->displayPost();
                input = input->next;
            }
        }

        system("Pause");
        system("CLS");
        goto l4; // Home Tab
    }
    else if (choice4 == 3)
    {
        // Delete/Update Post

    del1:
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\tDELETE/UPDATE MAIN MENU" << endl;
        cout << "\t\t-------------------------------------------" << endl;
        cout << "\n\t\tPress 1) To Delete a Post                         :  " << endl;
        cout << "\t\tPress 2) To Update a Post                         :  " << endl;
        cout << "\t\tPress 3) To Go back To Personal Tab               :  " << endl;
        int c, pno;
        cout << "\n\n\n\t\tEnter Choice   :       ";
        cin >> c;
        while (c < 1 || c > 3)
        {
            cout << "\n\n\t\tError ! Again Input in a Range (1 to 3)    :     ";
            cin >> c;
        }
        if (c == 1)
        {
            system("CLS");
            cout << "\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\tDELETE POST" << endl;
            cout << "\t\t-------------------------------------------\n\n"
                 << endl;
            cout << "\n\t\t Enter Post No  :     ";
            cin >> pno;
            while (pno < 0)
            {
                cout << "\n\n\t\tERROR ! INVALED POST NO \n\n";
                cin >> pno;
            }
            match->p2->remove(pno);
            cout << "\n\n\n\t\t==================================================\n";
            cout << "\t\t\t DELETE POST SUCCESSFULLY\n";
            cout << "\t\t==================================================\n\n";
            system("pause");
            goto del1; // for Updation and Deletion
        }
        // Update Post
        else if (c == 2)
        {
            char in;
            system("CLS");
            cout << "\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\tUPDATE POST" << endl;
            cout << "\t\t-------------------------------------------\n\n"
                 << endl;
            cout << "\n\t\t Enter Post No  :     ";
            cin >> pno;
            while (pno < 0)
            {
                cout << "\n\n\t\tERROR ! INVALED POST NO \n\n";
                cin >> pno;
            }
            match->p2->Update(pno);
            cin.ignore();
            cout << "\n\n\n\t\t\t Do You Want to Go Back To Personal Tab  (Y/N)  :      ";
            cin >> in;
            if (in == 'Y' || in == 'y')
            {
                system("CLS");
                goto l4; // Home Tab
            }
            else if (in == 'N' || in == 'n')
            {
                system("CLS");
            }
        }
        // Home Tab
        else if (c == 3)
        {
            system("pause");
            system("CLS");
            goto l4; // go to Home Tab
        }
    }
    else if (choice4 == 4)
    {
        CommentLinking c;
        int cn;
        // Add/View CommentLinking
    comm:
        system("CLS");
        cout << "\n\t\t-------------------------------------------" << endl;
        cout << "\t\t\tVIEW/ADD Comment" << endl;
        cout << "\t\t-------------------------------------------" << endl;
        cout << "\n\t\tPress 1) To Add Comment on a Post                          :  " << endl;
        cout << "\t\tPress 2) To View Comment on a Post                         :  " << endl;
        cout << "\t\tPress 3) To Go back To Home Tab                            :  " << endl;
        cout << "\n\n\n\t\tEnter Choice   :       ";
        cin >> cn;
        while (cn < 1 || cn > 3)
        {
            cout << "\n\n\t\tError ! Again Input in a Range (1 to 3)    :     ";
            cin >> cn;
        }
        if (cn == 1)
        {
            system("CLS");
            int pno = match->p2->p1.pno;
            c.addComment(match, pno);
            cout << "\n\n\n\t\t==================================================\n";
            cout << "\t\t\t COMMENT ADDED SUCCESSFULLY\n";
            cout << "\t\t==================================================\n\n";
            cout << "\n\n";
            system("pause");
            goto comm; // Comment Main Menu
        }
        else if (cn == 2)
        {
            system("CLS");
            int p = match->p2->p1.pno;
            c.viewComment(match, p);
            cout << "\n\n";
            system("pause");
            goto comm;
        }
        else if (cn == 3)
        {
            system("pause");
            system("CLS");
            goto l4;
        }
    }
    else if (choice4 == 5)
    {
        system("CLS");
        goto l2;
    }

l5:
    system("CLS");
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\tFRIENDS TAB" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. To Add Friends           :  " << endl;
    cout << "\t\tPress 2. To View My Friends       :  " << endl;
    cout << "\t\tPress 3. To Back The Main Menu    :  ";
    int choice5;
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice5;
    while (choice5 < 1 || choice5 > 3)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 5)    :     ";
        cin >> choice5;
    }
    if (choice5 == 1)
    {
        // Add Friend
        int c;
        system("CLS");
        if (match)
        {
        z:
            system("CLS");
            cout << "\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\tFRIENDS MAIN MENU" << endl;
            cout << "\t\t-------------------------------------------\n\n"
                 << endl;
            cout << "\n\t\t Press 1) To Visit Profile ";
            cout << "\n\t\t Press 2) To ADD/Follow ";
            cout << "\n\t\t Press 3) To Unfollow Friend";
            cout << "\n\t\t Press 4) To Go Back ";
            cout << "\n\n\t\t Enter Choice   :      ";
            cin >> c;
            while (c < 1 || c > 4)
            {
                cout << "\n\n\t\tError ! Again Input in a Range (1 to 4)    :     ";
                cin >> c;
            }
            if (c == 1)
            {
                // Profile Visit
                system("CLS");
                cout << "\n\t\t-------------------------------------------" << endl;
                cout << "\t\t\tUSER PROFILE VISIT" << endl;
                cout << "\t\t-------------------------------------------\n\n"
                     << endl;
                cout << "\n\t\tEnter the name you want to Follow    :     ";
                cin.ignore();
                getline(cin, name);
                if (input = S1.SearchN(name))
                {
                    input->p2->displayPost();
                }
                cout << endl
                     << endl;
                system("pause");
                system("CLS");
                goto z; // Friends Main Menu
            }
            else if (c == 2)
            {
                // Add Friend List
                system("CLS");
                cout << "\n\n\n\t\t==================================================\n";
                cout << "\t\t\t\t FRIENDS TAB\n";
                cout << "\t\t==================================================\n\n";
                cout << "\n\t\tEnter the name you want to Follow:     ";
                cin.ignore();
                getline(cin, name);
                if (S1.Search(name) == true)
                {
                    match->f2->AddFriendList(name);
                    cout << "\n\t\t---------------------------------------------------" << endl;
                    cout << "\t\t\tFRIENDS ADDED SUCCESSFULLY IN THE LIST" << endl;
                    cout << "\t\t---------------------------------------------------\n\n"
                         << endl;
                }
                else
                {
                    cout << "\n\n\t\tUSER NOT EXIT WITH THAT NAME\n\n";
                }
                system("pause");
                system("CLS");
                goto z; // Friends Main Menu
            }
            else if (c == 3)
            {
                // Unfollow Friends
                system("CLS");
                string u;
                system("CLS");
                cout << "\n\t\t-------------------------------------------" << endl;
                cout << "\t\t\tUN-FOLLOW FRIENDS" << endl;
                cout << "\t\t-------------------------------------------\n\n"
                     << endl;
                cout << "\n\t\tEnter the name you want to Un-Follow    :     ";
                cin.ignore();
                getline(cin, u);
                match->f2->UnfollowFrnd(u);
                cout << "\n\t\t----------------------------------------------------------" << endl;
                cout << "\t\t\tFRIENDS UN-FOLLOW SUCCESSFULLY FROM THE LIST" << endl;
                cout << "\t\t----------------------------------------------------------\n\n"
                     << endl;
                system("Pause");
                goto z; // Friends Main Menu
            }
            else if (c == 4)
            {
                goto l5; // Friends Tab
            }
        }
        else
        {
            cout << "USER NOT EXIST \n\n\n";
        }
    }
    else if (choice5 == 2)
    {
        // View Friends
        system("CLS");
        cout << "\n\n\n\t\t==================================================\n";
        cout << "\t\t\t\t DISPLAY ALL FRIENDS\n";
        cout << "\t\t==================================================\n\n";
        match->f2->ViewFriends();
        cout << "\n\n";
        system("pause");
        system("CLS");
        goto z; // Friends Main Menu
    }
    else if (choice5 == 3)
    {
        system("CLS");
        goto l2; // Go back To Log In Menu
    }

l6:
    system("CLS");
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << "\t\t\tMESSAGE TAB" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\n\t\tPress 1. For Select Friend/Send Message         :  " << endl;
    cout << "\t\tPress 2. For View Message                       :  " << endl;
    cout << "\t\tPress 3. For Delete Message			:  " << endl;
    cout << "\t\tPress 4. For Back The Main Menu                 :  ";
    int choice6;
    cout << "\n\n\t\tEnter Choice     :        ";
    cin >> choice6;
    while (choice6 < 1 || choice6 > 4)
    {
        cout << "\n\n\t\tError ! Again Input in a Range (1 to 4)    :     ";
        cin >> choice6;
    }
    if (choice6 == 1)
    {
        // Send Message
        system("CLS");
        FNode *tp = match->f2->head;
        m1.SendMessage(tp);
        system("CLS");
        goto l6;
    }
    else if (choice6 == 2)
    {
        // view Message
        m1.DisplayMessage();
        system("pause");
        system("CLS");
        goto l6;
    }
    else if (choice6 == 3)
    {
        // Delete Meggage

        FNode *t = match->f2->head;
        m1.DeleteMsg(t);
        cout << "\n\n\n\t\t==================================================\n";
        cout << "\t\t\t MESSAGE DELETED SUCCESSFULLY\n";
        cout << "\t\t==================================================\n\n";
        system("pause");
        system("CLS");
        goto l6;
    }
    else if (choice6 == 4)
    {
        system("CLS");
        goto l2; // go to main menu(login)
    }

    char ch;
    cout << "\n\t\tDo you want to back the main Menu  (Y/N)  :    ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        system("CLS");
        goto l1;
    }
    else if (ch == 'N' || ch == 'n')
    {
        system("CLS");
        goto l1; // Log In Menu
        // exit(0);
    }
    system("Pause");
    return 0;
}