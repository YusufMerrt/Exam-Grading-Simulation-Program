

# Exam Grading Simulation Program

This C program simulates the process of generating an answer key for a multiple-choice exam, applying the exam to a set of students, and then grading their responses. The program calculates the individual scores of the students, the class average, and the standard deviation of the scores. It also assigns letter grades based on the calculated scores.

## Features

1. **Generate Answer Key:** Creates a random answer key for the exam.
2. **Simulate Student Responses:** Simulates the responses of students to the exam questions based on probabilities of leaving answers blank and answering correctly.
3. **Grade the Exam:** Calculates the raw scores (HBN), class average, standard deviation, and T-scores for the students.
4. **Assign Letter Grades:** Determines letter grades for each student based on their T-scores and the class performance.

## Functions

- `void cevap_anahtari_uret(char cevap_anahtari[], int S);`
  - Generates a random answer key of length `S`.
  
- `void cevap_anahtari_yazdir(char cevap_anahtari[], int S);`
  - Prints the answer key.
  
- `void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D);`
  - Simulates student responses based on probabilities `B` (blank) and `D` (correct).
  
- `void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S);`
  - Prints the responses of a specific student.
  
- `void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S);`
  - Grades the students based on their responses and the answer key.
  
- `double sinif_ortalamasi_hesapla(double HBN[], int N);`
  - Calculates the class average score.
  
- `double standart_sapma_hesapla(double ortalama, double HBN[], int N);`
  - Calculates the standard deviation of the class scores.
  
- `void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[]);`
  - Calculates the T-scores for the students.

## Usage

1. **Compile the Program:**
   ```
   gcc -o exam_grading_simulation exam_grading_simulation.c -lm
   ```
   
2. **Run the Program:**
   ```
   ./exam_grading_simulation
   ```
   
3. **Input Data:**
   - Enter the number of students (`N`).
   - Enter the number of questions (`S`).
   - Enter the probability of leaving a question blank (`B`), as a float between 0.0 and 1.0.
   - Enter the probability of answering a question correctly (`D`), as a float between 0.0 and 1.0.

4. **Output:**
   - The program will print the answer key, the responses of each student, the class average, the standard deviation, and the T-scores. It will also assign letter grades to each student based on their T-scores.

## Example

```
Ogrenci sayisini giriniz (max 100) : 10
soru sayisini giriniz (max 100) : 20
Bos birakma ihtimalini giriniz (0.0-1.0) : 0.1
Dogru cevap verme ihtimalini giriniz (0.0-1.0) : 0.7

Cevap anahtari:
1:A | 2:B | 3:C | 4:D | 5:E | 6:A | 7:B | 8:C | 9:D | 10:E | 11:A | 12:B | 13:C | 14:D | 15:E | 16:A | 17:B | 18:C | 19:D | 20:E |

1 ogrencinin cevaplari:
1:A | 2:B | 3:X | 4:D | 5:E | 6:A | 7:B | 8:C | 9:D | 10:X | 11:A | 12:B | 13:C | 14:X | 15:E | 16:A | 17:B | 18:C | 19:D | 20:E |

...

sinif ortalama : 75.000000 

sinifin sitandart sapmasi : 10.000000

Sinif duzeyi : Mukemmel

1. ogrencinin HBN: 90.000000 T skoru : 70.000000 harf notu : AA
...
```

## Notes

- Ensure that the `N` (number of students) and `S` (number of questions) do not exceed 100.
- The probabilities `B` and `D` should be between 0.0 and 1.0.
- The program uses random number generation, so the results will vary with each run.

