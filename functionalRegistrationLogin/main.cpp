

// Konsoll basert registration & login applikasjon.

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>


bool lAuth(const std::string& user, const std::string& pass)
   {
     
     // Funksjonen sammenligner informasjon hentet fra data.txt, samme funksjon blir senere brukt.
     
   std::ifstream input("data.txt");
   
   std::string storedUser, storedPass;
   while(input >> storedUser >> storedPass)
   {
     if(storedUser == user && storedPass == pass)
     {
       return true;
     }
   }
     return false;  
}

void loginU()
{  
   // Innlogging data blir skrevet inn nedenfor
      
   std::cout << "\t\t Username:. . . \n\n";
   std::string lUser;
   std::cin >> lUser;
   std::cout << "\t\t Password:. . . \n\n";
   std::string lPass;
   std::cin >> lPass;

// Deretter blir dataen sammenlignet med hva som er skrevet i data.txt. Dersom det er likt vil if statement printe Login successful, 
// eller det mottsatte hvis usant

   if(lAuth(lUser,lPass)){
    std::cout << "\t\t Login successful \n\n";
   } else {
    std::cout << "\t\t Login unsuccessful \n\n";
   }
} 

void registerU()
{
  
  // Referer data til data.txt, ved å ta informasjon som blir skrevet inn av bruker til konsolen

  std::cout << "\t\t Register Username:. . . \n\n";
  std::string reUser;
  std::cin >> reUser;
  std::cout << "\t\t Register Password:. . . \n\n";
  std::string rePass;
  std::cin >> rePass;

   std::ofstream output("data.txt", std::ios_base::app | std::ios_base::out);
   if(output.is_open())
   {
     output << reUser << " " << rePass << std::endl; 
     output.close();
   } else {
     std::cout << "Error has occured!" << std::endl;
   }
}  

void choices()
{ 
 int choices;
   std::cout << "\t\t_______________ \n\n";
   std::cout << "\t\t    WELCOME!    \n\n";
   std::cout << "\t\t_______________ \n\n";    
   std::cout << "\t\t                \n\n";  
   std::cout << "\t\t 1. to login    \n\n";  
   std::cout << "\t\t 2. to register \n\n";  
   std::cout << "\t\t_______________ \n\n";  
 std::cin >> choices;

// Switch statment som lar bruker velge enten login eller register
// Deretter blir enten function kjørt basert på hva bruker valgte.

   switch (choices)
   {
   case 1:
   loginU();
    break;

  case 2:
   registerU();
    break;
   
   default:
    std::cout << "\t Not an option \n";
    break;
   }
    
}
int main()
{
   choices();
  
   return 0;
}