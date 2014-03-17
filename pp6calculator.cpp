// Standard Library
#include <iostream>
#include <limits>

// This Project
#include "PP6Day1Menu.hpp"
#include "PP6Day2Menu.hpp"



class FourVector
{
private:
  double t,x,y,z;

  double lengthOfFourVector() const
  {
    double c = 299792458;
    return -(c*t)*(c*t)+x*x+y*y+z*z;
  }

  double lengthOfThis;

public:

  double gett() const
  {
    return t;
  }

  double getx() const
  {
    return x;
  }

  double gety() const
  {
    return y;
  }

  double getz() const
  {
    return x;
  }

  void sett(double t_)
  {
    t = t_;
    lengthOfThis = lengthOfFourVector();
  }

  void setx(double x_)
  {
    x = x_;
    lengthOfThis = lengthOfFourVector();
  }

  void sety(double y_)
  {
    y = y_;
    lengthOfThis = lengthOfFourVector();
  }

  void setz(double z_)
  {
    z = z_;
    lengthOfThis = lengthOfFourVector();
  }


  double getlengthOfThis() const
  {
    return lengthOfThis;
  }


  FourVector(double t_, double x_, double y_, double z_)
    :t(t_), x(x_), y(y_), z(z_)
  {
    lengthOfThis = lengthOfFourVector();
  }
  // virtual ~FourVector();

  FourVector boostAlongZAxis(double beta)
  {
    // This function makes destructive changes to the FourVector
    double gamma = 1/(1-beta*beta);
    double tprime = gamma*(t-beta*z);
    double zprime = gamma*(z-beta*t);
    t = tprime;
    z = zprime;
    return *this;
  }

  // overloading those operator functions
  FourVector& operator+=(const FourVector& rhs)
  {
    t += rhs.gett(); x += rhs.getx(); y += rhs.gety(); z += rhs.getz();
    return *this;
  }

  FourVector& operator=(const FourVector& rhs)
  {
    if (&rhs !=this)
      {
	t = rhs.gett(); x = rhs.getx(); y = rhs.gety(); z = rhs.getz();
      }
    return *this;
  }

};

// Get that FourVector to print out!
std::ostream& operator<<(std::ostream& os, const FourVector& w)
{
  os << "(" << w.gett() <<", " << w.getx() << ", " << w.gety() << ", " << w.getz() << ")";
  return os;
}


void pp6day3_menu() {

  char op('\0');

  while (true)
    {
      std::cout << "PP6Calculator - Day 3 Menu" << std::endl;
      std::cout << "==========================" << std::endl;
      std::cout << "Enter the operation you would like to perform:" << std::endl;
      std::cout << "1) Calculate the length of a four vector" << std::endl;
      std::cout << "2) Calculate boost along Z axis for a four vector" << std::endl;

      // Ask for user input
      std::cin >> op;

      // TODO this is the second time I've seen this typed in, there must be a way
      // to automate it (nasfarley88 2014-03-17)
      //
      // check for bad input
      if(!std::cin)
	{
	  std::cerr << "[error] Error in input" << std::endl;
    
	  // clear the buffer
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}

      // Handle menu operation
      if (op == 'q')
	{
	  break;
	}
      else if (op == '1')
	{
	  // Define four vector
	  std::cout << "Please enter the values t, x, y, and z as space separated values"
		    << std::endl;
	  double a,b,c,d;	// not initialised?!
	  std::cin >> a >> b >> c >> d;
	  FourVector w = FourVector(a,b,c,d);
	  std::cout << w.getlengthOfThis() << std::endl;
	}
      else if (op == '2')
	{
	  // Define four vector
	  std::cout << "Please enter the values t, x, y, and z as space separated values"
		    << std::endl;
	  double a,b,c,d;	// not initialised?!
	  std::cin >> a >> b >> c >> d;
	  FourVector w = FourVector(a,b,c,d);

	  std::cout << "Please enter the beta factor (v/c) you wish to transform by"
		    << std::endl;
	  double beta = 0;
	  std::cin >> beta;
	  std::cout << w.boostAlongZAxis(beta) << ", " << std::endl;
	}
    }
}


//----------------------------------------------------------------------
// Main program
//
int main() 
{
  // Menu operation
  char item('\0');

  while (true)
  {
    // Ask the user to select a submenu or quit
    std::cout << "PP6Calculator - Main Menu" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "Choose the operation you would like to perform:" << std::endl;
    std::cout << "1)  Basic Mathematics from Day 1" << std::endl;
    std::cout << "2)  Array Operations from Day 2" << std::endl;
    std::cout << "3)  Day 3 stuff" << std::endl;
    std::cout << "q)  Quit" << std::endl;
    std::cout << ">> ";

    std::cin >> item;

    // check for bad input
    if(!std::cin)
    {
      std::cerr << "[error] Error in input" << std::endl;
    
      // clear the buffer
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    // Handle menu operation
    if (item == 'q')
    {
      break;
    }
    else if (item == '1')
    {
      pp6day1_menu();
    }
    else if (item == '2')
    {
      pp6day2_menu();
    }
    // day 3
    else if (item == '3')
    {
      pp6day3_menu();
    }
    else
    {
      std::cerr << "[error] Operation '" << item << "' not recognised."
                << std::endl;
      continue;
    }
  }
 
  std::cout << "Thank you for using pp6calculator!" << std::endl;
  return 0;
}
