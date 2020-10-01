#include <stdio.h>
#include <math.h>
#include <windows.h>

float f(float x) {
    return sinf(x);
}

float rectangles(float start, float end, float amount) {
    float iter = start, ans = 0., step = (end-start)/amount;
    while (iter < end) {
        ans = ans + step * (f(iter)+f(iter+step)) / 2.;
        iter = iter + step;
    }
    return ans;
}

float simpson(float start, float end, float amount) {
    float iter = start, ans = 0., a, b, step = (end-start)/amount;
    while (iter < end) {
        a = iter;
        b = iter + step;
        ans = ans + ((b-a)/6.) * (f(a) + 4.*f((a+b)/2.) + f(b));
        iter = iter + step;
    }
    return ans;
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    float a = 0.,b = 0.;
    int experements[6] = {5,10,50,100,500,1000};
    float results[6][2];
    printf("%s", "введите a и b:\n");
    scanf("%f%f", &a,&b);
    for (int i=0; i<6; i++){
        results[i][0] = rectangles(a,b,experements[i]);
        results[i][1] = simpson(a,b,experements[i]);
        printf("%s%.5f%c%.5f%c", "кол-во ", results[i][0], ' ', results[i][1], '\n');
    }
    return 0.;
}