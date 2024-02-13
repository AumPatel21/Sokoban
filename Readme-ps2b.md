# PS2b: Sokoban

## Contact
Name: Aum Patel
Section: 202
Time to Complete: 12 hours


## Description
In this project, we implement the game mechanics of Sokoban. The player can move up, left, down and right and push boxes into available storage locations. If the players succeeds to do so, they win and the game can be reset to play again.

### Features
I made four separate functions the four directions to use in movePlayer() so that it is easier to read and understand compared to everything written in one function. I also made use of switch cases for the same reason.

### Memory
Describe how you decided to store the level data including whether you used smart pointers.

I used a dynamically allocated char string to store the data of the level files


### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.

I used count_if(), any_of() and for_each() algorithms. count_if() was used to count the total number of goals in a level.  

any_of() was used to check if the storage location and box shared the same index. 

for_each() was used as a substitute for a for loop and apply the any_of() algorithm to every element in the array.

I implemented a lambda expression in the count_if() algorithm which would make it count only if its parameter equals to a storage location which is 'a' in our case.  

I implemented a lambda expression inside the any_of() algorithm to check if any the array contained 'A' and 'a' at the same index. If it did, then I would increment the number of boxes on storage locations.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I had trouble with resetting the map but I later realized that I could just make a copy of the original map in the main function and use that to reset the game

after fixing that, everything works.


### Extra Credit
Anything special you did.  This is required to earn bonus points.


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

I was looking for a video to understand lambda expression and this is also where I got the idea to use a for_each() algorithm too
https://www.youtube.com/watch?v=mWgmBBz0y8c

## Changes
I've fixed the reset function and now it works as intended. Added a Copy constructor so I can copy the level data in a temporary variable and use it in my reset function as a parameter to re-create the original map when user clicks R.


I used algorithms (count_if(), any_of(), for_each()) and lambda expressions in 
isWon(). I've written more in detail about this in ###Lambdas

I previously attempted to do the extra credit where the player sprite changes faces according to the direction it's moving for which i made a vector to load the images but for some reason it wasn't working So I removed it because I ran out of time.