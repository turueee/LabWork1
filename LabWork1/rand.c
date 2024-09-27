
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "func.h"



int main()
{
  double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0, time_of_on = time(0);
  int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index;
  char first_massive_of_remains[250000], second_massive_of_remains[250000];
  char third_massive_of_remains[250000], fourth_massive_of_remains[250000];
  FILE* fil;
  for (counter; counter < 250000; counter++)
  {
    first_massive_of_remains[counter] = 0;
    second_massive_of_remains[counter] = 0;
    third_massive_of_remains[counter] = 0;
    fourth_massive_of_remains[counter] = 0;
  }
  scanf("%lf", &min_ch);
  scanf("%lf", &max_ch);
  scanf("%d", &count_of_numbers);

  fil = fopen("stor.txt", "w");
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    random_number = make_random_number(min_ch, max_ch, counter);
    dec_remain = make_dec_remain(random_number);

    if (counter < 1000000)
    {
      if (fil != NULL)
        fprintf(fil, "%lf\n", random_number);
      else
        printf("IDIOT");
    }
    else
    {
      result += random_number;
    }

    if (dec_remain >= 0 && dec_remain < 250000)
    {
      first_massive_of_remains[dec_remain] = 1;
    }
    else if (dec_remain >= 250000 && dec_remain < 500000)
    {
      second_massive_of_remains[dec_remain - 250000] = 1;
    }
    else if (dec_remain >= 500000 && dec_remain < 750000)
    {
      third_massive_of_remains[dec_remain - 500000] = 1;
    }
    else
    {
      fourth_massive_of_remains[dec_remain - 750000] = 1;
    }
  }
  fclose(fil);

  fil = fopen("stor.txt", "r");
  if (count_of_numbers > 1000000)
    count_of_numbers = 1000000;
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    fscanf(fil, "%lf\n", &number);

    if (counter >= 0 && counter < 250000)
    {
      index = first_massive_of_remains[counter];
    }
    else if (counter >= 250000 && counter < 500000)
    {
      index = second_massive_of_remains[counter - 250000];
    }
    else if (counter >= 500000 && counter < 750000)
    {
      index = third_massive_of_remains[counter - 500000];
    }
    else
    {
      index = fourth_massive_of_remains[counter - 750000];
    }
    if (index == 1)
    {
      result -= number;
    }

    else
    {
      result += number;
    }
  }
  //for (counter = 0; counter < 250000; counter++)
    //printf("|%d| |%d| |%d| |%d|", first_massive_of_remains[counter], second_massive_of_remains[counter], third_massive_of_remains[counter], fourth_massive_of_remains[counter]);
  printf("%lf", result);
}
