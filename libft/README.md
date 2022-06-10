## Task description
This project aims to code a C library.

# Technical considerations
- It is forbidden to declare global variables.
- If you need subfunctions to write a complex function, you should define these subfunctions as static to avoid publishing them with your library. It would be a good habit to do this in your future projects as well.
- It is forbidden to submit unused files.
- You must use the command ar to create your library, using the command libtool is forbidden.
- Submit all files in the root of your repository.

Clone this repo and change directory to the libft folder:
```
    git clone https://github.com/jaymoz/42-school.git
    cd libft
```
Compile the project:
```c
   make
```
to use the library:
- include `libft.h` header in your file.
- compile your project with:
```
   gcc 'nameofyourfile' libft.a
```

additional description can be found in the subject below

[libft.pdf](https://github.com/jaymoz/42-school/files/7576737/libft.pdf)
