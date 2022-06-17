#include<iostream>
#include<fstream>
using namespace std;
class Details{
      private:
        int product_code;
        float discount;
        string product_name;
        float price;

      public:
        void mainMenu();
        void admin();
        void customer();
        void add();
        void modify();
        void rem();
        void list1();
        void receipt();
    };
    void Details :: mainMenu(){
        m :
         int choice;
         string email;
         string password;
         cout<<"\t\t\t\t\t______________________________________"<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"**********SUPERMARKET BILLING SYSTEM***********"<<endl;
         cout<<"\t\t\t\t\t______________________________________"<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t|       1.Admin                      |"<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t|       2.Customer                   |"<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t|       3.Exit                       |"<<endl;
         cout<<"\t\t\t\t\t                                      "<<endl;
         cout<<"\t\t\t\t\t        Please Select!                "<<endl;
         cin>>choice;
         switch(choice)
         {
       case 1:
           {
        cout<<"\t\t\t Please Log in.\t\t\t"<<endl;
        cout<<"\t\t\t Enter Email    \t\t\t"<<endl;
        cin>>email;
        cout<<"\t\t\t Enter Password \t\t\t"<<endl;
        cin>>password;
        if(email=="preeti@gmail.com" && password=="shopadmin"){
            admin();
        }
        else{
            cout<<"Invalid email/password"<<endl;

        }
           }
        break;
       case 2:
           {
            customer();
           }
        break;
       case 3:
        {
            exit(0);
        }
        break;
       default :
        {
            cout<<"Please Select from given options."<<endl;
        }

         }
         goto m;
    }





    void Details:: admin()
    {
        m:
      int choice;
      cout<<"\t\t\t\t\t\t Admin Menu \t\t\t\t\t\t"<<endl;
      cout<<"\n\t\t\|   1.Add the Product     |\t\t"<<endl;
      cout<<"\n\t\t\|   2.Modify the Product  |\t\t"<<endl;
      cout<<"\n\t\t\|   3.Remove the Product  |\t\t"<<endl;
      cout<<"\n\t\t\|   3.Back To Main Menu   |\t\t"<<endl;
      cout<<"Enter your Choice."<<endl;
      cin>>choice;
      switch(choice){
      case 1:
        add();
        break;

      case 2:
          modify();
          break;

      case 3:
        rem();
        break;

      case 4:
          mainMenu();
          break;
      default:
        cout<<"Invalid Input"<<endl;
    }
    goto m;
    }




    void Details::customer()
    {
     m:
    int choice;
    cout<<"\n\t\t    Customer    \t\t"<<endl;
    cout<<"                            "<<endl;
    cout<<"\n\t\t| 1.Buy the Product  |\t\t"<<endl;
    cout<<"\n\t\t| 2.Go Back          |\t\t"<<endl;
    cout<<"Enter your choice."<<endl;
    cin>>choice;
    switch(choice){
  case 1:
     receipt();
     break;

  case 2:
    mainMenu();
    break;
  default:
    cout<<"Invalid Choice."<<endl;
    }
    goto m;


}
void Details::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t  Add the Product  \t\t\t"<<endl;
    cout<<"\n\n\t\t\t  Enter the product code  \t\t\t"<<endl;
    cin>>product_code;
    cout<<"\n\n\t\t\t  Enter the product name  \t\t\t"<<endl;
    cin>>product_name;
    cout<<"\n\n\t\t\t  Enter the product price  \t\t\t"<<endl;
    cin>>price;
    cout<<"\n\n\t\t\t  Enter the product discount  \t\t\t"<<endl;
    cin>>discount;

    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;
        data.close();
    }

    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==product_code)
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
         data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;
        data.close();
    }
    }
    cout<<"record inserted."<<endl;

}


void Details::modify()
{

    fstream data ,data1;
    int product_key;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\n\n\t\t\t  Modify the Record  \t\t\t"<<endl;
     cout<<"\n\n\t\t\t  Enter the product code  \t\t\t"<<endl;
    cin>>product_key;


    data.open("database.txt",ios::in);

    if(!data)
    {

        cout<<"file doesn't exist"<<endl;
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>price>>discount;
        while(!data.eof())
        {
           if(product_key==product_code)
           {
                cout<<"\n\t\t\t  New Code of Product: "<<endl;
                cin>>c;
                cout<<"\n\t\t\t  New Name of Product: "<<endl;
                cin>>n;
                cout<<"\n\t\t\t  New Price of Product: "<<endl;
                cin>>p;
                cout<<"\n\t\t\t  New Discount of Product: "<<endl;
                cin>>d;

                data<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\t\t\t Record modified. "<<endl;
                token++;
           }
           else
           {
             data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
           }

           data>>product_code>>product_name>>price>>discount;
           }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");


        if(token==0)
        {
            cout<<"record not found"<<endl;

        }
    }


}


void Details::rem()
{
    fstream data,data1;
    int product_key;
    int token=0;
    cout<<"\n\n\t\t\t Delete Product.  \t\t"<<endl;
    cout<<"\t\t\t Enter the product code.  \t\t"<<endl;
    cin>>product_key;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist."<<endl;
    }

    else
    {
      data1.open("database.txt",ios::app|ios::out);
      data>>product_code>>product_name>>price>>discount;
      while(!data.eof())
      {
          if(product_code==product_key)
          {
              cout<<"\n\n\t\t\t Product Deleted Successfully.  \t\t\t"<<endl;
              token++;
          }
          else
          {
              data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
          }
          data>>product_code>>product_name>>price>>discount;
      }
      data.close();
      data1.close();
      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token==0)
      {
         cout<<"\t\t\t record not found \t\t\t"<<endl;
      }

    }

}


void Details::list1()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"*********************************************"<<endl;
    cout<<"Product No.\t\tProduct Name\t\tPrice\t\tDiscount\t\t"<<endl;
    data>>product_code>>product_name>>price>>discount;
    while(!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\t\t"<<discount<<"\t\t"<<endl;
        data>>product_code>>product_name>>price>>discount;
    }
    data.close();

}


void Details::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int count=0;
    float amount=0;
    float discount=0;
    float total=0;
    cout<<"\n\n\t\t\t  Receipt  \t\t\t"<<endl;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"Empty database"<<endl;
    }

    else
    {
        data.close();
        list1();
        cout<<"****************************************"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"        Please Place the Order          "<<endl;
        cout<<"|                                      |"<<endl;

    do
    {
    m:
     cout<<"\t\t\t Enter the product Code \t\t\t"<<endl;
     cin>>arrc[count];
     cout<<"\t\t\t Enter the product quantity \t\t\t"<<endl;
     cin>>arrq[count];
     for(int i=0;i<count;i++)
     {
         if(arrc[count]==arrc[i])
         {
             cout<<"\t\t Duplicate PRoduct Code.Please Try Again ."<<endl;
             goto m;
         }
     }
     count++;
     cout<<"\t\t Do you want to buy more products ? if yes then press y else press n. \t\t"<<endl;
     cin>>choice;


    }
    while(choice=='y');
    cout<<"************************* RECEIPT *************************"<<endl;
    cout<<"\t\tProduct Code\t\tPRoduct Name\t\tProduct Quantity\t\tPrice\t\tAmount\t\tAmount with Discount"<<endl;
    for(int i=0;i<=count;i++){
        data.open("database.txt",ios::in);
        data>>product_code>>product_name>>price>>discount;
        while(!data.eof())
        {
            if(product_code==arrc[i])
            {
                amount=price*arrq[i];
                discount=amount-(amount*discount/100);
                total=total+discount;
                cout<<endl<<"\t\t"<<product_code<<"\t\t"<<product_name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;
            }
            data>>product_code>>product_name>>price>>discount;
        }
    }
    data.close();
}
cout<<"\n\n__________________________________________________";
cout<<"\t\t\tTotal Amount: "<<total;
}


int main()
{
    Details obj;
    obj.mainMenu();
    return 0;

}













