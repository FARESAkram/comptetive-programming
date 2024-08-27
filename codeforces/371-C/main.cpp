#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool getCondition(ull* kitchen, ull* burgerNeeds){
    bool needBurger[3];

    for (int i = 0 ; i < 3 ; i ++ ){
        needBurger[i] = burgerNeeds[i] > 0 && kitchen[i] > 0;
    }
    return needBurger[0] || needBurger[1] || needBurger[2];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int burger = 0;
    int sausage = 1;
    int cheese = 2;

    string burgerStructure;
    cin >> burgerStructure;

    ull kitchen[3], storePrice[3], burgerNeeds[3] = {0,0,0}, money;
    ull burgersMade = 0;

    for(int i = 0 ; i < 3; i ++){
        cin >> kitchen[i];
    }
    for(int i = 0 ; i < 3; i ++){
        cin >> storePrice[i];
    }
    cin >> money;

    for (int i = 0 ; i < burgerStructure.size() ; i ++ ){
        char burgerPart = burgerStructure[i];
        if ( burgerPart == 'B' ){
            burgerNeeds[burger] ++;
        }
        if ( burgerPart == 'S' ){
            burgerNeeds[sausage] ++;
        }
        if ( burgerPart == 'C' ){
            burgerNeeds[cheese] ++;
        }
    }

    while (kitchen[burger] >= burgerNeeds[burger] && kitchen[sausage] >= burgerNeeds[sausage] && kitchen[cheese] >= burgerNeeds[cheese]){
        kitchen[burger] -= burgerNeeds[burger];
        kitchen[sausage] -= burgerNeeds[sausage];
        kitchen[cheese] -= burgerNeeds[cheese];
        burgersMade ++;
    }
    while (getCondition(kitchen, burgerNeeds)){
        int needsTobuy[3], i;
        for(i = 0 ; i < 3; i ++ ){
            needsTobuy[i] = burgerNeeds[i] - kitchen[i];
            if ( needsTobuy[i] > 0 ){
                int moneyToSpend = needsTobuy[i] * storePrice[i];
                if ( money < moneyToSpend ){
                    break;
                }
                money -= moneyToSpend;
                kitchen[i] = burgerNeeds[i];
            }
        }


        if ( i != 3 ){
            break;
        }
        while (kitchen[burger] >= burgerNeeds[burger] && kitchen[sausage] >= burgerNeeds[sausage] && kitchen[cheese] >= burgerNeeds[cheese]){
            kitchen[burger] -= burgerNeeds[burger];
            kitchen[sausage] -= burgerNeeds[sausage];
            kitchen[cheese] -= burgerNeeds[cheese];
            burgersMade ++;
        }
    }

    int burgerPrice = burgerNeeds[burger] * storePrice[burger] + burgerNeeds[sausage] * storePrice[sausage] + burgerNeeds[cheese] * storePrice[cheese];
    
    if ( money >= burgerPrice ){
        burgersMade += money / burgerPrice;
    }

    cout << burgersMade << endl;
    
    return 0;
}
