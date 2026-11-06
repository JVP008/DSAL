#include<iostream>
using namespace std;

class Product
{
    private:
    int pid;
    char name[20];
    int price;

    public:
    void setData(int p,char nm[],int pr)
    {
        pid=p;
        int i=0;
        while(nm[i]!='\0')
        {
            name[i]=nm[i];
            i++;
        }
        name[i]='\0';
        price=pr;
    }

    int getPid()
    {
        return pid;
    }

    char* getName()
    {
        return name;
    }

    int getPrice()
    {
        return price;
    }

    void display()
    {
        cout<<pid<<" "<<name<<" "<<price<<endl;
    }
};

class List
{
    private:
    Product P[15];
    int n;

    int Partition(int l,int u);
    void quick(int l,int h);

    public:
    List()
    {
        n=0;
    }
    void Input();
    void display();
    void sort();
};

void List::Input()
{
    cout<<"Enter number of products: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int pid,price;
        char name[20];
        cout<<"Enter pid, name, price for product "<<i+1<<": ";
        cin>>pid>>name>>price;
        P[i].setData(pid,name,price);
    }
}

void List::display()
{
    for(int i=0;i<n;i++)
    {
        P[i].display();
    }
}

int List::Partition(int l,int u)
{
    int p=l;
    int q=u;
    Product v=P[p];
    while(p<q)
    {
        while(P[p].getPrice()<=v.getPrice() && p<u)
            p++;
        while(P[q].getPrice()>v.getPrice())
            q--;
        if(p<q)
        {
            Product temp=P[p];
            P[p]=P[q];
            P[q]=temp;
        }
    }
    P[l]=P[q];
    P[q]=v;
    return q;
}

void List::quick(int l,int h)
{
    int j;
    if(l<h)
    {
        j=Partition(l,h);
        quick(l,j-1);
        quick(j+1,h);
    }
}

void List::sort()
{
    quick(0,n-1);
}

int main()
{
    List L;
    L.Input();
    L.sort();
    L.display();
    return 0;
}