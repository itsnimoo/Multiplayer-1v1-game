#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;
struct player
{
    int health;
    int pbar;
    int damage;
};
struct player p1, p2;

void init(struct player &p)
{
    p.health = 100;
    p.pbar = 0;
    p.damage = 10;
}

void healthcheck()
{
    if (p1.health<=0 && p2.health<=0){
        cout << "\nBoth players lost all health simultaneously. So, no one loses.\n";

    }
    else if (p1.health<=0 && p2.health>0){
        cout << "\nYou lose all health points. You lose!\n";

    }
    else if (p1.health>0 && p2.health<=0){
        cout << "\nThe bot loses all health points. You win!\n";

    }
}

void supercheck()
{
    char choice;
    if (p1.pbar>=3){
        Sleep(800);
        cout << "\nYou have a SUPERATTACK available. Would you like to use it? (Enter 'Y' for Yes and 'ANY OTHER KEY' for No)\n";
        cin >> choice;
        if (choice=='Y' || choice=='y'){
            Sleep(800);
            printf ("\nSUPER ATTACK UNLEASHED!!!\n You deal %d damage to bot.\n", p1.damage*2);
            p1.pbar=0;
            p2.health-=p1.damage*2;

        }
    }
    if (p2.pbar>=3){
        Sleep(800);
        cout << "\nBot is about to use its SUPER ATTACK.\n";
        Sleep(800);
        printf("Bot's SUPER ATTACK UNLEASHED!!!\n Bot deals %d damage to you.\n", p2.damage*2);
        Sleep(800);
        p2.pbar=0;
        p1.health-=p2.damage*2;

    }
}

void action(string m1, string m2)
{
    if (m1=="ATK" && m2=="ATK"){
        printf("Both players attack each other successfully - You lose %d health points and the bot loses %d health points.\n", p2.damage, p1.damage);
        p1.health-=p2.damage;
        p2.damage+=(p2.damage*3)/10;
        p2.health-=p1.damage;
        p1.damage+=(p1.damage*3)/10;
    }
    else if (m1=="ATK" && m2=="BLK"){
        printf("The bot blocks incoming attack successfully -> +1 power bar for bot.\n");
        p2.pbar++;
        p1.damage-=(p1.damage*3)/20;
    }
    else if (m1=="ATK" && m2=="CHG"){
        printf("Bot's charge fails and you attack successfully. Bot loses %d health points.\n", p1.damage);
        p2.health-=p1.damage;
        p1.damage+=(p1.damage*3)/10;
    }
    else if (m1=="BLK" && m2=="ATK"){
        printf("You block bot's incoming attack successfully -> +1 power bar for you.\n");
        p1.pbar++;
        p2.damage-=(p2.damage*3)/20;
    }
    else if (m1=="BLK" && m2=="BLK"){
        printf("+1 power bar for both players.\n");
        p1.pbar++;
        p2.pbar++;
    }
    else if (m1=="BLK" && m2=="CHG"){
        printf("Bot uses a charge attack and your block fails. You lose %d health points and bot gains %d health points.\n", p2.damage/2, p2.damage/2);
        p1.health-=p2.damage/2;
        p2.health+=p2.damage/2;
        p2.damage+=p2.damage/5;
    }
    else if (m1=="CHG" && m2=="ATK"){
        printf("Your charge fails and bot attacks successfully. You lose %d health points.\n", p2.damage);
        p1.health-=p2.damage;
        p2.damage+=(p2.damage*3)/10;
    }
    else if (m1=="CHG" && m2=="BLK"){
        printf("You use a charge attack and bot's block fails. You gain %d health points and bot loses %d health points.\n", p1.damage/2, p1.damage/2);
        p2.health-=p1.damage/2;
        p1.health+=p1.damage/2;
        p1.damage+=p1.damage/5;
    }
    else if (m1=="CHG" && m2=="CHG"){
        printf("Both players charge at each other. You: %d health gained, Bot: %d health gained\n", p1.damage/2-p2.damage/2, p2.damage/2-p1.damage/2);
        p1.health-=p2.damage/2;
        p2.health+=p2.damage/2;
        p2.health-=p1.damage/2;
        p1.health+=p1.damage/2;
        p1.damage+=p1.damage/5;
        p2.damage+=p2.damage/5;
    }
    else {
        cout << "Invalid move entered!\n";
    }
}

int main()
{
    cout << "************************\n";
    cout << "*   FRENZY FIGHTERS!   *" << endl;
    cout << "************************\n";
    cout << "\nRules:\n\n";
    cout << "This is a 1v1 game where you will have to first fill in 3 moves, and so will the computer do (randomly).\n";
    cout << "Initially, both players (YOU & BOT) have 100 HP, 10 damage points and 0 power bars.\n";
    cout << "You have 3 options per move: Attack(ATK), Block(BLK), Charge(CHG)\n\n";
    cout << "All possible combinations:\n";
    cout << "ATK-ATK: Both LOSE HP as much as OTHER'S CURRENT DAMAGE POINTS, and both GAIN +30% damage points.\n";
    cout << "BLK-BLK: Both players do nothing and only GAIN 1 POWER BAR each.\n";
    cout << "CHG-CHG: Both players GAIN HP equal to HALF of their current DAMAGE POINTS and INFLICT that much damage on their opponent.\n";
    cout << "ATK-CHG: The attacker REDUCES OPPONENT'S HEALTH by the amount of his current DAMAGE POINTS and also GAIN +30% damage points.\n";
    cout << "ATK-BLK: The attack FAILS and the attacker LOSES -15% damage points and the blocker GAINS +1 POWER BAR.\n";
    cout << "BLK-CHG: The charger INFLICTS damage equal to half its current DAMAGE POINTS and also GAINS that many HP.\n\n";
    cout << "SUPERATTACK: Once the 3 moves are done and if you have 3 or more power bars, you will be given the option to do a super attack, ";
    cout << "\nwhich will inflict damage that is twice(2x) of your current damage rating.\n";
    cout << "NOTE: If both players have 3 or more power bars, then you will be given the option to use your super attack first.\n";
    cout << "\nGOAL: Reduce opponent's health to or below 0 to win the game.\n";
    game_start:

    srand(time(0));
    int i;
    string pmove[3],cmove[3];
    string s[] = {"ATK","BLK","CHG"};
    init(p1);
    init(p2);
    while (true)
    {

        cout << "\nEnter any key\n";
        getch();
        system("CLS");
        cout << "\n\nYou:\nHealth Points: " << p1.health << "\nPower Bars: " << p1.pbar << "\nDamage Points: " << p1.damage << endl;
        cout << "\nBot:\nHealth Points: " << p2.health << "\nPower Bars: " << p2.pbar << "\nDamage Points: " << p2.damage << endl ;


        cout << "\n(Enter ATK, BLK or CHG)\n";
        for (i=0;i<3;i++){
            cout <<  "Enter move " << i+1 << " : ";
            cin >> pmove[i];
            cmove[i] = s[rand()%3];
        }
        Sleep(1000);
        cout << "Computer's moves: " << cmove[0] << ", " << cmove[1] << ", " << cmove[2] << endl << endl;
        Sleep(1000);
        for (i=0;i<3;i++){
            cout << "Action on Move " << i+1 << ": ";

            action(pmove[i], cmove[i]);
            Sleep(800);
            if (p1.health<=0 || p2.health<=0)
                break;
        }
        if (p1.pbar>=3 || p2.pbar>=3)
            supercheck();
        Sleep(700);
        if (p1.health<=0 || p2.health<=0)
            break;

    }
    healthcheck();

    i=0;
    char g[]="GAME";
    char choice;
    cout << endl;
    while (g[i]!='\0'){
        cout << g[i];
        Sleep(700);
        i++;
    }
    Sleep(800);
    cout << " OVER!";
    Sleep (1000);
    cout << "\n\nWant to play again? If yes, enter 'Y'. If no, then enter ANY OTHER KEY.\n";
    cin >> choice;
    if (choice=='Y' || choice=='y')
        goto game_start;
    Sleep(1000);
    cout << "\n\nPress any key to exit the game";
    getch();
    return 0;
}










