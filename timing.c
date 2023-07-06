#include <stdio.h>
#include <time.h>

typedef struct
{
    int Ninput;
    double *weights;
    double threshold;
} Perceptron;

void initializeperceptron(Perceptron *p, int size)
{
    p->Ninput = size;
    p->weights = (double *)malloc(size * sizeof(double));
    p->weights[0] = -0.400000;
    p->weights[1] = -0.530000;
    p->threshold = 0.250000;
}

double predict(Perceptron p, double *input)
{
    double sum = 0.0;
    int N = p.Ninput;
    for (int i = 0; i < N; i++)
    {
        sum += p.weights[i] * input[i];
    }
    sum += p.threshold;
    return (sum >= 0) ? 1.0 : 0.0;
}

int main()
{
    Perceptron p1;
    initializeperceptron(&p1, 2);
    double input[2] = {1, 1};

    clock_t start = clock();
    double prediction = predict(p1, input);
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Prediction: %f\n", prediction);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}

