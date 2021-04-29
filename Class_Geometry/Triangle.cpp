#include "Constants.h"
#include "Triangle.h"


    //Make lines
    /*void Make_lines () override
   {
       for (int i = 0; i < class_amount_lines; i++)
       {
           int class_coordinate = 0;
           if (i == class_amount_lines - 1)
           {
               class_figure_lines[i] = sqrt (((pow ((class_figure_points[0][class_coordinate] - class_figure_points[i][class_coordinate]), 2)) +
                   (pow ((class_figure_points[0][class_coordinate + 1] - class_figure_points[i][class_coordinate + 1]), 2))));
           }
           else
           {
               class_figure_lines[i] = sqrt (((pow ((class_figure_points[i + 1][class_coordinate] - class_figure_points[i][class_coordinate]), 2)) +
                   (pow ((class_figure_points[i + 1][class_coordinate + 1] - class_figure_points[i][class_coordinate + 1]), 2))));
           }
       }
   }*/

    void Triangle::Print_coordinate () 
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
            cout << endl << endl;
        }
    }

    void Triangle::Square () 
    {
        if (!check_figure_life)
        {
            cout << "Square function:  Triangle can't be made in IRL" << endl;
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

    // Draw
    /*void Draw ()
    {
        cout << endl << endl;
        cout << "*****************************************************************" << endl << endl;

        int temp_COORDINATE_X = 0, temp_MIN_X = 99999, temp_MAX_Y = -99999,
            temp_COORDINATE_Y = 1,
            difference_COORDINATE_Y = 0;

        for (int i = 0; i < class_amount_lines; i++)
        {
            if (arr_figure_points[i][temp_COORDINATE_X] < temp_MIN_X)
            {
                temp_MIN_X = arr_figure_points[i][temp_COORDINATE_X];
                //temp_MIN_X_point = i;
            }
            //if (arr_figure_points[i][temp_COORDINATE_Y] > temp_MAX_Y)
            //{
            //    temp_MAX_Y = arr_figure_points[i][temp_COORDINATE_Y];
            //    //temp_MAX_Y_point = i;
            //}
        }
        //cout << temp_MIN_X <<"            "<< temp_MAX_Y << endl;

        int* arr_figure_points_Y = new int[class_amount_lines];
        int* arr_figure_points_Y_COORDINATE = new int[class_amount_lines];
        for (int q = 0; q < class_amount_lines; q++)
        {
            arr_figure_points_Y_COORDINATE[q] = arr_figure_points[q][temp_COORDINATE_Y];
            arr_figure_points_Y[q] = q;
        }

        for (int k = 0; k < class_amount_lines; k++)
        {
            int temp = 0, temp_amount = 0, temp_point = 0;
            temp_MAX_Y = -99999;
            for (int g = k; g < class_amount_lines; g++)
            {
                if (arr_figure_points_Y_COORDINATE[g] > temp_MAX_Y)
                {
                    temp_MAX_Y = arr_figure_points_Y_COORDINATE[g];
                    temp = g;
                }
            }
            temp_amount = arr_figure_points_Y_COORDINATE[k];
            arr_figure_points_Y_COORDINATE[k] = temp_MAX_Y;
            arr_figure_points_Y_COORDINATE[temp] = temp_amount;

            temp_point = arr_figure_points_Y[k];
            arr_figure_points_Y[k] = temp;
            arr_figure_points_Y[temp] = temp_point;

        }
        //for (int i = 0; i < class_amount_lines; i++)
        //{
        //    cout << arr_figure_points_Y_COORDINATE[i] <<"     "<< arr_figure_points_Y [i]<< endl;
        //}

        for (int i = 0; i < class_amount_lines; i++)
        {
            for (int j = 0; j < (int)arr_figure_points[arr_figure_points_Y[i]][temp_COORDINATE_X]+temp_MIN_X+4; j++)
            {
                if (j == (int)arr_figure_points[arr_figure_points_Y[i]][temp_COORDINATE_X]+ temp_MIN_X +4-1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            if (i < 2)
            {
                //difference_COORDINATE_Y = arr_figure_points_Y_COORDINATE[i] - arr_figure_points_Y_COORDINATE[i + 1];
                for (int k = 0; k < arr_figure_points_Y_COORDINATE[i]; k++)
                {
                    cout << endl;
                }
            }
        }
        cout << endl << endl;
        cout << "*****************************************************************" << endl << endl;

        delete[] arr_figure_points_Y;
        delete[] arr_figure_points_Y_COORDINATE;
    }*/

    // Use_File
    /*void Use_File ()
    {
        string name = "Geometry.txt";
        fstream fs;
        fs.open (name, fstream::app);

        if (!fs.is_open ())
        {
            cout << "Can't open file" << endl;
        }
        else
        {
            cout << "File is open" << endl;

            int value{};
            cout << "Make your choice" << endl;
            cout << "1 - write geometry in the file" << endl;
            cout << "2 - read geometry in the file" << endl;
            cin >> value;
            if (value == 1)
            {
                cout << "Write geometry object: "<<endl;
                fs << this<<"\n";
            }
            else if (value == 2)
            {
                cout << "Geometry object from file: "<<endl;
                while (!fs.eof())
                {
                    Triangle trio (class_amount_lines);
                    fs >> trio;
                    cout << trio;
                }
            }
        }
    }*/

    void Triangle::Find_angles () 
    {
        if (!check_figure_life)
        {
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
                arr_amount_angle[i] = acos ((formula_top - pow (arr_figure_lines[i], 2)) / formula_bot) * 180 / M_PI;
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

        /*cout << "All angle in this triangle: " << endl;
        for (int q = 0; q < class_amount_lines; q++)
        {
            cout << "Angle for " << q + 1 << " point:  " << arr_amount_angle[q] << endl;
        }
        cout << endl;*/
    }

    void Triangle::Check_type () 
    {
        if (!check_figure_life)
        {
            return;
        }

        geometry_type = "Triangle: ";

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
        //cout << geometry_type << endl;
    }

istream& operator >>(istream& in, Triangle& other)
{
    if (other.class_amount_lines == NULL)
    {
        cout << "Error: class_amount_lines = NULL";
        return in;
    }
    cout << "Enter all points with coordinates:" << endl;
    for (int i = 0; i < other.class_amount_lines; i++)
    {
        cout << "Point " << i + 1 << ":  coordinate: ";
        for (int j = 0; j < COORDINATE; j++)
        {
            if (j == 0)
            {
                cout << "x" << i + 1 << ": ";
                cin >> other.arr_figure_points[i][j];
            }
            else
            {
                cout << "		      y" << i + 1 << ": ";
                cin >> other.arr_figure_points[i][j];
            }
        }
        cout << endl;
    }
    other.Make_lines ();
    other.Check_life ();
    other.Find_angles ();
    other.Check_type ();
    return in;
}

ostream& operator << (ostream& out, const Triangle& other)
{
    cout << "All lines of the figure: " << endl;
    for (int i = 0; i < other.class_amount_lines; i++)
    {
        if (i == 2)
        {
            cout << "Line from " << i + 1 << " - " << i - 1 << " points: ";
            cout << other.arr_figure_lines[i] << "  ";
            cout << endl;
            break;
        }
        cout << "Line from " << i + 1 << " - " << i + 2 << " points: ";
        cout << other.arr_figure_lines[i] << "  ";
        cout << endl;
    }
    cout << endl;

    if (other.check_figure_life)
    {
        cout << "Check_life function:  Triangle can be made in real life" << endl;

        cout << "All angle in this triangle: " << endl;
        for (int q = 0; q < other.class_amount_lines; q++)
        {
            cout << "Angle for " << q + 1 << " point:  " << other.arr_amount_angle[q] << endl;
        }
        cout << endl;

        cout << other.geometry_type << endl << endl;
    }
    else
    {
        cout << "Check_life function:  Triangle is broken" << endl<<endl;
        cout << "Find_angles function:  Triangle can't be made in real life" << endl;
        cout << "Check_type function:  Triangle can't be made in real life" << endl;
    }
    cout << endl;

    return out;
}