/* 
 * File:   main.cpp
 * Author: m.piehl
 *
 * Created on 29. Oktober 2014, 14:56
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <time.h> 

using namespace std;

template<class T> T
fromString(const std::string& s) {
    std::istringstream stream(s);
    T t;
    stream >> t;
    return t;
}

bool primeCalc(unsigned long long int primZahl) {
    if (primZahl == 2) return true;
    if (primZahl % 2 == 0) return false;
    if (primZahl % 3 == 0 xor primZahl == 3) return false;
    if (primZahl % 5 == 0 xor primZahl == 5) return false;
    unsigned long long checkTeiler = 7;
    bool prime = true; //erstmal davon ausgehen, dass die Zahl prim ist
    unsigned long long maxTeiler = sqrt(primZahl); // / checkTeiler; //maximaler Teiler kann nicht größer sein als die Wurzel der Primzahl
    while (checkTeiler <= maxTeiler && prime) { //solange der momentan größte Teiler nicht erreicht wurde und die Zahl als prim gilt

        if (primZahl % checkTeiler == 0) { //Teiler gefunden -> keine Primzahl
            prime = false;
            break;
        }
        checkTeiler += 2;
    }
    if (!prime) return false; //cout << "keine Primzahl! teiler: " << checkTeiler << " * " << primZahl / checkTeiler << endl << flush;
    else return true; //cout << primZahl << " ist prim!" << endl << flush;
}

unsigned long long findNextPrim(unsigned long long int primZahl) {
    if (primZahl == 2 || primZahl == 1) {
        primZahl += 1;
    } else {
        primZahl += 2;
    }
    while (!primeCalc(primZahl)) {
        primZahl += 2;
        //cout << primZahl << endl;
    }

    return primZahl;
}

unsigned long long int euler_eins() {
    unsigned long long int sum = 0;
    for (unsigned long long int i = 1; i < 3000000000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int euler_zwei(int fiboNum) {

    if (fiboNum <= 2) {
        return 2;
    }

    int pre = 1;
    int next = 2;

    int sum = 0;
    int placeholder = 0;

    while (next <= fiboNum) {
        if (next % 2 == 0) {
            sum += next;
        }
        placeholder = next;
        next += pre;
        pre = placeholder;

    }
    return sum;
}

int euler_drei(unsigned long long int myNumber) {

    int maxFactor = 1;
    int prim = 1;
    int maxTeiler = sqrt(myNumber);
    while (prim <= maxTeiler) {


        if (myNumber % prim == 0) {
            maxFactor = prim;
        }
        prim = findNextPrim(prim);

    }
    return maxFactor;
}

bool isPalindromic(int num) {

    string strNum = static_cast<ostringstream*> (&(ostringstream() << num))->str();
    string reverseStrNum = strNum;
    int pos = 0;
    for (int i = strNum.size() - 1; i >= 0; i--) {
        reverseStrNum[pos] = strNum[i];
        pos++;
    }

    if (reverseStrNum == strNum) {
        return true;
    } else {
        return false;
    }

}

int euler_vier() {
    int max = 0;
    for (int i = 999; i > 100; i--) {
        for (int j = 999; j > 100; j--) {
            int produkt = i*j;
            if (isPalindromic(produkt) && produkt > max) {
                max = produkt;

            }
        }
    }
    return max;
}

int euler_fuenf() {
    int zaehler = 20;
    int zahlen[10] = {};
    for (int i = 0; i <= 9; i++) {
        zahlen[i] = i + 11;
    }

    while (true) {
        for (int j = 0; j <= 19; j++) {

            if (zaehler % zahlen[j] != 0) {
                break;
            }
            if (zahlen[j] == 20) {
                return zaehler;
            }
        }
        zaehler += 20;
    }
}

unsigned long euler_sechs() {
    unsigned long sumOfSquares = 0;
    unsigned long sum = 0;

    for (int i = 1; i <= 100; i++) {
        sumOfSquares += i*i;
        sum += i;
    }
    cout << " squaresOfSum: " << sum * sum << " - sumOfSquares: " << sumOfSquares << " = ";
    return sum * sum - sumOfSquares;
}

int euler_sieben() {
    int prim = 1;
    for (int i = 1; i <= 10001; i++) {
        prim = findNextPrim(prim);
    }
    return prim;
}

unsigned long euler_acht() {

    string foo = "73167176531330624919225119674426574742355349194934";
    foo += "96983520312774506326239578318016984801869478851843";
    foo += "85861560789112949495459501737958331952853208805511";
    foo += "12540698747158523863050715693290963295227443043557";
    foo += "66896648950445244523161731856403098711121722383113";
    foo += "62229893423380308135336276614282806444486645238749";
    foo += "30358907296290491560440772390713810515859307960866";
    foo += "70172427121883998797908792274921901699720888093776";
    foo += "65727333001053367881220235421809751254540594752243";
    foo += "52584907711670556013604839586446706324415722155397";
    foo += "53697817977846174064955149290862569321978468622482";
    foo += "83972241375657056057490261407972968652414535100474";
    foo += "82166370484403199890008895243450658541227588666881";
    foo += "16427171479924442928230863465674813919123162824586";
    foo += "17866458359124566529476545682848912883142607690042";
    foo += "24219022671055626321111109370544217506941658960408";
    foo += "07198403850962455444362981230987879927244284909188";
    foo += "84580156166097919133875499200524063689912560717606";
    foo += "05886116467109405077541002256983155200055935729725";
    foo += "71636269561882670428252483600823257530420752963450";

    unsigned long max = 0;
    for (int i = 0; i < foo.size() - 12; i++) {
        unsigned long current = 1;
        for (int j = i; j <= i + 12; j++) {
            current *= foo[j] - '0';
        }
        if (current > max) {
            max = current;
        }
    }
    return max;

}

unsigned long euler_neun() {
    for (int a = 1; a <= 332; a++) {
        for (int b = a + 1; b <= 499; b++) {
            float c = sqrt(a * a + b * b);
            if (1000 == a + b + c) {
                cout << a << ", " << b << ", " << c << endl;
                return a * b*c;
            }
        }
    }
}

unsigned long euler_zehn() {
    unsigned long prim = 0;
    unsigned long sum = 0;
    while (prim < 2000000) {
        sum += prim;
        prim = findNextPrim(prim);
        cout << prim << endl;
    }
    return sum;
}

void euler_elf() {
    // siehe script.php -> Projects/projekt_euler
}

int number_of_divisors(unsigned long ulNum) {
    if (ulNum == 0) return 0;
    //prüfung auf 1 und ulNum selbst überspringen
    int count = 0;
    unsigned long sqrtulNum = sqrt(ulNum);
    if (ulNum % 2 != 0) {
        for (unsigned long i = 1; i <= sqrtulNum; i += 2) {
            if (ulNum % i == 0) {
                if (ulNum / i == sqrtulNum) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
    } else {
        for (unsigned long i = 1; i <= sqrtulNum; i++) {
            if (ulNum % i == 0) {
                if (ulNum / i == sqrtulNum) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
    }
    return count;
}

int *getDivisors(int to) {
    int *divisors = new int[to];
    for (int i = 0; i <= to + 1; i++) {
        divisors[i] = 0;
    }
    for (int divisor = 1; divisor <= to; divisor++) {
        for (int i = divisor; i <= to; i += divisor) {
            divisors[i]++;
        }
    }
    return divisors;
}

unsigned long euler_zwoelf() {
    unsigned long triangle = 0;
    int i = 0;
    do {
        i++;
        triangle += i;
        //cout << i << ": " << triangle << ": " << number_of_divisors(triangle) << endl;

    } while (number_of_divisors(triangle) < 500);
    return triangle;

}

void euler_dreizehn() {
    // siehe script.php -> Projects/projekt_euler
}

long getHalve(long num) {
    if (0 == num % 2) {
        return num / 2;
    } else {
        return 0;
    }
}

long getOdd(long num) {
    return num * 3 + 1;
}

long euler_vierzehn() {
    int counter;
    long num = 0;
    int half = 0;
    int maxChain = 0;
    int currentMaxNum;
    for (int i = 1; i < 1000000; i++) {
        counter = 1;
        num = i;
        while (num > 1) {
            //cout << i << ": " << num << endl;
            half = getHalve(num);
            if (0 == half) {
                num = getOdd(num);
            } else {
                num = half;
            }
            counter++;
        }
        if (counter > maxChain) {
            maxChain = counter;
            currentMaxNum = i;
        }

    }
    cout << "maxChain = " << maxChain << endl;
    return currentMaxNum;
}

unsigned long fak(unsigned long num) {
    if (num == 0) {
        return 1;
    }
    return num * fak(num - 1);
}

unsigned long long fakHalf(int num) {

    if (0 != num % 2 || num <= 0) {
        return 0;
    }
    unsigned long long fakHalf = 1;
    for (int i = num; i > num / 2; i--) {
        for (int multi = i; multi >= 1; multi++) {

        }
        fakHalf *= i;
        cout << i << ": " << fakHalf << endl;
    }
    return fakHalf;
}

/* Zahlen zu groß siehe Lösung in euler_15.js*/
unsigned long long euler_fuenfzehn(long gridSize) {
    unsigned long long routes = 0;
    int binomialRow = gridSize * 2;
    unsigned long long n = fakHalf(binomialRow);
    unsigned long long k = fak(gridSize);
    routes = n / k;

    return routes;
}

/**
 * converts a string containing only numbers into a string that is double the amount
 * 
 * @param stringNum
 * @return string
 */
string getDouble(string stringNum) {
    std::vector<int> square;
    //initial push for catching overflows
    square.push_back(0);
    //filling the vector with content from string
    for (int index = 0; index < stringNum.size(); index++) {
        square.push_back(stringNum[index] - '0');
    }
    int overflow = 0;
    //doubling all digits in vector 
    for (int i = square.size() - 1; i >= 0; i--) {

        //checking for overflow and calculating new digit
        if (square[i]*2 + overflow <= 9) {
            square[i] *= 2;
            square[i] += overflow;
            overflow = 0;
        } else {
            square[i] = ((square[i] * 2) % 10) + overflow;
            overflow = 1;
        }
    }
    //removing unnecessary zero if exists
    if (square[0] == 0) {
        square.erase(square.begin());
    }

    std::ostringstream doubledString;

    //converting vector to string
    if (!square.empty()) {
        // Convert all but the last element to avoid a trailing
        std::copy(square.begin(), square.end() - 1,
                std::ostream_iterator<int>(doubledString));

        // Now add the last element with no delimiter
        doubledString << square.back();
    }

    return doubledString.str();
}

int euler_sechszehn(int num, int pow) {
    int sum = 0;
    string stringNum = static_cast<ostringstream*> (&(ostringstream() << num))->str();
    for (int i = 1; i < pow; i++) {
        stringNum = getDouble(stringNum);
    }
    for (int i = 0; i < stringNum.size(); i++) {
        sum += stringNum[i] - '0';
    }
    return sum;
}

int getOneTillFifteen(int num) {
    switch (num) {
        case 1: return 3;
        case 2: return 3;
        case 3: return 5;
        case 4: return 4;
        case 5: return 4;
        case 6: return 3;
        case 7: return 5;
        case 8: return 5;
        case 9: return 4;
        case 10: return 3;
        case 11: return 6;
        case 12: return 6;
        case 13: return 7;
        case 14: return 8;
        case 15: return 7;
        default: return 0;
    }
}

int getTeens(int num) {
    switch (num) {
        case 1: return 4; //teen
        case 2: return 6; //twenty
        case 3: return 6; //thirty
        case 4: return 5; //forty
        case 5: return 5; //fifty
        case 6: return 5; //sixty
        case 7: return 7; //seventy
        case 8: return 6; //eighty
        case 9: return 6; //ninety
        default: return 0;
    }
}

int getNumOfLetters(int num) {
    int sum = 0;
    int firstDigit;
    int secondDigit;
    int thirdDigit;
    int fourthDigit;
    int hundred = 7;
    int thousand = 8;
    if (num < 100 && num > 15) {
        firstDigit = (num - (num % 10)) / 10;
        sum += getTeens(firstDigit);
        secondDigit = num % 10;
        sum += getOneTillFifteen(secondDigit);
    } else if (num <= 15) {
        sum += getOneTillFifteen(num);
    }
    if (num >= 100 && num < 1000) {
        sum += hundred;
        firstDigit = (num - (num % 100)) / 100;
        sum += getOneTillFifteen(firstDigit);
        if (getOneTillFifteen(num % 100) != 0) {
            sum += getOneTillFifteen(num % 100);
            sum += 3;
        } else {
            secondDigit = ((num % 100) - ((num % 100) % 10)) / 10;
            sum += getTeens(secondDigit);
            thirdDigit = (num % 100) % 10;
            sum += getOneTillFifteen(thirdDigit);
        }
        //counts letters for and if necessary
        if (secondDigit + thirdDigit > 0) {
            sum += 3;
        }
    }
    if (num >= 1000 && num < 10000) {
        sum += thousand;
        firstDigit = (num - (num % 1000)) / 1000;
        sum += getOneTillFifteen(firstDigit);
        secondDigit = (num % 1000 - ((num % 1000) % 100)) / 100;
        sum += getOneTillFifteen(secondDigit);
        if (getOneTillFifteen((num % 1000) % 100) != 0) {
            sum += getOneTillFifteen((num % 1000) % 100);
            sum += 3;
        } else {
            thirdDigit = (((num % 1000) % 100) - (((num % 1000) % 100) % 10)) / 10;
            sum += getTeens(thirdDigit);
            fourthDigit = (((num % 1000) % 100)) % 10;
            sum += getOneTillFifteen(fourthDigit);
        }

        if (fourthDigit + thirdDigit > 0) {
            sum += 3;
        }
    }

    return sum;
}

int euler_siebzehn(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += getNumOfLetters(i);
    }
    return sum;
}

unsigned long mix(unsigned long a, unsigned long b, unsigned long c) {
    a = a - b;
    a = a - c;
    a = a^(c >> 13);
    b = b - c;
    b = b - a;
    b = b^(a << 8);
    c = c - a;
    c = c - b;
    c = c^(b >> 13);
    a = a - b;
    a = a - c;
    a = a^(c >> 12);
    b = b - c;
    b = b - a;
    b = b^(a << 16);
    c = c - a;
    c = c - b;
    c = c^(b >> 5);
    a = a - b;
    a = a - c;
    a = a^(c >> 3);
    b = b - c;
    b = b - a;
    b = b^(a << 10);
    c = c - a;
    c = c - b;
    c = c^(b >> 15);
    return c;
}

int euler_achtzehn() {
    std::vector<int> triangleArray[15];
    triangleArray[0].push_back(75);

    triangleArray[1].push_back(95);
    triangleArray[1].push_back(64);

    triangleArray[2].push_back(17);
    triangleArray[2].push_back(47);
    triangleArray[2].push_back(82);

    triangleArray[3].push_back(18);
    triangleArray[3].push_back(35);
    triangleArray[3].push_back(87);
    triangleArray[3].push_back(10);

    triangleArray[4].push_back(20);
    triangleArray[4].push_back(4);
    triangleArray[4].push_back(82);
    triangleArray[4].push_back(47);
    triangleArray[4].push_back(65);

    triangleArray[5].push_back(19);
    triangleArray[5].push_back(1);
    triangleArray[5].push_back(23);
    triangleArray[5].push_back(75);
    triangleArray[5].push_back(3);
    triangleArray[5].push_back(34);

    triangleArray[6].push_back(88);
    triangleArray[6].push_back(2);
    triangleArray[6].push_back(77);
    triangleArray[6].push_back(73);
    triangleArray[6].push_back(7);
    triangleArray[6].push_back(63);
    triangleArray[6].push_back(67);

    triangleArray[7].push_back(99);
    triangleArray[7].push_back(65);
    triangleArray[7].push_back(4);
    triangleArray[7].push_back(28);
    triangleArray[7].push_back(6);
    triangleArray[7].push_back(16);
    triangleArray[7].push_back(70);
    triangleArray[7].push_back(92);

    triangleArray[8].push_back(41);
    triangleArray[8].push_back(41);
    triangleArray[8].push_back(26);
    triangleArray[8].push_back(56);
    triangleArray[8].push_back(83);
    triangleArray[8].push_back(40);
    triangleArray[8].push_back(80);
    triangleArray[8].push_back(70);
    triangleArray[8].push_back(33);

    triangleArray[9].push_back(41);
    triangleArray[9].push_back(48);
    triangleArray[9].push_back(72);
    triangleArray[9].push_back(33);
    triangleArray[9].push_back(47);
    triangleArray[9].push_back(32);
    triangleArray[9].push_back(37);
    triangleArray[9].push_back(16);
    triangleArray[9].push_back(94);
    triangleArray[9].push_back(29);

    triangleArray[10].push_back(53);
    triangleArray[10].push_back(71);
    triangleArray[10].push_back(44);
    triangleArray[10].push_back(65);
    triangleArray[10].push_back(25);
    triangleArray[10].push_back(43);
    triangleArray[10].push_back(91);
    triangleArray[10].push_back(52);
    triangleArray[10].push_back(97);
    triangleArray[10].push_back(51);
    triangleArray[10].push_back(14);

    triangleArray[11].push_back(70);
    triangleArray[11].push_back(11);
    triangleArray[11].push_back(33);
    triangleArray[11].push_back(28);
    triangleArray[11].push_back(77);
    triangleArray[11].push_back(73);
    triangleArray[11].push_back(17);
    triangleArray[11].push_back(78);
    triangleArray[11].push_back(39);
    triangleArray[11].push_back(68);
    triangleArray[11].push_back(17);
    triangleArray[11].push_back(57);

    triangleArray[12].push_back(91);
    triangleArray[12].push_back(71);
    triangleArray[12].push_back(52);
    triangleArray[12].push_back(38);
    triangleArray[12].push_back(17);
    triangleArray[12].push_back(14);
    triangleArray[12].push_back(91);
    triangleArray[12].push_back(43);
    triangleArray[12].push_back(58);
    triangleArray[12].push_back(50);
    triangleArray[12].push_back(27);
    triangleArray[12].push_back(29);
    triangleArray[12].push_back(48);

    triangleArray[13].push_back(63);
    triangleArray[13].push_back(66);
    triangleArray[13].push_back(4);
    triangleArray[13].push_back(68);
    triangleArray[13].push_back(89);
    triangleArray[13].push_back(53);
    triangleArray[13].push_back(67);
    triangleArray[13].push_back(30);
    triangleArray[13].push_back(73);
    triangleArray[13].push_back(16);
    triangleArray[13].push_back(69);
    triangleArray[13].push_back(87);
    triangleArray[13].push_back(40);
    triangleArray[13].push_back(31);

    triangleArray[14].push_back(4);
    triangleArray[14].push_back(62);
    triangleArray[14].push_back(98);
    triangleArray[14].push_back(27);
    triangleArray[14].push_back(23);
    triangleArray[14].push_back(9);
    triangleArray[14].push_back(70);
    triangleArray[14].push_back(98);
    triangleArray[14].push_back(73);
    triangleArray[14].push_back(93);
    triangleArray[14].push_back(38);
    triangleArray[14].push_back(53);
    triangleArray[14].push_back(60);
    triangleArray[14].push_back(4);
    triangleArray[14].push_back(23);

    int max = 0;
    int sum = 0;
    int salt = 0;
    int arraySize = sizeof (triangleArray) / sizeof (triangleArray[0]);
    int predecessor = 0;
    unsigned long seed = mix(clock(), time(NULL), getpid());

    while (true) {
        predecessor = 0;
        sum = triangleArray[0][0];
        for (int i = 1; i < arraySize; i++) {

            srand(seed);
            salt = rand() % 2; //0 or 1
            predecessor += salt;
            sum += triangleArray[i][predecessor];

            while (mix(clock(), time(NULL), getpid()) == seed) {
                //do nothing, wait for new seed
            }
            //get new seed when
            seed = mix(clock(), time(NULL), getpid());
        }
        if (sum > max) {
            cout << "new max found: " << sum << endl;
            max = sum;
        }
    }
    return max;
}

int euler_neunzehn() {
    bool leapYear = false;
    int days = 0;
    int sundays = 0;
    int dayOfTheWeek = 1; //Monday
    for (int year = 1900; year <= 2000; year++) {
        leapYear = (0 == (year % 4) && 0 != (year % 100)) || (0 == (year % 100) && 0 == (year % 400));
        for (int month = 1; month <= 12; month++) {
            if (2 == month) {
                days = leapYear ? 29 : 28;
            } else if (9 == month || 4 == month || 6 == month || 11 == month) {
                days = 30;
            } else {
                days = 31;
            }
            for (int i = 1; i <= days; i++) {
                if (dayOfTheWeek < 7) {
                    dayOfTheWeek++;
                } else {
                    if (1 == i && year >= 1901) {
                        sundays++;
                    }
                    dayOfTheWeek = 1;
                }
            }
        }
    }
    return sundays;
}

int euler_zwanzig() {
    string cheatHundredFak = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
    int sum = 0;
    for (int i = 0; i < cheatHundredFak.size(); i++) {
        sum += cheatHundredFak[i] - '0';
    }
    return sum;
}

long sum_of_divisors(int iNum) {
    if (0 == iNum) return 0;
    if (1 == iNum) return 1;
    //prüfung auf 1 und iNum selbst überspringen
    long iSum = 1;
    if (2 == iNum) return iSum;
    unsigned long sqrtiNum = sqrt(iNum);
    //ungerade sind nur durch ungerade teilbar -> gerade überspringen
    if (iNum % 2 != 0) {
        for (int i = 3; i <= sqrtiNum; i += 2) {
            if (iNum % i == 0) {
                iSum += i;
                //doppeltes addieren von Zahlen vermeiden
                if (iNum / i != i) {
                    iSum += iNum / i;
                }
            }
        }
    } else {
        for (int i = 2; i <= sqrtiNum; i++) {
            if (iNum % i == 0) {
                iSum += i;
                //doppeltes addieren von Zahlen vermeiden
                if (iNum / i != i) {
                    iSum += iNum / i;
                }
            }
        }
    }
    return iSum;
}

int euler_einundzwanzig() {
    int b;

    int sum = 0;

    for (int a = 1; a <= 10000; a++) {
        b = sum_of_divisors(a);
        if (sum_of_divisors(b) == a && a != b) {
            cout << a << endl;
            sum += a;
        }
    }
    return sum;
}

void euler_zweiundzwanzig() {
    //siehe euler_22.php
}

int euler_dreiundzwanzig() {
#define SIZE 28123

    std::vector<int> abundantNums;
    int abuSumNums[SIZE + 1] = {0};
    long sum = 0;
    long abuSum = 0;
    for (int i = 12; i <= SIZE - 12; i++) {
        if (sum_of_divisors(i) > i) {
            abundantNums.push_back(i);
        }
    }
    for (int a = 0; a < abundantNums.size(); a++) {
        for (int b = a; b < abundantNums.size(); b++) {
            abuSum = abundantNums[a] + abundantNums[b];
            if (20161 == abuSum) {
                cout << abundantNums[a] << " + " << abundantNums[b] << endl;
            }
            if (abuSum <= SIZE + 1 && 0 == abuSumNums[abuSum]) {
                abuSumNums[abuSum] = 1;

            }
        }
    }

    for (int i = 0; i <= SIZE + 1; i++) {
        if (0 == abuSumNums[i]) {
            //cout << "ist nicht als summe darstellbar: " << i << endl;
            sum += i;
        }
    }
    return sum;
}

void euler_vierundzwanzig() {
    // siehe Papier-> 999999 / 9! usw. dann verschieben von links nach rechts
}

string sumStrings(string numberA, string numberB) {
    //swap numbers for calculation algoithm reaons
    if (numberA.size() < numberB.size()) {
        swap(numberA, numberB);
    }
    int stringLengthA = numberA.size();
    int stringLengthB = numberB.size();
    //length of the new number +1 because of possible overflow
    int newNumberSize = stringLengthA + 1;
    std::vector<int> newNumberVec;
    //setting the size so we can add new digits from right to left
    newNumberVec.resize(newNumberSize);
    bool overflow = false;
    int digitA, digitB, newDigit;

    int i = 0;
    while (i <= stringLengthB || overflow) {
        //go through all digits for each number and take their values
        if (i < stringLengthA) {
            digitA = numberA[stringLengthA - 1 - i] - '0';
        } else {
            digitA = 0;
        }
        if (i < stringLengthB) {
            digitB = numberB[stringLengthB - 1 - i] - '0';
        } else {
            digitB = 0;
        }
        
        newDigit = digitA + digitB;
        //if overflow was true in the previous round we have add +1
        if (overflow) newDigit++;
        
        //cout << "newDigit: " << newDigit << ", A: " << digitA << ", B: " << digitB <<endl;
        //no overflow so simply add both digits and asign them as new digit for new number
        if (newDigit <= 9) {
            overflow = false;
            newNumberVec[newNumberSize - 1 - i] = newDigit;
            //cout << "new stringnumber(<10): " << newNumberVec[newNumberSize - 1 - i] << endl;
        //overflow -> look up last digit with modulo and take it as new digit for new number    
        } else if (newDigit >= 10) {
            overflow = true;
            newDigit %= 10;
            newNumberVec[newNumberSize - 1 - i] = newDigit;
            //cout << "new stringnumber(>10): " << newNumberVec[newNumberSize - 1 - i] << endl;
        }
        i++;
        
    }
    
    std::ostringstream myNewNumber;
    if (0 == newNumberVec[0]) {
        newNumberVec.erase(newNumberVec.begin());
    }
    //converting vector to string
    if (!newNumberVec.empty()) {
        // Convert all but the last element to avoid a trailing
        std::copy(newNumberVec.begin(), newNumberVec.end() - 1,
                std::ostream_iterator<int>(myNewNumber));

        // Now add the last element with no delimiter
        myNewNumber << newNumberVec.back();
    }

    return myNewNumber.str();
    
}


long euler_fuenfundzwanzig() {
    long count = 2;
    
    string strPre = "1";
    string strNext = "1";
    string placeholder = "";

    while (strNext.size() < 1000) {
        count++;
        placeholder = strNext;
        strNext = sumStrings(strPre, strNext);
        strPre = placeholder;

    }
    return count;
}

int main(int argc, char** argv) {
    //cout << "ergebnis für Euler Nr.1 = " << euler_eins() << endl;
    //cout << "ergebnis für Euler Nr.2 = " <<euler_zwei(4000000) << endl;
    //cout << "ergebnis für Euler Nr.3 = " << euler_drei(600851475143) << endl;
    //cout << "ergebnis für Euler Nr.4 = " << euler_vier() << endl;
    //cout << "ergebnis für Euler Nr.5 = " << euler_fuenf() << endl;
    //cout << "ergebnis für Euler Nr.6 = " << euler_sechs() << endl;
    //cout << "ergebnis für Euler Nr.7 = " << euler_sieben() << endl;
    //cout << "ergebnis für Euler Nr.8 = " << euler_acht() << endl;
    //cout << "ergebnis für Euler Nr.9 = " << euler_neun() << endl;
    //cout << "ergebnis für Euler Nr.10 = " << euler_zehn() << endl;
    //cout << "ergebnis für Euler Nr.12 = " << euler_zwoelf() << endl;
    //cout << "ergebnis für Euler Nr.14 = " << euler_vierzehn() << endl;
    //cout << "ergebnis für Euler Nr.16 = " << euler_sechszehn(2, 1000) << endl;
    //cout << "ergebnis für Euler Nr.17 = " << euler_siebzehn(1000) << endl;
    //cout << "ergebnis für Euler Nr.18 = " << euler_achtzehn() << endl;
    //cout << "ergebnis für Euler Nr.19 = " << euler_neunzehn() << endl;
    //cout << "ergebnis für Euler Nr.20 = " << euler_zwanzig() << endl;
    //cout << "ergebnis für Euler Nr.21 = " << euler_einundzwanzig() << endl;
    //cout << "ergebnis für Euler Nr.23 = " << euler_dreiundzwanzig() << endl;
    //cout << "ergebnis für Euler Nr.24 = " << euler_vierundzwanzig() << endl;
    //cout << "ergebnis für Euler Nr.24 = " << euler_fuenfundzwanzig() << endl;
    
}
