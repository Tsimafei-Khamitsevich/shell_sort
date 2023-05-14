#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <algorithm>
#include <iterator>

// сортировка методом Шелла
void ShellSort(int n, int mass[])
{
    int comparison = 0;
    int swap = 0;
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                comparison = ++comparison;
                if (tmp < mass[j - step]){
                    mass[j] = mass[j - step];
                    swap = ++swap;   
                }
                else
                    break;
            }
            mass[j] = tmp;
        }
    printf("\nAmount of comparisons %d \n", comparison);
    printf("Amount of swaps %d\n", swap);
}


// считает количество цифр в файле
int numberCount(FILE* input) {
  fseek(input, 0, SEEK_SET);
  int counter = 0;
  while (true) {
    int value;
    if (fscanf(input, "%d", &value) == 1)
      counter++;
    if (feof(input))
      break;
  }
  return counter;
}


// считывает числа
void read_numbers(FILE* input, int size, int* numbers) {
  fseek(input, 0, SEEK_SET);
  for (int i = 0; i < size; ++i) {
    fscanf(input, "%d", &numbers[i]);
  }
}


// выводит массив
void print_array(int* numbers, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}


// основная функция
int main_body(){
    
    // открываем файл
    FILE* input = fopen("INPUT.txt", "r");
    
    if (input == 0) {
    printf("cant open file\n");
    return 1;
    }
    // создаем массив
    int size = numberCount(input);
    
    // проверяет файл на пустоту 
    if (size == 0) {
    printf("the file is empty\n");
    return 0;
    }
    
    int* numbers = (int*)malloc(sizeof(int) * size);
    
    // считываем массив
    read_numbers(input, size, numbers);
    print_array(numbers, size);
        
    //сортировка методом Шелла
    ShellSort(size, numbers);
    //вывод отсортированного массива на экран
    printf("Sorted array:\n");
    print_array(numbers, size);
    
    return 0;
}

// тесты
int test_shell_sort()
{
    int numbers[] = {0, 10, 1, 4, 8, 9, 3, 5};
    int sorted[] = {0, 1, 3, 4, 5, 8, 9, 10};
    ShellSort(8, numbers);
    if (!(std::equal(numbers, numbers + sizeof numbers / sizeof *numbers, sorted))) printf("First test not working\n");
    
    int numbers1[] = {};
    int sorted1[] = {};
    ShellSort(0, numbers1);
    if (!(std::equal(numbers1, numbers1 + sizeof numbers1 / sizeof *numbers1, sorted1))) printf("Second test not working\n");
    
    int numbers2[] = {1};
    int sorted2[] = {1};
    ShellSort(1, numbers2);
    if (!(std::equal(numbers2, numbers2 + sizeof numbers2 / sizeof *numbers2, sorted2))) printf("Third test not working\n");
    
    int numbers3[] = {0, 10, 1, 4, -8, 9, -3, -5};
    int sorted3[] = {-8, -5, -3, 0, 1, 4, 9, 10};
    ShellSort(8, numbers3);
    if (!(std::equal(numbers3, numbers3 + sizeof numbers3 / sizeof *numbers3, sorted3))) printf("Fourth test not working\n");
    
}


int main()
{
   // test_functions();
   main_body();
   return 0;
}