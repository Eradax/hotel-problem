# Hotel Problem

## The game
You are the host of a hotel with `n` rooms numbered from 1 to `n`. In your hotel there is one guest who hasn't payed. Each night you start by checking one of the rooms and if the guest is there you win. Then if you didn't fint the guest they will move one room to the right (room `k -> k+1`) or one room to the left (room `k -> k-1`). Your goal is to as quickly as possible find the guest.

## The Problem
What is the minimum number of rooms you have to check until you are guaranteed  to have found the guest?

## Time complexity
A naive analysis of `hotel_brute.cpp` will give a time complexity of `O(n^2 * 2^n)`, although I conjecture that the time complexity is closer to `O(n^2 * nlgn)` because some states are unreachable.

For `hotel_test.cpp` you can easily show that it will have a time complexity of `O(n^3)`.
