// CS10B Introduction to Programming
// Description: Demonstrates the class application to store data about a few
//              beloved pets. Instantiates, mutates and displays the 
//              attributes of these objects.  
//              Update: Impliments static constants and validates parameter
//                      data in setters.
// Date: 5/15/2023
// Programmer: Derek Craig
#include <iostream>
#include <iomanip>   //setprecision 
#include <sstream>   //stringstream
using namespace std;

class Pet
{
   private:
         //Static member constants
      const static string DEFAULT_TYPE;
      const static string DEFAULT_NAME;
      const static double DEFAULT_AGE;
      const static double DEFAULT_WEIGHT;
      const static int MAXTYPE;
      const static int MINTYPE;
      const static int MAXNAME;
      const static int MINNAME;
      const static int MAXAGE;
      const static int MINAGE;
      const static int MAXWEIGHT;
      const static int MINWEIGHT;

   public:

      string type;
      string name;
      double age;
      double weight;
         //Default and paramiterized constructor
      Pet();
      Pet( string t, string n, double a, double w);

         // Accessors and mutators for each instance member
      bool setType(string t);
      bool setName(string n);
      bool setAge(double a);
      bool setWeight(double w);

      string getType() const { return type; }
      string getName() const { return name; }
      double getAge() const { return age; }
      double getWeight() const { return weight; }

      string toString();   //Returns string with all of the stats

      void display();   //Displays contents of toString()
};
   //Sets static members
const string Pet::DEFAULT_TYPE = "Unknown";
const string Pet::DEFAULT_NAME = "Noname";
const double Pet::DEFAULT_AGE = 0.0;
const double Pet::DEFAULT_WEIGHT = 0.0;
const int Pet::MAXTYPE = 7;
const int Pet::MINTYPE = 0;
const int Pet::MAXNAME = 10;
const int Pet::MINNAME = 0;
const int Pet::MAXAGE = 20;
const int Pet::MINAGE = 0;
const int Pet::MAXWEIGHT = 30;
const int Pet::MINWEIGHT = 0;

int main() 
{
      //Instantiating
   Pet defaultPet;
   Pet dog( "Dog", "Ein", 2, 21 ); 
   Pet cat( "Cat", "Garfield", 30, 45);
   Pet lizard( "Monster", "Godzilla", 252000000, 328000000 );

      //Displays
   defaultPet.display();
   dog.display();
   cat.display();
   lizard.display();

      //Mutating
   dog.setAge( 0 );
   cat.setWeight( 44 );
   lizard.setType( "Kaiju" );
   lizard.setType( "Prehistoric Reptilian");
   lizard.setName( "King of Monsters");

      //Displays
   defaultPet.display();
   dog.display();
   cat.display();
   lizard.display();

   return 0;
}
         
Pet::Pet()   //Constructor sets values to default
{
   type = Pet::DEFAULT_TYPE;
   name = Pet::DEFAULT_NAME;
   age = Pet::DEFAULT_AGE;
   weight = Pet::DEFAULT_WEIGHT;
}

         //Constructor takes all four parameters
Pet::Pet( string t, string n, double a, double w )
{
   if( !setType( t ) )        //Uses the data validation from the mutators
   { type = DEFAULT_TYPE; }   //to define instantiation input in all four
                              //parameters
   if( !setName( n ) )
   { name = DEFAULT_NAME; }
  
   if( !setAge( a ) )
   { age = DEFAULT_AGE; }
  
   if( !setWeight( w ) )
   { weight = DEFAULT_WEIGHT; }
}
   //Used to define type
bool Pet::setType( string t )
{
   if(( t.length() > MINTYPE ) && ( t.length() <= MAXTYPE ))
   {   
      if(( t == "Dog" ) || ( t == "Cat" ) || ( t == "Rabbit" ))
      {
         type = t;
         return true;
      }else{
              cout << "Pet type must be either Dog, Cat or Rabbit\n\n";
              type = DEFAULT_TYPE;
              return false;
           }
   }else{
           cout << "Pet type must be between 1 - 7 characters.\n\n";
           type = DEFAULT_TYPE;
           return false;
        }
}
   //Used to define name
bool Pet::setName( string n )
{
   if(( n.length() > MINNAME ) && ( n.length() <= MAXNAME))
   {
      name = n;
      return true;
   }else{
           cout << "Pet name must be between 1 - 10 characters.\n\n";
           name = DEFAULT_NAME;
           return false;
   }
}
   //Used to define age
bool Pet::setAge(double a)
{
   if(( a > MINAGE ) && ( a <= MAXAGE ))
   {
      age = a;
      return true;
   }else{
           cout << "Pet age must be between 1 - 20.\n\n";
           age = DEFAULT_AGE;
           return false;
   }
}
   //Used to define weight
bool Pet::setWeight( double w )
{
  if(( w > MINWEIGHT ) && ( w <= MAXWEIGHT ))
  {
     weight = w;
     return true;
  }else{
          cout << "Pet weight must be between 1 - 30.\n\n";
          weight = DEFAULT_WEIGHT;
          return false;
  }
}
   //Assembles class data into a string
string Pet::toString() 
{
   stringstream ss;
   ss << fixed << setprecision( 0 );
   ss << "Type: " << type 
      << "\nName: " << name 
      << "\nAge: " << age 
      << "\nWeight: " << weight << endl;
   
  return ss.str();
}
   //Displays toString
void Pet::display() { cout << toString() << endl; }

/*
Pet age must be between 1 - 20.

Pet weight must be between 1 - 30.

Pet type must be either Dog, Cat or Rabbit

Pet age must be between 1 - 20.

Pet weight must be between 1 - 30.

Type: Unknown
Name: Noname
Age: 0
Weight: 0

Type: Dog
Name: Ein
Age: 2
Weight: 21

Type: Cat
Name: Garfield
Age: 0
Weight: 0

Type: Unknown
Name: Godzilla
Age: 0
Weight: 0

Pet age must be between 1 - 20.

Pet weight must be between 1 - 30.

Pet type must be either Dog, Cat or Rabbit

Pet type must be between 1 - 7 characters.

Pet name must be between 1 - 10 characters.

Type: Unknown
Name: Noname
Age: 0
Weight: 0

Type: Dog
Name: Ein
Age: 0
Weight: 21

Type: Cat
Name: Garfield
Age: 0
Weight: 0

Type: Unknown
Name: Noname
Age: 0
Weight: 0
*/