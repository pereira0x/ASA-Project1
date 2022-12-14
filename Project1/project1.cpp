/**
 * @file project1.cpp
 * @author Simão Sanguinho - ist1102082, José Pereira - ist1103252
 * @group al023
 * @date 2022-12-13
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

/* hashmap to store the results of the recursive calls (memoization) */
unordered_map<long, long> combinations;

/* convert a vector to a long (example: <1,2,3,4> = 1234) */
long arrayToLong(short cValues[], short nLines) {
  long result = 0;
  for (short i = 0; i < nLines; i++)
    result = result * 10 + cValues[i];
  return result;
}

/* removes "bumps" from the stair line */
void clean(short cValues[], short nLines) {
  for (short i = 0; i < nLines - 2; i++)
    if (cValues[i] < cValues[i + 1] && cValues[i + 1] > cValues[i + 2])
      cValues[i + 1]--;
}

/* find the biggest c value and it's index */
pair<short, short> getLongestLine(short cValues[], short nLines) {
  short maxValue = *max_element(cValues, cValues + nLines);
  short maxIndex = distance(cValues, max_element(cValues, cValues + nLines));
  return {maxValue, maxIndex};
}

/* update the c values after removing a tile */
void updateCValues(short cValues[], short nLines, short currLine,
                   short tileSize) {
  for (short i = 0; i < tileSize; i++)
    cValues[currLine + i] -= tileSize;
}

/* returns the number of combinations to fill the area limited by cValues */
long findCombinations(short cValues[], short nLines, short nColumns) {
  /* clean the cValues to prevent any unnecessary calculations */
  clean(cValues, nLines);

  /* get the current position to start removing tiles */
  pair<short, short> currents = getLongestLine(cValues, nLines);
  short currColumn = currents.first;
  short currLine = currents.second;

  /* convert the cValues to a long to use as a key in the hashmap */
  long longArray = arrayToLong(cValues, nLines);

  /* stop condition - if the cValue is already in the hashmap */
  if (combinations.find(longArray) != combinations.end())
    return combinations[longArray];

  /* stop condition - if the biggest cValue is 1 */
  if (currColumn <= 1)
    return 1;

  /* remove the different tiles available */
  long sum = 0;
  short newCValues[nLines];
  for (short tilesize = 1;
       tilesize <= currColumn && tilesize <= nLines - currLine &&
       cValues[currLine + tilesize - 1] >= currColumn;
       tilesize++) {
    /* copy cValues to a new array so it doesn't get modified */
    for (short i = 0; i < nLines; i++)
      newCValues[i] = cValues[i];

    /* update the cValues after removing a tile */
    updateCValues(newCValues, nLines, currLine, tilesize);

    /* recursive call */
    sum += findCombinations(newCValues, nLines, nColumns);
  }
  /* save the result in the hashmap */
  return combinations[longArray] = sum;
}

int main() {
  /* board size limits */
  short nLines, nColumns, c;
  scanf("%hi %hi", &nLines, &nColumns);

  /* read the stair line (represented by c values) limiting the area to fill */
  short cValues[nLines];
  bool allZero = true;
  for (int i = 0; i < nLines; ++i) {
    scanf("%hi", &c);
    if (c != 0)
      allZero = false;
    cValues[i] = c;
  }

  long res = 0;
  /* if all c values are 0, there is no solution */
  res = allZero ? 0 : findCombinations(cValues, nLines, nColumns);
  printf("%ld\n", res);

  return 0;
}