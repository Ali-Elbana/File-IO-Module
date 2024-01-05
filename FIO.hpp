


#ifndef FIO_H
#define FIO_H

#include <iostream>
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


/*******************************************************************************************/



/*******************************************************************************************/

/* TO_DO: ✅

    Write these functions:
    1-Check if a file exists.
    2-Write data in binary mode.
    3-Write data in chunks in binary mode.
    4-Seek to a specific position in a txt file.
    5-Add a line or sort of lines after a specific position in a txt file.
    6-Search for a specific word or a line in a txt file.
    7-Delete a specific word or a line in a txt file.
    8-Replace a specific word or a line in a txt file.

*/

/*******************************************************************************************/

#endif