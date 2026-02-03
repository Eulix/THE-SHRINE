
# Q1

uniform dist
min 0
max 10

$\frac {7-5}{10} = \frac{1}{5}$


# Q2
a)
X ~ N(100,256 )
P(X>140) = 1-P(X<=140)
Z = $\frac{140-100}{16}$ = 2.5
P(Z) = 0.9938
P(X>140) = 1-0.9983 = 0.0017

b)
P(X < 88) = P(Z < $\frac{88-100}{16}$) = P(Z < -0.75) =  1- P(Z <= 0.75) = 1-0.7734 = 0.2266


c)

P($72 \leq x \leq 128$) = P($x\leq128$) - P($x\leq72$)
P($x\leq128$) - P($x\leq72$) = P($Z\leq \frac{128-100}{16}$) - \[1-P($z\leq \frac{|72-100|}{16}$)] = P($Z\leq 1.75$) - \[1-P($z\leq 1.75$)] 
P($Z\leq 1.75$) - \[1-P($z\leq 1.75$)]  = 0.9599 - (1-0.9599) = 0.9198

# Q3
a)
binomial distribution
outcomes: know of product, dk of product


b)
X ~ B(1000,0.2)
np = 200
n(1-p) = 800
np(1-p) = 160

c)
since np > 5 and n(1-p) > 5, use approx normal
X~N(200,160)

P($x\leq156$) = P($x<156.5$) \[binomial correction]
P($z\leq \frac{156-200}{\sqrt{160}}$) = 1- P($z\leq 3.44$)  = 0.0003
# Q4
X~N(134,16)

a)
P($x<150$) = P($z\leq \frac{150-134}{16}$) = 0.8413

b)

find upper 10%
find z value for lower 90% = 1.28
(1.28 \*16)+134 = 154.48

c)
P(Y<170) = 0.14 = 1- P($z \leq \frac{|170-\mu|}{\sigma}$)
z = -1.08
$\mu = (-1.08\sigma)+170$
$\sigma = \frac{170-\mu}{-1.08}$

P(Y>200) = 0.03 = 1 - P($z \leq -\frac{200-\mu}{\sigma}$)
z = 1.88
$\mu = (1.88\sigma)+200$
$\sigma = \frac{200-\mu}{1.88}$

$(-1.08\sigma)+170 = (1.88\sigma)+200$


$\sigma = \frac{170-\mu}{-1.08} = \frac{200-\mu}{1.88}$
# Q5
Binomial



# Q6
P(A = 0) = 0.8
P(A = 1) = 0.2
P(A > 1) - 0

P($500|A = 1) = 0.5
P($5000|A = 1) = 0.4
P($15000|A = 1) = 0.1


| x     | P(X=x) |
| ----- | ------ |
| 0     |        |
| 500   |        |
| 5000  |        |
| 15000 |        |


a)
E(x) = 500\*0.2\*0.5 + 5000\*0.2\*0.4 + 15000\*0.2\*0.1 = 750


b)
var = $5962500
std dev = $2442

c)
CV = $\frac{\sigma}{\mu}$
100 car owners buy insurance = 100\*E(x) and 100\*Var(x)

ans = 0.326

risk of one policy = $\frac{2442}{750}100\%$ = 325.5%
risk of 100 policy = 30.56%
which is higher