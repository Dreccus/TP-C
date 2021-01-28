#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}

/* Returns the size of an integer array */
int array_size(int* array){
  int len = 0;
  while(array[len] != -1){
    len++;
  }
  return len;
}

/* Prints the content of an integer array */
void print_array(int* array){ 
  int size = array_size(array);
  if(size > 0){
  int i;
  printf("[");
  for(i = 0; i < size-1; i++){
    printf(" %d,", array[i]);
  }
  printf(" %d]\n", array[size-1]);
  }
  else{
    printf("[%d]\n",array[0]);
  }
}

void print_array_with_name(int* array, char* name){
  printf("%s: ", name);
  print_array(array);
}

/* Returns 1 if arrays are equal. Returns 0 otherwise */
int are_arrays_equal(int* first, int* second){ 
  int size1 = array_size(first);
  int size2 = array_size(second);

  if(size1 != size2){
    return 0;
  }
  else{
    int i;
    for(i = 0; i < size1; i++){
      if(first[i] != second[i]){
        return 0;
      }
    }
    return 1;
  }

}


/* Returns a copy of the array in parameter, based on a new adress */
int* copy_array(int* array){
  int size = array_size(array);
  int* array_copy = allocate_integer_array(size+1);

  int i; 
  for(i = 0; i < size; i++){
    array_copy[i] = array[i];
  }
  array_copy[size] = -1;

  return array_copy;
}

/* Asks the user to input a length and positive integers. Then returns the allocated array.*/
int* fill_array(void){ /* faire en sorte qu'il soit impossible d'entrer autre chose qu'un entier en guise de longueur*/
  int len;
  printf("Entrez une longueur : ");
  scanf("%d", &len);
  int* toBeFilledArray = allocate_integer_array(len);

  int element;
  int i;
  /*while(i < len){
    printf("Entrez un entier. Nombre d'entiers actuel : %d \n", i);
    scanf("%d \n", &element);
    toBeFilledArray[i] = element;
    i++;
  }*/
  for(i = 0; i <len; i++){
    printf("Entrez un entier. Nombre d'entiers actuel : %d \n", i);
    scanf("%d \n", &element);
    toBeFilledArray[i] = element;
  }
  toBeFilledArray[len] = -1;

  return toBeFilledArray;
}

/* Returns an array with SIZE positive integers chosen randomly*/
int* random_array(int size, int max_entry){
  int* randomArray = allocate_integer_array(size);
  int i;
  for(i = 0; i < size; i++){
    randomArray[i] = rand() % max_entry;
  }
  randomArray[size] = -1;

  return randomArray;
}

/* Takes up two arrays and returns a new array composed of the two initial arrays added up */
int* concat_array(int* first, int* second){
  int size1 = array_size(first);
  int size2 = array_size(second);

  int* concatenated_array = allocate_integer_array(size1 + size2);

  if(size1 == 0){
    return second;
  }
  else if(size2 == 0){
    return first;
  }
  else{
    int i;
    for(i = 0; i < size1; i++){ /* Filling with the first array's values */
      concatenated_array[i] = first[i];
    }

    for(i = size1; i < size1 + size2; i++){ /* Filling with the second array's values */
      concatenated_array[i] = second[i - size1];
    }
  }
  concatenated_array[size1 + size2] = -1;
  
  return concatenated_array;
}

/* Takes two sorted arrays and merges their values. Returns the sorted merged values in a freshly allocated values */
int* merge_sorted_arrays(int* first, int* second){
  int size1 = array_size(first);
  int size2 = array_size(second);

  int* merged = allocate_integer_array(size1 + size2);
  
  int i=0; 
  int j=0; 
  int n=0;


  while(i<size1 && j<size2){
      if(second[j] < first[i]){
        merged[n] = second[j];
        j++;
      }


      else{
        merged[n] = first[i];
        i++;
      }
      n++;
  }

  for(j=j; j < size2; j++){
    merged[n] = second[j];
    n++;
  }

  for(i=i; i< size1; i++){
    merged[n] = first[i];
    n++;
  }

  merged[size1 + size2] = -1;

  return merged;
}

/* Takes one array and two array pointers. Splits the first array into two arrays of equal size if possible */
void split_arrays(int* array, int** first, int** second){
  int size = array_size(array);
  int i;

  if(size % 2 != 0){
    (*first) = allocate_integer_array(size/2+1);
    (*second) = allocate_integer_array(size/2);
  
    for(i = 0; i < size; i++){
      if(i <= size/2){
        *(first[0]+i) = array[i];
      }
      else{
        *(second[0] + i - size/2-1) = array[i];
        }
    }
    /*(*first)[size/2+1] = -1;*/
    *(first[0] + size/2 +1)= -1;
    *(second[0] + size/2)= -1;
  }

  else{
    (*first) = allocate_integer_array(size/2);
    (*second) = allocate_integer_array(size/2);

    for(i = 0; i < size; i++){
      if(i < size/2){
        *(first[0]+i) = array[i];
      }
      else{
        *(second[0] + i - size/2) = array[i];
      }

      
      }
    *(first[0] + size/2)= -1;
    *(second[0] + size/2)= -1;
    }
  return;
}

int* merge_sort(int* array){
  int size = array_size(array);
  if(size <= 1){
    return array;
  }

  int* first;
  int* second;

  printf("Split array in two parts: \n");
  split_arrays(array, &first, &second);
  print_array(array);
  print_array(first);
  print_array(second);

  
  
  first = merge_sort(first);
  second = merge_sort(second);
  printf("Merge the two following ones: \n");
  print_array(first);
  print_array(second);

  int* merged = merge_sorted_arrays(first, second); 
  
  print_array(merged);
  
  free_integer_array(merged);


  return merge_sorted_arrays(first, second);

}



/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){

  srand(time(NULL));

  int arraySize1 = 5;
  int arraySize2 = 7;

  int* array1 = allocate_integer_array(arraySize1); /* Equal to array2*/
  int* array2 = allocate_integer_array(arraySize1);
  int* array3 = allocate_integer_array(arraySize2); /* Not equal to array4*/
  int* array4 = allocate_integer_array(arraySize2);

  int i; /* re using i all the time since there is never a loop inside another loop*/
  for(i=0; i<arraySize1; i++){ /* Setting up array1 */
    array1[i] = (i+1)*2;
  }
  array1[arraySize1] = -1;

  for(i=0; i<arraySize1; i++){ /* Setting up array2 to be the same as array1 */
    array2[i] = (i+1)*2;
  }
  array2[arraySize1] = -1;

  for(i=0; i<arraySize2; i++){ /* Setting up array3, same as array1 until index arraySize1 */
    array3[i] = (i+1)*2;
  }
  array3[arraySize2] = -1;

  for(i=0; i<arraySize2; i++){ /* Setting up array4, same size as array3 but different values entirely */
    array4[i] = (i+2)*2;
  }
  array4[arraySize2] = -1;


  print_array_with_name(array1, "Array 1");
  print_array_with_name(array2, "Array 2");
  print_array_with_name(array3, "Array 3");
  print_array_with_name(array4, "Array 4");



  printf("\n***Testing are_arrays_equal():***\n");

  printf("a1 == a2  ? Should return 1 : %d \n", are_arrays_equal(array1, array2));
  printf("a1 == a3  ? Should return 0 : %d (Not the same size)\n", are_arrays_equal(array1, array3));
  printf("a3 == a4  ? Should return 0 : %d (Same size but not same values)\n\n", are_arrays_equal(array3, array4));

  printf("***Testing array_copy(), copying array1: ***\n");

  int* copiedArray = copy_array(array1);

  printf("copiedArray == array1 ? Should return 1 : %d\n", are_arrays_equal(copiedArray, array1));
  printf("copiedArray == array3 ? Should return 0 : %d\n\n", are_arrays_equal(copiedArray, array3));

  int randomThreshold = 15;

  printf("***Testing random_array, filling two arrays with random values , size = %d ***\n", arraySize1);
  int* randomArray1 = random_array(arraySize1, randomThreshold);
  print_array_with_name(randomArray1, "randomArray1");

  int* randomArray2 = random_array(arraySize2, randomThreshold);
  print_array_with_name(randomArray2, "randomArray2");

  printf("\n***Testing concat_array, concatenating array1 and array3 ***\n");
  int* concatenated_array = concat_array(array1, array3);
  print_array(array1);
  print_array(array3);
  print_array_with_name(concatenated_array, "Array 1 + Array 3");

  printf("\n***Testing merge_sorted_arrays.***\nMerging arrays with several values each");
  printf("Testing with Array1 and Array4.\n");
  int* sorted_merged = merge_sorted_arrays(array1, array4);
  print_array_with_name(array1, "Array 1");
  print_array_with_name(array4, "Array 4");

  print_array(sorted_merged);

  printf("\nMerging arrays with a unique value each (except for -1)\n");

  int* singleValue1 = allocate_integer_array(1);

  singleValue1[0] = 25;
  singleValue1[1] = -1;

  int* singleValue2 = allocate_integer_array(1);

  singleValue2[0] = 36;
  singleValue2[1] = -1;

  int* singleMerged = merge_sorted_arrays(singleValue1, singleValue2);
  print_array_with_name(singleValue1, "singleValue1");
  print_array_with_name(singleValue2, "singleValue2");
  print_array_with_name(singleMerged, "singleMerged"); /*Works with "unique" (not counting the -1) value arrays too*/

  int* split1;
  int* split2;
  printf("\n***Testing split_arrays. ***\nSplitting sorted_merged into split1 and split2\n");
  print_array_with_name(sorted_merged, "sorted_merged");
  split_arrays(sorted_merged, &split1, &split2);
  print_array_with_name(split1, "split1");
  print_array_with_name(split2, "split2");


  int* split3;
  int* split4;

  printf("\nSplitting array3 into split3 and split4\n");
  print_array_with_name(array3, "array3");
  split_arrays(array3, &split3, &split4);
  print_array_with_name(split3, "split3");
  print_array_with_name(split4, "split4");

  printf("\n***Testing merge_sort on a 20 elements random array with a maximum value of 100***\n");
  int* random_to_be_merge_sorted = random_array(10, 100);
  print_array_with_name(random_to_be_merge_sorted,"Random à trier");
  printf("Sorting random_to_be_merge_sorted with a merge sort :\n");
  int* sorted_random = merge_sort(random_to_be_merge_sorted);
  print_array_with_name(sorted_random,"Random trié");


  free_integer_array(array1);
  free_integer_array(array2);
  free_integer_array(array3);
  free_integer_array(array4);
  free_integer_array(copiedArray);
  free_integer_array(randomArray1);
  free_integer_array(randomArray2);
  free_integer_array(concatenated_array);
  free_integer_array(sorted_merged);
  free_integer_array(singleValue1);
  free_integer_array(singleValue2);
  free_integer_array(singleMerged);
  free_integer_array(split1);
  free_integer_array(split2);
  free_integer_array(split3);
  free_integer_array(split4);
  free_integer_array(random_to_be_merge_sorted);
  free_integer_array(sorted_random);



  return 0;
}
