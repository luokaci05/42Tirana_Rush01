# Rush-01: Skyscraper Puzzle Solver

Solves 4x4 skyscraper puzzles using backtracking.

## Compilation

```bash
cc -Wall -Wextra -Werror *.c -o rush-01
```

## Usage

```bash
./rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down rowleft1 rowleft2 rowleft3 rowleft4 rowright1 rowright2 rowright3 rowright4"
```

Provide 16 clues (1-4) as a single quoted string with spaces.

## Example

```bash
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Output:
```
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

## Rules

- Each row/column contains 1, 2, 3, 4 exactly once
- Clues indicate visible buildings from that direction
- Taller buildings hide shorter ones
