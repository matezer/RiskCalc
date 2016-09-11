#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main() {
    int NumberOfAttackers;
    int NumberOfDefenders;
    int AttDice[3];
    int AttDiceHighest[2];
    int DefDice[2];
    int AttDiceRank1, AttDiceRank2, DefDiceRank1, DefDiceRank2;
    int cycle, cycle2, cycle3 = 0;

    srand(time(0));

    printf("please enter the number of attackers:");
    scanf("%d", & NumberOfAttackers);

    printf("please enter the number of defenders:");
    scanf("%d", & NumberOfDefenders);

    for (cycle = 0; NumberOfAttackers > 2 && NumberOfDefenders > 1; cycle++) {

      int i;
      for (i = 0; i < 3; i++) {
        AttDice[i] = (rand() % 6) + 1;
        printf("att %d \n", AttDice[i]);
      }

      int j;
      for (j = 0; j < 2; j++) {
        DefDice[j] = (rand() % 6) + 1;
        printf("def %d \n", DefDice[j]);
      }

      if (AttDice[0] <= AttDice[1] && AttDice[0] <= AttDice[2]) {
        printf("att dice 1 scored the lowest (%d) \n", AttDice[0]);
        AttDiceHighest[0] = AttDice[1];
        AttDiceHighest[1] = AttDice[2];
      } else if (AttDice[1] <= AttDice[0] && AttDice[1] <= AttDice[2]) {
        printf("att dice 2 scored the lowest (%d) \n", AttDice[1]);
        AttDiceHighest[0] = AttDice[0];
        AttDiceHighest[1] = AttDice[2];
      } else {
        printf("att dice 3 scored the lowest (%d) \n", AttDice[2]);
        AttDiceHighest[0] = AttDice[0];
        AttDiceHighest[1] = AttDice[1];
      }
      printf("%d and %d are the highest att throws \n", AttDiceHighest[0], AttDiceHighest[1]);

      if (AttDiceHighest[0] >= AttDiceHighest[1]) {
        AttDiceRank1 = AttDiceHighest[0];
        AttDiceRank2 = AttDiceHighest[1];
      } else {
        AttDiceRank1 = AttDiceHighest[1];
        AttDiceRank2 = AttDiceHighest[0];
      }

      if (DefDice[0] >= DefDice[1]) {
        DefDiceRank1 = DefDice[0];
        DefDiceRank2 = DefDice[1];
      } else {
        DefDiceRank1 = DefDice[1];
        DefDiceRank2 = DefDice[0];
      }

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins rank1 (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins rank1 (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }
      if (AttDiceRank2 > DefDiceRank2) {
        printf("Att wins rank2 (%d to %d): minus one defender \n", AttDiceRank2, DefDiceRank2);
        NumberOfDefenders--;
      } else {
        printf("Def wins rank2 (%d to %d): minus one attacker \n", DefDiceRank2, AttDiceRank2);
        NumberOfAttackers--;
      }
      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);

    }
    for (cycle2 = 0; NumberOfAttackers > 2 && NumberOfDefenders > 0; cycle2++) {
      printf("defenders can only use 1 dice!\n");

      int i;
      for (i = 0; i < 3; i++) {
        AttDice[i] = (rand() % 6) + 1;
        printf("att %d \n", AttDice[i]);
      }
      DefDiceRank1 = (rand() % 6) + 1;
      printf("def %d \n", DefDiceRank1);

      if (AttDice[0] >= AttDice[1] && AttDice[0] >= AttDice[2]) {
        printf("att dice 1 scored the highest (%d) \n", AttDice[0]);
        AttDiceRank1 = AttDice[0];
      } else if (AttDice[1] >= AttDice[0] && AttDice[1] >= AttDice[2]) {
        printf("att dice 2 scored the highest (%d) \n", AttDice[1]);
        AttDiceRank1 = AttDice[1];
      } else {
        printf("att dice 3 scored the highest (%d) \n", AttDice[2]);
        AttDiceRank1 = AttDice[2];
      }

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }
      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);
      cycle++;

    }
    for (cycle2 = 0; NumberOfAttackers > 1 && NumberOfDefenders > 1; cycle2++) {
      printf("attackers can only use 2 dice!\n");

      int i;
      for (i = 0; i < 2; i++) {
        AttDice[i] = (rand() % 6) + 1;
        printf("att %d \n", AttDice[i]);
      }

      int j;
      for (j = 0; j < 2; j++) {
        DefDice[j] = (rand() % 6) + 1;
        printf("def %d \n", DefDice[j]);
      }

      if (AttDice[0] >= AttDice[1]) {
        printf("att dice 1 scored the highest (%d) \n", AttDice[0]);
        AttDiceRank1 = AttDice[0];
        AttDiceRank2 = AttDice[1];
      } else {
        printf("att dice 2 scored the highest (%d) \n", AttDice[1]);
        AttDiceRank1 = AttDice[1];
        AttDiceRank2 = AttDice[0];
      }

      if (DefDice[0] >= DefDice[1]) {
        printf("def dice 1 scored the highest (%d) \n", DefDice[0]);
        DefDiceRank1 = DefDice[0];
        DefDiceRank2 = DefDice[1];
      } else {
        printf("def dice 1 scored the highest (%d) \n", DefDice[0]);
        DefDiceRank1 = DefDice[1];
        DefDiceRank2 = DefDice[0];
      }

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }
      if (AttDiceRank2 > DefDiceRank2) {
        printf("Att wins rank2 (%d to %d): minus one defender \n", AttDiceRank2, DefDiceRank2);
        NumberOfDefenders--;
      } else {
        printf("Def wins rank2 (%d to %d): minus one attacker \n", DefDiceRank2, AttDiceRank2);
        NumberOfAttackers--;
      }
      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);
      cycle++;

    }
    for (cycle2 = 0; NumberOfAttackers > 1 && NumberOfDefenders > 0; cycle2++) {
      printf("attackers can only use 2 dice and defenders only 1!\n");

      int i;
      for (i = 0; i < 2; i++) {
        AttDice[i] = (rand() % 6) + 1;
        printf("att %d \n", AttDice[i]);
      }
      DefDiceRank1 = (rand() % 6) + 1;
      printf("def %d \n", DefDiceRank1);

      if (AttDice[0] >= AttDice[1]) {
        printf("att dice 1 scored the highest (%d) \n", AttDice[0]);
        AttDiceRank1 = AttDice[0];
      } else {
        printf("att dice 2 scored the highest (%d) \n", AttDice[1]);
        AttDiceRank1 = AttDice[1];
      }

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }

      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);
      cycle++;
    }
    for (cycle2 = 0; NumberOfAttackers > 0 && NumberOfDefenders > 1; cycle2++) {
      printf("attackers can only use 1 dice!\n");

      AttDiceRank1 = (rand() % 6) + 1;
      printf("att %d \n", AttDiceRank1);

      int j;
      for (j = 0; j < 2; j++) {
        DefDice[j] = (rand() % 6) + 1;
        printf("def %d \n", DefDice[j]);
      }

      if (DefDice[0] >= DefDice[1]) {
        printf("def dice 1 scored the highest (%d) \n", DefDice[0]);
        DefDiceRank1 = DefDice[0];
      } else {
        printf("def dice 2 scored the highest (%d) \n", DefDice[1]);
        DefDiceRank1 = DefDice[1];
      }

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }

      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);
      cycle++;
    }
    for (cycle3 = 0; NumberOfAttackers > 0 && NumberOfDefenders > 0; cycle3++) {
      printf("Both attackers and defenders can use only 1 dice! (1v1 me m8)\n");

      AttDiceRank1 = (rand() % 6) + 1;
      printf("att %d \n", AttDiceRank1);

      DefDiceRank1 = (rand() % 6) + 1;
      printf("def %d \n", DefDiceRank1);

      if (AttDiceRank1 > DefDiceRank1) {
        printf("Att wins (%d to %d): minus one defender \n", AttDiceRank1, DefDiceRank1);
        NumberOfDefenders--;
      } else {
        printf("Def wins (%d to %d): minus one attacker \n", DefDiceRank1, AttDiceRank1);
        NumberOfAttackers--;
      }
      printf("end of round %d \t Attackers left: %d \t Defenders left: %d \n \n", cycle + 1, NumberOfAttackers, NumberOfDefenders);
      cycle++;
    }
    if (NumberOfAttackers == 0) {
      printf("Defenders are victorious! \n");
    } else if (NumberOfDefenders == 0) {
      printf("Attackers are victorious! \n");
    } else {
      printf("program derped :( \n");
    }
    return 0;
  }

