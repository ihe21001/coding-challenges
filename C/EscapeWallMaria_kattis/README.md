# Escape Wall Maria: A Pathfinding Challenge
## Overview
In this challenge, the fictional city of Wall Maria is under threat, and the protagonist, Eren, needs to find the quickest escape route before danger arrives. The city is modeled as an N*M grid where movement is possible both horizontally and vertically.

## Grid Representation
### Impassable Zones: 
Some areas in Wall Maria are blocked due to burning houses and buildings, making them impassable. These are represented on the grid as ‘1’.
### Safe Zones: 
Areas that are unburned and safe to traverse are marked as ‘0’.
### Direction-Specific Zones: 
Certain zones in Wall Maria can only be accessed from a specific direction. These zones are marked as ‘U’, ‘D’, ‘L’, or ‘R’, indicating the permitted direction of entry (Up, Down, Left, or Right respectively).
## Time Constraint
Eren is aware of the exact time, t, when danger will strike. He must reach the border of Wall Maria before this time. It takes one unit of time to move through one grid zone.

## Starting Position and Objective
### Starting Point: 
Eren's starting location is indicated on the grid by the letter ‘S’.
### Escape Goal: 
The objective is to determine if it is possible for Eren to escape before time t. If escape is feasible, the algorithm should calculate the minimum number of zones Eren must traverse to safely exit Wall Maria.
## Challenge
Given Eren's starting position and the grid layout of Wall Maria, your task is to create a solution that calculates the quickest possible escape route within the given time constraints.

## Input
The input consists of a single test case. The first line contains three integers t (1<= t <= 200), N (1 <= B <= 100) and M (1 <= M <= 100). The rest of N lines will be Wall Maria’s grid containing characters ‘1‘, ‘0‘, ‘S‘, ‘U‘, ‘D‘, ‘L‘, or ‘R‘. There is exactly one ‘S‘ in the input.

## Output
If it is possible to escape Wall Maria, output the minimum number of zones that must be traversed to escape. If it is not possible to escape, print “NOT POSSIBLE”!

## Example
### Sample Input 1:
```yaml
2 4 4
1111
1S01
1011
0U11
```

### Sample Output 1:
```yaml
2
```


### Sample Input 2:
```yaml
2 4 4
1111
1S01
1011
0L11
```

### Sample Output 2:
```yaml
NOT POSSIBLE
```


### Sample Input 3:
```yaml
1 4 4
1S01
1001
1011
0U11
```

### Sample Output 3:
```yaml
0
```





