
# tutorial timetable

- Wk2: descriptivve stats + probability theory
- Wk3: Probability theory +Discrete probability distribution
- Wk4: Continuous probability distribution (Q1-6)
- Wk5: Sampling distributions (Q7-10)
- Wk6: revision

Show workings in exams
Blue / black pen only in exam
expected to attempt tutorial qn before class
open mouth and ask qns if dk
solve qns independently and correctly
# Chap 1: Descriptive Statistics

### Formulas & Symbols

| Parameter (population) / Statistic (Sample) | Populaion                  | Sample            |
| ------------------------------------------- | -------------------------- | ----------------- |
| Mean                                        | $\mu$ / mu                 | $\bar{x}$ / x-bar |
| Variance                                    | $\sigma^2$ / sigma squared | $s^2$ / s squared |
| Standard Deviation                          | $\sigma$ / sigma           | $s$ / just s      |
| Proportion                                  | p / just p                 | $\hat{p}$ / p-hat |

general formula for mean = $\frac{ x_1f_1 + x_2f_2 + ... + x_kf_k}{ n }$ = $\frac{ \displaystyle\sum_{} x_if_i } {n}$

mean (discrete data) = $\frac{ \displaystyle\sum_{} x_i } {n}$   
- $x_i$ = each value from set
- no $f_i$ as frequency for each discrete data is 1

mean (grouped data) = $\frac{ \displaystyle\sum_{} {group\ average}_i \times {group\ frequency}_i} {n}$   

median (odd num of values) = middle num
median (even num of values) = two middle nums / 2
median (grouped data) = $L_m + (\frac{ \frac{n}{2} - cf_{m-1} }{ f_m })w_m$
- n = number of values
- $L_m$ = Lower bound of class containing median
- $f_m$ = frequency of class containing median
- $cf_{m-1}$ = cumilative freq of ALL class before median class
- $w_m$ = width of class containing median (e.g. category range is 20-60, so $w_m$ is 40 )

Population variance $\sigma^2$ = $\frac{\displaystyle\sum{} (x_i - \mu)^2}{N}$  
Alt formula = $\frac{1}{N}[\displaystyle\sum{}x_i^2 - \frac{(\displaystyle\sum{}x_i)^2}{N}]$
- $x_i$ = each value from set
- $\mu$ = set mean
- N = population size
- 
- note
- may be easier to use alt formula when you do not have the mean or difference to mean for each val

Sample variance $s^2$ = $\frac{\displaystyle\sum{} (x_i - \bar{x})^2}{n - 1}$  
Alt formula = $\frac{1}{n-1}[\displaystyle\sum{}x_i^2 - \frac{(\displaystyle\sum{}x_i)^2}{n}]$
- $x_i$ = each value from set
- $\bar{x}$ = sample mean
- n = sample size
- is n-1 for precision
- 
- note
- may be easier to use alt formula when you do not have the mean or difference to mean for each val

standard deviation = $\sqrt{varience}$ = $\sqrt{\frac{\displaystyle\sum{} (x_i - \mu)^2}{N}}\ \ \ OR\ \ \ \sqrt{\frac{\displaystyle\sum{} (x_i - \bar{x})^2}{n - 1}}$  
- $x_i$ = each value from set
- $\mu$ = set mean
- n = set size

InterQuartile Range (IQR) = $Q3 - Q1$
- Q1 = median of lower quartile
- Q3 = median of upper quartile

coeffecient of variation = CV = $\frac{\sigma}{\mu} * 100\%$ OR $\frac{s}{\bar{x}} * 100\%$
- $\sigma$ = population standard deviation
- $\mu$ = mean
- $s$ = sample standard deviation
- $\bar{x}$ = sample mean

Proportion (Population)  $P_i = \frac{f_i}{N}$
Proportion (Sample)  $\hat{p_i} = \frac{f_i}{n}$

$f_i$ = frequency of specific category
N = $\displaystyle\sum{f_i}$ (All data)
n = size of sample


$Outlier < [Q1 - 1.5(IQR)]$
OR
$Outlier < [Q3 + 1.5(IQR)]$

### types of stats:  
Descriptive : 
- needs collecting, 
- Organizing, 
- Summarizing, 
- Presenting of Data, 
- only deal with outcome from sample data  
Inferential : 
- Making inferences,
- Hypothesis testing, 
- Making predictions, 
- Determining relationships, 
- given the outcome, infere for the popultion
Probability Theory: 
- Understanding the uncertainty of data, 
- given the population and sample size, predict the probability of an outcome

descriptive generally tells you the population size, or only describes the outcome

inferential generally does not say source or population size, may make assumptions of the population based on info from the outcome, may add on further ideas to the outcome or inferences from the outcome

these 2 stats will result in different presentation of the data
---e.g.---
280 randomly selected people in town  
210 have last name Nicolussi  
Descriptive: 220 (75%) of these 280 people have last name Nicolussi  
Inferential: 75$ of all people living in italy have the last name Nicolussi

on last 3 sundays, Henry sold 2,1,0 cars respectivly  
descriptive: Henry averaged 1 new car sold, per Sunday, for the last 3 Sundays  
inferential: Heney never sells more than 2 cars on a Sunday
\---------

### Stats can be misused

Ambiguity:  
Bank A: "Our interest rates are 1% lower"  
Ambiguity 1: lower than which bank?  
ambiguity 2: if Bank B = 2%, is Bank A 1% or 1.98%  

Misleading:  
President Trump's approval rating amoing Latinos going up to 50%  
National Polling results for only 153 Latino voters  
Mean Margin of error is +- 9.9%
all stats will have margin of error  


For accuracy, should collect census of whole population but impractical/immpossible (may miss people who have left which turns the census into a sample; or maybe take too long)  
so use sample, which is a smaller subset of population, which should be fair (in terms of reasonably similar distribution to the rest of the population and of a sufficent size to reflect overall trends in population) in order to infer for population

Parameter - a summary number describing **POPULATION**  
	$\mu$ / mu - mean  
    $\sigma^2$ / sigma squared - varience  
    $\sigma$ / sigma - standard deviation  
    $p$ - population

Statistic - a summary number for a **SAMPLE**  
    $\bar{x}$ / x bar - mean  
    $s^2$ / s squared - varience  
    $s$ / s - standard deviation  
    $\hat{p}$ / p hat - proportion / sample  

### Types of data
Qualitative data:
describe characteristic / quality of variable
scale of measurement is a set of catagories / split into various categories (even if they are numerical like zipcodes)  
there is no "larger" or "smaller" to these values  
e.g.  racial groups

Quantitative data:
numerical, differ in magnitude
can be used in calculations
scale for measurement has numerical values that represent different magnitudes of the variable  
"larger / greater than" and "smaller / less than" are relevant and important
e.g. height weight

types of quatitative data:  
Diesccrete (countable)  
Continuous (non-countable) (possible infinite precision and total if the precision of the measuring instrument was not a limiting factor)  

qualitative categorical data commonly presented as bar or pie chart

quantitative data can be identified as frequencey distribution as well, shown in histogram

large data set / quantitative continuous data, can use classes covering continnuous non-overlapping range of values to group data together

Crosstabulation shows relationship between 2 variables, either can be qualitative/quantitative data  


## Frequency analysis

to quantify qualitative/categorical data 

Tally total
Obtain frequency of each
calculate relative frequency

Use pie chart/bar chart to represent frequency

Collection of all categories and their corresponding relative frequencies = the relative frequency distribution of a variable

once calculate relative frequency can display in histogram of frequency on y axis and quantitative value on x axis marking the left and right boundary of the category

can change histogram from freq analysis to percentage on y axis and each category mean on x axis

for big ass set of quantitative continuous data, tend to group data into categories to be able to present more succinctly

recommend 5 - 14 classes on contiuous non-overlapping
### Formula

$P_i = \frac{f_i}{N}$
$\hat{p_i} = \frac{f_i}{n}$

$f_i$ = frequency of specific category
N = $\displaystyle\sum{f_i}$ (All data)
n = size of sample

## Bivarate Data

sometimes categories may have to be broad to make the histogram with contiguous data
will skew how histogram looks if using raw frequency on x axis

using density on y axis will give more accurate chart

Density = $\frac{Relative\ frequenccy}{Class\ Width}$

| Histogram (Density)                                                                  | Barchart                                                          |
| ------------------------------------------------------------------------------------ | ----------------------------------------------------------------- |
| Bars cannot be reorderd                                                              | Categorical                                                       |
| bars width represent bins/classes/intervals of values<br>can be of different lengths | bars widths is the same<br>Width no meaning                       |
| no gaps ( if have gap, value in that range is 0)                                     | May have gaps between bars for visual neatness<br>Gaps no meaning |
| used to see distributions                                                            | Height of archart is frequency                                    |
|                                                                                      | Barchart compares variables                                       |

## Cross Tabulation

To find relationship between 2 variables
Variables can be different types of data; qualitative or quantitative

Cross tabulation creates a contingency table

for quantitative data, create ranges and use the ranges in the contingency table
so the table wil have qualitative categories on one axis and  ranges on the other

rmbr add totals column/row for each axis

contingency table can be presented as clustered/stacked bar chart
clustered chart: easier to see distribution
stacked chart: easier to proportion

## Mean Mode Median / measures of concentration of data
Individual values used to express collecction of data
diffreent ways to measure concentration of data
by itself, insufficient to summarize whole dataset

Mean Average
Mode most common
Median middle most

for grouped data, given the mean for each range and the frequency of each range


if mean < median  &&  mean < mode : negatively skewed
mean = median = mode :  perfect normal distribution / not enuf data lol
if mean > median  &&  mean > mode : positively skewed

unimodal: only 1 value which is most frequent
bimodal: 2 values which is most frequent OR 2 distinct peaks in histogram
trimodal: 3 values which is most frequent OR 3 distinct peaks in histogram
quadmodal: 4 values which is most frequent OR 4 distinct peaks in histogram

## Outliers
outliers heavily influence the mean of a set
may cause misleading due to skewing of data

solutions:
1. remove outlier
2. use median instead

### Formula for proving outlier

$Outlier < [Q1 - 1.5(IQR)]$
OR
$Outlier < [Q3 + 1.5(IQR)]$

![[outlier.png]]

## Variance and standard deviation / measures of spread of data

- Range
	- Highest_val - lowest val
	- Susceptible to outliers, which may make range look very big
- Interquartile Range
	- upper_quartile Q3 - lower_quartile Q1
	- Middle quartile Q2= median
	- describes spread around the middle
	- we will use exclude method for the module
	- i.e.
	- 3,4,4,5,6,8,8
		- 5 is q2, exclude from sets to find q1 and q3
	- 1,3,4,4,5,6,6,7,8,8
		- q2 = (5+6)/2; 
		- 5 is part of q1 set
		- 6 is part of q3 set
- Varience
	- Average of the distances (squared deviations) from the mean
	- Bigger distinction than standard deviation between values further away from the mean cus squared
	- $\frac{\displaystyle\sum{} (x_i - \mu)^2}{N}\ \ \ OR\ \ \ \frac{\displaystyle\sum{} (x_i - \bar{x})^2}{n - 1}$
		- $x_i$ = each sample in set
		- $\mu$ = population mean
		- N = population size
		- $\bar{x}$ = sample mean
		- $n$ = sample size
- Standard Deviation
	- the difference between each data point from the mean
	- $\sqrt{\sigma^2}\ \ \ OR\ \ \ \sqrt{s^2}$

box plot:
- ![[box_plot_example.png]]

## Coefficient of Variance
measure of relative variability
ratio of standard deviation to mean
also called risk


# Chap 2: Probability theory

## Formula

Classical
 P(A) = $\frac{f}{N}$
- f = num outcomes of A
- N = total outcomes

Relative freq
P(A) = $\frac{f}{N}$
- f = number of times the outcome occurs
- N = total number of observations

Venn Diagram
0 < P(A) < 1
P(S) = 1
- S = sample space

Event A OR B
- P(A∪B) = P(A) + P(B) - P(A∩B)
Event A AND B
- P(A∩B) = P(A) * P(B)

Mutually Exclusive;
- P(A∩B) = 0
- P(A∪B) = P(A) + P(B)

Conditional Probability:
- P(A|B) = $\frac{P(A∩B)}{P(B)}$
- P(B|A) = $\frac{P(A∩B)}{P(A)}$
- P(A|B) $\neq$ P(B|A)
- P(A|B) $\neq$ P(A∩B)

Multiplicative Rules:
- From P(A|B) = $\frac{P(A∩B)}{P(B)}$; we have P(A∩B) = P(A|B)P(B)

Independent vs Mutually Exclusive
- Tree diagram helpful when time / order is involved

| When event are:    | P(A∪B) / P(A or B) =     | P(A∩B) / P(A and B) = | P(A\|B) =                   |
| ------------------ | ------------------------ | --------------------- | --------------------------- |
| Mutually Exclusive | P(A) + P(B)              | 0                     | 0                           |
| Independent        | P(A) + P(B) - P(A)P(B)   | P(A)P(B)              | P(A)                        |
| Any                | P(A) + P(B) - P(A and B) | P(A)P(B\|A)           | $\frac{P(A\ and\ B)}{P(B)}$ |

Exhaustive events:
- P(A∪B) = P(S) = 1

Law of total Probability
- Given a set of ***mutually exclusive and exhaustive events ($S_1...S_k$)**,*
- P(A) = P(A∩$S_1$) + P(A∩$S_2$) + ... + P(A∩$S_k$)
-  P(A) = P(A|$S_1$)P($S_1$) + P(A|$S_2$)P($S_2$) + ... + P(A|$S_k$)P($S_k$)
	- rewrite with multiplicative rule

Bayes theorem
- P(B|A) = $\frac{P(A|B)P(B)}{P(A|B)P(B) + P(A|B^`)P(B^`)}$
## How to interpret probability

Mathematical definition:
- a number between 0 and 1 (inclusive) that is assigned to a random outcome of uncertainties

Interpretations of probability;
- Classical (theoretical) probability
	- all random outcomes are equally likely to occur
	- can only use classical probability formula when all events equally likely
- Relative frequency (Empirical) probability

## Classical Probability

P(A) = Number of different outcomes in A / Total number f possible outcomes
- there may be more events after A so count all final states after event A
- P(A) = f/N
- f = num outcomes of A
- N = total outcomes

## Relative Frequency Probability
Collect data over time / use existing past data

P(A) = $\frac{f}{N}$
- f = number of times the outcome occurs
- N = total number of observations

Possible Concerns:
- how many times are considered a long run
- What if the outcome cannot be repeated
- What if no past data as is new situation

## Probability of events

note regardless of which interpretation you use, theory of probability applies to both

Sample Space (S)
- Set of all possible outcomes of a random phenomenon
- Is the box in Venn Diagram
Event (A)
- set of all outcomes we are interested in
- is circle/ellipse within sample space inn Venn Diagram

![[probability.png]]

0 < P(A) < 1
P(S) = 1

## Complementary

Probability event A does not happen = A\` = 1 - P(A)

## Multiple Events occur

Event A = P(A)
Event B = P(B)

Event A OR B  P(A∪B) = P(A) + P(B) - P(A∩B)
Minus for double count

Event A AND B = P(A∩B) = P(A) * P(B)


Mutually Exclusive;
- P(A∩B) = 0
- P(A∪B) = P(A) + P(B)

## Conditional Probability

### Formula
P(A|B) = $\frac{P(A∩B)}{P(B)}$
P(B|A) = $\frac{P(A∩B)}{P(A)}$

P(A|B) read as P(A) given B occurred

P(A|B) $\neq$ P(B|A)

P(A|B) $\neq$ P(A∩B)

Reason:
![[Conditional_probability.png]]

## Multiplicative Rules

From P(A|B) = $\frac{P(A∩B)}{P(B)}$
we have P(A∩B) = P(A|B)P(B)

P(A∩B) means B happened first then A, which is why we multiply the chance of B happening with the chance of A happening after B

## Independent vs Mutually exclusive 

Mutually Exclusive:
- Definition: Cannot happen simultaneously
- Dependency: Occurrence of one event results in the NON-occurrence of the other
- Probability of both events happening P(A∩B) = 0
- Venn Diagram: sets do not overlap
- Must be dependent because occurrence of one event affects the other 
Independent:
- Definition: occurrence and outcome of 1 event does not control occurrence or outcome of other event
- Dependency: Occurrence of one event has no influence on the occurrence of the other
- Probability of both events happening P(A∩B) = P(A) - P(B)
- Venn Diagram: sets overlap
- Cannot be mutually Exclusive as both events can happen together

| When event are:    | P(A or B) is:            | P(A and B) is | P(A\|B) is:                 |
| ------------------ | ------------------------ | ------------- | --------------------------- |
| Mutually Exclusive | P(A) + P(B)              | 0             | 0                           |
| Independent        | P(A) + P(B) - P(A)P(B)   | P(A)P(B)      | P(A)                        |
| Any                | P(A) + P(B) - P(A and B) | P(A)P(B\|A)   | $\frac{P(A\ and\ B)}{P(B)}$ |

If P(A|B) = P(A) and P(B|A) = P(B),
A and B are independent events

If A and B are independent, 
P(A∩B) = P(A)P(B)

Can extend to repeat of same event if Independent from itself
$P(A_1∩A_2∩A_3∩...∩A_n) = P(A_1)P(A_3)P(A_2)...P(A_n)$

Tree diagram helpful when time / order is involved
Write probability of individual event on each branch


## Bayes Theorem

exhaustive events: P(A∪B) = P(S) = 1
is any number of events covers all possible outcomes, the set of all participating events is considered exhaustive (the union of this set of events is exhaustive)

### Law of total probability

Given a set of ***mutually exclusive and exhaustive events ($S_1...S_k$)**,* probability of event A (P(A)) can now be expressed using the law of total probability

P(A) = P(A∩$S_1$) + P(A∩$S_2$) + ... + P(A∩$S_k$)

rewrite with multiplicative rule
P(A) = P(A|$S_1$)P($S_1$) + P(A|$S_2$)P($S_2$) + ... + P(A|$S_k$)P($S_k$)


### Back to Bayes-ics theorem
Using conditional probability equations, 
P(A|B) = $\frac{P(A∩B)}{P(B)}$
P(B|A) = $\frac{P(A∩B)}{P(A)}$
Bayes combines the 2 into P(B|A) = $\frac{P(A|B)P(B)}{P(A)}$

Which then he rewrite denominator using law of total probability,
set of mutually exclusive exhaustive events are B and B\`
P(B|A) = $\frac{P(A|B)P(B)}{P(A|B)P(B) + P(A|B^`)P(B^`)}$

Bayes theorem useful when data given only has 1 specific event first as well as the probability of that event e.g. always A first then B, P(A) given


# Chap 3

### Formula

discrete (P(X = x))
continuous P($x_1\leq X\leq x_2$)

mean of discrete data variable = $\frac{ \displaystyle\sum_{} x_if_i } {n} = x_i \frac{ \displaystyle\sum_{} f_i } {n}$

mean of discrete random variable / Expected Value E(X) = $\mu$ = $\displaystyle\sum{}xP(X=x)$

Variance of discrete random variable:
Var(X) = $\sigma^2 = \displaystyle\sum{} (x - \mu)^2P(X=x)$
Std dev:
$\sigma = \sqrt{\sigma^2}$

Representation of binomial random variable X
X ~ B(n,p)
- n = number of trails
- p = probability of success 

Probability of specific outcome
P(X=x) = $\binom{n}{x}p^x(1-p)^{n-x}$
- x = num of successes
- $\binom{n}{x}$ = total num combinations
	- n = total num of trials outcomes (e.g. total students)
	- x = num successes (num students you want to pass / fail)
		- e.g. if goal is to fail all, x = total num students
	- $\binom{n}{x} = \frac{n!}{(n-x!)x!}$
- p = probability of success outcome

Binomial Mean
$E(X) = np$

Binomial Variance
$VAR(X) = np(1-p)$

### Variables
Normal variable
- represent quantity
- no assumptions about value

Random variable:
- Denoted with capitol letter
- Possible values are numerical outcomes of a random phenomenon
- value follows probability distribution
- subject to some randomness / chance
- can be discrete (P(X = x))
	- must be one of countable list of distinct values
	- can find probabilities for exact outcomes
	- should be make sense
		- whole values for things like birth year, number of babies bron this year
- continuous P($x_1\leq X\leq x_2$)
	- can take any value in an interval / collection of intervals
	- limited to finding probability for intervals of values

### Probability Distribution

if probability has discrete outcomes, use barchart / graph / formula
if probability is continuous values, use distribution

### Probability distribution vs frequency distribution

|                                  | Frequency                                                                                                                            | Probability                                                           |
| -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------- |
| sum of all values                | 1                                                                                                                                    | 1                                                                     |
| probability / relative frequency | $0\leq\frac{f_i}{n}\leq1$                                                                                                            | $0\leq P(X=x)\leq1$                                                   |
| source                           | empirical data                                                                                                                       | expected probability                                                  |
| mean                             | mean of discrete data variable<br>$\frac{ \displaystyle\sum_{} x_if_i } {n} = x_i \frac{ \displaystyle\sum_{} f_i } {n}$<br><br><br> | mean or expected value<br>E(X) = $\mu$ = $\displaystyle\sum{}xP(X=x)$ |

### Law of large numbers

Expected value of practical importance sine as number of trials increase, mean will converge on expected value

expected value is mean of infinite trials, idealized
mean is from empirical data

### Variance and Standard Deviation of Discrete random variables

Var(X) = $\sigma^2 = \displaystyle\sum{} (x - \mu)^2P(X=x)$

$\sigma = \sqrt{\sigma^2}$

### Binomial Random Variable
Special Class of Random variable

must exhibit
- 1 of 2 discrete outcomes categorized as success//failure / binary outcome
- probability of success/failure is fixed over all trials
- fixed and finite number of independent and identical trials

### Binomial Distribution

Probability of binomial random variable X
- X ~ B(n,p)
	- n = number of trails
	- p = probability of success 
Formula
P(X=x) = $\binom{n}{x}p^x(1-p)^{n-x}$
- x = num of successes
- $\binom{n}{x}$ = total num combinations
	- n = total num of trials outcomes
	- x = num successes
- p = probability of success outcome

$\binom{n}{x} = \frac{n!}{(n-x!)x!}$


Mean
$E(X) = np$

Variance
$VAR(X) = np(1-p)$

# Chap 4

## Formula

P($L_b \leq x \leq U_b) = \frac{U_b-L_b}{U_l}$
- $L_b$ - lower bound
- $U_b$ - Upper bound
- $U_l$ - Upper Limit of Continuous space

|                    | Continuous random variable                                                          |
| ------------------ | ----------------------------------------------------------------------------------- |
| mean               | E(X) = <br>$\mu =$<br>$\int_{-∞}^∞ f(x)dx$                                          |
| Variance           | Var(X) = <br>$\sigma^2 =$<br>$\int_{-∞}^∞ (x-\mu)^2 \int (x)dx$                     |
| Alternate Variance | Var(X) = <br>$\sigma^2 =$<br>$E(X^2)-\mu^2$<br>Where $E(X^2) = \int_{-∞}^∞ x^2f(x)$ |

Z = $\frac{x-\mu}{\sigma}$
$\mu = np$
$\sigma^2 = np(1-p)$

approximation
X~B(n,p) -> Y~N(np,np(1-p))

## Continuous spaces
For all intervals of \[a,b] (when all possibilities are equally likely):
- $\frac{|b-a|}{U_l}$
- $a$ - lower bound
- $b$ - Upper bound
- $U_l$ - Upper Limit of Continuous space

When drawing a graph for continuous spaces
- x axis - interval like angle (0-360)
- y-axis / F(x) - 1/upper limit of whole interval
- area under the graph aka density - probability of continuous random variable

e.g.
Angles between 2 lines in a circle
Angle is continuous value, can have as many decimal places as you want
but if you ask for P($0 \leq x \leq 180$), then probability can be found

## Density

F(x) is the density function of the space
in a circle, F(x) = $\frac{1}{360}$

For any interval where ($a \leq x \leq b$) the probability is the area under the curve

Probability = (b-a) \* height

e.g.
(b-a) \* height = (b-a) \*  $\frac{1}{360}$ =  $\frac{(b-a)}{360}$

## Probability Density Function
Describes continuous random variables

Definition::
the probability density function of a continuous random variable $X$ is a function $f(x)$ such that the area under the curve over an interval equals the probability of $X$ in that interval.

$f(x) \geq 0$:
$P(c \leq x \leq d) = \int_c^d f(x)dx$

Since infinitely many values / outcomes, probability of a particular outcome to occur is negligible
$P(X=x) = \int_c^d f(x)dx = 0$

So can only find probability for intervals
$P(a < X < b) = P(a \leq X < b) = P(a < X \leq b) = P(a \leq X \leq b) = \int_a^b f(x)dx$
less than or less than equals doesnt matter as including that specific value does not matter due to nature of continuous space

Requirements of density functions:
- $f(x) \geq 0$
- area under the curve = $\int_{-∞}^∞ f(x) = 1$

## Types of Distribution

### Uniform Distribution

Contiguous Uniform Distribution / Rectangle distribution
has symmetric probability distributions
all intervals of the same length on the x-axis are equally probable

### Normal Distribution
Normal Random Variable / Normal distribution
very useful to model random phenomenon in real world

Definition:
normal distribution X, written as X ~ N($\mu, \sigma^2$), is a continuous random variable having the classic bell-shaped probability density function

$f(x) \geq 0$:
$P(c \leq x \leq d) = \int_c^d f(x)dx$
True function: $f(x) = (\frac{1}{\sigma \sqrt{2\pi}^e})^{-0.5(\frac{x-\mu}{\sigma})^2}$;  for -∞ < x < ∞
standard normal: $f(x) = (\frac{1}{\sqrt{2\pi}^e})^{-0.5(x)^2}$;  for -∞ < x < ∞

![[normal_dist_to_std_dist.png]]

## Z-table

still difficult to calculate in standard normal
can rely on Z-table for pre-computed probability
has probability P($Z \leq z$)

1.36 = 1.3 then .06

1.345 = 1.3 diff between .04 and .05

what about P(Z > 1.11)?
Complement P($Z \leq z$)

Since symmetric about the mean
![[symmetric_about_mean.png]]
P($Z \geq z$) = 1 - P($Z < z$)
P($Z \geq -z$) = P($Z \leq z$)
P($Z \leq -z$) = 1 - P($Z \leq z$)
P($-z \leq Z \leq z$) = P($Z \leq z$) - P($Z \leq -z$)

Can also find Z given probability
P(Z < z) = 0.95
means z = 1.645


# Chap 5

## Approximate Binomial Distribtion

Given X ~ B(n,p) with n so large such that np >5 and n(1-p) > 5
can use X ~ N($\mu, \sigma^2$) where $\mu$ = np, $\sigma^2$ = np(1-p)

| Inequality type | Correction             |
| --------------- | ---------------------- |
| P(X = a)        | P($a-0.5 < X < a+0.5$) |
| P(X > a)        | P(X > a + 0.5)         |
| P(X $\leq$ a)   | P(X < a + 0.5)         |
| P(X < a)        | P(X < a - 0.5)         |
| P(X $\geq$ a)   | P(X > a - 0.5)         |
Continuity Correction

## Combining Random Variables

Add mean is add means of both
diff mean is subtract both
E(X+Y) = E(X) + E(Y)
E(X-Y) = E(X) - E(Y)

Add variance is add variance of both
diff variance is still add both lol
Var(X+Y) = Var(X) + Var(Y)
Var(X-Y) = Var(X) + Var(Y)


Given discrete / continuous random variables X, Y as well as constants a, b
$E(aX \pm b) = aE(X) \pm b$
$Var(aX \pm b) = a^2Var(X)$

the following are true if X and Y are independent
$E(aX \pm bY) = aE(X) \pm bE(Y)$
$Var(aX \pm bY) = a^2Var(X) \pm b^2Var(Y)$

if X and Y are normal distribution, $aX \pm bY$ is also normal
if X and Y are binomial distribution, $aX \pm bY$ is also binomial, only if they have the same success probability p

## Statistical Studies
Inferential Statistics is to obtain sample statistics to make inferences about population parameters in order to answer our questions.
calculate $\bar{x}$, infer $\mu$

steps:
1. Curiosity about something
2. Questions about a parameter (variable)
	- What are statistical qns
	- a qn that you can collect data with variability
		- Variability: the degree to which data points vary
1. Collect data appropriate for that parameter
2. Make inferences about that value of the parameter