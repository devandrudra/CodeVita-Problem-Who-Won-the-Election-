# Voting Simulation (TCS CodeVita Proble)

This project simulates a voting system where two parties, A and B, try to influence neutral supporters represented by '-'.
Each neutral supporter votes for the closest party supporter. If both are equidistant, the supporter remains neutral.

# Problem Statement

You are given a string q consisting of characters:

'A' → supporter of Party A

'B' → supporter of Party B

'-' → neutral supporter

## Rules for neutral voters:

A neutral voter chooses the nearest party supporter (A or B).

If the distances are equal, the neutral voter stays neutral.

After processing all neutrals, count total votes for A and B.

Final Output:

"A" if A has more votes

"B" if B has more votes

"Coalition" if both have equal votes

### Example
Input:
A--B-A-B--

Process:

Neutral at index 1 → closer to A

Neutral at index 2 → closer to A

Neutral at index 9 → closer to B

Final Votes:
A votes = 3
B votes = 3
Result = Coalition

# Approach
## 1. Brute Force Approach

For each neutral supporter, expand left and right until finding the nearest A or B.

Compare distances and assign the vote accordingly.

Time Complexity: O(n²)

## 2. Optimised Approach

Precompute two arrays:

distA[i] = distance of index i from nearest A

distB[i] = distance of index i from nearest B

Traverse string once to assign votes efficiently.

Time Complexity: O(n)