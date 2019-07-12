# Fillit

Another project at 42. In this one, we need to parse one **and only one** file, that is given in parameter to the executable, and retrieve a list of well formated *tetriminos*¹. Depending on this list, the next step is to print on the standard output the first *smallest square*² found in which all pieces can fit correctly.

## Install

Should be fully portable (tested on macOS X, Debian Stretch 9.8 and Windows 10). This program doesn't need anything to run correctly.

Simply type command bellow in your shell :
```shell
$> make
```

## Usage
### Run the program

Once the program is compiled, run it with the following command line :
```shell
$> ./fillit 'file'
```
The given file must contains a valid list of tetriminos otherwise an error is displayed. If, at any point during the process, an error occurs, the allocated memory is freed and an an error message is written on the standard output before the program's end.

This project was done in collaboration with [@abaurens](https://github.com/abaurens)

*tetriminos*¹ : Tetriminos are defined by a combination of four connected points or cells.   
*smallest square*² : The smallest square is the first solution found by the program. A correct solution is a result in which all pieces are placed the highest  and at the left most position.
