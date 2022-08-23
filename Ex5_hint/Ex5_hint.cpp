#include <iostream>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }
};

class Sphere :Solid
{
private:
    double radius;
public:
    Sphere(double radius) //球の半径
    {
        this->radius = radius;
    }
    double GetVolume()
    {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    double GetSurface()
    {
        return radius * radius * M_PI * 4;
    }
};

int main()
{
    Box box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cone<double> cone{ 3,2.5,5 };
    cout << " Coneの体積=" << cone.GetVolume() << endl;
    cout << " Coneの表面積=" << cone.GetSurface() << endl;
    Sphere<double> sphere{ 3 };
    cout << " Sphereの体積=" << sphere.GetVolume() << endl;
    cout << " Sphereの表面積=" << sphere.GetSurface() << endl;
}
