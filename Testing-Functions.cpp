
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
#define OPEN_TXT_FILE_RD    STOP
#define OPEN_TXT_FILE_WT    STOP
#define OPEN_BIN_FILE_RD    STOP
#define OPEN_BIN_FILE_WT    STOP
#define CLEAR_FILE          STOP
#define CHECK_FILE_STATUS   RUN

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

        // Open the file using the open_txt_file_read function
        std::ifstream fileStream = open_txt_file_read( filename ) ;

        // Read and print the content line by line
        std::string line ;

        while( std::getline(fileStream, line) )  
        {
            std::cout << line << std::endl;
        }

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_TXT_FILE_WT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::cout << "Enter the name of the file to write: " ;
        std::string filename ;
        std::cin >> filename ;

        // Open the file using the open_file_write function
        std::ofstream fileStream = open_txt_file_write( filename ) ;

        // Write some text to the file
        fileStream << "Hello, this is a test.\n";
        fileStream << "Writing to a text file using C++.\n";

        std::cout << "Text written to the " << filename << " file.\n";

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_BIN_FILE_RD == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename {"test.bin"} ;

        create_bin_file( filename ) ;

        // Declare a variable of type std::ofstream
        std::ofstream fout ;

        // Open the file in binary write mode
        fout.open( filename, std::ios::out | std::ios::binary ) ;

        // Check if the file is open
        if( fout.is_open() != true )
        {
            std::cerr << "Cannot open file!" << std::endl ;
        }

        // Write some data to the file
        int     x {42}    ;
        double  y {3.14}  ;
        char    z {'A'}   ;

        fout.write( reinterpret_cast<const char*>(&x), sizeof(x) ) ;
        fout.write( reinterpret_cast<const char*>(&y), sizeof(y) ) ;
        fout.write( reinterpret_cast<const char*>(&z), sizeof(z) ) ;

        // Close the file
        fout.close();

        // Open the file using the open_bin_file_read function
        std::ifstream fileStream = open_bin_file_read( filename ) ;

        // Read the data from the file
        fileStream.read( reinterpret_cast<char*>(&x), sizeof(x) ) ;
        fileStream.read( reinterpret_cast<char*>(&y), sizeof(y) ) ;
        fileStream.read( reinterpret_cast<char*>(&z), sizeof(z) ) ;

        // Print the data to the standard output
        std::cout << "The data read from the file is: \n" ;
        std::cout << "x = " << x << "\n" ;
        std::cout << "y = " << y << "\n" ;
        std::cout << "z = " << z << "\n" ;

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_BIN_FILE_WT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename {"test.bin"} ;

        create_bin_file( filename ) ;

        std::ofstream fout = open_bin_file_write( filename ) ;

        // Write some data to the file
        int     x {42}    ;
        double  y {3.14}  ;
        char    z {'A'}   ;

        fout.write( reinterpret_cast<const char*>(&x), sizeof(x) ) ;
        fout.write( reinterpret_cast<const char*>(&y), sizeof(y) ) ;
        fout.write( reinterpret_cast<const char*>(&z), sizeof(z) ) ;

        // Close the file
        fout.close();

        // Open the file using the open_bin_file_read function
        std::ifstream fileStream = open_bin_file_read( filename ) ;

        // Read the data from the file
        fileStream.read( reinterpret_cast<char*>(&x), sizeof(x) ) ;
        fileStream.read( reinterpret_cast<char*>(&y), sizeof(y) ) ;
        fileStream.read( reinterpret_cast<char*>(&z), sizeof(z) ) ;

        // Print the data to the standard output
        std::cout << "The data read from the file is: \n" ;
        std::cout << "x = " << x << "\n" ;
        std::cout << "y = " << y << "\n" ;
        std::cout << "z = " << z << "\n" ;

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CLEAR_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"}    ;
        std::string bin_filename {"test.bin"}       ;

        std::ofstream tfout = open_txt_file_write( txt_filename ) ;

        clear_file( txt_filename ) ;

        std::ofstream bfout = open_bin_file_write( bin_filename ) ;

        clear_file( bin_filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CHECK_FILE_STATUS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"}    ;

        check_file_status( txt_filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/
