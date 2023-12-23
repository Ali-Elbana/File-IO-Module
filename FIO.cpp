


#include "FIO.hpp"

/*******************************************************************************************/
/*******************************************************************************************/

void create_txt_file( const std::string &filename ) 
{

    // Open the file for writing
    std::ofstream file( filename ) ;

    // Check if the file is successfully opened
    if( file.is_open() != true ) 
    {
        std::cerr << "Error: Could not create file " << filename << "\n" ;
    }
    else
    {

        // Close the file
        file.close() ;

        std::cout << "File '" << filename << "' created successfully.\n" ;

    }

}

/*******************************************************************************************/
/*******************************************************************************************/

void create_bin_file( const std::string &filename ) 
{

    // Open the file for writing in binary mode
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    // Check if the file is successfully opened
    if( file.is_open() != true ) 
    {
        std::cerr << "Error: Could not create binary file " << filename << "\n" ;
    }
    else
    {

        // Example data to write to the binary file
        int numbers[] = {1, 2, 3, 4, 5} ;

        // Write the data to the file
        file.write( reinterpret_cast<const char*>(numbers), sizeof(numbers) ) ;

        // Close the file
        file.close() ;

        std::cout << "Binary file '" << filename << "' created successfully.\n" ;

    }

}

/*******************************************************************************************/
/*******************************************************************************************/




/*******************************************************************************************/
/*******************************************************************************************/


