#include<iostream>
using namespace std;
double fun(double x)
{
    return x*x*x-x*x-2;
}
void bisection(double a, double b, double eph)
{
    if (fun(a)*fun(b)>=0)
    {
        cout<<"Wrong initialization"<<endl;
        return;
    }
    double c;
    int itr = 1;

    while(b-a>=eph)
    {
        c = (a+b)/2;
        cout<<"a= "<<a<<"b= "<<b<<"c= "<<"f(a)= "<<fun(a)<<"f(c)= "<<fun(c);
        if(fun(c)==0.0)break;
        if(fun(a)*fun(c)>=0) a=c;
        else b=c;
        itr++;
    }
    cout<<"\nRoot : "<<c<<endl;
}

int main()
{
    double a,b;
    cin>>a>>b;
    bisection(a,b,0.008);
    return 0;
}
