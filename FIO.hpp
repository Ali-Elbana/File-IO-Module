


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



/*******************************************************************************************/



#endif