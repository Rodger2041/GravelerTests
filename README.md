# GravelerTests
Implemented code for simulation of rolling 4 sided dice.

https://www.youtube.com/watch?v=M8C8dHQE2Ro

## Use of Pseudorandom number

For generating pseudorandom numbers, I calculated each prime between 1e8 and 1e9 and stored it in an array, then with the use of a random seed and two randomly chosen primes, I generated an index.
The index will be the position of the first prime we will be using. Initial value of our random number is 0.
Each iteration, the random number will be updated as follows:

$number=(number \cdot prime)\cdot prime$

So the first few iterations will be as follows:

$prime_1^2$

$(prime_1^2+prime_2)\cdot prime_2$

$((prime_1^2+prime_2)\cdot prime_2)+prime_3)\cdot prime_3$

As these numbers are too big, they will be stored modulus $m_1=1e9+7$ (prime).

Which primes are chosen in which iteration will be decided by the 'index' variable which itself it updated based on the random seed and the previous prime as well the the epoch number.

### Actual Generation

We will take the random number val, which will be a number less than $m_1$ and update it.

$val=(val+prime_i)\cdot prime_i$

This number will then be converted into base 4 and all its bits except the MSB (since the MSB cannot be 0) will be used. This will give us around 20 random vlues between 0-3 per update.

Then we will make this value less than $m_1$ again by taking remainder with $m_1$.

This pseudorandom number will generate numbers faster than inbuilt libraries, and it is random enough for our case. The maths behind the generation is inspired by that of hashing and modular arithmetic.

## The other code

The simulation run by the original code does not represent the actual situation in game. The value of 99 achieved by the original video (and 101) by me is NOT

Graveler getting paralysed X times before exploding.

BUT

Graveler getting paralysed X times in 231 Turns.

Which is wrong because that is assuming you can move 231-X times without exploding. That is 132 turns, but that is obviously not the case. Graveler can only fend off paralysis for 54 turns, and so that is our limit.

## Conclusion

So what does that mean?

Basically, the actual expected answer of the experiment is LESS than 99 because of the reason stated above. We need to count the paralysis turns before 54 non-paralysis turns occur. I will update this readme when I successfully run the correct simulation to get the actual answer.
