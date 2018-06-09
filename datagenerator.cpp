#include <iostream>
#include <fstream>
#include <string>
#include <dlib/rand.h>


int main(int argc, char const *argv[]) {

    std::ofstream oFile("example_data.txt");
    dlib::rand rnd;
    double x = 0; double y = 0;
    int num = 50;
    double radius = 0.5;
    for (long i = 0; i < num; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        x = 2*radius*rnd.get_random_double()-radius;
        y = sign*sqrt(radius*radius - x*x);
        oFile<<x<<";"<<y<<"\n";
    }

    radius = 10.0;
    for (long i = 0; i < num ; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        x = 2*radius*rnd.get_random_double()-radius ;
        y = sign*sqrt(radius*radius - x*x);
        oFile<<x<<";"<<y<<"\n";
    }

    radius = 4.0;
    for (long i = 0; i < num; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        x = 2*radius*rnd.get_random_double()-radius;
        y = sign*sqrt(radius*radius - x*x);

        x += 25;
        y += 25;
        oFile<<x<<";"<<y<<"\n";
    }

    std::ofstream oFileTwo("sky_data.txt");
    for(auto i = 0; i < 300; i++){
        auto x = rnd.get_double_in_range(-100,100);
        auto y = rnd.get_double_in_range(-100,100);
        oFileTwo<<x<<";"<<y<<'\n';
    }

    oFile.close();
    oFileTwo.close();

    return 0;
}
