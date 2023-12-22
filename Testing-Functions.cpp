
#include <iostream>
#include <fstream>
#include <filesystem>

#include "FIO.hpp"

#define RUN     1
#define STOP    0

#define CREATE_TXT_FILE RUN

#if CREATE_TXT_FILE == RUN

    int main( )
    {

        // Example usage of the create_txt_file function
        const std::string filename = "example.txt" ;

        create_txt_file( filename ) ;

        return 0;

    }

#endif




