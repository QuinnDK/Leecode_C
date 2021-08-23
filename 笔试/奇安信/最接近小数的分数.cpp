#include<iostream>
using namespace std;

double abs(double a)
{
    if(a<=0)
        return -a;
    else
        return a;
}
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    double m;
    cin>>m;
    double minn=abs(0-m);
    int a=0,b=1;
    for(int i=1; i<=1000; i++)
    {
        int sum=(int)(i*m+0.5);
        if(sum<=i)
        {
            double f=sum*1.0/i;
            double k=abs(f-m);
            if(minn>k)
            {
                minn=k;
                a=sum;
                b=i;
            }
        }

    }
    int r=gcd(a,b);
    cout<<"["<<a/r<<","<<b/r<<"]"<<endl;
}