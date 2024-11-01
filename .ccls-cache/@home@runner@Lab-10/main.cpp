// CS10A Introduction to Programming
// Description: Demonstrates the class application to store data about a few
//              beloved pets. Instantiates, mutates and displays the 
//              attributes of these objects.  
// Date: 5/10/2023
// Programmer: Derek Craig
#include <iostream>
#include <iomanip>   //setprecision 
using namespace std;

class Pet
{
   private:

      string type;
      string name;
      double age;
      double weight;

   public:

         //Constructor sets values to default
      Pet()   
      {
         type = "Unknown";
         name = "Noname";
         age = 0.0;
         weight = 0.0;
      }

         //Constructor takes all four parameters
      Pet( string t, string n, double a, double w)
      {
         type = t;
         name = n;
         age = a;
         weight = w;
      }

         // Accessors and mutators for each instance member
      void setType(string t)
         { type = t; }

      void setName(string n)
         { name = n; }

      void setAge(double a)
         { age = a; }

      void setWeight(double w)
         { weight = w; }

      string getType()
         { return type; }

      string getName()
         { return name; }

      double getAge()
         { return age; }

      double getWeight()
         { return weight; }

         //Returns string with all of the stats
      string toString() 
      {
         stringstream ss;
         ss << fixed << setprecision( 0 );
         ss << "Type: " << type 
            << "\nName: " << name 
            << "\nAge: " << age 
            << "\nWeight: " << weight << endl;
         return ss.str();
      }

         //Displays contents of toString()
      void display() 
      { cout << toString() << endl; }
};

int main() 
{
      //Instantiating
   Pet defaultPet;
   Pet dog( "Corgi", "Ein", 2, 21 ); 
   Pet cat( "Tabby", "Garfield", 40, 45);
   Pet lizard( "Monster", "Godzilla", 252000000, 328000000 );

      //Mutating
   dog.setAge( 1 );
   cat.setWeight( 44 );
   lizard.setType( "Kaiju" );

      //Displays

   defaultPet.display();
   dog.display();
   cat.display();
   lizard.display();
}
/*
Type: Unknown
Name: Noname
Age: 0
Weight: 0

Type: Corgi
Name: Ein
Age: 1
Weight: 21

Type: Tabby
Name: Garfield
Age: 40
Weight: 44

Type: Kaiju
Name: Godzilla
Age: 252000000
Weight: 328000000
*/