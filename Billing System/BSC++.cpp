#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________\n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t  SuperMarket Menu  \n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t____________________\n";
    cout<<"\t\t\t\t| 1) Administrator |\n";
    cout<<"\t\t\t\t|                  |\n";
    cout<<"\t\t\t\t| 2) Buyer         |\n";
    cout<<"\t\t\t\t|                  |\n";
    cout<<"\t\t\t\t| 3) Exit          |\n";
    cout<<"\t\t\t\t|                  |\n";
    cout<<"\n\t\t\t Please Select";
    cin>>choice;

    switch(choice)
    {
    case 1:

        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Password     \n";
        cin>>password;

        if(email=="tanmaydikshit12@gmail.com" && password=="Tanmay@21")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid Email/Password";
        }
        break;
    
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"Please Select from the given options";
    }
    }
goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|______1) Add the Product_____|";
    cout<<"\n\t\t\t                              |";
    cout<<"\n\t\t\t|______2) Modify the Product__|";
    cout<<"\n\t\t\t                              |";
    cout<<"\n\t\t\t|______3) Delete the Product__|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|______4) Back to main menu___|";

    cout<<"\n\n\t Please Enter Your Choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default:
        cout<<"Invalid Choice!";
    }
   goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"                \n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) Go Back     \n";
    cout<<"\t\t\t Enter Your Choice : ";

    cin>>choice;
    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();

        default:
        cout<<"Invalid Choice : ";

    }
   goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product Code of the Product";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product ";
    cin>>pname;
    cout<<"\n\n\t Price of the Product ";
    cin>>price;
    cout<<"\n\n\t Discount on the Product ";
    cin>>dis;

    data.open("Database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    if(token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t Record Inserted !";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product Code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File Doesn't Exist !";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product New Code : ";
                cin>>c;
                cout<<"\n\t\t Name of the Product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not Found Sorry!";
        }
    }
}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code :";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File Doesn't Exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token==0)
            {
                cout<<"\n\n Record Not Found";
            }
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n________________________________\n";
    cout<<"ProNo  Name  tPrice";
    cout<<"\n\n________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }

    else
    {
        data.close();
        list();
        cout<<"\n____________________________________\n";
        cout<<"\n|                                   \n";
        cout<<"\n      Please Place the Order        \n";
        cout<<"\n|                                   \n";
        cout<<"\n____________________________________\n";
        do
        {
            m:
            cout<<"\n\n Enter Product Code ";
            cin>>arrc[c];
            cout<<"\n\n Enter Product Quantity";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code !";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do You Want to buy another product? If Yes, Press Y Else N";
            cin>>choice;
        } while(choice=='y');

        cout<<"\n\n\t\t\t____________________RECEIPT_________________\n";
        cout<<"\n Product No \t Product Name \t Product Quantity \t Price \t Amount with Discount \n";

        for(int i=1;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<pname<<arrq[i]<<price<<amount<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n________________________";
    cout<<"\n Total Amount : "<<total;
}

int main()
{
    shopping s;
    s.menu();
}
