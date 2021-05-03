#pragma once
#include <iostream>
#include "string"
#include "fstream"
#define _USE_MATH_DEFINES
#include <math.h> // cmath не работает, жалуется что M_PI не обпределён
#include "iomanip"

using namespace std;


class Geometry
{
public:
    Geometry ();

    Geometry (int amount_points);

    //Geometry (double** figure_points, int amount_points);

    ~Geometry ();

    /*friend istream& operator >>(istream& in, Geometry& other);
    friend ostream& operator << (ostream& out, const Geometry& other);*/

protected:
    int class_amount_lines{};
    int** arr_figure_points{};
    double* arr_figure_lines{};

    bool check_figure_life = false;

    double* arr_amount_angle{};
    double squareGeometry{};

    string geometry_type{};

    // Создание линии фигуры из данных координат
    void Make_lines ();

    // Возможно ли построение такой фигуры
    void Check_life ();

    virtual void Square () = 0;
    virtual void Check_type () = 0; // Вид заданной пользователем фигуры
    virtual void Find_angles () = 0;

    virtual void Print_coordinate () = 0;

    virtual void Draw () = 0;

    virtual void Meridian () = 0;
};

/*istream& operator >>(istream& in, Geometry& other)
{
    if (other->class_amount_lines == NULL)
    {
        cout << "Error: class_amount_lines = NULL";
        return in;
    }
    cout << "Enter all points with coordinates:" << endl;
    for (int i = 0; i < other->class_amount_lines; i++)
    {
        cout << "Line " << i + 1 << ":  coordinate: ";
        for (int j = 0; j < COORDINATE; j++)
        {
            if (j == 0)
            {
                cout << "x" << i + 1 << ": ";
                cin >> other->arr_figure_points[i][j];
            }
            else
            {
                cout << "		     y" << i + 1 << ": ";
                cin >> other->arr_figure_points[i][j];
            }
        }
        cout << endl;
    }
    other->Make_lines ();
    other->Check_life ();
    other->Find_angles ();
    other->Check_type ();
    return in;
}*/

/*ostream& operator << (ostream& out, const Geometry& other)
{
    cout << "All lines of the figure: ";
    for (int i = 0; i < other.class_amount_lines; i++)
    {
        cout << other.arr_figure_lines[i] << "  ";
    }
    cout << endl << endl;

    if (other.check_figure_life)
    {
        cout << "Check_life function:  Triangle can be make in real life" << endl;
    }
    else
    {
        cout << "Check_life function:  Triangle is broken" << endl;
    }
    cout << endl;

    cout << "All angle in this triangle: " << endl;
    for (int q = 0; q < other.class_amount_lines; q++)
    {
        cout << "Angle for " << q + 1 << " point:  " << other.arr_amount_angle[q] << endl;
    }
    cout << endl;

    cout << other.geometry_type << endl;

    return out;
}*/
