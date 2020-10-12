#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define k 6

float f(float x) {
    return sinf(x);
}

float calcRectangles(float start, float end, float amountOfRectangles) {
    float iter = start, ans = 0., step = (end-start)/amountOfRectangles;
    while (iter < end) {
        ans = ans + step * (f(iter)+f(iter+step)) / 2.;
        iter = iter + step;
    }
    return ans;
}

float calcSimpson(float start, float end, float amountOfRectangles) {
    float iter = start, ans = 0., a, b, step = (end-start)/amountOfRectangles;
    while (iter < end) {
        a = iter;
        b = iter + step;
        ans = ans + ((b-a)/6.) * (f(a) + 4.*f((a+b)/2.) + f(b));
        iter = iter + step;
    }
    return ans;
}

int main(void) {
    float a = 0.,b = 0.;
    int experements[k] = {6,10,50,100,500,1000};
    float results[k][2];
    scanf("%f %f", &a,&b);
    if (a>b || a<0 || b>M_PI){
        printf("%s", "error: invalid interval");
    }
    else{
        for (int i=0; i<6; i++){
            results[i][0] = calcRectangles(a,b,experements[i]);
            results[i][1] = calcSimpson(a,b,experements[i]);
            printf("%d%s%.5f%c%.5f%c", experements[i], ": ", results[i][0], ' ', results[i][1], '\n');
        }
    }
    return 0;
}