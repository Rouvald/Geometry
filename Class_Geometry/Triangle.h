#pragma once
#include "Geometry.h"


class Triangle : public Geometry
{
public:
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

   // Конструктор по умолчанию, который вызывает конструктор по умолчанию родителя
    Triangle () : Geometry () {}

    Triangle (int amount_points) : Geometry (amount_points) {}

    // Конструктор, который вызывает конструктор родителя
    /*Triangle (double** figure_points, int amount_points) : Geometry (figure_points, amount_points)
    {
        Find_angles ();
    }*/


    void Print_coordinate () override;

    void Square () override;

    //void Draw () override;

    friend istream& operator >>(istream& in, Triangle& other);
    friend ostream& operator << (ostream& out, const Triangle& other);

    //Use_File
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

protected:

    void Find_angles () override;

    void Check_type () override;
};
