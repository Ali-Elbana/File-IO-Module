


#include "FIO.hpp"

void create_txt_file(const std::string& filename) 
{

    // Open the file for writing
    std::ofstream file( filename ) ;

    // Check if the file is successfully opened
    if( !file.is_open() ) 
    {
        std::cerr << "Error: Could not create file " << filename << "\n" ;
    }
    else
    {

        // Write some content to the file
        file << "Hello, this is a new file!\n";
        file << "You can add more content here.\n";

        // Close the file
        file.close();

        std::cout << "File '" << filename << "' created successfully.\n" ;

    }

}


