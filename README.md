# Convex Hull OpenCV C++
A Convex Hull is essentially the convex boundary around an object. 
Here is something interesting we discovered while researching the 
algorithms for finding the Convex Hull. 

The first O(n) algorithm was published by Sklansky in 1972. It was later proven to be incorrect. 
Between 1972 and 1989, 16 different linear algorithms were published and 7 of them were found to 
be incorrect later on! The algorithm implemented in OpenCV is one by Sklansky (1982). 
It happens to be INCORRECT as well! However, it works just fine for a vast majority of cases. 
