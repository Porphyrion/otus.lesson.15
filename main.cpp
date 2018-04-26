#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <dlib/clustering.h>
#include <dlib/rand.h>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace dlib;

using sample_type = matrix<double, 2, 1>;
using kernel_type =  radial_basis_kernel<sample_type>;

int main(int argc, char const *argv[])
{
    int nCenters;
    if(argc > 1){
        nCenters = atoi(argv[1]);
    } else {
        nCenters = 3;
    }
    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 12);
    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

    sample_type m;

    string line;
    ofstream oFile("result.txt");

    while(std::getline(std::cin, line)){
        boost::tokenizer<boost::char_separator<char>>
                tokenizer{line, boost::char_separator<char>{";"}};
                auto i = 0;
                for (auto j : tokenizer) {
                    m(i) = stod(j); ++i;
                }
                samples.push_back(m);
    }

    test.set_number_of_centers(nCenters);
    pick_initial_centers(nCenters, initial_centers, samples, test.get_kernel());
    test.train(samples,initial_centers);

    for(auto i : samples){
        oFile<<i(0)<<";"<<i(1)<<";"<<test(i)<<endl;
    }

    std::vector<unsigned long> assignments = spectral_cluster(kernel_type(0.1), samples, 4);
    cout << mat(assignments) << endl;


    return 0;
}
