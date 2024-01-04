


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

        // Close the file
        file.close() ;

        std::cout << "Binary file '" << filename << "' created successfully.\n" ;

    }

}

/*******************************************************************************************/
/*******************************************************************************************/

void delete_file( const std::string &filename ) 
{

    // Try to delete the file
    int result = remove( filename.c_str() ) ;

    // Check the result
    if( result == 0 ) 
    {
        // Print a success message
        std::cout << "File '" << filename << "' deleted.\n";
    }
    else 
    {
        // Print an error message
        std::cerr << "Error: Could not delete file '" << filename << "'\n";
    }

}

/*******************************************************************************************/
/*******************************************************************************************/

void rename_file( const std::string &oldName, const std::string &newName )
{

    int result = std::rename( oldName.c_str(), newName.c_str() ) ;

    if( result == 0 ) 
    {
        std::cout << "File renamed successfully." << std::endl ;
    } 
    else 
    {
        std::perror( "Error renaming file" ) ;
    }

}

/*******************************************************************************************/
/*******************************************************************************************/

std::ifstream open_txt_file_read( const std::string &filename )
{

    std::ifstream fin ;

    fin.open( filename, std::ios::in ) ;

    if( fin.is_open() != true ) 
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;
    }
    else
    {
        std::cout << "Text file '" << filename << "' opened in read mode successfully.\n" ;
    }

    return fin ;

}

/*******************************************************************************************/
/*******************************************************************************************/

std::ofstream open_txt_file_write( const std::string &filename )
{

    std::ofstream fout ;

    fout.open( filename, std::ios::out ) ;

    if( fout.is_open() != true ) 
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;
    }
    else
    {
        std::cout << "Text file '" << filename << "' opened in write mode successfully.\n" ;
    }

    return fout ;

}

/*******************************************************************************************/
/*******************************************************************************************/

std::ifstream open_bin_file_read( const std::string &filename )
{

    std::ifstream fin ;

    fin.open( filename, std::ios::in | std::ios::binary ) ;

    if( fin.is_open() != true ) 
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;
    }
    else
    {
        std::cout << "Bin file '" << filename << "' opened in read mode successfully.\n" ;
    }

    return fin ;

}

/*******************************************************************************************/
/*******************************************************************************************/

std::ofstream open_bin_file_write( const std::string &filename )
{

    std::ofstream fout ;

    fout.open( filename, std::ios::out | std::ios::binary ) ;

    if( fout.is_open() != true ) 
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;
    }
    else
    {
        std::cout << "Bin file '" << filename << "' opened in write mode successfully.\n" ;
    }

    return fout ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void clear_file( const std::string & filename ) 
{

    // Open the file with truncation mode
    std::ofstream ofs( filename, std::ofstream::out | std::ofstream::trunc ) ;

    // Close the file
    ofs.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void check_file_status( const std::string &filename ) 
{

    std::ifstream file( filename ) ;
    
    if( file ) 
    {

        if( file.is_open() == true ) 
        {
            std::cout << "File is open.\n" ;
        } 
        else 
        {
            std::cout << "File is closed.\n" ;
        }

        if( file.good() == true ) 
        {
            std::cout << "File '" << filename << "' is in a good state (no errors).\n" ;
        } 
        else 
        {
            // Do nothing
        }

        if( file.fail() == true ) 
        {
            std::cerr << "Non-fatal failure in file '" << filename << "' (a logical error on I/O operation).\n" ;
        }
        else 
        {
            // Do nothing
        }

        if( file.bad() == true ) 
        {
            std::cerr << "Fatal failure in file '" << filename << "' (reading/writing error on I/O operation).\n" ;        
        }
        else 
        {
            // Do nothing
        }

        if( file.eof() == true ) 
        {
            std::cout << "End-of-file reached in file '" << filename << "'.\n" ;        
        }
        else 
        {
            // Do nothing
        }
        
    } 
    else 
    {
        std::cout << "File does not exist.\n" ;
    }
    
    file.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

std::string read_firstLine_txtFile( const std::string &filename )
{

    // Create an input file stream object
    std::ifstream fin( filename ) ;

    // Declare a string to store the line
    std::string line ;

    // Check if the file is open
    if( fin.is_open() == true )
    {

        // Read the first line from the file
        std::getline( fin, line ) ;

        // Close the file
        fin.close() ;

    }
    else
    {
        // Return an empty string if the file cannot be opened
        line = "" ;
    }

    return line ;

}

/*******************************************************************************************/
/*******************************************************************************************/


/*******************************************************************************************/
/*******************************************************************************************/


/*******************************************************************************************/
/*******************************************************************************************/


/*******************************************************************************************/
/*******************************************************************************************/



/*******************************************************************************************/
/*******************************************************************************************/
