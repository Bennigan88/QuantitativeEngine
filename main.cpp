#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



double xi, xf, vi, vf, ac, t;
char cxi, cxf, cvi, cvf, ca, ct;
bool bxi, bxf, bvi, bvf, ba, bt;

bool even(int x);
double f(double x);
int choose_coef_s(int i, int n);
int choose_coef_m(int i, int n);
int choose_coef_t(int i, int n);
void simpsons(double apar, double bpar, int ppar);
void midpoint(double apar, double bpar, int npar);
void trapezoid(double apar, double bpar, int npar);
void kinematics(void);
void kinematics_report(void);
void simpsons_menu(void);
void midpoint_menu(void);
void trapezoid_menu(void);
void kinematics_menu(void);
bool wrong_answer(char anspar);

double a=0;
double b=0;
int p=0;
int n=0;
double dx=0;
char ans;
int choice;




int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    do {
        system("CLS");
        cout << "Please make a selection: " << endl << endl;
        cout
             << "1. Midpoint Rule Integration\n"
             << "2. Trapezoid Rule Integration\n"
             << "3. Simpson's Rule Integration\n"
             << "4. Kinematic Solver\n"
             << "5. Quit" << endl << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do {
                system("CLS");
                cout << "You have chosen to integrate with the Midpoint Rule. Is this correct? y/n: ";
                cin >> ans;
                switch (ans)
                {
                    case 'y':
                        break;
                    case 'n':
                        main();
                        break;
                    default:
                        cout << "You have entered an incorrect key." << endl;
                        system("PAUSE");
                };
            } while (wrong_answer(ans));

            midpoint_menu();
            break;
        case 2:
            do {
                system("CLS");
                cout << "You have chosen to integrate with the Trapezoid Rule. Is this correct? y/n: ";
                cin >> ans;
                switch (ans)
                {
                    case 'y':
                        break;
                    case 'n':
                        main();
                        break;
                    default:
                        cout << "You have entered an incorrect key." << endl;
                        system("PAUSE");
                };
            } while (wrong_answer(ans));

            trapezoid_menu();
            break;
        case 3:
            do {
                system("CLS");
                cout << "You have chosen to integrate with Simpson's Rule. Is this correct? y/n: ";
                cin >> ans;
                switch (ans)
                {
                    case 'y':
                        break;
                    case 'n':
                        main();
                        break;
                    default:
                        cout << "You have entered an incorrect key." << endl;
                        system("PAUSE");
                };
            } while (wrong_answer(ans));

            simpsons_menu();
            break;
        case 4:
            do {
                system("CLS");
                cout << "You have chosen to use the Kinematic Solver. Is this correct? y/n: ";
                cin >> ans;
                switch (ans)
                {
                    case 'y':
                        break;
                    case 'n':
                        main();
                        break;
                    default:
                        cout << "You have entered an incorrect key." << endl;
                        system("PAUSE");
                };
            } while (wrong_answer(ans));

            kinematics_menu();
            break;
        case 5:
            exit (0);
            break;
        };



        do {
            cout << endl << endl << "Return to QEngine main menu? y/n: ";
            cin >> ans;
        } while (wrong_answer(ans));

        if (ans=='n')
            exit (0);

    } while (ans == 'y');



}

bool even(int x) //simple even test. if even, returns 1
{
    if (x%2==0)
        return 1;
    else
        return 0;
}
double f(double x) //here function of curve is defined by programmer
{
    //here programmer defines function of curve
    const long double e = 2.718281828459045235360287471352662497757247093;
    //return (pow(x,3));
    //return (1/(sqrt(pow(e,pow(x,2))-3*pow(x,2))));
    //return (sqrt(pow(x,2)+x+1));
    //return (1/(1+pow(x,2)));
//    return(sin(pow(e,(.5*x))));
    return(cos(pow(x,2)));

}

int choose_coef_t(int i, int n)
{
    if (i==0||i==n) //if first or last term, coef is 1
        return 1;
    else
        return 2; //all intermediate terms will be 2
}
int choose_coef_s(int i, int n) //these coefficients are based on Simpon's Rule
{
    if (i==0 || i==n) //first and last time around
        return 1;
    else if (!(even(i))) //if i is odd
        return 4;
    else
        return 2;
}

void simpsons_menu(void)
{
    system("CLS");
    cout << "-----------------SIMPSON'S RULE----------------------------------" << endl;
    cout << "Please set limits of integration separated by a space: ";
    cin >> a >> b;
    cout << "Please set number of parabolas to estimate with: ";
    cin >> p;
    cout << endl;
    cout << "Range of integration will be divided into " << p*2 << " divisions (n=" << p*2 << "). \nIntegral will be"
         << " estimated with " << p << " parabolas." << endl << endl;
    system("PAUSE");
    simpsons(a,b,p);
}
void trapezoid_menu(void)
{
    system("CLS");
    cout << "-----------------TRAPEZOID RULE----------------------------------" << endl;
    cout << "Please set limits of integration separated by a space: ";
    cin >> a >> b;
    cout << "Please set number of trapezoids to estimate with: ";
    cin >> n;
    cout << endl;
    cout << "Range of integration will be divided into " << n << " trapezoids." << endl;
    system("PAUSE");
    trapezoid(a,b,n);
}
void midpoint_menu(void)
{
    system("CLS");
    cout << "-----------------MIDPOINT RULE-----------------------------------" << endl;
    cout << "Please set limits of integration separated by a space: ";
    cin >> a >> b;
    cout << "Please set number of divisions to estimate integral with: ";
    cin >> n;
    cout << endl;
    cout << "Range of integration will be divided into " << n << " segments." << endl;
    system("PAUSE");
    midpoint(a,b,n);
}
void kinematics_menu(void)
{
//    system("CLS");
//    cout << "Welcome to the Kinematic Solver. Please have ready the following informatoin if available:" << endl;
//    cout << "Initial and final positions, initial and final velocities, acceleration, and time." << endl;
//    system("PAUSE");
    kinematics();
}
void kinematics(void)
{

    system("CLS");
    do
    {
        //first the program will ask if each variable is given, and if it is, the user will be
        //prompted to provide the value for that variable. if user indicates variable is not given,
        //the program will echo that the variable is not given
        do {
            system("CLS");
            bxi=0; bxf=0; bvi=0; bvf=0; ba=0; bt=0; //sets all variables to not given
            cout << "Is initial position given? y/n: "; //asks if xi is given
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
            } while (wrong_answer(ans));

        if (ans == 'y')
        {
            cout << "Please enter initial position in meters: "; //asks for value of xi
            cin >> xi;
            cout << "You entered an initial position of " << xi << " meters." << endl << endl;
            bxi = true; //sets xi to "given"
            system("PAUSE");
        }
        else if (ans == 'n')
        {
            cout << "You have indicated that initial position is not given." << endl << endl;
            bxi = false; //sets xi to "not given"
            system("PAUSE");
        }


        do {
            system("CLS");
            kinematics_report();
            cout<< "Is final position given? y/n: "; //asks if xf is given
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));

        if (ans == 'y')
        {
            cout << "Please enter final position in meters: "; //asks for value of xf
            cin >> xf;
            cout << "You entered a final position of " << xf << " meters." << endl << endl;
            bxf = true; //sets xf to "given"
            system("PAUSE");

        }
        else if (ans == 'n')
        {
            cout << "You have indicated that final position is not given." << endl << endl;
            bxf = false; //sets xf to "not given"
            system("PAUSE");
        }

        do {
            system("CLS");
            kinematics_report();
            cout << "Is initial velocity given? y/n: ";
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));

        if (ans == 'y')
        {
           cout << "Please enter initial velocity in meters per second: ";
           cin >> vi;
           cout << "You entered an initial velocity of " << vi << " meters per second." << endl << endl;
           bvi = true; //sets vi as "given"
           system("PAUSE");
        }
        else if (ans =='n')
        {
            cout << "You have indicated that initial velocity is not given." << endl << endl;
            bvi = false; //sets vi as "not given"
            system("PAUSE");
        }

        do {
            system("CLS");
            kinematics_report();
            cout<< "Is final velocity given? y/n: "; //asks if vf is given
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));

        if (ans == 'y')
        {
            cout << "Please enter final velocity in meters per second: ";
            cin >> vf;
            cout << "You entered a final velocity of " << vf << " meters per second." << endl << endl;
            bvf = true; //sets vf to "given"
            system("PAUSE");
        }
        else if (ans =='n')
        {
            cout << "You have indicated that final velocity is not given." << endl << endl;
            bvf = false; //sets vf to "not given"
            system("PAUSE");
        }

        do {
            system("CLS");
            kinematics_report();
            cout<< "Is acceleration given? y/n: "; //asks if a is given
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));

        if (ans == 'y')
        {
            cout << "Please enter acceleration in meters per second per second: ";
            cin >> ac;
            cout << "You entered an acceleration of " << a << " meters per second per second." << endl << endl;
            ba = true; //sets a to "given"
            system("PAUSE");
        }
        else if (ans =='n')
        {
            cout << "You have indicated that acceleration is not given." << endl << endl;
            ba = false; //sets a to "not given"
            system("PAUSE");
        }

        do {
            system("CLS");
            kinematics_report();
            cout<< "Is time given? y/n: "; //asks if t is given
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered an incorrect answer." << endl << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));

        if (ans == 'y')
        {
            cout << "Please enter time in seconds: ";
            cin >> t,
            cout << "You entered a time of " << t << " seconds." << endl << endl;
            bt = true; //sets t to "given"
            system("PAUSE");
        }
        else if (ans =='n')
        {
            cout << "You have indicated that time is not given." << endl << endl;
            bt = false; //sets t to "not given"
            system("PAUSE");
        }


        //now the computer wil go through several if conditions, each condition being a set
        //of boolean values indicating whether each variable is "given" or "not given".
        //if a specific set of booleans is met, the variable will be d for using a predefined equation.
        //if the booleans are not met, the next set of booleans is evaluated, and then the next. if none of the
        //sets of boolean conditions are met, program outputs message that no appropriate equation exists.

        system("CLS");
        kinematics_report();
        string solve_for;
        cout << "Please choose a variable to solve for. Select by typing xi, xf, vi, vf, a, or t\n"
             << "followed by pressing enter: ";
        cin >> solve_for;
        cout << "You selected " << solve_for << "." << endl;

        if (solve_for == "xi")
        {
            if ((bxf==true)&&(bvi==true)&&(bt==true)&&(ba==true)) //if all variables are given for xi equation 1
            {
                cout << "xi will be solved for with xi equation #1\n";
                cout << "xi = xf - vi*t - (1/2)a*t^2" << endl;
                xi = (xf - vi*t - .5*ac*(pow(t,2)));
                cout << "xi = " << xi << " meters." << endl;
            }
            else if ((bxf==true)&&(bvf==true)&&(bvi==true)&&(ba==true))
            {
                cout << "xi will be solved for with xi equation #2\n";
                cout << "xi = xf - (vf^2-vi^2)/2a" << endl;
                xi = xf - (pow(vf,2) - pow(vi,2))/(2*ac);
                cout << "xi = " << xi << " meters." << endl;
            }
            else if ((bxf==true)&&(bvi==true)&&(bvf==true)&&(bt==true))
            {
                cout << "xi will be solved for with xi equation #3" << endl;
                cout << "xi = xf - (1/2)(vi + vf)*t" << endl;
                xi = (xf - (1/2)*(vi + vf)*t);
                cout << "xi = " << xi << " meters." << endl;
            }
            else if ((bxf==true)&&(bvf==true)&&(bt==true)&&(ba==true))
            {
                cout << "xi will be solved for with xi equation #4" << endl;
                cout << "xi = xf - vf*t + (1/2)a*t^2" << endl;
                xi = xf - vf*t + (1/2)*ac*pow(t,2);
                cout << "xi =" << xi << " meters" << endl;
            }
            else
                cout << "There is no equation for xi that matches the given variables." << endl;
        }
        else if (solve_for == "xf")
        {
            if ((bxi==true)&&(bvi==true)&&(bt==true)&&(ba==true))
            {
                cout << "xf will be solved for with xf equation #1" << endl;
                cout << "xf = xi + vi*t + (1/2)a*t^2" << endl;
                xf = xi + vi*t + (1/2)*ac*pow(t,2);
                cout << "xf = " << xf << " meters" << endl;
            }
            else if ((bvf==true)&&(bvi==true)&&(bxi==true)&&(ba==true))
            {
                cout << "xf will be solved for with xf equation #2" << endl;
                cout << "xf = xi + (vf^2 - vi^2)/2a" << endl;
                xf = xi + (pow(vf,2) - pow(vi,2))/(2*ac);
                cout << "xf = " << xf << " meters." << endl;
            }
            else if ((bxi==true)&&(bvi==true)&&(bvf==true)&&(bt==true))
            {
                cout << "xf will be solved for with xf equation #3" << endl;
                cout << "xf = xi + (1/2)(vi + vf)*t" << endl;
                xf = xi + (1/2)*(vi + vf)*t;
                cout << "xf = " << xf << " meters." << endl;
            }
            else if ((bxi==true)&&(bvf==true)&&(bt==true)&&(ba==true))
            {
                cout << "xf will be solved for with xf equation #4" << endl;
                cout << "xf = xi + vf*t - (1/2)a*t^2" << endl;
                xf = xi + vf*t - (1/2)*ac*pow(t,2);
                cout << "xf = " << xf << " meters." << endl;
            }
            else
                cout <<"There is no equation for xf that matches the given variables." << endl;
        }
        else if (solve_for == "vi")
        {
            if ((bvf==true)&&(ba==true)&&(bt==true))
            {
                cout << "vi will be solved for with vi equation #1" << endl;
                cout << "vi = vf - a*t" << endl;
                vi = vf - ac*t;
                cout << "vi = " << vi << " meters per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(ba==true)&&(bt==true))
            {
                cout << "vi will be solved for with vi equation #2" << endl;
                cout << "vi = (xf - xi)/t - (1/2)a*t" << endl;
                vi = (xf - xi)/t - (1/2)*ac*t;
                cout << "vi = " << vi << " meters." << endl;
            }
            else if ((bvf==true)&&(ba==true)&&(bxf==true)&&(bxi==true))
            {
                cout << "vi will be solved for with vi equation #3" << endl;
                cout << "vi = sqrt(vf^2 - 2a(xf - xi))" << endl;
                vi = sqrt(pow(vf,2)-(2*ac)*(xf - xi));
                cout << "vi = " << vi << " meters per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(bvf==true)&&(bt==true))
            {
                cout << "vi will be solved for with vi equation #4" << endl;
                cout << "vi = 2(xf - xi)/t - vf" << endl;
                vi = 2*(xf - xi)/t - vf;
                cout << "vi = " << vi << " meters per second." << endl;
            }
            else
            {
                cout << "There is no equation for vi that matches the given variables." << endl;
            }
        }
        else if (solve_for == "vf")
        {
            if ((bvi==true)&&(ba==true)&&(bt==true))
            {
                cout << "vf will be solved for with vf equation #1" << endl;
                cout << "vf = vi + a*t";
                vf = vi + ac*t;
                cout << "vf = " << vf << " meters per second." << endl;
            }
            else if ((bvi==true)&&(ba==true)&&(bxf==true)&&(bxi==true))
            {
                cout << "vf will be solved for with vf equation #2" << endl;
                cout << "vf = sqrt(vi^2 + 2a(xf - xi))" << endl;
                vf = sqrt(pow(vi,2) + (2*ac)*(xf - xi));
                cout << "vf = " << vf << " meters per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(bvi==true)&&(bt==true))
            {
                cout << "vf will be solved for with vf equation #3" << endl;
                cout << "vf = 2(xf - xi)/t - vi" << endl;
                vf = 2*(xf - xi)/t - vi;
                cout << "vf = " << vf << " meters per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(ba==true)&&(bt==true))
            {
                cout << "vf will be solved for with vf equation #4" << endl;
                cout << "vf = (xf - xi)/t + (1/2)a*t" << endl;
                vf = (xf - xi)/t + (1/2)*ac*t;
                cout << "vf = " << vf << " meters per second." << endl;
            }
            else
            {
                cout << "There is no equation for vf that matches the given variables." << endl;
            }
        }
        else if (solve_for == "a")
        {
            if ((bvf==true)&&(bvi==true)&&(bt==true))
            {
                cout << "a will be solved for with a equation #1" << endl;
                cout << "a = (vf - vi)/t" << endl;
                ac = (vf - vi)/t;
                cout << "a = " << a << " meters per second per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(bvi==true)&&(bt==true))
            {
                cout << "a will be solved for with a equation #2" << endl;
                cout << "a = 2(xf - xi - vi*t)/t^2" << endl;
                ac = 2*(xf - xi - vi*t)/pow(t,2);
                cout << "a = " << a << " meters per second per second." << endl;
            }
            else if ((bvf==true)&&(bvi==true)&&(bxf==true)&&(bxi==true))
            {
                cout << "a will be solved for with a equation #3" << endl;
                cout << "a = (vf^2 - vi^2)/2(xf - xi)" << endl;
                ac = (pow(vf,2) - pow(vi,2))/(2*(xf - xi));
                cout << "a = " << a << " meters per second per second." << endl;
            }
            else if ((bxf==true)&&(bxi==true)&&(bvf==true)&&(bt==true))
            {
                cout << "a will be solved for with a equation #4" << endl;
                cout << "a = -2(xf - xi - vf*t)/t^2" << endl;
                ac = -2*(xf - xi - vf*t)/pow(t,2);
                cout << "a = " << a << " meters per second per second." << endl;
            }
            else
            {
                cout << "There is no equation for a that matches the given variables." << endl;
            }
        }
        else if (solve_for == "t")
        {
            if ((bvf==true)&&(bvi==true)&&(ba==true)&&(ac!=0))
            {
                cout << "t will be solved for with t equation #1" << endl;
                cout << "t = (vf - vi)/a" << endl;
                t = (vf - vi)/ac;
                cout << "t = " << t << " seconds." << endl;
            }
            else if ((bvi==true)&&(ba==true)&&(bxf==true)&&(bxi==true))
            {
                if ((a==0)&&(vi!=0))
                {
                    cout << "t will be solved for with t equation #2 for a=0" << endl;
                    cout << "t = (xf - xi)/vi" << endl;
                    t = (xf - xi)/vi;
                    cout << "t = " << t << " seconds." << endl;
                }
                else
                {
                    cout << "t will be solved for with t equation #2" << endl;
                    cout << "t = (-vi + sqrt(vi^2 + 2a(xf - xi)))/a AND t = (-vi - sqrt(vi^2 + 2a(xf-xi)))/a" << endl;
                    t = (-vi + sqrt(pow(vi,2) + (2*ac)*(xf - xi)))/ac;
                    cout << "t = " << t << " seconds AND t = ";
                    t = (-vi - sqrt(pow(vi,2) + (2*ac)*(xf - xi)))/ac;
                    cout << t << " seconds." << endl; //in this instance, there are two values for t that satisfy conditions
                }


            }
            else if ((bxf==true)&&(bxi==true)&&(bvi==true)&&(bvf==true))
            {
                cout << "t will be solved for with t equation #3" << endl;
                cout << "t = 2(xf - xi)/(vi + vf)" << endl;
                t = 2*(xf - xi)/(vi + vf);
                cout << "t = " << t << " seconds." << endl;
            }
            else if ((bvf==true)&&(ba==true)&&(bxf==true)&&(bxi==true))
            {
                cout << "t will be solved for with t equation #4" << endl;
                cout << "t = (-vf + sqrt(vf^2 - 2a(xf - xi)))/-a AND t = (-vf - sqrt(vf^2 - 2a(xf - xi)))/-a" << endl;
                t = (-vf + sqrt(pow(vf,2) - (2*ac)*(xf - xi)))/-a;
                cout << "t = " << t << " seconds AND t = ";
                t = (-vf - sqrt(pow(vf,2) - (2*ac)*(xf - xi)))/-a;
                cout << t << " seconds." << endl;
            }
            else
            {
                cout << "There is no equation for t that matches the given variables." << endl;
            }
        }


        cout << endl << endl;
        do {
            cout << "Would you like to do additional kinematic computations? y/n: ";
            cin >> ans;
            if (wrong_answer(ans))
                {
                    cout << "You have entered a wrong answer." << endl;
                    system("PAUSE");
                }
        } while (wrong_answer(ans));


    } while (ans == 'y' || ans == 'Y');
}


void trapezoid(double apar, double bpar, int npar)
{
    system("CLS");
    cout << "-----------------TRAPEZOID RULE----------------------------------" << endl;

    dx = (bpar-apar)/n; //dx is length of each division

    int coef=0;
    double series=0;

    cout.precision(5);
    cout << "Series looks like: " << endl;
    for (int i=0; i<=n; i++)
        {
            coef = choose_coef_t(i,n);
            series += coef*f(apar+(dx*i));
            cout << coef << " * " << "f(" << apar+(dx*i) << ") +" << endl;
        }
    cout.precision(20);
    cout << "dx/2 = " << dx/2 << endl;
    cout << "series = " << series << endl;
    cout.precision(20);
    cout << endl << "Definite integral = " << (dx/2)*(series);

}
void midpoint(double apar, double bpar, int npar)
{
    system("CLS");
    cout << "-----------------MIDPOINT RULE-----------------------------------" << endl;

    dx = (bpar-apar)/n;  //dx is length of each division

    int coef=0;
    double series=0;

    cout.precision(5);
    cout << "Series looks like: " <<endl;
        for (int i=0; i<n; i++)
        {
            //no need to choose a coefficient, all coefficients are 1
            series += f(.5*(apar+(dx*i)+apar+(dx*(i+1))));
            cout << "f(" << (.5*(apar+(dx*i)+apar+(dx*(i+1)))) << ") +" << endl;
        }
    cout << "dx = " << dx << endl;
    cout << "series = " << series << endl;
    cout.precision(20);
    cout << "Definite integral = " << dx*series;
}
void simpsons(double apar, double bpar, int ppar)
{
    system("CLS");
    cout << "-----------------SIMPSON'S RULE----------------------------------" << endl;

    n=2*ppar; //two divisions for each parabola
    dx = (bpar-apar)/n; //dx is length of each division

    int coef=0;
    double series=0;

    cout.precision(5);
    cout << "Series looks like: " << endl;
    for (int i=0; i<=n; i++)
    {
        coef = choose_coef_s(i,n);
        series += coef*f(apar+(dx*i));
        cout << coef << " * " << "f(" << apar+(dx*i) << ") +" << endl;
    }

    cout << "dx/3 = " << dx/3 << endl;
    cout << "series = " << series << endl;
    cout.precision(20);
    cout << endl << "Definite integral = " << (dx/3)*(series);
}

bool wrong_answer(char anspar)
{
    if (!(anspar=='y'||anspar=='n')) //if ans is not either y, Y, n, or N
        return 1; //answer is not appropriate
    else
        return 0; //answer is appropriate
}
void kinematics_report(void)
{

    if (bxi)
        cout << "xi = " << xi << "m, ";
    if (bxf)
        cout << "xf = " << xf << "m, ";
    if (bvi)
        cout << "vi = " << vi << "m/s, ";
    if (bvf)
        cout << "vf = " << vf << "m/s, ";
    if (ba)
        cout << "a = " << ac << "m/s/s, ";
    if (bt)
        cout << "t = " << t << "s, ";

    if ((bxi)||(bxf)||(bvi)||(bvf)||(ba)||(bt))
        cout << endl << endl;
}



