#include <stdio.h>
#include <stdlib.h> /* for atoi() */

//buffer size 1024 bytes

int main(int argc, char const *argv[])
{
	double numBytes;

	//test passing arguments into main
	int m,n;
    if (argc != 4) {
    	printf("Usage: %s m n filename\n",argv[0]);
    	return 1;
    }
    m = atoi(argv[1]); /* convert strings to integers */
    n = atoi(argv[2]);
    printf("%s received m=%i n=%i filename=%s\n",argv[0],m,n,argv[3]);

    // end test
	//program is opened and filenames are specified
	//./mycp <arg1> <arg2>
	
	//accept input
	//arg1 is source file, arg2 is destination file
	//arg1 = sourceFile; arg2 = destinationFile;
	//cp (arg1 arg2)
		//open sourceFile
			//if doesnt exist. 
				//error message 
				//return 0
		//create destinationFile
			//if exists 
				//error message 
				//return 0
		//loop through contents of sourceFile and copy to destinationFile
			//read contents of sourceFile
				//if error 
					//error message 
					//return 0
			//write contents to destinationFile
				//if error 
					//error message 
					//return 0
		//close both files
		//get total number of bytes copied
		//print total number of bytes copied
			//printf("copied %d bytes", numBytes)

	return 0;
}

       
