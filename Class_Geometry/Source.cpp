#include <iostream>
#include "string"
#define _USE_MATH_DEFINES
#include <math.h> // cmath не работает, жалуется что M_PI не обпределён
using namespace std;

const int COORDINATE = 2;


class Geometry
{
public:
    Geometry () {}

    //Geometry (int amount_points)
    //{
    //    class_amount_lines = amount_points;
    //    class_figure_points = new double* [class_amount_lines];
    //    for (int i = 0; i < class_amount_lines; i++)
    //    {
    //        class_figure_points[i] = new double[COORDINATE];
    //    }
    //}

    Geometry (double** figure_points, int amount_points)
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
        arr_amount_angle = new int [class_amount_lines];
    }

    // Создание линии фигуры из данных координат
    void Make_lines ()
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
        cout << "All lines of the figure: ";
        for (int i = 0; i < class_amount_lines; i++)
        {
            cout << arr_figure_lines[i] << "  ";
        }
        cout << endl << endl;
    }

    // Возможно ли построение такой фигуры
    void Check_life ()
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
        if (check_figure_life)
        {
            cout << "Check_life function:  Triangle can be make in real life" << endl;
        }
        else
        {
            cout << "Check_life function:  Triangle is broken" << endl;
        }
        cout << endl;
    } // Возможно ли построение такой фигуры
	virtual void Square () = 0;
    virtual void Check_type () {}; // Вид заданной пользователем фигуры
    virtual void Find_angles () {};

    virtual void Print_coordinate () {};

    ~Geometry ()
    {
        delete[] arr_figure_lines;
        for (int i = 0; i < class_amount_lines; i++)
        {
            delete[] arr_figure_points[i];
        }
        delete[] arr_figure_points;
        delete[] arr_amount_angle;
    }

    //friend istream& operator >>(istream& in, const Geometry* other);

protected:
	int class_amount_lines{};
	double** arr_figure_points{};
    double* arr_figure_lines{};

	bool check_figure_life = false;

    int* arr_amount_angle{};
    double squareGeometry{};

    string geometry_type{};
};

//istream& operator >>(istream& in, const Geometry* other)
//{
//    cout << "Enter all points with coordinates:" << endl;
//    for (int i = 0; i < other->class_amount_lines; i++)
//    {
//        cout << "Line " << i + 1 << ":  coordinate: ";
//        for (int j = 0; j < COORDINATE; j++)
//        {
//            if (j == 0)
//            {
//                cout << "x" << i + 1 << ": ";
//                cin >> other->class_figure_points[i][j];
//            }
//            else
//            {
//                cout << "		     y" << i + 1 << ": ";
//                cin >> other->class_figure_points[i][j];
//            }
//        }
//        cout << endl;
//    }
//    return in;
//}


class Triangle : public Geometry
{
public:
    // Make lines

    //void Make_lines () override
    //{
    //    for (int i = 0; i < class_amount_lines; i++)
    //    {
    //        int class_coordinate = 0;
    //        if (i == class_amount_lines - 1)
    //        {
    //            class_figure_lines[i] = sqrt (((pow ((class_figure_points[0][class_coordinate] - class_figure_points[i][class_coordinate]), 2)) +
    //                (pow ((class_figure_points[0][class_coordinate + 1] - class_figure_points[i][class_coordinate + 1]), 2))));
    //        }
    //        else
    //        {
    //            class_figure_lines[i] = sqrt (((pow ((class_figure_points[i + 1][class_coordinate] - class_figure_points[i][class_coordinate]), 2)) +
    //                (pow ((class_figure_points[i + 1][class_coordinate + 1] - class_figure_points[i][class_coordinate + 1]), 2))));
    //        }
    //    }
    //}

	// Конструктор, который вызывает конструктор родителя
	Triangle (double** figure_points, int amount_points) : Geometry (figure_points, amount_points) 
    {
        Find_angles ();
        geometry_type = "Triangle: ";
    }

    void Print_coordinate () override
    {
        cout << "All coordinates of all points of the figure: " << endl;
        for (int i = 0; i < class_amount_lines; i++)
        {
            cout << "Line " << i + 1 << ":  coordinate: ";
            for (int j = 0; j < COORDINATE; j++)
            {
                if (j == 0)
                {
                    cout << "x" << i + 1 << ": " << arr_figure_points[i][j] << endl;
                }
                else
                {
                    cout << "		     y" << i + 1 << ": " << arr_figure_points[i][j];
                }
            }
            cout << endl<<endl;
        }
    }

	void Find_angles () override
    {
        if (!check_figure_life)
        {
            cout << "Find_angles function:  Triangle can't be made in IRL" << endl;
            return;
        }

        int sum_angle = 0;
        for (int i = 0; i < class_amount_lines; i++)
        {
            double formula_top = 0;
            double formula_bot = 2;

            if (i != 2)
            {
                for (int j = 0; j < class_amount_lines; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    else
                    {
                        formula_top += pow (arr_figure_lines[j], 2);
                        formula_bot *= arr_figure_lines[j];
                    }
                }
                arr_amount_angle[i] = int (acos ((formula_top - pow (arr_figure_lines[i], 2)) / formula_bot) * 180 / M_PI);
                sum_angle += arr_amount_angle[i];
            }
            else
            {
                arr_amount_angle[i] = 180 - sum_angle;
            }
        }
        int temp = 0;

        for (int k = 0; k < class_amount_lines - 1; k++)
        {
            temp = arr_amount_angle[k];
            arr_amount_angle[k] = arr_amount_angle[k + 1];
            arr_amount_angle[k + 1] = temp;
        }

        cout << "All angle in this triangle: " << endl;
        for (int q = 0; q < class_amount_lines; q++)
        {
            cout << "Angle for " << q + 1 << " point:  " << arr_amount_angle[q] << endl;
        }
        cout << endl;
    }

	void Check_type () override
	{
        if (!check_figure_life)
        {
            cout << "Check_type function:  Triangle can't be made in IRL" << endl;
            return;
        }
        for (int i = 0; i < class_amount_lines; i++)
        {
            if (arr_amount_angle[i] == 90)
            {
                geometry_type += " Rectangular, ";
                break;
            }
            else if (arr_amount_angle[i] > 90)
            {
                geometry_type += " Obtuse, ";
                break;
            }
            if (i == 2)
            {
                geometry_type += " Acute-angled, ";
            }
        }
        int check_equal_lines = 0;
        for (int i = 0; i < class_amount_lines; i++)
        {
            for (int j = i + 1; j < class_amount_lines; j++)
            {
                if (i != j)
                {
                    if (arr_figure_lines[i] == arr_figure_lines[j])
                    {
                        check_equal_lines++;
                    }
                }
            }
        }
        if (check_equal_lines == 3)
        {
            geometry_type += "Equilateral triangle";
        }
        else if (check_equal_lines == 1)
        {
            geometry_type += "Isosceles triangle";
        }
        else
        {
            geometry_type += "Versatile triangle";
        }
        cout << geometry_type << endl;
	}

	void Square () override
    {
        if (!check_figure_life)
        {
            cout << "Square function:  Triangle can't be made in IRL"<<endl;
            return;
        }
        double perimetr = 0;;

        for (int i = 0; i < class_amount_lines; i++)
        {
            perimetr += arr_figure_lines[i];
        }
        perimetr /= 2;

        squareGeometry = sqrt (perimetr * (perimetr - arr_figure_lines[0]) * (perimetr - arr_figure_lines[1]) * (perimetr - arr_figure_lines[2]));

        cout << "Square: " << squareGeometry << endl;
    }
};



//class Rectangle : public Geometry
//{
//public:
//	Rectangle (double** figure_points, int amount_points) : Geometry (figure_points, amount_points) {}
//
//	void Square () override
//	{
//        return;
//	}
//};


int main ()
{
	int amount_points;
	cout << "Enter count of point in figure: ";
	cin >> amount_points;
	cout << endl;

	if (amount_points <3 && amount_points <5)
	{
		cout << "Error , I cant make Geometry, because points = " << amount_points << endl;
	}
	else
	{
		double** figure_points = new  double*[amount_points];
		for (int i = 0; i < amount_points; i++)
		{
			figure_points[i] = new double[COORDINATE];
		}

		switch (amount_points)
		{
		case 3:
		{
            cout << "Enter all points with coordinates:" << endl;
            for (int i = 0; i < amount_points; i++)
            {
                cout << "Line " << i + 1 << ":  coordinate: ";
                for (int j = 0; j < COORDINATE; j++)
                {
                    if (j == 0)
                    {
                        cout << "x" << i + 1 << ": ";
                        cin >> figure_points[i][j];
                    }
                    else
                    {
                        cout << "		     y" << i + 1 << ": ";
                        cin >> figure_points[i][j];
                    }
                }
                cout << endl;
            }
            Triangle tri (figure_points, amount_points);

            //tri.Print_coordinate ();
			//tri.Check_life ();
            //tri.Square ();
			//tri.Find_angles ();
            tri.Check_type ();
		}
			break;

        //case 4:
        //{
        //    cout << "Enter all points with coordinates:" << endl;
        //    for (int i = 0; i < amount_points; i++)
        //    {
        //        cout << "Line " << i + 1 << ":  coordinate: ";
        //        for (int j = 0; j < COORDINATE; j++)
        //        {
        //            if (j == 0)
        //            {
        //                cout << "x" << i + 1 << ": ";
        //                cin >> figure_points[i][j];
        //            }
        //            else
        //            {
        //                cout << "		     y" << i + 1 << ": ";
        //                cin >> figure_points[i][j];
        //            }
        //        }
        //        cout << endl;
        //    }
//
        //    //Rectangle quad (figure_points, amount_points);
//
        //}
        //break;

		default:
			break;
		}

		
        for (int i = 0; i < amount_points; i++)
        {
            delete[] figure_points[i];
        }
        delete[] figure_points;
	}



    return 0;
}