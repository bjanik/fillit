# fillit - Can you fillit?

## Use

./fillit [file]

Program takes a file as argument which describes a list of Tetrominos, which will have to be assembled to create the smallest square possible.

Our programm will first have to check if the input file is correctly formatted:
    No more than 26 tetrominos present int he input file
    
    Each Tetrominos must be represented on a 4 x 4 square for example : 
    
    #...
    
    #...
    
    #...
    
    #...
                                                                      
If the file is formatted correctly, then the program will display all the Tetrominos assembled in in smallest square.

In order to differentiate the tetrominos displayed, they will be displayed with as capital letters, starting from A.

Example solution display:

    AAAA
    
    BBB.
    
    ..B.
    
    ....
    
