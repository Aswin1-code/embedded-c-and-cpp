
#include<iostream>
using namespace std;
class Weight;
class Height
{
  float height;
  public:
  Height(float x=0)
  {
     if(x<=0)
     {cout<<"Invalid height.setting.Setting to 1 cm";
      height=1;
     }
     else
     {height=x;}
  }
  friend float calcBMI(Height,Weight);
};
class Weight
{
   float weight;
   public:
   Weight(float x=0)
   {
    if(x<0)
      {cout<<"Invalid weight.Weight is defaulted to 0kg";
       weight=0; }
    else
        {weight=x;}
   }
    friend float calcBMI(Height,Weight);
};
class BMI:public Height,public Weight
{
   public:
      BMI(float h,float w):Height(h),Weight(w){}
      void displayBMI()
      {
        cout<<"BMI:"<<calcBMI(*this,*this);
      }
};
float calcBMI(Height h,Weight w)
{
   float hm=h.height/100.0;
   float bmi=w.weight/(hm*hm);
   return bmi;
}
int main()
{
  float x,y;
cout<<"enter height:";
cin>>x;
cout<<"enter weight:";
cin>>y;
BMI p1(x,y);
p1.displayBMI();
return 0;
}
