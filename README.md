****************************************************
Abir Abbas         						     0955448
CIS2750 - Assignment 2
2018-02-02                        abbasa@uoguelph.ca
****************************************************

************
Compilation
************

make

***********************
Running the program(s)
***********************
./A3

*****************
Question 2.4
*****************

The average ratio was calculated using the data under the "output" section of this README

average ratio for brute force : 48904760 shifts/s

average ratio for horsepool : 52554058 shifts/s

analysis : They both have a very similar shifts/s ratio, which is most likely due to the fact that the algorithms for the most part
uses the same comparisons and functions to actually figure out whether the search pattern matches or not. The key difference between the
two aglorithm is the number of total shifts, so even tho they have the same shifts/s ratio, they will likely have different amount of shifts and computing times.
as a result both will have a worst case time of O(mn) because both have the same shifts/s ratio but the average case will differ.

*****************
output
*****************
Word : outcome
Total strings found : 20
Total pattern switches : 3036227
Total time taken : 0.064741 seconds

Word : the
Total strings found : 28338
Total pattern switches : 3212415
Total time taken : 0.070274 seconds

Word : potato
Total strings found : 0
Total pattern switches : 3080274
Total time taken : 0.063161 seconds

Word : test
Total strings found : 253
Total pattern switches : 3168368
Total time taken : 0.066411 seconds

Word : dinosaur
Total strings found : 0
Total pattern switches : 2992180
Total time taken : 0.060859 seconds

Word : dictionary
Total strings found : 0
Total pattern switches : 2904086
Total time taken : 0.057531 seconds

Word : to
Total strings found : 15252
Total pattern switches : 3256464
Total time taken : 0.067872 seconds

Word : I
Total strings found : 6168
Total pattern switches : 3300512
Total time taken : 0.063863 seconds

Word : communication
Total strings found : 33
Total pattern switches : 2771945
Total time taken : 0.055776 seconds

Word : money
Total strings found : 2
Total pattern switches : 3124321
Total time taken : 0.061313 seconds

************* HORSEPOOL ************


Word : outcome
Total strings found : 20
Total pattern switches : 490397
Total time taken : 0.010929 seconds


Word : the
Total strings found : 28338
Total pattern switches : 1049208
Total time taken : 0.019851 seconds


Word : potato
Total strings found : 0
Total pattern switches : 586477
Total time taken : 0.011170 seconds


Word : test
Total strings found : 253
Total pattern switches : 853860
Total time taken : 0.016284 seconds


Word : dinosaur
Total strings found : 0
Total pattern switches : 466418
Total time taken : 0.009309 seconds


Word : dictionary
Total strings found : 0
Total pattern switches : 403625
Total time taken : 0.008414 seconds


Word : to
Total strings found : 15252
Total pattern switches : 1521719
Total time taken : 0.024499 seconds


Word : I
Total strings found : 6168
Total pattern switches : 2706912
Total time taken : 0.040871 seconds


Word : communication
Total strings found : 33
Total pattern switches : 318048
Total time taken : 0.007905 seconds


Word : money
Total strings found : 2
Total pattern switches : 697834
Total time taken : 0.012412 seconds

