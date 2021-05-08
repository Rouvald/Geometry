/*#include <iostream>
#include "string"
#include "fstream"
#define _USE_MATH_DEFINES
#include <math.h> // cmath не работает, жалуется что M_PI не обпределён
using namespace std;*/
#include "Geometry.h"
#include "Triangle.h"

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

	if (amount_points <3 || amount_points >=4)
	{
		cout << "Error , I cant make Geometry, because points = " << amount_points << endl;
	}
	else
	{
		/*double** figure_points = new  double*[amount_points];
		for (int i = 0; i < amount_points; i++)
		{
			figure_points[i] = new double[COORDINATE];
		}*/

		switch (amount_points)
		{
		case 3:
		{
            /*cout << "Enter all points with coordinates:" << endl;
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
            }*/
            cout << "it's great! You wanna create the triangle!" << endl << endl;
            Triangle tri(amount_points);

            cin >> tri;
            cout << endl << endl;
            cout << tri;
            tri.Square ();
            tri.Draw ();
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

		
        /*for (int i = 0; i < amount_points; i++)
        {
            delete[] figure_points[i];
        }
        delete[] figure_points;
        */
	}



    return 0;
}