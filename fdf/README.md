## Project description
This project is about creating a simplified graphic “wireframe” (“fils de fer” in French,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to your program. Here is an example:

<img width="604" alt="Screenshot 2021-11-21 at 20 47 01" src="https://user-images.githubusercontent.com/62575348/142773189-996b1da5-34db-4018-a4e7-e1b0403c89b0.png">
Each number corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

clone this repo and change directory to fdf:
```html
   git clone https://github.com/jaymoz/42-school.git
   cd fdf
```
compile the project:
```html
   make
```
to run the project, various maps can be found in the test_maps folder in the project, here is an example:
```html
   ./fdf test_maps/pyra.fdf
```
<img width="1009" alt="Screenshot 2021-11-21 at 20 55 23" src="https://user-images.githubusercontent.com/62575348/142773431-e7760a12-1f02-4741-acc4-ec22d99455cc.png">

additional description can be found in the subject below:

[fdf.pdf](https://github.com/jaymoz/42-school/files/7576782/fdf.pdf)
