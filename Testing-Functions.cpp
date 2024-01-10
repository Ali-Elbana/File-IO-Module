/* FILENAME: Testing-Function.cpp
*  Author:  Ali El-Bana
*  Version:  V1.0
*  DATE:   Thur 12/21/2023
*/

#include "FIO.hpp"

#define RUN     1
#define STOP    0

#define CREATE_TXT_FILE         RUN
#define CREATE_BIN_FILE         STOP
#define DELETE_FILE             STOP
#define RENAME_FILE             STOP
#define OPEN_TXT_FILE_RD        STOP
#define OPEN_TXT_FILE_WT        STOP
#define OPEN_BIN_FILE_RD        STOP
#define OPEN_BIN_FILE_WT        STOP
#define CLEAR_FILE              STOP
#define CHECK_FILE_STATUS       STOP
#define RD_FLINE_FILETXT        STOP
#define RD_LLINE_FILETXT        STOP
#define RD_ENTIRE_FILETXT       STOP
#define WT_TO_FILETXT           STOP
#define AD_TO_FILETXT           STOP
#define CP_FILETXT              STOP
#define CP_FILEBIN              STOP
#define CNT_LINES               STOP
#define FILE_EXISTANCE          STOP
#define WT_OBJ_FILEBIN          STOP
#define AD_OBJ_FILEBIN          STOP
#define RD_OBJ_FILEBIN          STOP
#define WT_CHUNCK_FILEBIN       STOP
#define RD_CHUNCK_FILEBIN       STOP
#define GET_FILETXT_POS         STOP
#define SEEK_FILETXT_POS        STOP
#define RST_FILETXT_POS         STOP
#define RD_LINE_FILETXT_POS     STOP
#define WT_LINE_FILETXT_POS     STOP
#define DEL_LINE_FILETXT_NUM    STOP
#define RD_LINES_FILETXT_POS    STOP
#define WT_LINES_FILETXT_POS    STOP
#define DEL_LINES_FILETXT_NUM   STOP
#define RD_LINE_FILETXT_NUM     STOP
#define WT_LINE_FILETXT_NUM     STOP
#define RD_LINES_FILETXT_NUM    STOP
#define WT_LINES_FILETXT_NUM    STOP
#define AD_LINE_FILETXT_NUM     STOP
#define AD_LINES_FILETXT_NUM    STOP
#define FD_WORD_FILETXT_NUM     STOP
#define DEL_WORD_FILETXT        STOP
#define REP_WORD_FILETXT        STOP


/*******************************************************************************************/
/*******************************************************************************************/

#if CREATE_TXT_FILE == RUN

    int main( void )
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_txt_file function
        const std::string filename = "example.txt" ;

        create_txt_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CREATE_BIN_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_binary_file function
        const std::string filename = "example.bin" ;

        create_bin_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if DELETE_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // Example usage of the create_binary_file function
        const std::string filename = "new_file.txt" ;

        delete_file( filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RENAME_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string oldFileName = "example.txt";
        std::string newFileName = "new_file.txt";

        rename_file( oldFileName, newFileName ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_TXT_FILE_RD == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::cout << "Enter the name of the file to read: " ;
        std::string filename ;
        std::cin >> filename ;

        // Open the file using the open_txt_file_read function
        std::ifstream fileStream = open_txt_file_read( filename ) ;

        // Read and print the content line by line
        std::string line ;

        while( std::getline(fileStream, line) )  
        {
            std::cout << line << std::endl;
        }

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_TXT_FILE_WT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::cout << "Enter the name of the file to write: " ;
        std::string filename ;
        std::cin >> filename ;

        // Open the file using the open_file_write function
        std::ofstream fileStream = open_txt_file_write( filename ) ;

        // Write some text to the file
        fileStream << "Hello, this is a test.\n";
        fileStream << "Writing to a text file using C++.\n";

        std::cout << "Text written to the " << filename << " file.\n";

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_BIN_FILE_RD == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename {"test.bin"} ;

        create_bin_file( filename ) ;

        // Declare a variable of type std::ofstream
        std::ofstream fout ;

        // Open the file in binary write mode
        fout.open( filename, std::ios::out | std::ios::binary ) ;

        // Check if the file is open
        if( fout.is_open() != true )
        {
            std::cerr << "Cannot open file!" << std::endl ;
        }

        // Write some data to the file
        int     x {42}    ;
        double  y {3.14}  ;
        char    z {'A'}   ;

        fout.write( reinterpret_cast<const char*>(&x), sizeof(x) ) ;
        fout.write( reinterpret_cast<const char*>(&y), sizeof(y) ) ;
        fout.write( reinterpret_cast<const char*>(&z), sizeof(z) ) ;

        // Close the file
        fout.close();

        // Open the file using the open_bin_file_read function
        std::ifstream fileStream = open_bin_file_read( filename ) ;

        // Read the data from the file
        fileStream.read( reinterpret_cast<char*>(&x), sizeof(x) ) ;
        fileStream.read( reinterpret_cast<char*>(&y), sizeof(y) ) ;
        fileStream.read( reinterpret_cast<char*>(&z), sizeof(z) ) ;

        // Print the data to the standard output
        std::cout << "The data read from the file is: \n" ;
        std::cout << "x = " << x << "\n" ;
        std::cout << "y = " << y << "\n" ;
        std::cout << "z = " << z << "\n" ;

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if OPEN_BIN_FILE_WT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename {"test.bin"} ;

        create_bin_file( filename ) ;

        std::ofstream fout = open_bin_file_write( filename ) ;

        // Write some data to the file
        int     x {42}    ;
        double  y {3.14}  ;
        char    z {'A'}   ;

        fout.write( reinterpret_cast<const char*>(&x), sizeof(x) ) ;
        fout.write( reinterpret_cast<const char*>(&y), sizeof(y) ) ;
        fout.write( reinterpret_cast<const char*>(&z), sizeof(z) ) ;

        // Close the file
        fout.close();

        // Open the file using the open_bin_file_read function
        std::ifstream fileStream = open_bin_file_read( filename ) ;

        // Read the data from the file
        fileStream.read( reinterpret_cast<char*>(&x), sizeof(x) ) ;
        fileStream.read( reinterpret_cast<char*>(&y), sizeof(y) ) ;
        fileStream.read( reinterpret_cast<char*>(&z), sizeof(z) ) ;

        // Print the data to the standard output
        std::cout << "The data read from the file is: \n" ;
        std::cout << "x = " << x << "\n" ;
        std::cout << "y = " << y << "\n" ;
        std::cout << "z = " << z << "\n" ;

        fileStream.close( ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CLEAR_FILE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"}    ;
        std::string bin_filename {"test.bin"}       ;

        std::ofstream tfout = open_txt_file_write( txt_filename ) ;

        clear_file( txt_filename ) ;

        std::ofstream bfout = open_bin_file_write( bin_filename ) ;

        clear_file( bin_filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CHECK_FILE_STATUS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"}    ;

        check_file_status( txt_filename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_FLINE_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename    {"example.txt"} ;
        std::string fContent        {""}            ;

        fContent = read_firstLine_txtFile( txt_filename ) ;

        std::cout<< "The first line in the file '" <<txt_filename <<"' is:\n" <<fContent <<'\n' ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_LLINE_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename    {"example.txt"} ;
        std::string fContent        {""}            ;

        fContent = read_lastLine_txtFile( txt_filename ) ;

        std::cout<< "The last line in the file '" <<txt_filename <<"' is:\n" <<fContent <<'\n' ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_ENTIRE_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename    {"example.txt"} ;
        std::string fContent        {""}            ;

        fContent = read_entire_txtFile( txt_filename ) ;

        std::cout<< "The content of the file '" <<txt_filename <<"' is:\n" <<fContent <<'\n' ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_TO_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename1    {"example.txt"}    ;
        std::string txt_filename2    {"example2.txt"}   ;
        std::string fContent        {""}                ;

        fContent = read_entire_txtFile( txt_filename1 ) ;

        write_to_txtFile( txt_filename2, fContent ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if AD_TO_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"} ;

        append_to_txtFile( txt_filename, "\nI'm now developing a module for file I/O operations.\n" ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if AD_TO_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string txt_filename {"example.txt"} ;

        append_to_txtFile( txt_filename, "\nI'm now developing a module for file I/O operations.\n" ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CP_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string sourceFilename      = "example.txt"     ;
        std::string destinationFilename = "example2.txt"    ;

        copy_file( sourceFilename, destinationFilename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CP_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string sourceFilename      = "test.bin"     ;
        std::string destinationFilename = "test2.bin"    ;

        copy_file( sourceFilename, destinationFilename ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if CNT_LINES == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "FIO.cpp" ;
    
        std::cout <<"\nThe number of lines in " << filename << " is: "
        << count_fileLines( filename ) << " line.\n" ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if FILE_EXISTANCE == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "FO.cpp" ;

        if( does_file_exist( filename ) == true )
        {
            std::cout <<"\nThe file '" << filename << "' already exist.\n" ;
        }
        else
        {
            std::cout <<"\nThe file '" << filename << "' doesn't exist.\n" ;
        }

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_OBJ_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "test2.bin" ;

        int     x   {20} ;
        char    y  {'A'} ;

        write_data_binFile( filename, x ) ;

        write_data_binFile( filename, y ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if AD_OBJ_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "test2.bin" ;

        int     x  {30}  ;
        char    y  {'B'} ;

        append_data_binFile( filename, x ) ;

        append_data_binFile( filename, y ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_OBJ_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "test2.bin" ;

        int offset {0} ;
        
        char readChar = read_data_binFile<char>( filename, offset ) ;

        offset += sizeof( char ) ;

        int readInt = read_data_binFile<int>( filename, offset ) ;

        std::cout<< "\nThe readChar = " << readChar << "\nThe readInt = " << readInt << '\n' ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_CHUNCK_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // declare an array of double values
        double data[] = {1.2, 3.4, 5.6, 7.8, 9.0} ; 

        // declare the size of the array
        int size = 5 ; 

        // declare the size of each chunk
        int chunk_size = 2 ; 

        // declare the file name
        std::string filename = "test2.bin" ; 

        // call the function template with double type and the variables as arguments
        write_chunck_binFile<double>( filename, data, size, chunk_size ) ;

        // print a message to the console
        std::cout << "The data has been written to the file in chunks of size " << chunk_size << std::endl ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_CHUNCK_FILEBIN == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        // declare an array of double values
        double data[5]; 

        // declare the size of the array
        int size = 5; 

        // declare the size of each chunk
        int chunk_size = 2; 

        // declare the file name
        std::string filename = "test2.bin" ; 

        // call the function template with double type and the variables as arguments
        read_chunck_binFile<double>( filename, data, size, chunk_size ) ;

        // print the data to the console
        std::cout << "\nThe data read from the file in chunks of size " << chunk_size << " are: \n" ;
        for( int i = 0; i < size; i++ )
        {
            std::cout << data[i] << " " ;
        }

        std::cout << '\n' ;
        
        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if GET_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::streampos position = get_position_txtFile( filename ) ;

        if( position != -1 ) 
        {
            std::cout << "Current position in file " << filename << ": " << position << ".\n" ;
        } 
        else 
        {
            std::cerr << "Error: Could not open the file to get the current position.\n" ;
        }
        
        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if SEEK_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::ifstream file( filename ) ;

        std::streampos pos {3} ;

        seek_position_txtFile( file, pos ) ;

        std::streampos currPosition = get_position_txtFile( file ) ;

        if( currPosition != -1 ) 
        {
            std::cout << "Current position in file " << filename << ": " << currPosition << ".\n" ;
        } 
        else 
        {
            std::cerr << "Error: Could not open the file to get the current position.\n" ;
        }
        
        file.close() ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RST_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::ifstream file( filename ) ;

        std::streampos pos {3} ;

        seek_position_txtFile( file, pos ) ;

        std::streampos currPosition = get_position_txtFile( file ) ;

        if( currPosition != -1 ) 
        {
            std::cout << "Current position in file " << filename << ": " << currPosition << ".\n" ;
        } 
        else 
        {
            std::cerr << "Error: Could not open the file to get the current position.\n" ;
        }

        reset_position_txtFile( file ) ;

        currPosition = get_position_txtFile( file ) ;

        std::cout << "\nAfter reseting the position:\n" ;

        if( currPosition != -1 ) 
        {
            std::cout << "Current position in file " << filename << ": " << currPosition << ".\n" ;
        } 
        else 
        {
            std::cerr << "Error: Could not open the file to get the current position.\n" ;
        }

        file.close() ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_LINE_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::ifstream file( filename ) ;

        std::streampos pos {3} ;

        std::cout<< "\nThe line is: " << readLine_atPosition_txtFile( filename, pos ) << '\n' ;

        file.close() ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_LINE_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::streampos pos {20} ;

        writeLine_atPosition_txtFile( filename, "Enjoy using this module?", pos ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if DEL_LINE_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        int lineNum {2} ;

        deleteLine_atNumber_txtFile( filename, lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_LINES_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::streampos pos {3} ;

        std::cout<< "\nThe lines are: \n" << readLines_atPosition_txtFile( filename, pos ) << '\n' ;

        return 0 ;

    }

#endif


/*******************************************************************************************/
/*******************************************************************************************/

#if WT_LINES_FILETXT_POS == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::vector<std::string> newLines {"Line 1", "Line 2", "Line 3"} ;

        std::streampos pos {20} ;

        writeLines_atPosition_txtFile( filename, newLines, pos ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if DEL_LINES_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        int lineNum {2} ;

        deleteLines_atNumber_txtFile( filename, lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_LINE_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        int lineNum {2} ;

        std::cout<< "\nThe line is: " << readLine_atNumber_txtFile( filename, lineNum ) << '\n' ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_LINE_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        int lineNum {5} ;

        writeLine_atNumber_txtFile( filename, "Line 4", lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if RD_LINES_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::vector<std::string> lines ;

        int lineNum {6} ;

        lines = readLines_atNumber_txtFile( filename, lineNum ) ;

        for( const auto &line : lines ) 
        {
            std::cout<< line << '\n' ;
        }

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if WT_LINES_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::vector<std::string> newLines {"Line 5", "Line 6", "Line 7"} ;

        int lineNum {6} ;

        writeLines_atNumber_txtFile( filename, newLines, lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if AD_LINE_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        int lineNum {9} ;

        appendLine_atNumber_txtFile( filename, "Line 8", lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if AD_LINES_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::vector<std::string> newLines {"Line 9", "Line 10", "Line 11"} ;

        int lineNum {10} ;

        appendLines_atNumber_txtFile( filename, newLines, lineNum ) ;

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if FD_WORD_FILETXT_NUM == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::string targetWord = "1" ; 

        int lineFound = findWord_txtFile( filename, targetWord ) ;

        if( lineFound != -2 ) 
        {
            std::cout << "The word '" << targetWord << "' was found on line " << lineFound << ".\n" ;
        } 
        else 
        {
            std::cout << "The word '" << targetWord << "' was not found in the file.\n" ;
        }

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if DEL_WORD_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;

        std::string targetWord = "Line 1" ; 

        bool success = deleteWord_txtFile( filename, targetWord ) ;

        if( success == true )
        {
            std::cout << "The word " << targetWord << " was deleted successfully from the file " << filename << ".\n" ; // print a success message
        }
        else 
        {
            std::cout << "The word " << targetWord << " was not found in the file " << filename << ".\n" ; // print a failure message
        }

        return 0 ;

    }

#endif

/*******************************************************************************************/
/*******************************************************************************************/

#if REP_WORD_FILETXT == RUN

    int main( void ) 
    {

        // Clear the terminal window
        system( "cls" ) ;

        std::string filename = "example.txt" ;
  
        std::string word = "Line 2" ; 

        std::string newWord = "Line 1" ;

        bool result = replaceWord_txtFile( filename, word, newWord ) ;

        if( result == true ) 
        { 
            std::cout << "The word " << word << " was replaced with " << newWord << " successfully in the file " << filename << ".\n" ; 
        }
        else 
        {
            std::cout << "The word " << word << " was not found in the file " << filename << ".\n" ;
        }

        return 0 ;

    }

#endif


/*******************************************************************************************/
/*******************************************************************************************/
