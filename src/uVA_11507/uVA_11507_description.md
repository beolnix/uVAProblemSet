
# Problem
uVA_11507: Bender B. Rodríguez Problem
[link to the problem page](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2502)

Bender is a robot built by Mom’s Friendly Robot Company at its plant in Tijuana, Mexico in 2996. He is a Bending-Unit 22, serial number 2716057 and chassis number 1729. He was created for the task of bending metal wires.
Bender needs to bend a wire of length `L` (`L ≥ 2` an integer). The wire is represented in the Bender’s brain (a MOS Technology 6502 microprocessor) as a line stucked in the origin of a tridimensional cartesian coordinate system, and extended along the x positive axis (`+x`), so that the  xed extreme of the wire is in the coordinate `(0, 0, 0)` and the free extreme of the wire is in the coordinate `(L, 0, 0)`.
Bender bends the wire at speci c points, starting at the point `(L − 1, 0, 0)` and ending at the point `(1, 0, 0)`. For each `i` from `L − 1` to `1`, Bender can take one of the following decisions:
* Not to bend the wire at point `(i, 0, 0)`.
* To bend the wire at point `(i,0,0)` an angle of `π` to be parallel to the `axis+y`,`-y`,`+zor-z`.

## Input
The  rst line of each test case gives an integer `L` (`2 ≤ L ≤ 100000`) indicating the length of the wire. The second line of each test case contains the `L − 1` decisions taken by Bender at each point, separated by spaces. The j-th decision in the list (for each `1 ≤ j ≤ L − 1`) corresponds to the decision
taken at the point `(L − j, 0, 0)`, and must be one of the following:
* `No` if the wire isn’t bended at point `(L − j, 0, 0)`.
* `+y` if the wire is bended at point `(L−j,0,0)` on the `+y` axis. 
* `-y` if the wire is bended at point `(L−j,0,0)` on the `-y` axis. 
* `+z` if the wire is bended at point `(L−j,0,0)` on the `+z` axis.
* `-z` if the wire is bended at point `(L−j,0,0)` on the `-z` axis.

The end of the input is indicated when `L = 0`.

## Output
For each case in the input, print one line with the direction pointed by the last segment of the wire, `+x`, `-x`, `+y`, `-y`, `+z` or `-z` depending on the case.

## Sample Input
```
3
+z -z
3
+z +y
2
+z
4
+z +y +z
5
No +z No No
0
```

## Sample Output
```
+x
+z
+z
-x
+z
```
