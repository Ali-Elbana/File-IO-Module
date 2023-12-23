
#include <iostream>
#include <fstream>
#include <filesystem>

#include "FIO.hpp"

#define RUN     1
#define STOP    0

#define CREATE_TXT_FILE STOP
#define CREATE_BIN_FILE STOP
#define DELETE_FILE     RUN


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
        const std::string filename = "example.txt" ;

        delete_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/





/*******************************************************************************************/
/*******************************************************************************************/
