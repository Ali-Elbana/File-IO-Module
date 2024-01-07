


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

std::string read_lastLine_txtFile( const std::string &filename )
{

    // Create an input file stream object
    std::ifstream fin( filename ) ;

    // Declare a string to store the line
    std::string line ;

    // Check if the file is open
    if( fin.is_open() == true )
    {

        // Seek to the end of the file
        fin.seekg( 0, std::ios::end ) ;

        // Loop backwards until a newline is found or the beginning of the file is reached
        while( fin )
        {

            // Move one character back
            fin.seekg( -1, std::ios::cur ) ;

            // Get the current character
            char ch = fin.peek() ;

            // If the character is a newline, break the loop
            if( ch == '\n' )
            {
                break ;
            }
            else
            {
                // Insert the character at the beginning of the line
                line.insert( 0, 1, ch ) ;
            }

            // If the beginning of the file is reached, move to the first position
            if( fin.tellg() == 0 )
            {

                fin.seekg( 0 ) ;

                break ;

            }
            else
            {
                // Continue
            }

        }

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

std::string read_entire_txtFile( const std::string &filename ) 
{

    // Open the file in binary mode and seek to the end
    std::ifstream fin( filename ) ;

    std::stringstream buffer ;

    // Check if the file is open
    if( fin.is_open() == true )
    {

        buffer << fin.rdbuf() ;

        // Close the file
        fin.close() ;

    }
    else
    {
        // Return an empty string if the file cannot be opened
        buffer.str() = "" ;
    }

    return buffer.str() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void write_to_txtFile( const std::string &filename, const std::string &content ) 
{

    std::ofstream file( filename ) ;

    if( file.is_open() == true ) 
    {
        // Write the content to the file
        file << content ;  

        std::cout << "Content written to file: " << filename << '\n' ;
    } 
    else 
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }

    file.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void append_to_txtFile( const std::string &filename, const std::string &content )
{

    std::ofstream file( filename, std::ios::app ) ;

    if( file.is_open() == true ) 
    {
        // Write the content to the file
        file << content ;  

        std::cout << "Content written to file: " << filename << '\n' ;
    } 
    else 
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }

    file.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void copy_file( const std::string &sourceFilename, const std::string &destinationFilename ) 
{

    // Open the source file in binary mode
    std::ifstream sourceFile( sourceFilename, std::ios::binary ) ;

    // Open the destination file in binary mode
    std::ofstream destinationFile( destinationFilename, std::ios::binary  ) ;

    if( (sourceFile.is_open() && destinationFile.is_open()) == true ) 
    {
        
        // Copy the source file stream buffer to the destination file stream
        destinationFile << sourceFile.rdbuf ();

        std::cout << "Content copied from " << sourceFilename << " to " << destinationFilename << ".\n" ;

    } 
    else 
    {
        std::cerr << "Error: Could not open files for copying.\n" ;
    }

    sourceFile.close() ;

    destinationFile.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

int count_fileLines( const std::string &filename ) 
{

    std::ifstream file( filename ) ;

    int lineCount {0} ;

    if( file.is_open() == true ) 
    {
        std::string line ;

        while( std::getline(file, line) ) 
        {
            // For each line read, increment the line count
            lineCount++ ;
        }

        file.close() ;

    } 
    else 
    {

        lineCount = -1 ;

        std::cerr << "Error: Could not open file " << filename << " for reading.\n" ;

    }

    return lineCount ;

}

/*******************************************************************************************/
/*******************************************************************************************/

bool does_file_exist( const std::string &filename ) 
{

    bool is_found {false} ;

    if( std::filesystem::exists( filename ) == true )
    {
        is_found = true ;
    }
    else
    {
        is_found = false ;
    }

    return is_found ;

}

/*******************************************************************************************/
/*******************************************************************************************/

std::streampos get_position_txtFile( std::ifstream &file ) 
{

    std::streampos currentPosition {-1} ;

    if( file.is_open() == true ) 
    {
        // Get the current position in the file
        currentPosition = file.tellg() ;
    }
    else
    {
        currentPosition = -1 ;

        std::cerr << "Error: Could not open file for reading.\n" ;
    }

    return currentPosition ;

}


/*******************************************************************************************/
/*******************************************************************************************/

void seek_position_txtFile( std::ifstream &file, std::streampos position ) 
{

    if( file.is_open() == true ) 
    {

        // Move the file pointer to the specified position
        file.seekg( position, std::ios::beg ) ;

        if( file.tellg() == position ) 
        {
            std::cout << "File pointer successfully moved to position: " << position << ".\n" ;
        } 
        else 
        {
            std::cerr << "Error: Could not move file pointer to position " << position << ".\n" ;
        }

    } 
    else 
    {
        std::cerr << "Error: Could not open file for reading.\n" ;
    }

}

/*******************************************************************************************/
/*******************************************************************************************/

void reset_position_txtFile( std::ifstream &file ) 
{

    if( file.is_open() == true ) 
    {
        // Reset the position to the beginning of the file
        file.seekg( 0, std::ios::beg ) ;

        std::cout << "Position reset to the beginning of file.\n" ;
    } 
    else 
    {
        std::cerr << "Error: Could not open file.\n" ;
    }
    
}

/*******************************************************************************************/
/*******************************************************************************************/



/*******************************************************************************************/
/*******************************************************************************************/



/*******************************************************************************************/
/*******************************************************************************************/




/*******************************************************************************************/
/*******************************************************************************************/
