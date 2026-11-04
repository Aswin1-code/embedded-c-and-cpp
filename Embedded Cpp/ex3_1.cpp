
#include<iostream>
#include<cstring>
using namespace std;
class person
{
   protected:
      string name;
      int id;
   public:
      person(string n=" ",int x=0):name(n),id(x){}
      virtual void display()=0;
      virtual ~person(){}
};
class academic:virtual public person
{
   protected:
      float marks;
   public:
      academic(string n=" ",int x=0,float y=0):person(n,x)
      {
         marks=y;
      }
};
class sports:virtual public person
{
   protected:
      float score;
   public:
      sports(string n=" ",int x=0,float y=0):person(n,x)
        {
         score=y;
        }
};
class result:public academic,public sports
{
   protected:
      float final_score;
   public:
      result(string n,int x,float y,float z):person(n,x),academic(n,x,y),sports(n,x,z)
      {
         final_score=calcfinal(*this);
      }
friend float calcfinal(result &r);
};
float calcfinal(result &r)
{
   return ((0.7*r.marks) + (0.3*r.score));
}
class undergraduate:public result
{
   public:
      undergraduate(string n,int x,float y,float z):person(n,x),result(n,x,y,z){}
      void display()
      {
         cout<<"...UG result..."<<endl;
         cout<<"Name:"<<name<<"     ID:"<<id<<endl;
         cout<<"Final score:"<<final_score<<endl;
      }
};
class postgraduate:public result
{
   public:
        postgraduate(string n,int x,float y,float z):person(n,x),result(n,x,y,z){}
        void display()
        {
           cout<<"...PG result..."<<endl;
           cout<<"Name:"<<name<<"    ID:"<<id<<endl;
           cout<<"Final score:"<<final_score<<endl;
        }
};
        int main()
{
   undergraduate u("Bala",101,85,90);
   postgraduate p("Prashanna",102,92,80);
   person *ptr;
   ptr=&u;
   ptr->display();
   ptr=&p;
   ptr->display();
   return 0;
}
