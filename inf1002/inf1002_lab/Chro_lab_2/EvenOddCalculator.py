r'''
Task Description:
In this task, you are assigned to develop one program to help users calculate 
different information based a series of user provided numbers (integers). 
Detailed requirement is provided as follows: 

Input: A series of numbers 
Output: (Your output should be in one line)
	. The summation of the even numbers and summation of the odd numbers in 
       the input list 
	. The difference between the biggest and smallest numbers in the input list
	. The count of even numbers and odd numbers in the input list
	. The "centered" average of the list of integers. The centered average can be 
       calculated as the mean average of the values, after removing the largest and 
       smallest values in the array. If there are multiple copies of the smallest 
       value, ignore all but keep just one copy, and likewise for the largest value. 
       For instance, [12,2,8,7,100] -> 9; [2,2,8,11,100] -> 7

To have a better understanding of the loops, please try to implement 
two programs: one uses "for" and another uses "while" loop.

Running Examples:

C:\INF1002\Lab2\EvenOddCalculator> python EvenOddCalculator.py 12,2,8,7,100
The sum of all even numbers is 122, the sum of all odd numbers is 7, the difference between the biggest and smallest number is 98, the total number of even numbers is 4, the total number of odd numbers is 1, the centered average is 9.

C:\INF1002\Lab2\EvenOddCalculator> python EvenOddCalculator.py 1,2,abcd,8,11,200,301
Please enter valid integers.
'''
import sys
# write your code here
# you can use sys.argv[1] to get the first input argument.
# sys.argv[2] is the second argument, etc.
def EvenOddCalculator():
       UserInput = sys.argv[1].split(",")
       IntInput = []
       EvenSum=0
       OddSum=0
       CountEven=0
       CountOdd=0
       try:
              for i in UserInput:
                     IntInput.append(int(i))
                     if int(i) % 2 == 0:
                            CountEven += 1
                            EvenSum += int(i)
                     else:
                            CountOdd += 1
                            OddSum += int(i)           
              IntInput.sort()
              Smallest = IntInput[0]
              Biggest = IntInput[-1]
              IntInput.pop(0)
              IntInput.pop(-1)
              if IntInput.count(IntInput[0]) > 1 and IntInput[0] == Smallest:
                     for i in range(IntInput.count(IntInput[0]) - 1):
                            IntInput.count(IntInput[0])
                            IntInput.remove(IntInput[0])
              print(f"The sum of all even numbers is {EvenSum}, the sum of all odd numbers is {OddSum}, the difference between the biggest and smallest number is {Biggest-Smallest}, the total number of even numbers is {CountEven}, the total number of odd numbers is {CountOdd}, the centered average is {int(sum(IntInput) / len(IntInput))}.")
       except:
              print("Please enter valid integers.")

if __name__=='__main__':
       EvenOddCalculator()