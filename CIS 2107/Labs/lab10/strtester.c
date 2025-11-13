#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

int main()
{
  int i, result;

  // Test all_letters
  result = all_letters("Hello world");
  if (result == 1)
  {
    printf("All letters are either Upper or lowercase: \"%d\" \n\n", result);
  }
  else
  {
    printf("All letters are not either Upper or lowercase: \"%d\" \n\n", result);
  }

  // Test num_in_range
  printf("Characters such that b<=c<=t: %d\n\n", num_in_range("Yellow", 'f', 'm'));

  // Test diff
  printf("Number of times differed: %d\n\n", diff("Slash", "Stash"));

  // Test shorten
  char s1[] = "Hello There";
  shorten(s1, 5);
  printf("String shortened: \"%s\" \n\n", s1);

  // Test len_diff
  printf("The length difference is: %d\n\n", len_diff("Solo", "Leveling"));

  // Test rm_left_space
  char s2[] = "      Ethereum";
  rm_left_space(s2);
  printf("String with left spaces removed: \"%s\" \n\n", s2);

  // Test rm_right_space
  char s3[] = "Ethereum      ";
  rm_right_space(s3);
  printf("String with right spaces removed: \"%s\" \n\n", s3);

  // Test rm_space
  char s4[] = "   Ethereum    ";
  rm_space(s4);
  printf("String with left and right spaces removed: \"%s\" \n\n", s4);

  // Test find <------- Here
  char *h = "Star Wars";
  char *n = "ar";
  printf("Number of times \"%s\" is in \"%s\": %d\n\n", h, n, find(h, n));

  // Test ptr_to
  char *ptr_found = ptr_to("The Wager", "Wa");
  if (ptr_found != NULL)
  {
    printf("String found: \"%s\"\n\n", ptr_found);
  }
  else
  {
    printf("String not found\n\n");
  }

  // Test is_empty
  i = is_empty("    ");
  if (i == 1)
  {
    printf("Sting is empty: %d\n\n", i);
  }
  else
  {
    printf("Sting is not empty: %d\n\n", i);
  }

  // Test str_zip
  char *zip = str_zip("TheHomeDepot", "Lowes");
  if (zip != NULL)
  {
    printf("The combined strings are: \"%s\"\n\n", zip);
    free(zip);
  }
  else
  {
    printf("Could not be comined\n\n");
  }

  // Test capitalize
  char s5[] = "ten Percent luck twenty percent Skill";
  capitalize(s5);
  printf("Senctence capitalized: \"%s\"\n\n", s5);

  // Test strcmp_ign_case
  result = strcmp_ign_case("Hashirama", "hashirama");
  if (result < 0)
  {
    printf("s2 after s1: %d\n\n", result);
  }
  else if (result > 0)
  {
    printf("s1 after s2: %d\n\n", result);
  }
  else
  {
    printf("s2 equals s1: %d\n\n", result);
  }

  // Test take_last
  i = 3;
  char s6[] = "Eldin Ring";
  take_last(s6, i);
  printf("Sentence with the last %d chars taken: \"%s\"\n\n", i, s6);

  // Test dedup
  printf("String with no duplicates: \"%s\"\n\n", dedup("We dont monkey around here"));

  // Test pad
  i = 10;
  printf("String padded: \"%s\" \n\n", pad("superdry", i));

  // Test ends_with_ignore_case
  result = ends_with_ignore_case("Capping", "ing");
  if (result == 1)
  {
    printf("Suff is a suffix: %d \n\n", result);
  }
  else
  {
    printf("Suff is not a suffix: %d \n\n", result);
  }

  // Test repeat

  printf("String repeated: %s\n\n", repeat("is never the end", 5, ','));

  // Test replace
  char *result_s1 = replace("Brady is the X JCole is the X", "X", "GOAT");

  if (result_s1 != NULL)
  {
    printf("Replaced string: %s\n\n", result_s1);
    free(result_s1);
  }
  else
  {
    printf("Could not be replaced\n\n");
  }

  // Test str_connect
  char *b_sounds[] = {"Bing", "Bang", "Boom", "Bam"};
  char *b_string = str_connect(b_sounds, 3, '+');
  if (b_string != NULL)
  {
    printf("Sting connected: %s\n\n", b_string);
    free(b_string);
  }
  else
  {
    printf("Could not be connected\n\n");
  }

  // Test rm_empties
  char *sentence[] = {"I", "", "heat", "up", "", "I", "can't", "", "cool", "down", NULL};
  rm_empties(sentence);
  i = 0;
  printf("Empties removed: ");
  while (sentence[i] != NULL)
  {
    printf("%s ", sentence[i]);
    i++;
  }
  puts("\n");

  // Test str_chop_all
  i = 0;
  char **delimiter_words = str_chop_all("What is up doc", ' ');
  if (delimiter_words == NULL)
  {
    printf("Error: memory allocation failed\n");
    return 1;
  }
  while (delimiter_words[i] != NULL)
  {
    if (i == 0)
    {
      printf("%s", delimiter_words[i]);
    }
    else
    {
      printf(" %s", delimiter_words[i]);
    }
    free(delimiter_words[i]);
    i++;
  }
  puts("\n");
  free(delimiter_words);
  return 0;
}