
#include <iostream>
#include <fstream>
#include <filesystem>

#include "FIO.hpp"

#define RUN     1
#define STOP    0

#define CREATE_TXT_FILE     STOP
#define CREATE_BIN_FILE     STOP
#define DELETE_FILE         STOP
#define RENAME_FILE         STOP
#define OPEN_TXT_FILE_RD    RUN

/*******************************************************************************************/
/*******************************************************************************************/

#if CREATE_TXT_FILE == RUN

    int main( void )
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_txt_file function
        const std::string filename = "example.txt" ;

        create_txt_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CREATE_BIN_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_binary_file function
        const std::string filename = "example.bin" ;

        create_bin_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if DELETE_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_binary_file function
        const std::string filename = "new_file.txt" ;

        delete_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RENAME_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string oldFileName = "example.txt";
        std::string newFileName = "new_file.txt";

        rename_file( oldFileName, newFileName ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_TXT_FILE_RD == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::cout << "Enter the name of the file to read: " ;
        std::string filename ;
        std::cin >> filename ;

        filename += ".txt" ;

        // Open the file using the open_file_read function
        std::ifstream fileStream = open_txt_file_read( filename ) ;

        // Read and print the content line by line
        std::string line ;

        while( std::getline(fileStream, line) )  
        {
            std::cout << line << std::endl;
        }

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/
