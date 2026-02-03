
# Q1
correct
P(S|F) = $\frac{P(F|S)P(S)}{P(F|S)P(S) + P(F|S^`)P(S^`)} = \frac{.1 * .8}{.1*.8 + .01*.2} = 0.9756$


# Q2
a.

| time   | freq | grp mean | xifi  | xi^2 fi |
| ------ | ---- | -------- | ----- | ------- |
| 35-45  | 12   | 40       | 480   | 19200   |
| 45-55  | 54   | 50       | 2700  | 135000  |
| 55-65  | 68   | 60       | 4080  | 244800  |
| 65-85  | 41   | 75       | 3075  | 230625  |
| 85-105 | 23   | 95       | 2185  | 207575  |
| total  | 198  |          | 12520 | 837200  |
overall mean = 63.23

correction
std = 15.203
$\frac{1}{n-1}[\displaystyle\sum{}x_i^2f_i - \frac{(\displaystyle\sum{}x_if_i)^2}{n}] = \frac{1}{198-1}[837200 - \frac{(12520)^2}{198}] = 15.203$

b.

$L_m + (\frac{ \frac{n}{2} - cf_{m-1} }{ f_m })w_m$
55 + ($\frac{ \frac{198}{2}-54 }{68}$)10 = 61.62

correction

55 + ($\frac{ \frac{198}{2}-66 }{68}$)10 = 59.85

c.  ( upper limit of most common group - lower limit of most common group ) / 2 + lower limit of most common group= mode
( 65-55 )/2 + 55 = 60

correction
mode is class 55-65

# Q3
a.
0.6 * 0.3 * 0.75 = .135

b.
.5*.3 + .5*.75 = .9
correction
.5*.3*.4 + .5*.75*.4 = 0.21
# Q4

a.
random variable X is discrete as number of later arrivals can only be whole numbers

b. total 460

| num late | num pupil | P(X=x)  | xP(X=x)    |
| -------- | --------- | ------- | ---------- |
| 0        | 275       | 275/480 | 0(275/480) |
| 1        | 111       | 111/480 |            |
| 2        | 33        | 33/480  |            |
| 3        | 12        | 12/480  |            |
| 4        | 13        | 13/480  |            |
| 5        | 16        | 16/480  |            |

c. 
E(X) = $\mu$ = $\displaystyle\sum{}xP(X=x)$ = 275(275/480) + 111(111/480) + 33(33/480) + 12(12/480) + 13(13/480) + 16(16/480) 


correction
E(X) = $\mu$ = $\displaystyle\sum{}xP(X=x)$ = 0(275/480) + 1(111/480) + 2(33/480) + 3(12/480) + 4(13/480) + 5(16/480) 
= 0.75
????????????
# Q5
a.
X ~ B(5,0.15)

P(X<=2) = P(X=0) + P(X=1) + P(X=2)

(.85 \* .85 \* .85 \* .85 \*.85) + (.85 \* .85 \* .85 \* .85 \*.15) + (.85 \* .85 \* .85 \* .15 \*.15) = 

Correcction 0.9734

b.
correction
P(X>3) = P(X=3) + P(X=4) + P(X=5)

1-value of part a = 0.0266

c. 
correction
np = 5\*0.15 =0.75

var(X) = np(1-p) = 0.6375
std dev = 0.7984

# Q6



# Q7




# extra


| letter |     |     |
| ------ | --- | --- |
| A      | -1  | .4  |
| B      | -5  | .3  |
| C      | 2   | .2  |
| D      | 10  | .1  |
|        |     | 1   |

-1*.4 + -5*.3 + 2(.2) + 10(.1) = -.4 -1.5 +.4+1 = -0.5