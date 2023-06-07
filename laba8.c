#include <stdio.h>
#include <math.h> //для pow() 
#define M_PI 3.14159265358979323846

/* Va - скорость точки в апогее орбиты Земли
Vw - скорость конца геоцентрического радиус-вектора Ra
We - угловая скорость вращения Земли
Ra - радиус-вектор апогея
Rp - радиус-вектор перигея
u - гравитационный параметр Земли
i - наклонение орбиты
h - шаг вычислений 
endRa - правая граница для диапазона Ra */

int main () {

    //для файловой составляющей работы

    FILE *file = fopen("Kepler.csv", "w");

    //для математической составлящей работы

    const float u = 398600.4, i = (63.4 * M_PI) / 180;
    const double We = 7.2921159 * pow(10, -5);
    const int h = 10;
    double Va, Vw;
    int Ra = 45000, endRa = 60000;
    const double Rp = pow(We, 2) * pow(Ra, 4) * pow(cos(i), 2) / 
    (2*u - pow(We, 2) * pow(Ra, 3) * pow(cos(i), 2));

    Ra = 0;
    Va = 1, Vw = 0; //для условия пересечения Va > Vw

    fprintf(file, "Ra,Va,Vw\n");

    while ((Ra <= endRa) && (Va > Vw)) { //непонятно: до пересечения включительно или нет? Сделала вкл.
        Va = sqrt(2 * u * Rp / (Ra * (Ra + Rp)));
        Vw = We * Ra * cos(i);
        fprintf(file, "%d,%lf,%lf\n", Ra, Va, Vw);
        Ra+=h;
    };

    fclose(file);

    return 0;
}
