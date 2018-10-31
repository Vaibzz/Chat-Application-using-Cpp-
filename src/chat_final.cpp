#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void page1();
void page2(string);
map<string,string> user;

class frnd
{
    vector<string> flist;
    struct chat
    {
    int message_id;
    string sender,receiver;
    char mess[50][100];
    int num_of_message=0;
    };

public:
    map<string,chat> sms;
    void addfrnd(string);
    void unfrnd(string);
    void dispfrnd(string);
    void chat_on(string,string,char*);
    void inbox(string);
};



void frnd::chat_on(string uname,string reciepient,char *message)
{
    int flag=0;
    sms[reciepient].sender=uname;
    sms[reciepient].receiver=reciepient;
    map<string,string>::iterator iuser;
    for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            if(iuser->first==reciepient)
            {
                flag++;
            }
        }
        if(!flag)
        {
            cout<<"\nSorry!! No user found\a\a\n";
            page2(uname);
        }


    int i;
    char cuname[20];
    for(i=0;uname[i]!='\0';i++)
    {

        cuname[i]=uname[i];
    }
    strcpy(sms[reciepient].mess[sms[reciepient].num_of_message],cuname);
    strcat(sms[reciepient].mess[sms[reciepient].num_of_message],":  ");
    strcat(sms[reciepient].mess[sms[reciepient].num_of_message],message);



sms[reciepient].num_of_message++;
}



void frnd::inbox(string uname)
{
    cout<<"\nWelcome "<<uname<<" to your Inbox\n\n";
    cout<<"All Messages in your Inbox:\n\n";
    for(int i=0;i<=sms[uname].num_of_message;i++)
    {
        puts(sms[uname].mess[i]);
        cout<<endl<<endl;
    }
}

void frnd::addfrnd(string uname)
{
    vector<string>::iterator iv;
    map<string,string>::iterator iuser;
   int uflag=0,flag=0,flag3=0;
 string addname;
 cout<<"\nEnter the name which you want to add in your friend list"<<endl;
 cin>>addname;
 cout<<"\nPlease wait! checking for  "<<addname<<"......\n";
 // waiting time for new mwssage
for(int i=0;i<99999910;)
{
i++;
}
 for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            for(iv=flist.begin();iv!=flist.end();iv++)
            {
               if(*iv==addname)
                    flag3++;
            }
            if(addname==uname)
            {

                uflag++;
                break;
            }



            else if(iuser->first==addname)
             flag++;

}
//error for trying to add yourself as your friend
if(uflag==1 && flag==0 && flag3==0)
    cout<<"\nSorry! Can't add yourself to your friend list\n";
if(flag==1 && uflag==0 && flag3==0)
{
  cout<<"\nFound\t"<<addname<<endl;
  flist.push_back(addname);
  cout<<"\nCongratulations! "<<addname<<" has been added to your friend list\n"<<endl;

}
else if(uflag==0&&flag==0)
    {
    cout<<"\nSorry!! this username does not exist\n";
    }
else if(flag3)
{
    cout<<"\n"<<addname<<" already exists in your friend list\n";
}

}

void frnd::dispfrnd(string uname)
{
    int c=0;
    vector<string>::iterator i;
    i=flist.begin();
    cout<<"\nWelcome "<<uname<<" Your Friends are:"<<endl;
    for(;i!=flist.end();i++)
    {
        cout<<"\n"<<*i<<endl;
        c++;
    }
    cout<<endl<<endl<<"\nTotal friends: "<<c;
}

void frnd::unfrnd(string uname)
{
    if(flist.empty())
    {
        cout<<"\nFriend list empty..!!\a\n";
    }
    else{
    int c=0,pos=0,flag=0;
    string name;
    cout<<"\nenter the friend name you want to unfriend \n";
    cin>>name;
    vector<string>::iterator i;
    i=flist.begin();

    for(;i!=flist.end();i++)
    {
        c++;
        if(*i==name)
        {
            flag++;
          pos=c-1;
          break;
        }
    }

    i=flist.begin();
    if(pos || flag)
    {
        cout<<"\n Removing "<<name<<" from your friend list..\a\a\a\a\n";
        flist.erase(i+pos);
        cout<<name<<" has been successfully removed from your friend list\n";
    }
    if(flag==0 && pos==0)
    {
        cout<<"\nNo such friend exists in your friend list\n";
    }
}
}

void page1()
{
    int flag=0,choice;

cout<<"\n\t\t\tWELCOME TO THE V-MESSENGER\n";




    while(1)
{

cout<<"\nPlease Enter your choice\n  1-Sign_up\n  2-Sign_in\n  3-Exit \n \n"<<endl;
cin>>choice;

switch(choice)
{
case 1:
    {

        string username,pwd;
        cout<<"\nchoose a username\n";
        cin>>username;
        cout<<"\nchoose a password\n";
        cin>>pwd;
map<string,string>::iterator iuser;
        if(user.empty())
        {
        user[username]=pwd;
        }
        else
        {

        for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            if(iuser->first==username)
            {
                cout<<"\nSorry! username not available..please try with some other name\n";
                break;
            }
            else
              {user[username]=pwd;
              break;}
        }
        }
    break;
    }


 case 2:
    {

        string lusername,lpwd;
        cout<<"\nenter your username\n";
        cin>>lusername;
        cout<<"\nenter your password\n";
        cin>>lpwd;
        map<string,string>::iterator iuser;
        for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            if(iuser->first==lusername && iuser->second==lpwd)
            {
                    cout<<"\nWELCOME "<<lusername<<"!!  You have successfully logged in \n";

                    flag=1;
                    page2(lusername);
                    break;

            }}


            if(flag==0)
                {
                    cout<<"\nusername or password incorrect\n\t!!Please try again\n";
                    break;
                }

break;
        }


case 3:
    {

        cout<<"\ndisplay\n";
        map<string,string>::iterator iuser;
        cout<<"\nall users\n";
for(iuser=user.begin();iuser!=user.end();iuser++)
{
    cout<<iuser->first<<"\t"<<iuser->second;
}
        break;
    }

}
if(flag==1)
                {
                    break;
                }
}
}


map<string,frnd> f;
void page2(string uname)
{
   
int choice2,choice3;
main_menu:
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t     WELCOME    "<<uname<<endl<<endl;
   
    cout<<"\n\t    ***********Choose from following menu**********\n";
    cout<<"\n1-Inbox\n2-Chat\n3-Friend_list\n4-Add friend\n5-Unfriend\n6-Group chat\n7-Log out\n";
    cin>>choice2;
    switch(choice2)
    {
    case 1:
      {

            f[uname].inbox(uname);
 cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
        if(choice3)
        goto main_menu;

break;
        }
    case 2:
        {
            string reciepient;
            cout<<"\nPlease enter the reciepient's name:\n";
            cin>>reciepient;
            char message[100];
        cout<<"\nPlease Type Your message :"<<endl;
        cin.ignore();
        cin.getline(message,100);
            f[reciepient].chat_on(uname,reciepient,message);
            cout<<"\nYour message has been sent\n";
            cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
        if(choice3)
        goto main_menu;

break;

        }
    case 3:
        {
           f[uname].dispfrnd(uname);
           cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
        if(choice3)
        goto main_menu;
      break;
       }
    case 4:
        {
        f[uname].addfrnd(uname);
        cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
if(choice3)
        goto main_menu;
        break;
        }
    case 5:
        {
        f[uname].unfrnd(uname);
        cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
if(choice3)
        goto main_menu;
        break;}


    case 6:
        {

    char ch;

    vector<string>rec;
    map<string,string>::iterator iuser;
    vector<string>::iterator irec;
group:
    int flag=0;
        string reciepient;
    cout<<"Enter reciepient";
    cin>>reciepient;

    for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            if(iuser->first==reciepient)
            {
                flag++;
            }
        }
        if(!flag)
        {
            cout<<"\nSorry!! No such user exist\a\a\n";
            goto group;
        }

    rec.push_back(reciepient);
    cout<<"Do you want to add more reciepients (y/n)?\n";
    cin>>ch;

    if(ch=='y')
        goto group;

    else if(ch=='n')
    {
         char message[100];
        cout<<"\nPlease Type Your message :"<<endl;
        cin.ignore();
        cin.getline(message,100);
         for(irec=rec.begin();irec!=rec.end();irec++)
        {
            f[*irec].chat_on(uname,*irec,message);
        }
    }
    cout<<"\nYour message has been sent\n";
    cout<<"\npress any number except '0' to go back to main menu\n";
        cin>>choice3;
if(choice3)
        goto main_menu;
        break;
        }

case 7:
    {
        system("cls");
        cout<<"\nyou have been successfully logged out\n";

        page1();


        break;

    }
}
}



int main()
{
page1();
return 0;
}
