# Guessing Game Analysis: Detecting Cheating

## Overview
Analyze transcripts of a guessing game to determine if there's evidence of cheating. In the game, Stan thinks of a number (1-10), and Ollie guesses it. Stan's responses indicate if the guess is too high, low, or correct.

## Objective
- **Input**: Transcripts of the game, including guesses and responses.
- **Task**: Determine whether Stan's responses are consistent, or if they indicate cheating.

## Input Format
- Each transcript in the standard input consists of a series of paired guesses and responses.
- A guess is a single integer line between 1 and 10 (inclusive).
- A response is a line stating “too high”, “too low”, or “right on”.
- Each game concludes with the response “right on”.
- The end of all transcripts is marked by a line containing 0.
- There are at most 2500 guess-response pairs in total.

## Output Format
- For each game, output “Stan is dishonest” if the responses are inconsistent with the final guess.
- If the responses are consistent, output “Stan may be honest”.

## Example
### Sample Input 1:
```yaml
10
too high
3
too low
4
too high
2
right on
5
too low
7
too high
6
right on
0
```

### Sample Output 1:
```yaml
Stan is dishonest
Stan may be honest
```
