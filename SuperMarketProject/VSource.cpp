#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


struct Item{                 // nodes
   public:
    int serialNumber;
    int cartnumber = 0;
    int quantity;
    double price;
    string name;
};

int SI = 0,TSI = 0;
vector<Item> AllItems;
vector<Item> CartItems;

class Inventory{       // Inventory management
   public:
    void Create_Inventory(); 
    void Display_Inventory();

    void Alphabetical_Order();
    void Price_Ascending();
    void Quantity_Ascending();

    void SI_Order();

    int Search_By_Name(const string& itemName);
};

class Cart{          // Cart
   public: 
    int cartSerialNumber;

    void display_Cart();
    void insert_Cart(int a);
    void insert_Cart();
    void remove_Cart();
};

int main()           // main body
{
    int mopt, copt, dopt, aopt, n;
    string searchname;
    Inventory mall;
    Cart user;
    mall.Create_Inventory();
    system("cls");
    cout << "--------------Welcome to Super Market----------------\n";
    cout << "Here are the items we have:\n\n";
    mall.Display_Inventory();

    do{
        cout << "Select the below options:\n";
        cout << "( 1 ) Cart Options\n";
        cout << "( 2 ) Display Options\n";
        cout << "( 3 ) Search\n";
        cout << "( 4 ) Exit\n";
        cout << "\nOption: ";
        cin >> mopt;

        switch(mopt)
        {
            case 1:
                do{
                    //system("cls");
                    cout << "Select the below Cart Options:\n";
                    cout << "( 1 ) Insert an item in cart\n";
                    cout << "( 2 ) Delete an item in cart\n";
                    cout << "( 3 ) Display Cart / Bill\n";
                    cout << "( 4 ) Go back\n";
                    cout <<"\nOption: ";
                    cin >> copt;

                    switch(copt)
                    {
                        case 1:
                            mall.Display_Inventory();
                            user.insert_Cart();
                            break;
                        case 2:
                            user.display_Cart();
                            user.remove_Cart();
                            break;
                        case 3:
                            user.display_Cart();
                            break;
                        case 4:
                            cout << "Going back\n";
                            break;
                        default:
                            cout << "Enter correct option.\n";
                    }

                }while(copt != 4);
                break;
            case 2:
                do{
                    //system("cls");
                    cout << "Select below display options:\n";
                    cout << "( 1 ) Display by serial number\n";
                    cout << "( 2 ) Display by item name\n";
                    cout << "( 3 ) Display by quantity\n";
                    cout << "( 4 ) Display by price\n";
                    cout << "( 5 ) Go back\n";
                    cout << "\nOption: ";
                    cin >> dopt;

                    switch(dopt)
                    {
                        case 1:
                            mall.SI_Order();
                            mall.Display_Inventory();
                            break;
                        case 2:
                            mall.Alphabetical_Order();
                            mall.SI_Order();
                            break;
                        case 3:
                            mall.Quantity_Ascending();
                            mall.SI_Order();
                            break;
                        case 4:
                            mall.Price_Ascending();
                            mall.SI_Order();
                            break;
                        case 5:
                            cout << "Going back\n";
                            break;
                        default:
                            cout << "Enter the correct option\n";
                    }

                }while(dopt != 5);
                break;
            case 3:
                cout << "Enter name of the item you are looking for: ";
                cin >> searchname;
                n = mall.Search_By_Name(searchname);
                if(n == 0)
                {
                    break;
                }
                else
                {
                    do{
                        cout << "( 1 ) Add to cart\n";
                        cout << "( 2 ) Go back\n";
                        cout <<"\nOption: ";
                        cin >> aopt;

                        switch(aopt)
                        {
                            case 1:
                            user.insert_Cart(n);
                                break;
                            case 2:
                                cout << "Going back\n";
                                break;
                            default:
                                cout << "Enter the correct option\n";
                        }

                    }while(aopt != 2);
                    break;
                }
                    
                case 4:
                    cout <<"Thank you for shopping\n";
                    break;
                default:
                    "Enter the correct option\n";
        }

    }while(mopt != 4);

   return 0;
}

void Inventory::Create_Inventory()
{
   Item temp;
   fstream fileItems,fileQuantity,filePrices;              // creating files
   fileItems.open("Items.txt",ios::in);
   fileQuantity.open("Quantity.txt",ios::in);
   filePrices.open("Prices.txt",ios::in);
   string strItems;
   int intQuantity;
   float flPrices;

   while(getline(fileItems,strItems))
   {
      temp = Item();
      SI++;
      temp.serialNumber = SI;
      fileQuantity >> intQuantity;
      filePrices >> flPrices; 
      temp.name = strItems;
      temp.price = flPrices;
      temp.quantity = intQuantity;
      //cout << *temp->name << "\t" << temp->quantity << "\t" << temp->price <<endl;
      AllItems[SI];
      AllItems.push_back(temp);
   }

   fileItems.close();                    // closing files
   fileQuantity.close();
   filePrices.close();
}

void Inventory::Display_Inventory() 
{
    cout << "SI  Items   Quantity  Total\n";
   for(int i=0; i<=(SI-1); i++)
   {
        if (AllItems[i].serialNumber == 5)
        {
            cout <<AllItems[i].serialNumber << ". " << AllItems[i].name << "\t\t"
                << AllItems[i]. quantity << "\t" << AllItems[i].price << "\n";
        }
        else
        {

            cout <<AllItems[i].serialNumber << ". " << AllItems[i].name << "\t"
                << AllItems[i]. quantity << "\t" << AllItems[i].price << "\n";
        }
   }
   cout <<"\n";
}

void Inventory::Alphabetical_Order()
{
   sort(AllItems.begin(), AllItems.end(), [](const Item& a, const Item& b) {
        return a.name < b.name;
    });
    
    cout << "\nItems in Alphabetical Order:\n";
    cout << "SI  Items   Quantity  Price\n";
    for (const auto& item : AllItems) 
    {
        if (item.serialNumber == 5)
        {
            cout <<item.serialNumber << ". " << item.name << "\t\t"
                << item. quantity << "\t" << item.price << "\n";
        }
        else
        {

            cout <<item.serialNumber << ". " << item.name << "\t"
                << item. quantity << "\t" << item.price << "\n";
        }
    }
}

void Inventory::Price_Ascending()
{
   sort(AllItems.begin(), AllItems.end(), [](const Item& a, const Item& b) {
        return a.price < b.price;
    });
    
    cout << "\nItems in Ascending Price Order:\n";
    cout << "SI  Items   Quantity  Price\n";
    for (const auto& item : AllItems) 
    {
        if (item.serialNumber == 5)
        {
            cout <<item.serialNumber << ". " << item.name << "\t\t"
                << item. quantity << "\t" << item.price << "\n";
        }
        else
        {

            cout <<item.serialNumber << ". " << item.name << "\t"
                << item. quantity << "\t" << item.price << "\n";
        }
    }
}

void Inventory::Quantity_Ascending()
{
   sort(AllItems.begin(), AllItems.end(), [](const Item& a, const Item& b) {
        return a.quantity < b.quantity;
    });
    
    cout << "\nItems in Ascending Quantity Order:\n";
    cout << "SI  Items   Quantity  Price\n";
    for (const auto& item : AllItems) 
    {
        if (item.serialNumber == 5)
        {
            cout <<item.serialNumber << ". " << item.name << "\t\t"
                << item. quantity << "\t" << item.price << "\n";
        }
        else
        {

            cout <<item.serialNumber << ". " << item.name << "\t"
                << item. quantity << "\t" << item.price << "\n";
        }
    }
}

void Inventory::SI_Order()
{
    sort(AllItems.begin(), AllItems.end(), [](const Item& a, const Item& b) {
        return a.serialNumber < b.serialNumber;
    });
}

int Inventory::Search_By_Name(const string& itemName) 
{
    for (const auto& item : AllItems) 
    {
        if (item.name == itemName) 
        {
            cout << "\nItem Found:\n";
            cout << item.serialNumber << ". " << item.name
                 << "\t" << item.quantity << "\t" << item.price << endl;
            return item.serialNumber;
        }
    }
    
    cout << "\nItem '" << itemName << "' not found in inventory.\n";
    return 0;
}

void Cart::display_Cart()
{                        
    int gtotal=0;
    time_t TIME = time(NULL);
    cout <<"\n";
    cout << ctime(&TIME) << endl;                           // Add date and time. 
    cout << "SI  Items   Quantity  Total\n";
    for(int i=0; i<=(TSI-1); i++)
   {
      cout <<i+1 << ".  " << CartItems[i].name << "\t"
            << CartItems[i]. quantity << "\t" << CartItems[i].price*CartItems[i].quantity << "\n";
            gtotal = gtotal + (CartItems[i].price*CartItems[i].quantity);
   }
   cout << "\nGrand Total:\t\t" << gtotal << endl;
   cout <<"\n";
}

void Cart::insert_Cart()
{
    int a,b,i;
    cout << "Enter SI number of item to add: ";
    cin >> a;
    Item temp;

    for(i=0; i<SI; i++)
    {
        if(AllItems[i].serialNumber == a)
        {
            temp = AllItems[i];
            do{
                cout << "Enter proper quantity: ";
                cin >> b;
            }while(b > AllItems[i].quantity);
            AllItems[i].quantity = AllItems[i].quantity - b;
            break;
        }
    }
    
    TSI++;
    temp.cartnumber = TSI;
    temp.quantity = b;
    CartItems.push_back(temp);
}

void Cart::insert_Cart(int a)
{
    int b,i;
    Item temp;

    for(i=0; i<SI; i++)
    {
        if(AllItems[i].serialNumber == a)
        {
            temp = AllItems[i];
            do{
                cout << "Enter proper quantity: ";
                cin >> b;
            }while(b > AllItems[i].quantity);
            AllItems[i].quantity = AllItems[i].quantity - b;
            break;
        }
    }
    
    TSI++;
    temp.cartnumber = TSI;
    temp.quantity = b;
    CartItems.push_back(temp);
}

void Cart::remove_Cart()
{
    int a;
    do{
    cout << "Enter SI number to remove: ";
    cin >> a;
    }while(a > TSI);
    
    for(int i=0; i<TSI; i++)
    {
        if(a == CartItems[i].cartnumber)
        {
            CartItems.erase(CartItems.begin() + (i));
            TSI--;
            while(i<TSI)
            {
                i++;
                CartItems[i].cartnumber--;
            }
        }
    }
}
