#include <iostream>
#include <iomanip>
#include <cmath>

void ShowComma()
{
    int a = 1, b = 2, c = 3;
    int x = (a, b, c);
    int y = a = b = c;
    std::cout << x << '\t' << y << std::endl;
}

void CalculateJudgeAverage()
{
    int number_of_judges;
    double total_score = 0;
    std::cin >> number_of_judges;
    for (int idx = 0; idx < number_of_judges; ++idx)
    {
        int each_score = 0;
        std::cin >> each_score;
        total_score += each_score;
    }
    double Average_score = total_score / number_of_judges;
    std::cout << std::fixed << std::setprecision(1) << Average_score << std::endl; 
}

void CalculateYearsToDouble()
{
    double money = 100000;
    int years = 0;
    while (money < 200000)
    {
        money *= 1.05;
        years++;
    }
    std::cout << years << std::endl;
}

void CalculateSquareRoot()
{
    double original_number;
    std::cin >> original_number;
    while (original_number < 0)
    {
        printf("%f cant be negative. Try another positive number: ", original_number);
    }
    double tempx1 = original_number / 2;
    double tempx2 = (tempx1 + original_number / tempx1) / 2;
    do
    {
        tempx1 = tempx2;
        tempx2 = (tempx1 + original_number / tempx1) /2;
    }
    while (fabs(tempx2 - tempx1) < 1e-5);
    double result = tempx2;
    std::cout << result << std::endl;
}

void PrintMultiplicationTable()
{
    for (int row = 1; row <= 9; ++row)
    {
        for (int column = 1; column <= row; ++column)
        {
            int multiplied_result = column * row;
            std::cout << column << '*' << row << '=' << multiplied_result << '\t';
        }
        std::cout << std::endl;
    }
}

void CheckPrime()
{
    int number;
    std::cin >> number;
    while (number <= 1)
    {
        std::cout << "Choose an integer number bigger than 1: ";
        std::cin >> number;
    }
    bool is_prime = true;
    int limit = static_cast<int>(sqrt(number));
    for (int n = 2; n <= limit; ++n)
    {
        if (number % n == 0)
        {
            is_prime = false;
            break;
        }
    }
    if (is_prime)
    {
        std::cout << number << " is a prime." << std::endl;
    }
    else
    {
        std::cout << number << " isnt a prime." << std::endl; 
    }
}

void FindPrime()
{
    for (int number = 2; number <= 100; ++number)
    {
        bool is_prime = true;
        int limit = static_cast<int>(sqrt(number));
        if (number % 2 == 0 && number != 2)
        {
            continue;
        }
        else
        {
            for (int division = 3; division <= limit; division += 2)
            {
                if (number % division == 0)
                {
                    is_prime = false;
                    continue;
                }
            }
        }
        if (is_prime)
        {
            std::cout << number << ' ';
        }
    }
}

void SolveHundredChickens()
{
    for (int male_count = 0; male_count <= 100 / 5; ++male_count)
    {
        for (int female_count = 0; female_count <= 100 / 3; ++female_count)
        {
            int immature_count = 100 - male_count - female_count;
            if ((male_count * 5 + female_count * 3 + immature_count / 3 == 100) && (immature_count % 3 == 0))
            {
                printf("male: %d female: %d immature: %d\n", male_count, female_count, immature_count);
            }
        }
    }
}

void CalculateSin()
{
    const double kEpsilon = 1e-4;
    double number, expand_item, result;
    std::cin >> number;
    expand_item = result = number;
    int sign = -1, factorial_n = 1;
    while (fabs(expand_item) >= kEpsilon)
    {
        expand_item = expand_item * pow(number, 2) / ((factorial_n * 2) * (factorial_n * 2 + 1));
        result += sign * expand_item;
        sign *= -1;
        factorial_n++;
    }
    printf("sin(%g) = %f", number, result);
}

void PrintFibonacci()
{
    int former = 0, latter = 1;
    std::cout << former << ' ' << latter << ' ';
    for (int idx = 0; idx < 18; ++idx)
    {
        int temp = former + latter;
        std::cout << temp << ' ';
        former = latter;
        latter = temp;
    }
}

void TurtleRabbitRace()
{
    const int kTurtleVelocity = 3, kRabbitVelocity = 9;
    const int kRabbitRestLimit = 30, kRabbitRunLimit = 10;
    int minute;
    std::cin >> minute;
    int turtle_distance = 0, rabbit_distance = 0;
    int rabbit_run_time = 0, rabbit_rest_time = 0;
    bool is_rabbit_rest = false;
    for (int time = 1; time <= minute; ++time)
    {
        turtle_distance += kTurtleVelocity;
        if (is_rabbit_rest)
        {
            ++rabbit_rest_time;
            if (rabbit_rest_time == kRabbitRestLimit)
            {
                rabbit_rest_time = 0;
                is_rabbit_rest = false;
            }
        }
        else
        {
            ++rabbit_run_time;
            rabbit_distance += kRabbitVelocity;
            if (rabbit_run_time == kRabbitRunLimit)
            {
                rabbit_run_time = 0;
                if (rabbit_distance > turtle_distance)
                {
                    is_rabbit_rest = true;
                }
            }
        }
    }
    if (rabbit_distance > turtle_distance)
    {
        std::cout << "Rabbit wins." << std::endl;
    }
    else if (rabbit_distance < turtle_distance)
    {
        std::cout << "Turtle wins." << std::endl;
    }
    else
    {
        std::cout << "The contest is a draw." << std::endl;
    }
}

int main()
{
    TurtleRabbitRace();
    return 0;
}