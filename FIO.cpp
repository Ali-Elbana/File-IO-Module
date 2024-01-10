


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

std::string readLine_atPosition_txtFile( const std::string &filename, std::streampos position ) 
{

    std::ifstream file( filename ) ;

    std::string line ;

    if( file.is_open() == true ) 
    {
        
        // Use the seek_position_txtFile function to set the file position
        seek_position_txtFile( file, position ) ;

        std::getline( file, line ) ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;

        line = "" ;  // Return an empty string to indicate an error
    }

    
    file.close() ;

    return line ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void writeLine_atPosition_txtFile( const std::string& filename, const std::string& newLine, 
std::streampos position ) 
{

    std::fstream file( filename, std::ios::in | std::ios::out ) ;

    if( file.is_open() == true ) 
    {
        
        // Move to the specified position
        file.seekp( position ) ;

        // Read the content after the position
        std::stringstream contentAfterPosition ;

        contentAfterPosition << file.rdbuf() ;

        // Move back to the specified position
        file.seekp( position ) ;

        // Write the new line
        file << newLine ;

        // Write the content after the position
        file << contentAfterPosition.str() ;

        std::cout << "Line added successfully at position " << position << " in " << filename << ".\n" ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    file.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void deleteLine_atNumber_txtFile( const std::string &filename, int lineNumber ) 
{

    // open the source file
    std::ifstream fin( filename ) ; 

    // create a temporary file
    std::ofstream temp( "temp.txt" ) ; 

    // store each line
    std::string line {""} ;

    // keep track of the line number
    int lineCount {0} ; 

    if( fin.is_open() == true ) 
    {

        // read each line
        while( getline(fin, line) ) 
        { 

            // if not the line to delete
            if( lineCount != (lineNumber - 1) ) 
            { 
                // write to the temporary file
                temp << line << "\n" ; 
            }
            else
            {
                // Skip it
            }

            // increment the line number
            lineCount++ ; 

        }

        std::cout << "Line deleted successfully at line number " << lineNumber << " in " << filename << ".\n" ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    // close the source file
    fin.close() ; 

    // close the temporary file
    temp.close() ; 

    // delete the source file
    remove( filename.c_str() ) ; 

    // rename the temporary file
    rename( "temp.txt", filename.c_str() ) ; 

}

/*******************************************************************************************/
/*******************************************************************************************/

std::string readLines_atPosition_txtFile( const std::string &filename, std::streampos position ) 
{

    std::ifstream file( filename ) ;
    std::string line ;
    std::stringstream lines ;

    if( file.is_open() == true ) 
    {

        // Use the seek_position_txtFile function to set the file position
        file.seekg( position ) ;

        // Read lines from the specified position until the end
        while( std::getline(file, line) ) 
        {
            lines << line << '\n' ;
        }

    } 
    else 
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;

        lines.str() = "" ;
    }

    file.close() ;

    return lines.str() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void writeLines_atPosition_txtFile( const std::string &filename, const std::vector<std::string> &newLines, 
std::streampos position ) 
{
    
    std::fstream file(filename, std::ios::in | std::ios::out) ;

    if( file.is_open() == true ) 
    {

        // Move to the specified position
        file.seekp( position ) ;

        // Read the content after the position
        std::stringstream contentAfterPosition ;

        contentAfterPosition << file.rdbuf() ;

        // Move back to the specified position
        file.seekp( position ) ;

        // Write the new lines
        auto it = newLines.begin() ;

        const auto last = newLines.end() ;

        while( it != last ) 
        {

            file << *it ;

            it++ ;

            // Add a newline character only if it's not the last iteration
            if( it != last ) 
            {
                file << '\n' ;
            }
            else
            {
                // Do nothing
            }

        }

        // Write the content after the position
        file << contentAfterPosition.str() ;

        std::cout << "Lines added successfully at position " << position << " in " << filename << ".\n" ;

    } 
    else 
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    file.close() ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void deleteLines_atNumber_txtFile( const std::string &filename, int lineNumber ) 
{
    
    // open the source file
    std::ifstream fin( filename ) ; 

    // create a temporary file
    std::ofstream temp( "temp.txt" ) ; 

    // store each line
    std::string line {""} ;

    // keep track of the line number
    int lineCount {0} ; 

    if( fin.is_open() == true ) 
    {

        // read each line
        while( getline(fin, line) ) 
        { 

            // if not the line to delete
            if( lineCount < (lineNumber - 1) ) 
            { 
                // write to the temporary file
                temp << line << "\n" ; 
            }
            else
            {
                // Skip it
            }

            // increment the line number
            lineCount++ ; 

        }

        std::cout << "Line deleted successfully at line number " << lineNumber << " in " << filename << ".\n" ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    // close the source file
    fin.close() ; 

    // close the temporary file
    temp.close() ; 

    // delete the source file
    remove( filename.c_str() ) ; 

    // rename the temporary file
    rename( "temp.txt", filename.c_str() ) ; 

}

/*******************************************************************************************/
/*******************************************************************************************/

std::string readLine_atNumber_txtFile( const std::string &filename, int lineNumber ) 
{

    std::ifstream file( filename ) ;

    std::string line {""} ;

    if( file.is_open() == true) 
    {

        int currentLineNumber {0} ;

        // Read lines until the desired line number is reached
        while( (currentLineNumber < lineNumber) && std::getline(file, line) ) 
        {
            currentLineNumber++ ;
        }

        file.close() ;

        // Check if the desired line number was found
        if( currentLineNumber != lineNumber ) 
        {
            std::cerr << "Error: Line number " << lineNumber << " not found in file.\n" ;

            line = "" ;
        } 
        else 
        {
           // Do nothing
        }

    } 
    else 
    {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n" ;

        line = "" ;

    }

    return line ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void writeLine_atNumber_txtFile( const std::string &filename, const std::string &lineContent, int lineNumber ) 
{

    // Open the source file.
    std::ifstream fin( filename ) ; 

    // Create a temporary file.
    std::ofstream temp( "temp.txt" ) ; 

    // Store each line.
    std::string line {""} ;

    // Keep track of the line number.
    int line_count {0} ; 

    if( fin.is_open() == true ) 
    {

        // Read each line.
        while( getline(fin, line) ) 
        { 

            // If the line to write.
            if( line_count == (lineNumber - 1) ) 
            { 
                // Write the new line to the temporary file.
                temp << lineContent << "\n" ; 
            }
            else
            {
                // Write the original line to the temporary file.
                temp << line << "\n" ; 
            }

            // Increment the line number.
            line_count++ ; 

        }

        std::cout << "Line written successfully at line number " << lineNumber << " in " << filename << ".\n" ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    // Close the source file.
    fin.close() ; 

    // Close the temporary file.
    temp.close() ; 

    // Delete the source file.
    remove( filename.c_str() ) ; 

    // Rename the temporary file.
    rename( "temp.txt", filename.c_str() ) ; 

}

/*******************************************************************************************/
/*******************************************************************************************/

std::vector<std::string> readLines_atNumber_txtFile( const std::string& filename, int startLineNumber ) 
{
    std::ifstream file( filename ) ;

    std::vector<std::string> lines ;

    if( file.is_open() == true) 
    {

        std::string line {""} ;

        int currentLineNumber  {1} ;

        // Read and discard lines until the specified startLineNumber
        while( (currentLineNumber < startLineNumber) && std::getline(file, line) ) 
        {
            currentLineNumber++ ;
        }

        // Read lines from startLineNumber to the end and store in the vector
        while( std::getline(file, line) ) 
        {
            lines.push_back( line ) ;
        }

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << "\n" ;
    }

    file.close() ;

    return lines ;

}

/*******************************************************************************************/
/*******************************************************************************************/

void writeLines_atNumber_txtFile( const std::string &filename, const std::vector<std::string> &lines, 
int lineNumber ) 
{

    // Open the source file.
    std::ifstream fin( filename ) ; 

    // Create a temporary file.
    std::ofstream temp( "temp.txt" ) ; 

    // Store each line.
    std::string line {""} ;

    // Keep track of the line number.
    int line_count {0} ; 

    if( fin.is_open() == true ) 
    {

        // Read each line.
        while( getline(fin, line) ) 
        { 

            // If the line to insert.
            if( line_count == (lineNumber - 1) ) 
            { 
                // For each line to add.
                for( const auto &line_to_add : lines ) 
                {
                    // Write the new line to the temporary file.
                    temp << line_to_add << "\n" ; 
                }
            }
            else
            {
                // Write the original line to the temporary file.
                temp << line << "\n" ; 
            }

            // Increment the line number.
            line_count++ ; 

        }

        std::cout << "Lines added successfully at line number " << lineNumber << " in " << filename << ".\n" ;

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << ".\n" ;
    }

    // Close the source file.
    fin.close() ; 

    // Close the temporary file.
    temp.close() ; 

    // Delete the source file.
    remove( filename.c_str() ) ; 

    // Rename the temporary file.
    rename( "temp.txt", filename.c_str() ) ; 

}

/*******************************************************************************************/
/*******************************************************************************************/

void appendLine_atNumber_txtFile( const std::string &filename, const std::string &lineToAdd, 
int lineNumber ) 
{

    std::ifstream inputFile( filename ) ;

    std::vector<std::string> lines ;

    std::string line ;

    if( inputFile.is_open() == true ) 
    {
        
        // Read existing content line by line
        while( std::getline(inputFile, line) ) 
        {
            lines.push_back(line) ;
        }

        inputFile.close() ; 

        // Insert the new line at the specified position
        if( lineNumber >= 1 && lineNumber <= static_cast<int>(lines.size()) + 1 ) 
        {
            lines.insert( lines.begin() + lineNumber - 1, lineToAdd ) ;
        } 
        else 
        {
            std::cerr << "Error: Invalid line number.\n" ;
        }

        // Write the updated content back to the file
        std::ofstream outputFile( filename ) ;

        if( outputFile.is_open() == true ) 
        {

            for( const auto &updatedLine : lines ) 
            {
                outputFile << updatedLine << '\n' ;
            }

            std::cout << "Line added successfully at position " << lineNumber << ".\n" ;

            outputFile.close() ;

        }
        else
        {
            std::cerr << "Error: Could not open file " << filename << " for writing.\n" ;
        }

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n" ;
    }

}

/*******************************************************************************************/
/*******************************************************************************************/

void appendLines_atNumber_txtFile( const std::string &filename, const std::vector<std::string> &linesToAdd, 
int lineNumber )  
{
    std::ifstream inputFile( filename ) ;

    std::vector<std::string> existingLines ;

    std::string line ;

    if( inputFile.is_open() == true ) 
    {
        
        // Read existing content line by line
        while( std::getline(inputFile, line) ) 
        {
            existingLines.push_back(line) ;
        }

        inputFile.close();

        // Insert the new lines at the specified position
        if( lineNumber >= 1 && lineNumber <= static_cast<int>(existingLines.size()) + 1 ) 
        {
            existingLines.insert( existingLines.begin() + lineNumber - 1, linesToAdd.begin(), linesToAdd.end() ) ;
        } 
        else 
        {
            std::cerr << "Error: Invalid line number.\n" ;
        }

        // Write the updated content back to the file
        std::ofstream outputFile( filename ) ;

        if( outputFile.is_open() == true ) 
        {
            for( const auto &updatedLine : existingLines ) 
            {
                outputFile << updatedLine << '\n' ;
            }

            std::cout << "Lines added successfully at position " << lineNumber << ".\n" ;

            outputFile.close() ;
        }
        else
        {
            std::cerr << "Error: Could not open file " << filename << " for writing.\n" ;
        }

    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n" ;
    }

}

/*******************************************************************************************/
/*******************************************************************************************/

int findWord_txtFile( const std::string &filename, const std::string &targetWord ) 
{

    std::ifstream file( filename ) ;

    int lineNumber {-1} ;

    bool isFound {false} ;

    if( file.is_open() == true ) 
    {
        
        std::string line ;

        lineNumber = 1 ;

        while( std::getline(file, line) ) 
        {

            size_t found = line.find( targetWord ) ;

            if( found != std::string::npos ) 
            {
                // Word found in the current line
                file.close() ;

                isFound = true ;

                break ;

            }
            else
            {
                lineNumber++ ;
            }

        }
        
    }
    else
    {

        std::cerr << "Error: Could not open file " << filename << " for reading.\n" ;

        // Return -1 to indicate an error
        lineNumber = -1 ;  

    }

    file.close() ;

    if( isFound != true )
    {
        // Return -2 if the word is not found in the file
        lineNumber = -2 ;
    }
    else
    {
        // Do nothing
    }

    return lineNumber ;  

}

/*******************************************************************************************/
/*******************************************************************************************/

bool deleteWord_txtFile ( const std::string &fileName, const std::string &word ) 
{

    int lineNumber = findWord_txtFile( fileName, word ) ; // call the function to find the line number

    bool isSucceed {true} ;

    if( lineNumber > 0 ) // check if the word is found in the file
    {

        std::ifstream fileInput ; // create an input file stream
        fileInput.open ( fileName ) ; // open the file
        std::ofstream fileOutput ; // create an output file stream
        fileOutput.open ( "temp.txt" ) ; // open a temporary file

        // check if both files are opened successfully
        if( fileInput.is_open() == true && fileOutput.is_open() == true ) 
        {

            std::string line ; // a variable to store each line of the file
            int currentLine = 0 ; // a variable to keep track of the current line number

            while( std::getline(fileInput, line) ) // read each line of the file
            {

                currentLine++ ; // increment the current line number

                if( currentLine == lineNumber ) // check if the current line contains the word to delete
                {

                    size_t pos = line.find ( word ) ; // find the position of the word in the line
                    line.erase ( pos, word.length() ) ; // erase the word from the line

                }
                else
                {
                    // Do nothing
                }

                fileOutput << line << "\n" ; // write the line to the temporary file

            }

            fileInput.close() ; // close the input file
            fileOutput.close() ; // close the output file

            remove ( fileName.c_str() ) ; // delete the original file
            rename ( "temp.txt", fileName.c_str() ) ; // rename the temporary file to the original file name

            isSucceed = true ; // return true to indicate success

        }
        else
        {

            std::cerr << "Error: Could not open files for reading and writing.\n" ; // print an error message
            isSucceed =  false ; // return false to indicate failure

        }

    }
    else
    {
        isSucceed =  false ; // return false if the word is not found in the file
    }

    return isSucceed ;

}

/*******************************************************************************************/
/*******************************************************************************************/

bool replaceWord_txtFile ( const std::string &fileName, const std::string &word, const std::string &newWord ) 
{

    int lineNumber = findWord_txtFile ( fileName, word ) ; // call the function to find the line number

    bool isSucceed {true} ;

    if( lineNumber > 0 ) // check if the word is found in the file
    {

        std::ifstream fileInput ; // create an input file stream
        fileInput.open ( fileName ) ; // open the file
        std::ofstream fileOutput ; // create an output file stream
        fileOutput.open ( "temp.txt" ) ; // open a temporary file

        if( fileInput.is_open() == true && fileOutput.is_open() == true ) // check if both files are opened successfully
        {

            std::string line ; // a variable to store each line of the file
            int currentLine = 0 ; // a variable to keep track of the current line number

            while( std::getline(fileInput, line) ) // read each line of the file
            {

                currentLine++ ; // increment the current line number

                if( currentLine == lineNumber ) // check if the current line contains the word to replace
                {

                    size_t pos = line.find ( word ) ; // find the position of the word in the line
                    line.replace ( pos, word.length(), newWord ) ; // replace the word with the new word in the line

                }
                else
                {
                    // Do nothing
                }

                fileOutput << line << "\n" ; // write the line to the temporary file

            }

            fileInput.close() ; // close the input file
            fileOutput.close() ; // close the output file
            
            remove ( fileName.c_str() ) ; // delete the original file
            rename ( "temp.txt", fileName.c_str() ) ; // rename the temporary file to the original file name

            isSucceed = true ; // return true to indicate success

        }
        else
        {

            std::cerr << "Error: Could not open files for reading and writing.\n" ; // print an error message

            isSucceed = false ; // return false to indicate failure

        }

    }
    else
    {
        isSucceed = false ; // return false if the word is not found in the file
    }

    return isSucceed ;

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
