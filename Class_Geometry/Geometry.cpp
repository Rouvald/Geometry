#include "Geometry.h"
#include "Constants.h"

Geometry::Geometry ()
{
    class_amount_lines = NULL;
    arr_figure_points = nullptr;
    arr_amount_angle = nullptr;
}

Geometry::Geometry (int amount_points)
{
    class_amount_lines = amount_points;
    arr_figure_points = new double* [class_amount_lines];
    for (int i = 0; i < class_amount_lines; i++)
    {
        arr_figure_points[i] = new double[COORDINATE];
    }
    arr_amount_angle = new int[class_amount_lines];
}

/*Geometry::Geometry (double** figure_points, int amount_points)
{
    class_amount_lines = amount_points;
    arr_figure_points = new double* [class_amount_lines];
    for (int i = 0; i < class_amount_lines; i++)
    {
        arr_figure_points[i] = new double[COORDINATE];
    }

    for (int i = 0; i < class_amount_lines; i++)
    {
        for (int j = 0; j < COORDINATE; j++)
        {
            arr_figure_points[i][j] = figure_points[i][j];
        }
    }
    Make_lines ();
    Check_life ();
    arr_amount_angle = new int[class_amount_lines];
}*/

/*friend istream& operator >>(istream& in, Geometry& other);
friend ostream& operator << (ostream& out, const Geometry& other);*/

// —оздание линии фигуры из данных координат
void Geometry::Make_lines ()
{
    arr_figure_lines = new double[class_amount_lines];

    for (int i = 0; i < class_amount_lines; i++)
    {
        int class_coordinate = 0;
        if (i == class_amount_lines - 1)
        {
            arr_figure_lines[i] = sqrt (((pow ((arr_figure_points[0][class_coordinate] - arr_figure_points[i][class_coordinate]), 2)) +
                (pow ((arr_figure_points[0][class_coordinate + 1] - arr_figure_points[i][class_coordinate + 1]), 2))));
        }
        else
        {
            arr_figure_lines[i] = sqrt (((pow ((arr_figure_points[i + 1][class_coordinate] - arr_figure_points[i][class_coordinate]), 2)) +
                (pow ((arr_figure_points[i + 1][class_coordinate + 1] - arr_figure_points[i][class_coordinate + 1]), 2))));
        }
    }
    /*cout << "All lines of the figure: ";
    for (int i = 0; i < class_amount_lines; i++)
    {
        cout << arr_figure_lines[i] << "  ";
    }
    cout << endl << endl;*/
}

// ¬озможно ли построение такой фигуры
void Geometry::Check_life ()
{

    for (int i = 0; i < class_amount_lines; i++)
    {
        double sum = 0;
        for (int j = 0; j < class_amount_lines; j++)
        {
            if (j == i)
            {
                continue;
            }
            else
            {
                sum += arr_figure_lines[j];
            }
        }
        if (sum > arr_figure_lines[i])
        {
            check_figure_life = true;
        }
        else
        {
            check_figure_life = false;
            break;
        }
    }
    /*if (check_figure_life)
    {
        cout << "Check_life function:  Triangle can be make in real life" << endl;
    }
    else
    {
        cout << "Check_life function:  Triangle is broken" << endl;
    }
    cout << endl;*/
}

Geometry::~Geometry ()
{
    delete[] arr_figure_lines;
    for (int i = 0; i < class_amount_lines; i++)
    {
        delete[] arr_figure_points[i];
    }
    delete[] arr_figure_points;
    delete[] arr_amount_angle;
}

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