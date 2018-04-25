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

int main()
{
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

    //std::cout<<"Samples size: "<<samples.size()<<std::endl;
    test.set_number_of_centers(3);
    pick_initial_centers(3, initial_centers, samples, test.get_kernel());
    test.train(samples,initial_centers);

    for(auto i : samples){
        oFile<<i(0)<<";"<<i(1)<<";"<<test(i)<<endl;
    }

    //cout << "num dictionary vectors for center 0: " << test.get_kcentroid(0).dictionary_size() << endl;
    //cout << "num dictionary vectors for center 1: " << test.get_kcentroid(1).dictionary_size() << endl;
    //cout << "num dictionary vectors for center 2: " << test.get_kcentroid(2).dictionary_size() << endl;

    std::vector<unsigned long> assignments = spectral_cluster(kernel_type(0.1), samples, 4);
    cout << mat(assignments) << endl;
}
