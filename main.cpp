#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>
#include <stdio.h>

void HomeMenu();
void MainPage();
void MainMenu();
void QuitMenu();

///Looping Vars
bool cont = true;
bool smallCont = true;
bool smallCont_2 = true;
int smallCont_3 = 1;

///Namespace references
using std::string;
using std::cin;
using std::locale;

char choiceMain;
char choicePage;

std::fstream fptr;
std::fstream qfile;

///Pages
enum Page
{
    homePage, menuPage, mainPage, quitPage
}page;

///For Including Spaces in the DATA File;
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

bool fileisEmpty(std::fstream &file)/// <------ THIS IS THE FUNCTION FOR CHECKING EMPTY FILES
{
    return file.peek() == std::fstream::traits_type::eof();
}

///Main Structure of Data;
struct WasteProducts
{
    char ID[6];
    char Parts[20];
    char Description[150];
    char Solution[250];
    int Units;
}WP;

///Design of First Page
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

///Second Page
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
    std::cout << "Enter choice -> a or b.\n" << "--> ";
    std::cin >> choiceMain;

}

///Main page
void MainPage()
{
    ///Looping Vars
    smallCont = 1;
    smallCont_2 = 1;
    ///Open File
    fptr.open("BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);

    ///Main choice of searching or managing
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
    ///If 'a' is pressed
    case 'a':
        {
            ///Number of products
            int noOfProducts = 1;
            std::cout << "******************************************************************";
            ///Moves the pointer to the first position
            fptr.seekp(0);
            ///While the file is not ended
            while(fptr.eof() != 1)
            {
                ///read file
                fptr.read((char*)&WP, sizeof(WasteProducts));
                ///Display
                std::cout << "\n" << "--> (" << fptr.tellp()/432 << ") " << WP.Parts;
                ///Increment NoOfProducts by 1 on each iteration
                noOfProducts++;
            }

            std::cout << "\n******************************************************************";
            ///Close File Pointer
            fptr.close();
            std::cout << "\nWhich product do you wish to check(Enter name exactly as listed above): \n" << "--> ";

            ///The input of the product by user
            char searchPart[20];
            std::cin >> searchPart;

            fptr.open("BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);
            fptr.seekp(0);

            ///Comparison b/w input and variable of product
            bool comparison;

            ///While file has not ended
            while (fptr.eof() != 1)
            {
                fptr.read((char*)&WP, sizeof(WasteProducts));
                std::string part = WP.Parts;
                std::string userSearch = searchPart;

                ///If the pointer matches with the product is correct
                if (userSearch.compare(part) == 0)
                {
                    comparison = true;
                    //std::cout << "\nWould you like to view the information about this product?(y/n): ";
                    break;
                }
                ///If the pointer doesnt match with the product  is wrong
                else
                {
                    comparison = false;
                    //std::cout << "Please Enter the correct product name.";
                    ///Continue to the next iteration of the loop
                    continue;
                }
            }

            ///If the input is wrong
            if (fptr.eof() && !comparison)
            {
                std::cout << "Please Enter the correct product name.";
            }
            fptr.close();
            ///If the input is correct
            if (comparison)
            {
                std::cout << "\nProduct name: " << "\"" << searchPart <<"\". Would you like to view the information about this product?(y/n): ";
                char choice;
                std::cin >> choice;
                ///While looping
                while (smallCont_2 == 1)
                {
                    ///Check if the user wants to display info
                    switch (choice)
                    {
                        ///Yes?
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
                        ///Yes
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
                        ///No?
                        case ('n'):
                        {
                            std::cout << "* --> OKAY!";
                            smallCont_2 = 0;
                            break;
                        }
                        ///No?
                        case ('N'):
                        {
                            std::cout << "* --> OKAY!";
                            smallCont_2 = 0;
                            break;
                        }
                        ///If input is wrong
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
    ///If 'b' is pressed
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
            ///No of Products
            int noOfProducts = 1;
            ///Move pointer to 1st position
            fptr.seekp(0);
            std::cout << "******************************************************************\n";
            std::cout << "* --> This is the product list: \n";
            std::cout << "*        ________________\n" << "*";
            while (fptr.eof() != 1)
            {
                fptr.read((char *)&WP, sizeof(WasteProducts));

                std::cout << "\n* --> " << WP.Parts;
                ///Increment No Of Product
                noOfProducts++;
            }
            std::cout << "\n*        _________________\n*\n******************************************************************";

            fptr.close();
            fptr.open("BackupEwasteWasteProducts.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);

            ///The user's input for product
            char searchPart[20];

            std::cout << "\n* --> Which product do you want to manage: \n* --> ";
            std::cin >> searchPart;


            fptr.seekp(0);
            ///Comparison (same as above)
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
            ///Input input is wrong
            if (fptr.eof() && !comparison)
            {
                std::cout << "* --> Please Enter the correct product name.";
            }
            qfile.open("BackupEwasteUnits.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);

            ///If input is correct
            if (comparison)
            {

                std::cout << "* --> Do you want to (a)dd or (r)emove quantity units of products (a/r): \n* --> ";

                ///this is the product ID type of thingy.
                int prodNo = (fptr.tellp()/432);
                ///Quantity choice
                char qChoice;
                ///Input
                std::cin >> qChoice;


                ///Check the input
                switch (qChoice)
                {
                    ///If user wants to add units
                    case ('a'):
                    {
                        ///This is the file which stores values of array. This is not a persistent file (volatile)
                        std::fstream arrfile;
                        ///This is the file which stores values of array. This is a persistence file (non-volatile)
                        std::fstream arrMain;

                        ///Open file
                        arrfile.open("arrayQfile.txt", std::fstream::in | std::fstream::out);
                        ///looping var which checks if the user came back for management for second time without closing the application
                        bool smallCont_4 = 0;
                        ///looping var which checks if the user is coming for management for the first time.
                        if (smallCont_3 != 1)
                        {
                            smallCont_4 = 1;
                        }

                        ///The main array which checks for units for products.
                        int userProdUnits[noOfProducts];
                        ///If the user came back second time
                        while (smallCont_4 == 1)
                        {
                            for (int i = 1; i < noOfProducts; i++)
                            {
                                ///adds the value of Ith node of array to the file
                                arrfile >> userProdUnits[i];
                            }
                            ///breaks loop
                            smallCont_4 = 0;

                        }

                        ///close file
                        arrfile.close();
                        ///open file
                        arrfile.open("arrayQfile.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

                        ///If file fails to open then close it
                        if (!arrfile.is_open() || arrfile.fail())
                        {
                            arrfile.close();
                        }
                        arrfile.close();


                        ///open
                        arrfile.open("arrayQfile.txt", std::fstream::in | std::fstream::out);


                        std::cout << "* --> Enter the number of units of " << searchPart << " you want to add. \n* --> ";
                        ///Main var which keeps track of the units
                        int units = 0;
                        std::cin >> units;

                        arrMain.open("arrayQMain.txt", std::fstream::in | std::fstream::out);

                        ///Checks if user came for the first time
                        while (smallCont_3 == 1)
                        {
                            if (fileisEmpty(arrMain))
                            {
                                for (int i = 0; i < noOfProducts; i++)
                                {
                                    userProdUnits[i] = 1;

                                }
                                std::cout << "isEmpty";
                            }
                            else
                            {
                                for (int i = 0; i < noOfProducts; i++)
                                {
                                    arrMain >> userProdUnits[i];
                                }
                                std::cout << "isNotEmpty";
                            }


                            smallCont_3++;
                        }

                        ///Main line of code which increments the value of the units
                        userProdUnits[prodNo] += units;

                        ///If file is open then export the var to file
                        if (arrfile.is_open())
                        {
                            for (int i = 1; i < noOfProducts; i++)
                            {
                                arrfile << userProdUnits[i] << " ";
                            }
                        }
                        ///if file doesn't open
                        else
                        {
                            std::cout << "Error, couldnot open file";
                        }

                        arrfile.close();


                        arrMain.open("arrayQMain.txt", std::ios::in | std::ios::out);

                        ///Add the values of array to the main array file
                        for (int i = 1; i < noOfProducts; i++)
                        {
                            std::cout << userProdUnits[i] << std::endl;
                            arrMain << userProdUnits[i] << " ";
                        }

                        arrMain.close();

                        /*qfile.write((char*)&WP, sizeof(WasteProducts));

                        qfile.seekp(0);
                        /*while (qfile.eof() != 1)
                        {
                            qfile.read((char*)&WP, sizeof(WasteProducts));
                            std::cout << prodSerial << " " << WP.Parts << " " << WP.Units << std::endl;
                        }

                        for (int i = 0; i < noOfProducts; i++)
                        {
                            std::cout << userProdUnits[i] << std::endl;
                        }*/



                    }
                }


            }

            break;


        }
        ///Wrong choice
    default:
        {
            std::cout << "* --> Please enter a valid choice.";
            break;
        }
    }
    fptr.close();

    ///Loops after every main activity like management and searching of products
    while (smallCont == 1)
    {
        std::cout << "\n\n* --> Type 'b' to go back or 'q' to quit the program: \n" << "* --> ";
        std::cin >> choicePage;

        switch (choicePage)
        {
            ///menupage
            case ('b'):
            {
                system("cls");
                page = menuPage;
                smallCont = 0;
                break;
            }///quit
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
        ///break;
    }
}
///Quit page design
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

    system("pause>null");
    exit(1);
}

///Main Function
int main()
{

    cont = 1;
    system("cls");
    ///A variable which keeps the app in loop;

    page = homePage;

    ///Reference for Spacing in Data File;
    cin.imbue(locale(cin.getloc(), new colon_is_space));

    ///Main looping var
    while (cont == 1)
    {
        ///homepage
        if (page == homePage)
        {
            HomeMenu();
            page = menuPage;
        }
        ///menupage
        if (page == menuPage)
        {
            system("cls");
            MainMenu();
            page = mainPage;
            system("cls");
        }
        ///Main Page
        if (page == mainPage)
        {
            MainPage();
            ///page = menuPage;
        }
        /*if (page = quitPage)
        {
            system("cls");
            QuitMenu();
            cont = 0;
        }*/
    }


}

