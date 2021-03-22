// here we will see how we can have multiple parameters in one template
#include<iostream>
#include<string>
using namespace std;

/*
template <class Tem1 , class Tem2 , ............>  rember parameters are separarted by comma
class name
{
    tem1 x;
    tem2 po();
    .
    .
    .
};
*/

template <class T1, class T2>
class income
{
    public:
        T1 salary;
        T2 job_category;
        income(){}
        income(T1 a,T2 b):salary(a),job_category(b){}
};

template < class T1>
class expense 
{
    public:
       T1 expend;
       expense(){}
       expense(T1 c):expend(c){}     
};

template < class T1, class T2>
class savings : public income<T1,T2> , public expense<T1>
{
    public:
        T1 saved;
        static int i;
        savings(T1 a,T2 b,T1 c):income<T1,T2>(a,b),expense<T1>(c)
        {
            saved = (income<T1,T2>::salary-expense<T1>::expend);
        }
        void result()
        {    
            cout<<"\njob describition of person "<<i<<" is "<<income<T1,T2>::job_category<<endl;
            cout<<"\nsaving of person"<<i<<" is"<<savings<T1,T2>::saved<<" in a month "<<endl;
            if((expense<T1>::expend)<(3*(income<T1,T2>::salary)/4))
            {
                cout<<"\nYour are on right path "<<endl;
            }
            else 
            {
                cout<<"\nSave money "<<endl;
            }
            i++;
        };

};

template <class T1,class T2>
int savings<T1,T2> :: i=1;

int main()
{
    int n;
    float  a,c;
    char b;
    cout<<"\nHow many persons are under consideration "<<endl;
    cin>>n;

    savings<float,char> *p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter salary of person "<<(i+1)<<endl;
        cin>>a;
        cout<<"\nEnter job category"<<endl;
        cin>>b;
        cout<<"\nEnter expenses "<<endl;
        cin>>c;
        p[i] = new savings<float,char>(a,b,c);
    }

    for(int i=0;i<n;i++)
    {
         p[i]->result();
    }
    return 0;
}
