# Odd Man Out Challenge

## Overview
In this challenge, you're hosting a party with an odd number of guests. Each couple was given a unique invitation number. Your task is to find out which guest is attending alone by examining the invitation numbers.

## Input Format
- The first line contains the number of cases, \( N \).
- Each test case has two lines:
  - The first line contains \( G \), the number of guests.
  - The second line contains a space-separated list of \( G \) integers, representing the invitation codes of the guests.
- Constraints:
  - \( 1 <= N <= 50 \)
  - \( 0 < C < 2^{31} \)
  - \( 3 <= G < 1000 \)

## Output Format
- For each test case, output a line in the format: “Case #x: C”, where \( C \) is the invitation code of the guest who is alone.

## Example
### Sample Output 1:
```yaml
3
3
1 2147483647 2147483647
5
3 4 7 4 3
5
2 10 2 10 5
```

### Sample Output 2:
```yaml
Case #1: 1
Case #2: 7
Case #3: 5
```
