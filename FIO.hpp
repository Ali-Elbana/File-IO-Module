


#ifndef FIO_H
#define FIO_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdio>  // for remove
#include <sstream>

/*******************************************************************************************/

// 1-Function to create a txt file
void create_txt_file( const std::string &filename ) ;

/*******************************************************************************************/

// 2-Function to create a bin file
void create_bin_file( const std::string &filename ) ;

/*******************************************************************************************/

// 3-Function to delete any file
void delete_file( const std::string &filename ) ;

/*******************************************************************************************/

// 4-Function to rename any file
void rename_file( const std::string &oldName, const std::string &newName ) ;

/*******************************************************************************************/

// 5-Function to open txt file in read mode
std::ifstream open_txt_file_read( const std::string &filename ) ;

/*******************************************************************************************/

// 6-Function to open txt file in write mode
std::ofstream open_txt_file_write( const std::string &filename ) ;

/*******************************************************************************************/

// 7-Function to open bin file in read mode
std::ifstream open_bin_file_read( const std::string &filename ) ;

/*******************************************************************************************/

// 8-Function to open bin file in write mode
std::ofstream open_bin_file_write( const std::string &filename ) ;

/*******************************************************************************************/

// 9-Function to clear the content of any type of files
void clear_file( const std::string & filename ) ;

/*******************************************************************************************/

// 10-Check file status
void check_file_status( const std::string &filename ) ; 

/*******************************************************************************************/

// 11-Read the first line of a text file
std::string read_firstLine_txtFile( const std::string &filename ) ;

/*******************************************************************************************/

// 12-Read the last line of a text file
std::string read_lastLine_txtFile( const std::string &filename ) ;

/*******************************************************************************************/

// 13-Read the entire txt file 
std::string read_entire_txtFile( const std::string &filename ) ;

/*******************************************************************************************/

// 14-Write on a txt file
void write_to_txtFile( const std::string &filename, const std::string &content ) ;

/*******************************************************************************************/

// 15-Append on a txt file
void append_to_txtFile( const std::string &filename, const std::string &content ) ;

/*******************************************************************************************/

// 16-Copy the content of one txt file to another txt file
void copy_file( const std::string &sourceFilename, const std::string &destinationFilename ) ;

/*******************************************************************************************/

// 17-Count the number of lines in a file
int count_fileLines( const std::string &filename ) ;

/*******************************************************************************************/

// 18-Check if a file exists
bool does_file_exist( const std::string &filename ) ;

/*******************************************************************************************/

// 19-Write any data in binary mode
template <typename T>
void write_data_binFile( const std::string &filename, T &x ) 
{
    
    std::ofstream file( filename, std::ios::out | std::ios::binary ) ; 

    if( file.is_open() == true )
    {
        // write an obj as bytes
        file.write( reinterpret_cast<char*>(&x), sizeof(x) ) ; 
    }
    else
    {
        std::cerr << "Error: Could not open file '" << filename << "'.\n" ;
    }

    file.close();
    
}

/*******************************************************************************************/

// 20-Append any data in binary mode
template <typename T>
void append_data_binFile( const std::string &filename, T &data ) 
{
    
    std::ofstream file( filename, std::ios::out | std::ios::binary | std::ios::app ) ; 

    if( file.is_open() == true )
    {
        // write an obj as bytes
        file.write( reinterpret_cast<char*>(&data), sizeof(data) ) ; 
    }
    else
    {
        std::cerr << "Error: Could not open file '" << filename << "'.\n" ;
    }

    file.close();
    
}

/*******************************************************************************************/

// 21-Read any data from a bin file
template <typename T>
T read_data_binFile( const std::string& filename, int currentPosition ) 
{

    T data ;

    // Declare an input file stream object
    std::ifstream file( filename, std::ios::binary | std::ios::in ) ; 

    // Check if the file was successfully opened
    if( file.is_open() == true ) 
    {

        // Set the file pointer to the specified position
        file.seekg( currentPosition ) ;

        // Read the int value from the file
        file.read( reinterpret_cast<char*>(&data), sizeof(data) ) ;

        // Close the file
        file.close() ;

    }
    else 
    {
        // Handle the error
        std::cerr << "Could not open the file\n" ;
    }

    return data ;

}

/*******************************************************************************************/

// 22-Write data in chunks in bin file
template <typename T>
void write_chunck_binFile( const std::string& filename, T *data, int size, int chunk_size ) 
{
    
    // Declare an output file stream object with the binary flag
    std::ofstream file( filename, std::ios::binary | std::ios::out ) ; 

    // Check if the file was successfully opened
    if( file.is_open() == true ) 
    {
        // Loop through the data in chunks
        for( int i = 0; i < size; i += chunk_size )
        {
            // Calculate the actual size of the current chunk
            int actual_size = std::min( chunk_size, size - i ) ;

            // Write the chunk to the file
            file.write( reinterpret_cast<char*>(data + i), actual_size * sizeof(T) ) ;
        }

        // Close the file
        file.close() ;

    }
    else 
    {
        // Handle the error
        std::cerr << "Could not open the file\n" ;
    }

}

/*******************************************************************************************/

// 23-Read data in chunks from bin file
template <typename T>
void read_chunck_binFile( const std::string& filename, T *data, int size, int chunk_size ) 
{
    // Declare an input file stream object with the binary flag
    std::ifstream file( filename, std::ios::binary | std::ios::in ) ; 

    // Check if the file was successfully opened
    if( file.is_open() == true ) 
    {
        // Loop through the file in chunks
        for( int i = 0; i < size; i += chunk_size )
        {
            // Set the read position to the current chunk
            file.seekg( i * sizeof(T) ) ;

            // Read the chunk from the file
            file.read( reinterpret_cast<char*>(data + i), chunk_size * sizeof(T) ) ;
        }

        // Close the file
        file.close() ;

    }
    else 
    {
        // Handle the error
        std::cerr << "Could not open the file\n" ;
    }

}

/*******************************************************************************************/

// 24-Get a specific position in a txt file
std::streampos get_position_txtFile( std::ifstream &file ) ;

/*******************************************************************************************/

// 25-Seek to a specific position in a txt file
void seek_position_txtFile( std::ifstream &file, std::streampos position )  ;

/*******************************************************************************************/

// 26-Reset the position to the beginning of the file
void reset_position_txtFile( std::ifstream &file ) ;

/*******************************************************************************************/

// 27-Read a line at a specific position in a txt file
std::string readLine_atPosition_txtFile( const std::string &filename, std::streampos position ) ;

/*******************************************************************************************/

// 28-Write a line at a specific position in a txt file
void writeLine_atPosition_txtFile( const std::string& filename, const std::string& newLine, 
std::streampos position )  ;

/*******************************************************************************************/

// 29-Delete a line at a specific number in a txt file
void deleteLine_atNumber_txtFile( const std::string &filename, int lineNumber ) ;

/*******************************************************************************************/

// 30-Read lines at a specific position in a txt file
std::string readLines_atPosition_txtFile( const std::string &filename, std::streampos position ) ;

/*******************************************************************************************/

// 31-Write lines at a specific position in a txt file
void writeLines_atPosition_txtFile( const std::string &filename, const std::vector<std::string> &newLines, 
std::streampos position ) ;

/*******************************************************************************************/

// 32-Delete lines at a specific number in a txt file
void deleteLines_atNumber_txtFile( const std::string &filename, int lineNumber ) ;

/*******************************************************************************************/

// 33-Read a line at a specific number in a txt file
std::string readLine_atNumber_txtFile( const std::string &filename, int lineNumber ) ;

/*******************************************************************************************/

// 34-Write a line at a specific number in a txt file
void writeLine_atNumber_txtFile( const std::string &filename, const std::string &lineContent, int lineNumber ) ;

/*******************************************************************************************/

// 35-Read lines at a specific number in a txt file
std::vector<std::string> readLines_atNumber_txtFile( const std::string& filename, int startLineNumber ) ;

/*******************************************************************************************/

// 36-Write lines at a specific number in a txt file
void writeLines_atNumber_txtFile( const std::string &filename, const std::vector<std::string> &lines, 
int lineNumber ) ;

/*******************************************************************************************/

// 37-Append a line at a specific number in a txt file
void appendLine_atNumber_txtFile( const std::string &filename, const std::string &lineToAdd, 
int lineNumber ) ;

/*******************************************************************************************/

// 38-Append lines at a specific number in a txt file
void appendLines_atNumber_txtFile( const std::string &filename, const std::vector<std::string> &linesToAdd, 
int lineNumber )  ;

/*******************************************************************************************/

// 39-Search for a specific word in a txt file and return the first line number where it occurs
int findWord_txtFile( const std::string &filename, const std::string &targetWord ) ;

/*******************************************************************************************/

// 40-Delete a specific word in a txt file
bool deleteWord_txtFile ( const std::string &fileName, const std::string &word ) ;

/*******************************************************************************************/

// 41-Replace a specific word in a txt file
bool replaceWord_txtFile ( const std::string &fileName, const std::string &word, 
const std::string &newWord ) ;

/*******************************************************************************************/

// 42-Lock file 


/*******************************************************************************************/

// 43-Unlock fle


/*******************************************************************************************/

#endif