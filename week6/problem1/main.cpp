#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include <valarray>
#include <fstream>

using namespace std;

using path = vector<double>;
using multipath = vector<path>;

path gbm_single_path_demo(double S0, double mu, double sigma, double T, double dt, mt19937 &gen){
    path results(100, S0);
    return results;
}

void write_all(const multipath &V, string fn = "multiRuns.csv") {
  ofstream my_file(fn);
  for (int t = 0; t < static_cast<int>(V[0].size()); ++t) {
    int p = 0;
    // write the 1st column without comma
    my_file << V[p++][t];
    // To write CSV file, we need to loop over all series' i element
    for (; p < static_cast<int>(V.size()); ++p) {
      my_file << "," << V[p][t]; // print "," from 2nd column onwards
    }
    my_file << endl;
  }
  my_file.close();
}

void test_end_values(valarray<double> vals, double expected_mean,
                     double expected_stdev) {
  auto mean = vals.sum() / vals.size();
  auto stdev = sqrt(pow(vals - mean, 2.0).sum() / vals.size());
  auto mean_diff = (mean - expected_mean) / expected_mean;
  auto stdev_diff = (stdev - expected_stdev) / expected_stdev;
  cout << "[n]: " << vals.size() << " mean: " << mean << " (" << mean_diff
       << "), stdev: " << stdev << " (" << stdev_diff << ")" << endl;
}

int main(){
    // gbm
    const double mu = 0.5;
    const double sigma = 0.3;
    // mc simulation
    const size_t paths = 100'000;
    const double dt{1/365.0};
    // market data
    const double S0{100};
    // time to maturity
    const double T{dt * 120};

    const auto expected_mean = exp(T* mu) * S0;
    const auto expected_stdev = S0 * exp(T * mu) * sqrt(exp(sigma * sigma * T) - 1);

    cout << "expected mean: " << expected_mean << endl;
    cout << "expected stdev: " << expected_stdev << endl;

    seed_seq seed{1238982};
    mt19937 gen{seed};

    valarray<double> end_values(0.0, paths);
    
    multipath traj;

    gen.seed(seed);
    for (size_t n = 0; n < paths; n++) {
        traj.emplace_back(gbm_single_path_demo(S0, mu, sigma, T, dt, gen));
        end_values[n] = traj[n].back();
    }

    write_all(traj, "gbm_single_path.csv");
    test_end_values(end_values, expected_mean, expected_stdev);
    return 0;
}

