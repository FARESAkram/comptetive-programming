
# Polycarpus Loves Hamburgers

## Problem Overview

Polycarpus loves making hamburgers and wants to know how many hamburgers he can cook given the following:

1. **Ingredients**: Bread (`B`), Sausage (`S`), and Cheese (`C`).
2. **Recipe**: A string describing the order of ingredients from bottom to top. For example, "BSCBS" means the hamburger has bread, sausage, cheese, bread, and sausage.
3. **Kitchen Stock**: He has a limited number of bread, sausage, and cheese in his kitchen.
4. **Shop**: There is an unlimited supply of these ingredients in the shop, each with a specific price.
5. **Money**: He has a certain number of rubles and is willing to buy more ingredients if necessary.

The task is to compute the maximum number of hamburgers Polycarpus can make using his current stock and available rubles.

## Input

1. **Recipe String**: A string that represents the hamburger recipe. It contains only the letters 'B' (Bread), 'S' (Sausage), and 'C' (Cheese).
2. **Stock**: The number of bread, sausage, and cheese currently available in the kitchen.
3. **Prices**: The prices of bread, sausage, and cheese in the shop.
4. **Rubles**: The amount of money Polycarpus has to buy additional ingredients.

### Example Input

```
BSCBS
4 3 2
3 2 5
100
```

This input means:
- Recipe: Bread, Sausage, Cheese, Bread, Sausage.
- Kitchen has 4 pieces of bread, 3 pieces of sausage, and 2 pieces of cheese.
- Shop prices are: Bread = 3 rubles, Sausage = 2 rubles, Cheese = 5 rubles.
- Polycarpus has 100 rubles to spend.

## Output

The program should output the maximum number of hamburgers Polycarpus can make.

### Example Output

```
4
```

## Solution Outline

1. **Parse the Recipe**: First, we count how many units of bread, sausage, and cheese are required to make one hamburger.
2. **Make Hamburgers with Kitchen Stock**: We try to make as many hamburgers as possible using the ingredients Polycarpus already has in his kitchen.
3. **Use Rubles to Buy More Ingredients**: After the kitchen ingredients run out, we calculate how many more hamburgers can be made by buying additional ingredients with the available rubles.
4. **Calculate Maximum Hamburgers**: We maximize the number of hamburgers by buying the necessary ingredients until Polycarpus runs out of rubles.

## Key Steps

1. **Recipe Parsing**: For each character in the recipe string, count how many pieces of bread (`B`), sausage (`S`), and cheese (`C`) are needed to make one hamburger.

2. **Greedy Hamburger Making**: First, make as many hamburgers as possible using only the ingredients from the kitchen.

3. **Buying Ingredients**: Once the kitchen runs out of ingredients, calculate how much of each ingredient is missing, buy them from the shop, and subtract the cost from the available rubles.

4. **Remaining Rubles**: After buying the missing ingredients, if there are still rubles left, calculate how many more hamburgers Polycarpus can afford.

## Code Explanation

Here is a breakdown of the key sections of the code:

- **Input Parsing**: The recipe string is read first, followed by the kitchen stock, shop prices, and the available rubles.
  
- **Count Recipe Needs**: We count the number of bread (`B`), sausage (`S`), and cheese (`C`) pieces needed to make one hamburger.
  
- **Hamburger Making Loop**: First, make as many hamburgers as possible with the available stock, then check if more ingredients need to be purchased. Rubles are spent on ingredients until no more hamburgers can be made.
  
- **Final Calculation**: Once the kitchen and rubles are exhausted, compute the maximum number of hamburgers Polycarpus can make.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

bool getCondition(ull* kitchen, ull* burgerNeeds) {
    bool needBurger[3];
    for (int i = 0 ; i < 3 ; i++) {
        needBurger[i] = burgerNeeds[i] > 0 && kitchen[i] > 0;
    }
    return needBurger[0] || needBurger[1] || needBurger[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int burger = 0, sausage = 1, cheese = 2;
    string burgerStructure;
    cin >> burgerStructure;

    ull kitchen[3], storePrice[3], burgerNeeds[3] = {0, 0, 0}, money;
    ull burgersMade = 0;

    for (int i = 0 ; i < 3; i++) {
        cin >> kitchen[i];
    }
    for (int i = 0 ; i < 3; i++) {
        cin >> storePrice[i];
    }
    cin >> money;

    for (char burgerPart : burgerStructure) {
        if (burgerPart == 'B') burgerNeeds[burger]++;
        if (burgerPart == 'S') burgerNeeds[sausage]++;
        if (burgerPart == 'C') burgerNeeds[cheese]++;
    }

    while (kitchen[burger] >= burgerNeeds[burger] && kitchen[sausage] >= burgerNeeds[sausage] && kitchen[cheese] >= burgerNeeds[cheese]) {
        kitchen[burger] -= burgerNeeds[burger];
        kitchen[sausage] -= burgerNeeds[sausage];
        kitchen[cheese] -= burgerNeeds[cheese];
        burgersMade++;
    }

    while (getCondition(kitchen, burgerNeeds)) {
        int needsToBuy[3], i;
        for (i = 0 ; i < 3; i++) {
            needsToBuy[i] = burgerNeeds[i] - kitchen[i];
            if (needsToBuy[i] > 0) {
                ull moneyToSpend = needsToBuy[i] * storePrice[i];
                if (money < moneyToSpend) break;
                money -= moneyToSpend;
                kitchen[i] = burgerNeeds[i];
            }
        }
        if (i != 3) break;
        while (kitchen[burger] >= burgerNeeds[burger] && kitchen[sausage] >= burgerNeeds[sausage] && kitchen[cheese] >= burgerNeeds[cheese]) {
            kitchen[burger] -= burgerNeeds[burger];
            kitchen[sausage] -= burgerNeeds[sausage];
            kitchen[cheese] -= burgerNeeds[cheese];
            burgersMade++;
        }
    }

    int burgerPrice = burgerNeeds[burger] * storePrice[burger] + burgerNeeds[sausage] * storePrice[sausage] + burgerNeeds[cheese] * storePrice[cheese];
    if (money >= burgerPrice) {
        burgersMade += money / burgerPrice;
    }

    cout << burgersMade << endl;
    
    return 0;
}
```

## How the Code Works

1. **Input Reading**: The recipe and quantities are read into the appropriate arrays and variables.
2. **Burger Needs Calculation**: The number of `B`, `S`, and `C` needed for one hamburger is computed from the recipe string.
3. **Hamburger Construction**: First, hamburgers are made using the kitchen stock. Then, ingredients are bought from the shop until rubles run out.
4. **Final Output**: The total number of hamburgers made is printed as output.
