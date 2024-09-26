# Hotel Problem

## The game
You are the host of a hotel with `n` rooms numbered from 1 to `n`. In your hotel there is one guest who hasn't payed. Each night you start by checking one of the rooms and if the guest is there you win. Then if you didn't fint the guest they will move one room to the right (room `k -> k+1`) or one room to the left (room `k -> k-1`). Your goal is to as quickly as possible find the guest.

## The Problem
What is the minimum number of rooms you have to check until you are guaranteed  to have found the guest?

## Time complexity
A naive analysis of `hotel_brute.cpp` will give a time complexity of `O(n^2 * 2^n)`, although I conjecture that the time complexity is closer to `O(n^2 * nlgn)` because some states are unreachable.

For `hotel_test.cpp` you can easily show that it will have a time complexity of `O(n^3)`.

# `hotel_brute.cpp`

## Purpose
The purpose of this program is to calculate the minimum number of moves required to find the guest. This program can also describe a set of moves to do this, this is implemented with backtracking.

## Algorithm
The algorithm starts with a boolean array with all true values representing whether or not the guest could be in that room. We then explore each possible move that the host could make, if the host finds the guest we would be done so we assume that they didn't find the guest. Then we mark the room as false because we now know that the guest wasn't in that room, for the transition when our guest switches room we accomplish this by doing saying that
```cpp
new_arr[i] = old_arr[i - 1] | old_arr[i + 1]
```
To make this go fast we search trough the states such that we update the states that took the fewest moves to get to first this ensures that we get the correct answer and don't have to recalculate any states.

# `hotel_test.cpp`

## Purpose
The purpose of this algorithm is to check whether or not a set of moves will return a state consisting of only false values meaning we found the guest, we used this to check that our solution worked and that we hadn't missed any edgecases.
