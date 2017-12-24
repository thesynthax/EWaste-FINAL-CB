#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>

void HomeMenu();
void MainPage();
void MainMenu();
void QuitMenu();

//Looping Vars
bool cont = true;
bool smallCont = true;
bool smallCont_2 = true;

//Namespace references
using std::string;
using std::cin;
using std::locale;

char choiceMain;
char choicePage;

std::fstream fptr;
std::fstream qfile;

enum Page
{
    homePage, menuPage, mainPage, quitPage
}page;

//For Including Spaces in the DATA File;
struct colon_is_space : std::ctype<char> {
    colon_is_space() : std::ctype<char>(get_table()) {}
    static mask const* get_table()
    {
    static mask rc[table_size];
    rc[':'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    return &rc[0];
    }
};

//Main Structure of Data;
struct WasteProducts
{
    char ID[6];
    char Parts[20];
    char Description[150];
    char Solution[250];
    int Units;
}WP;

void HomeMenu()
{
    page = homePage;
    std::cout << "**************************************************************************" << std::endl;
    std::cout << "*     \\      /\\      / |----- |       /---  /---\\   |\\    /| |----       *" << std::endl;
    std::cout << "*      \\    /  \\    /  |____  |      |     |     |  | \\  / | |___        *" << std::endl;
    std::cout << "*       \\  /    \\  /   |      |      |     |     |  |  \\/  | |           *" << std::endl;
    std::cout << "*        \\/      \\/    |----- |-----  \\---  \\---/   |      | |----       *" << std::endl;
    std::cout << "*------------------------------------------------------------------------*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                   E-Waste Management Solutions Inc.                  |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                      PRESS ANY KEY TO CONTINUE...                    |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                                     `o//so.                          |*" << std::endl;
    std::cout << "*|                                    -mMMMmhMM+                        |*" << std::endl;
    std::cout << "*|                                   `:+NhNMMMM-                        |*" << std::endl;
    std::cout << "*|                               ://+mNhNMhdMMM:                        |*" << std::endl;
    std::cout << "*|                             .oNMMMM/:dMs`/osd+.-                     |*" << std::endl;
    std::cout << "*|                          .oNMMMMMMNMMs.-s- :myyy-                    |*" << std::endl;
    std::cout << "*|                         -sNMMMMMMMMMMNhhNm/`.oydMds-                 |*" << std::endl;
    std::cout << "*|                        oNMMMMMMM    MMMMh+omm: -yhmh.                |*" << std::endl;
    std::cout << "*|                       -dMMMMMMM      MMMNMMM/:yy-..oh+`              |*" << std::endl;
    std::cout << "*|                   oNNy+MMMMMMMMM    MMMMMmNMs.-:``.                  |*" << std::endl;
    std::cout << "*|                  /dhydMs-sMNmNMMM  MMMMMMMMMMMmshNm:                 |*" << std::endl;
    std::cout << "*|                 /MMMNhNNhys:oNMNMMMMMMMMMMMMMMMMMm-                  |*" << std::endl;
    std::cout << "*|                :NddNMNNs` +md++mMMMMMMMMMMMMMMMm/                    |*" << std::endl;
    std::cout << "*|                 -hNmdNNhmo````oNNyhMMMMMMMMMMMmo`                    |*" << std::endl;
    std::cout << "*|                   -:`.- .smyso./.-hMNNMMMMMMm+`                      |*" << std::endl;
    std::cout << "*|                           hdsMho`+ms-sMMMMMh`                        |*" << std::endl;
    std::cout << "*|                            `+Mhdo `.yMd///-                          |*" << std::endl;
    std::cout << "*|                              -//sm+  -                               |*" << std::endl;
    std::cout << "*|                                   ./                                 |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|----------------------------------------------------------------------|*" << std::endl;
    std::cout << "**************************************************************************" << std::endl;
    system("pause>null");
}

void MainMenu()
{
    page = menuPage;
    std::cout << "**************************************************************************" << std::endl;
    std::cout << "*******************-----------------------------------********************" << std::endl;
    std::cout << "*                 *|E-Waste Management Solutions Inc.|*                  *" << std::endl;
    std::cout << "*                 *-----------------------------------*                  *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*                 What do you want to do:                                *" << std::endl;
    std::cout << "*                   ___________________                                  *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*             (a) I want to go through the product list.                 *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*             (b) I want to search and manage E-Waste Products.          *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "*                                                                        *" << std::endl;
    std::cout << "**************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter choice -> a, b, c.\n" << "--> ";
    std::cin >> choiceMain;

}

void MainPage()
{
    smallCont = 1;
    smallCont_2 = 1;
    fptr.open("C:/Users/TheSynthax/Downloads/E_Waste-20171222T115040Z-001/E_Waste/BackupEwaste/BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);
    switch(choiceMain)
    {
    /*case 'a':
        {
            char choice = 'y';
            std::cout << "Enter the details" << std::endl;
            while (choice == 'y' || choice == 'Y')
            {
                std::cout << "Enter ID: ";
                std::cin >> WP.ID;
                std::cout << "Enter Part: ";
                std::cin >> WP.Parts;
                std::cout << "Enter Description: ";
                std::cin >> WP.Description;
                std::cout << "Enter Solution: ";
                std::cin >> WP.Solution;
                fptr.write((char *)&WP, sizeof(WP));
                std::cout << "Record added successfully. Do you want to add more? (Y)(N)";
                std::cin >> choice;
            }
            break;
        }*/
    case 'a':
        {
            int noOfProducts = 1;
            std::cout << "******************************************************************";
            fptr.seekp(0);
            while(fptr.eof() != 1)
            {
                fptr.read((char*)&WP, sizeof(WasteProducts));
                std::cout << "\n" << "--> (" << fptr.tellp()/432 << ") " << WP.Parts;

                noOfProducts++;
            }

            std::cout << "\n******************************************************************";
            fptr.close();
            std::cout << "\nWhich product do you wish to check(Enter name exactly as listed above): \n" << "--> ";
            char searchPart[20];
            std::cin >> searchPart;

            fptr.open("C:/Users/TheSynthax/Downloads/E_Waste-20171222T115040Z-001/E_Waste/BackupEwaste/BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);
            fptr.seekp(0);

            bool comparison;

            while (fptr.eof() != 1)
            {
                fptr.read((char*)&WP, sizeof(WasteProducts));
                std::string part = WP.Parts;
                std::string userSearch = searchPart;

                if (userSearch.compare(part) == 0)
                {
                    comparison = true;
                    //std::cout << "\nWould you like to view the information about this product?(y/n): ";
                    break;
                }
                else
                {
                    comparison = false;
                    //std::cout << "Please Enter the correct product name.";
                    continue;
                }
            }

            if (fptr.eof() && !comparison)
            {
                std::cout << "Please Enter the correct product name.";
            }
            fptr.close();
            if (comparison)
            {
                std::cout << "\nProduct name: " << "\"" << searchPart <<"\". Would you like to view the information about this product?(y/n): ";
                char choice;
                std::cin >> choice;
                while (smallCont_2 == 1)
                {
                    switch (choice)
                    {
                        case ('y'):
                        {
                            system("cls");
                            std::cout << "*******************************************************************************************";
                            std::cout << "\n* Product searched: --> " << searchPart << std::endl;
                            std::cout << "*" << std::endl;

                            std::cout << "* What is " << searchPart << " -->\n";
                            std::cout << "*-------------------------------------------------------------------" << std::endl;
                            std::cout << "* " << WP.Description << std::endl;
                            std::cout << "*\n";
                            std::cout << "* How and where can be waste " << searchPart << "s be used -->\n";
                            std::cout << "*-------------------------------------------------------------------" << std::endl;
                            std::cout << "* " << WP.Solution << std::endl;
                            std::cout << "*******************************************************************************************";


                            smallCont_2 = 0;
                            break;
                        }
                        case ('Y'):
                        {
                            system("cls");
                            std::cout << "*******************************************************************************************";
                            std::cout << "\n* Product searched: --> " << searchPart << std::endl;
                            std::cout << "*" << std::endl;

                            std::cout << "* What is " << searchPart << " -->\n";
                            std::cout << "*-------------------------------------------------------------------" << std::endl;
                            std::cout << "* " << WP.Description << std::endl;
                            std::cout << "*\n";
                            std::cout << "* How and where can be waste " << searchPart << "s be used -->\n";
                            std::cout << "*-------------------------------------------------------------------" << std::endl;
                            std::cout << "* " << WP.Solution << std::endl;

                            smallCont_2 = 0;
                            break;
                        }
                        case ('n'):
                        {
                            std::cout << "* --> OKAY!";
                            smallCont_2 = 0;
                            break;
                        }
                        case ('N'):
                        {
                            std::cout << "* --> OKAY!";
                            smallCont_2 = 0;
                            break;
                        }
                        default:
                        {
                            //system("cls");
                            std::cout << "* --> Please enter a valid option. ";
                            smallCont_2 = 0;
                        }
                    }
                }
            }

            break;

        }
    case 'b':
        {
            /*char searchPart[20];        //Wont be there in the GUI versionz
            std::cout << "Enter what you want to search: ";
            std::cin >> searchPart;
            fptr.seekp(0);
            while(fptr.eof() != 1)
            {
                fptr.read((char *)&WP, sizeof(WasteProducts));
                std::string part = WP.Parts;
                std::string searched = searchPart;
                if(part.compare(searched) == 0)
                {
                    fptr.read((char *)&WP, sizeof(WasteProducts));
                    std::cout << "Found" << std::endl;
                    std::cout << "\n\tID\tParts\tDescription\tSolution\t";
                    std::cout << "\n\t" << WP.ID << "\t" << WP.Parts << "\t" << WP.Description << "\t" << WP.Solution;
                    break;
                }
            }*/

            int noOfProducts = 1;

            fptr.seekp(0);
            std::cout << "******************************************************************\n";
            std::cout << "This is the product list: \n";
            std::cout << "   ________________\n";
            while (fptr.eof() != 1)
            {
                fptr.read((char *)&WP, sizeof(WasteProducts));

                std::cout << "\n" << "--> (" << fptr.tellp()/432 << ") " << WP.Parts;
                noOfProducts++;
            }
            std::cout << "\n\n******************************************************************";
            int userProdUnits[noOfProducts];

            char searchPart[20];

            std::cout << "\n* --> Which product do you want to manage: \n* --> ";
            std::cin >> searchPart;

            fptr.open("C:/Users/TheSynthax/Downloads/E_Waste-20171222T115040Z-001/E_Waste/BackupEwaste/BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);
            fptr.seekp(0);

            bool comparison;

            while (fptr.eof() != 1)
            {
                fptr.read((char*)&WP, sizeof(WasteProducts));
                std::string part = WP.Parts;
                std::string userSearch = searchPart;

                if (userSearch.compare(part) == 0)
                {
                    comparison = true;
                    break;
                }
                else
                {
                    comparison = false;
                    continue;
                }
            }

            if (fptr.eof() && !comparison)
            {
                std::cout << "Please Enter the correct product name.";
            }
            fptr.close();

            break;

            if (comparison)
            {

            }
        }
    case 'c':
        {
            /*int Units[18];  //This is the variable that will store the quantity of the units
            /**
            * Each variable of the array will store the quantity of the respective part
            * For example:-
            * Units[0] = quantity(Mouse Wired)
            * Units[1] = quantity(Keyboard Wired)
            * and so on...
            */
            /*while(fptr.eof() != 1) //While end of file is not true...
                {
                    int x = 0;
                    /**
                    * Over here you will ask the user that which product you want to add the quantity
                    * The while loop will search the parts and then when it is found you will add it
                    * Pseudo-Code:-
                    * while(fptr.eof() != 1)break;
                    *    {
                    *        fptr.read((char *)&WP, sizeof(WasteProducts));
                    *        std::string part = WP.Parts;
                    *        std::string searched = searchPart;
                    *        int x = 0;
                    *        if(searched.compare(part) == 0)
                    *        {
                    *           cout << "Enter the quantity of" << WP.Parts << ": ";
                    *           cin >> Unit[x];
                    *        }
                    *        x++;
                    *    }
                    */
                    /*fptr.read((char *)&WP, sizeof(WasteProducts));
                    std::cout << WP.Parts << ":";
                    std::cin >> Units[x];      //Appending for every product
                    x++;    //Appending the array number
                }*/


            break;
        }
    default:
        {
            std::cout << "* --> Please enter a valid choice.";
            break;
        }
    }
    fptr.close();

    while (smallCont == 1)
    {
        std::cout << "\n\n* --> Type 'b' to go back or 'q' to quit the program: \n" << "* --> ";
        std::cin >> choicePage;

        switch (choicePage)
        {
            case ('b'):
            {
                system("cls");
                page = menuPage;
                smallCont = 0;
                break;
            }
            case ('q'):
            {
                system("cls");
                QuitMenu();
                smallCont = 0;

                break;
            }
            default:
            {
                system("cls");
                std::cout << "* --> Please enter a valid choice. \n";

            }
        }
        //break;
    }
}

void QuitMenu()
{
    page = quitPage;
    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "*#                                                          _   ______      #*" << std::endl;
    std::cout << "*#  ------------- |      |        /\\        |\\       | |   /   /      \\     #*" << std::endl;
    std::cout << "*#        |       |      |       /  \\       | \\      | |  /   |             #*" << std::endl;
    std::cout << "*#        |       |      |      /    \\      |  \\     | | /    |             #*" << std::endl;
    std::cout << "*#        |       |------|     /      \\     |   \\    | |/      \\______      #*" << std::endl;
    std::cout << "*#        |       |      |    /--------\\    |    \\   | |\\             \\     #*" << std::endl;
    std::cout << "*#        |       |      |   /          \\   |     \\  | | \\             |    #*" << std::endl;
    std::cout << "*#        |       |      |  /            \\  |      \\ | |  \\            |    #*" << std::endl;
    std::cout << "*#        |       |      | /              \\ |       \\| |   \\_  \\______/     #*" << std::endl;
    std::cout << "*#                                                                          #*" << std::endl;
    std::cout << "*#                    _________________________________                     #*" << std::endl;
    std::cout << "*#                                                                          #*" << std::endl;
    std::cout << "*#                                                                          #*" << std::endl;
    std::cout << "*#                                                                          #*" << std::endl;
    std::cout << "*#            *    Thanks for checking out our project !    *               #*" << std::endl;
    std::cout << "*#            *                                             *               #*" << std::endl;
    std::cout << "*#            *            Press any key to quit...         *               #*" << std::endl;
    std::cout << "*#            *                                             *               #*" << std::endl;
    std::cout << "*#            *                                             *               #*" << std::endl;
    std::cout << "*#            *                *************                *               #*" << std::endl;
    std::cout << "*#            *                                             *               #*" << std::endl;
    std::cout << "*#            *                                             *               #*" << std::endl;
    std::cout << "******************************************************************************" << std::endl;

    exit(0);
}

//Main Function
int main()
{
    cont = 1;
    system("cls");
    //A variable which keeps the app in loop;

    page = homePage;

    //Reference for Spacing in Data File;
    cin.imbue(locale(cin.getloc(), new colon_is_space));

    /*switch (page)
    {
        case (homePage):
        {
            HomeMenu();
            page = menuPage;
        }
        case (menuPage):
        {
            system("cls");
            MainMenu();
            page = mainPage;
            system("cls");
        }
        case (mainPage):
        {
            MainPage();
        }
    }*/

    while (cont == 1)
    {
        if (page == homePage)
        {
            HomeMenu();
            page = menuPage;
        }
        if (page == menuPage)
        {
            system("cls");
            MainMenu();
            page = mainPage;
            system("cls");
        }
        if (page == mainPage)
        {
            MainPage();
            //page = menuPage;
        }
        /*if (page = quitPage)
        {
            system("cls");
            QuitMenu();
            cont = 0;
        }*/
    }


}

