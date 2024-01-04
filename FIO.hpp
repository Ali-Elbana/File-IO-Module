


#ifndef FIO_H
#define FIO_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>  // for remove

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

// 13-Read the entire file 


/*******************************************************************************************/

#endif